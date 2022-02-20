#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <ranges>
#include "SDK.hpp"

class Keybinds
{
protected:
	Keybinds() {}

private:
	Keybinds(Keybinds const&) = delete;
	Keybinds(Keybinds&&) = delete;
	Keybinds& operator=(Keybinds const&) = delete;
	Keybinds& operator=(Keybinds&&) = delete;

	std::unordered_map<int32_t, sdk::FKey> KeyMap{
		{ VK_LBUTTON, sdk::FKey("LeftMouseButton") },
		{ VK_RBUTTON, sdk::FKey("RightMouseButton") },
		{ VK_MBUTTON, sdk::FKey("MiddleMouseButton") },
		{ VK_XBUTTON1, sdk::FKey("ThumbMouseButton") },
		{ VK_XBUTTON2, sdk::FKey("ThumbMouseButton2") },
		{ VK_BACK, sdk::FKey("BackSpace") },
		{ VK_TAB, sdk::FKey("Tab") },
		{ VK_RETURN, sdk::FKey("Enter") },
		{ VK_PAUSE, sdk::FKey("Pause") },
		{ VK_CAPITAL, sdk::FKey("CapsLock") },
		{ VK_ESCAPE, sdk::FKey("Escape") },
		{ VK_SPACE, sdk::FKey("SpaceBar") },
		{ VK_PRIOR, sdk::FKey("PageUp") },
		{ VK_NEXT, sdk::FKey("PageDown") },
		{ VK_END, sdk::FKey("End") },
		{ VK_HOME, sdk::FKey("Home") },
		{ VK_LEFT, sdk::FKey("Left") },
		{ VK_UP, sdk::FKey("Up") },
		{ VK_RIGHT, sdk::FKey("Right") },
		{ VK_DOWN, sdk::FKey("Down") },
		{ VK_INSERT, sdk::FKey("Insert") },
		{ VK_DELETE, sdk::FKey("Delete") },
		{ VK_NUMPAD0, sdk::FKey("NumPadZero") },
		{ VK_NUMPAD1, sdk::FKey("NumPadOne") },
		{ VK_NUMPAD2, sdk::FKey("NumPadTwo") },
		{ VK_NUMPAD3, sdk::FKey("NumPadThree") },
		{ VK_NUMPAD4, sdk::FKey("NumPadFour") },
		{ VK_NUMPAD5, sdk::FKey("NumPadFive") },
		{ VK_NUMPAD6, sdk::FKey("NumPadSix") },
		{ VK_NUMPAD7, sdk::FKey("NumPadSeven") },
		{ VK_NUMPAD8, sdk::FKey("NumPadEight") },
		{ VK_NUMPAD9, sdk::FKey("NumPadNine") },
		{ VK_MULTIPLY, sdk::FKey("Multiply") },
		{ VK_ADD, sdk::FKey("Add") },
		{ VK_SUBTRACT, sdk::FKey("Subtract") },
		{ VK_DECIMAL, sdk::FKey("Decimal") },
		{ VK_DIVIDE, sdk::FKey("Divide") },
		{ VK_F1, sdk::FKey("F1") },
		{ VK_F2, sdk::FKey("F2") },
		{ VK_F3, sdk::FKey("F3") },
		{ VK_F4, sdk::FKey("F4") },
		{ VK_F5, sdk::FKey("F5") },
		{ VK_F6, sdk::FKey("F6") },
		{ VK_F7, sdk::FKey("F7") },
		{ VK_F8, sdk::FKey("F8") },
		{ VK_F9, sdk::FKey("F9") },
		{ VK_F10, sdk::FKey("F10") },
		{ VK_F11, sdk::FKey("F11") },
		{ VK_F12, sdk::FKey("F12") },
		{ VK_NUMLOCK, sdk::FKey("NumLock") },
		{ VK_SCROLL, sdk::FKey("ScrollLock") },
		{ VK_LSHIFT, sdk::FKey("LeftShift") },
		{ VK_RSHIFT, sdk::FKey("RightShift") },
		{ VK_LCONTROL, sdk::FKey("LeftControl") },
		{ VK_RCONTROL, sdk::FKey("RightControl") },
		{ VK_LMENU, sdk::FKey("LeftAlt") },
		{ VK_RMENU, sdk::FKey("RightAlt") },
		{ VK_LWIN, sdk::FKey("LeftCommand") },
		{ VK_RWIN, sdk::FKey("RightCommand") },
		{ '0', sdk::FKey("Zero") },
		{ '1', sdk::FKey("One") },
		{ '2', sdk::FKey("Two") },
		{ '3', sdk::FKey("Three") },
		{ '4', sdk::FKey("Four") },
		{ '5', sdk::FKey("Five") },
		{ '6', sdk::FKey("Six") },
		{ '7', sdk::FKey("Seven") },
		{ '8', sdk::FKey("Eight") },
		{ '9', sdk::FKey("Nine") },
		{ 'A', sdk::FKey("A") },
		{ 'B', sdk::FKey("B") },
		{ 'C', sdk::FKey("C") },
		{ 'D', sdk::FKey("D") },
		{ 'E', sdk::FKey("E") },
		{ 'F', sdk::FKey("F") },
		{ 'G', sdk::FKey("G") },
		{ 'H', sdk::FKey("H") },
		{ 'I', sdk::FKey("I") },
		{ 'J', sdk::FKey("J") },
		{ 'K', sdk::FKey("K") },
		{ 'L', sdk::FKey("L") },
		{ 'M', sdk::FKey("M") },
		{ 'N', sdk::FKey("N") },
		{ 'O', sdk::FKey("O") },
		{ 'P', sdk::FKey("P") },
		{ 'Q', sdk::FKey("Q") },
		{ 'R', sdk::FKey("R") },
		{ 'S', sdk::FKey("S") },
		{ 'T', sdk::FKey("T") },
		{ 'U', sdk::FKey("U") },
		{ 'V', sdk::FKey("V") },
		{ 'W', sdk::FKey("W") },
		{ 'X', sdk::FKey("X") },
		{ 'Y', sdk::FKey("Y") },
		{ 'Z', sdk::FKey("Z") },
		{ ';', sdk::FKey("Semicolon") },
		{ '=', sdk::FKey("Equals") },
		{ ',', sdk::FKey("Comma") },
		{ '-', sdk::FKey("Hyphen") },
		{ '.', sdk::FKey("Period") },
		{ '/', sdk::FKey("Slash") },
		{ '`', sdk::FKey("Tilde") },
		{ '[', sdk::FKey("LeftBracket") },
		{ '\\', sdk::FKey("Backslash") },
		{ ']', sdk::FKey("RightBracket") },
		{ '\'', sdk::FKey("Apostrophe") },
		{ ' ', sdk::FKey("SpaceBar") },
		{ '&', sdk::FKey("Ampersand") },
		{ '*', sdk::FKey("Asterix") },
		{ '^', sdk::FKey("Caret") },
		{ ':', sdk::FKey("Colon") },
		{ '$', sdk::FKey("Dollar") },
		{ '!', sdk::FKey("Exclamation") },
		{ '(', sdk::FKey("LeftParantheses") },
		{ ')', sdk::FKey("RightParantheses") },
		{ '"', sdk::FKey("Quote") },
		{ '_', sdk::FKey("Underscore") },
		{ 224, sdk::FKey("A_AccentGrave") },
		{ 231, sdk::FKey("C_Cedille") },
		{ 233, sdk::FKey("E_AccentAigu") },
		{ 232, sdk::FKey("E_AccentGrave") },
		{ 167, sdk::FKey("Section") }
	};

