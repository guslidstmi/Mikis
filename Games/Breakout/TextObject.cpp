#include "TextObject.h"

TextObject::TextObject(sf::Font& font, int x, int y) :
mText{}
{
	mText.setFont(font);
	mText.setCharacterSize(20);
	mText.setStyle(sf::Text::Bold);
	mText.setColor(sf::Color::White);
	mText.setPosition(x, y);
}