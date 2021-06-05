#ifndef _MACROBUTTON_h
#define _MACROBUTTON_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <iostream>
#include <memory>

#include <BleKeyboard.h>

using namespace std;

using KeyModifiers = enum : byte
{
	LeftCtrl = 0x80,
	LeftShift = 0x81,
	LeftAlt = 0x82,
	LeftGui = 0x83,
	RighCtrl = 0x84,
	RightShift = 0x85,
	RightAlt = 0x86,
	RightGui = 0x87,
};

using Keys = enum : byte
{
	UpArrow = 0xda,
	DownArrow = 0xd9,
	LeftArrow = 0xd8,
	RightArrow = 0xd7,
	Backspace = 0xb2,
	Tab = 0xb3,
	Return = 0xb0,
	Esc = 0xb1,
	Insert = 0xd1,
	Delete = 0xd4,
	PageUp = 0xd3,
	PageDown = 0xd6,
	Home = 0xd2,
	End = 0xd5,
	CapsLock = 0xc1,
	F1 = 0xc2,
	F2 = 0xc3,
	F3 = 0xc4,
	F4 = 0xc5,
	F5 = 0xc6,
	F6 = 0xc7,
	F7 = 0xc8,
	F8 = 0xc9,
	F9 = 0xca,
	F10 = 0xcb,
	F11 = 0xcc,
	F12 = 0xcd,
	F13 = 0xf0,
	F14 = 0xf1,
	F15 = 0xf2,
	F16 = 0xf3,
	F17 = 0xf4,
	F18 = 0xf5,
	F19 = 0xf6,
	F20 = 0xf7,
	F21 = 0xf8,
	F22 = 0xf9,
	F23 = 0xfa,
	F24 = 0xfb,
};

using KeyMedia = MediaKeyReport;
static const KeyMedia NextTrack = { 1, 0 };
static const KeyMedia PreviousTrack = { 2, 0 };
static const KeyMedia Stop = { 4, 0 };
static const KeyMedia PlayPause = { 8, 0 };
static const KeyMedia Mute = { 16, 0 };
static const KeyMedia VolumeUp = { 32, 0 };
static const KeyMedia VolumeDown = { 64, 0 };
static const KeyMedia WwwHome = { 128, 0 };
static const KeyMedia LocalMachineBrowser = { 0, 1 }; // Opens "My Computer" On Windows
static const KeyMedia Calculator = { 0, 2 };
static const KeyMedia WwwBookmarks = { 0, 4 };
static const KeyMedia WwwSearch = { 0, 8 };
static const KeyMedia WwwStop = { 0, 16 };
static const KeyMedia WwwBack = { 0, 32 };
static const KeyMedia ConsumerControlConfiguration = { 0, 64 }; // Media Selection
static const KeyMedia EmailReader = { 0, 128 };


class MacroButton
{

public:
	MacroButton(Keys key, std::vector<KeyModifiers> modifiers);
	MacroButton(KeyMedia media);

private:
	Keys _key;
	MediaKeyReport _media;
	std::vector<KeyModifiers> _modifiers;
};

#endif