	enum class MouseButton : int32_t
	{
		Left = 0,
		Middle,
		Right,
		Thumb01,
		Thumb02,
		Invalid,
	};

	static void Execute(const int32_t& KeyCode);
	static void ExecuteKeyUp(const int32_t& KeyCode);

public:
	struct Function
	{
		std::function<void()> Function;
		std::unordered_set<int32_t> ModifierKeys;
		bool bRepeat = false;
		std::function<void()> KeyUpFunction;
	};

	std::unordered_set<int32_t> PressedKeys{};
	std::unordered_map<int32_t, Function> FunctionMap{};

	static int32_t GetKeyCodeFromKey(const sdk::FKey Key);
	static int32_t GetKeyCodeFromMouseButton(const MouseButton Button);
	static bool OnKeyDown(const int32_t KeyCode, const uint32_t CharacterCode, const bool IsRepeat);
	static bool OnKeyUp(const int32_t KeyCode, const uint32_t CharacterCode, const bool IsRepeat);
	static bool OnMouseDown(const int32_t Button);
	static bool OnMouseUp(const int32_t Button);
	static void ClearKeybind(const sdk::FKey Key);
	static void SetKeybind(const sdk::FKey Key, std::function<void()> InFunction, std::vector<sdk::FKey> ModifierKeys, bool bRepeat, std::function<void()> InKeyUpFunction = nullptr);
	static void Process(const int32_t KeyCode, bool bOnKeyUp = false);
	static void Process();

	static __forceinline Keybinds& Get()
	{
		static Keybinds Instance;
		return Instance;
	}
};
