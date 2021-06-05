#include "MacroButton.h"

MacroButton::MacroButton(Keys key, std::vector<KeyModifiers> modifiers) : _key(key), _modifiers(modifiers)
{	
}

MacroButton::MacroButton(KeyMedia media)
{
	memcpy(this->_media, media, sizeof(KeyMedia));
}
