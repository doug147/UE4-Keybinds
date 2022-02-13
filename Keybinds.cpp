#include "Keybinds.h"

/// <summary>
/// Function handler for FSlateApplication::OnKeyDown.
/// Adds the key to the set of pressed keys then immediately processes it, as long as the IsRepeat flag is not true.
/// </summary>
/// <param name="KeyCode"></param>
/// <param name="CharacterCode"></param>
/// <param name="IsRepeat"></param>
/// <returns></returns>
bool Keybinds::OnKeyDown(const int32_t KeyCode, const uint32_t CharacterCode, const bool IsRepeat)
{
	if (!IsRepeat)
	{
		Get().PressedKeys.insert(KeyCode);
		Process(KeyCode);
	}
	return true;
}

/// <summary>
/// Function handler for FSlateApplication::OnKeyUp.
/// Removes the KeyCode from the set of Pressed keys.
/// </summary>
/// <param name="KeyCode"></param>
/// <param name="CharacterCode"></param>
/// <param name="IsRepeat"></param>
/// <returns></returns>
bool Keybinds::OnKeyUp(const int32_t KeyCode, const uint32_t CharacterCode, const bool IsRepeat)
{
	Get().PressedKeys.erase(KeyCode);
	return true;
}

/// <summary>
/// Returns the KeyCode from the FKey
/// </summary>
/// <param name="Key"></param>
/// <returns>KeyCode</returns>
int32_t Keybinds::GetKeyCodeFromKey(const sdk::FKey Key)
{
	if (auto it = std::find_if(Get().KeyMap.begin(), Get().KeyMap.end(),
			[&](const std::pair<int32_t, sdk::FKey>& pair) {
				return pair.second == Key;
			}); it != Get().KeyMap.end())
	{
		return it->first;
	}
	return 0;
}

/// <summary>
/// Clears the keybind, first resolving the FKey to a KeyCode
/// </summary>
/// <param name="Key"></param>
void Keybinds::ClearKeybind(const sdk::FKey Key)
{
	const auto KeyCode = GetKeyCodeFromKey(Key);
	if (!!KeyCode)
	{
		Get().FunctionMap.erase(KeyCode);
	}
}

/// <summary>
/// Sets the keybind with the given parameters
/// </summary>
/// <param name="Key">Primary keybind key</param>
/// <param name="InFunction">Function to execute</param>
/// <param name="ModifierKeys">Set of modifier keys which will be resolved to KeyCodes</param>
/// <param name="bRepeat">Whether or not to execute this function every tick</param>
void Keybinds::SetKeybind(const sdk::FKey Key, std::function<void()> InFunction, std::vector<sdk::FKey> ModifierKeys, bool bRepeat)
{
	const auto KeyCode = GetKeyCodeFromKey(Key);
	if (!!KeyCode)
	{
		std::unordered_set<int32_t> ModifierKeyCodes;
		for (auto&& InKey : ModifierKeys)
		{
			const auto ModifierKeyCode = GetKeyCodeFromKey(InKey);
			if (!!ModifierKeyCode)
			{
				ModifierKeyCodes.insert(ModifierKeyCode);
			}
		}
		Get().FunctionMap[KeyCode] = Function{ InFunction, ModifierKeyCodes, bRepeat };
	}
}

/// <summary>
/// Execute the function that is mapped to the KeyCode that is provided as long as all the modifier keys are also pressed (if any exist).
/// </summary>
/// <param name="KeyCode">The original KeyCode passed from OnKeyDown</param>
void Keybinds::Execute(const int32_t& KeyCode)
{
	auto&& ModifierKeys = Get().FunctionMap[KeyCode].ModifierKeys;
	for (auto&& Key : ModifierKeys)
	{
		if (!Get().PressedKeys.contains(Key))
			return;
	}
	Get().FunctionMap[KeyCode].Function();
}

/// <summary>
/// Process a single key press when when a key was pressed with IsRepeat == false.
/// </summary>
/// <param name="KeyCode"></param>
void Keybinds::Process(const int32_t KeyCode)
{
	if (Get().FunctionMap.contains(KeyCode))
	{
		Execute(KeyCode);
	}
}

/// <summary>
/// This should be called every tick. It checks the keys pressed (normally a very small container) to see if it contains any keys that are mapped to functions.
/// If a mapped key is found and flagged as repeating, it will call the Execute function for further validation and processing.
/// </summary>
void Keybinds::Process()
{
	auto Matches = Get().PressedKeys | std::views::filter([&](const int32_t& i) { return Get().FunctionMap.contains(i) && Get().FunctionMap[i].bRepeat; });
	std::ranges::for_each(Matches.begin(), Matches.end(), Execute);
}