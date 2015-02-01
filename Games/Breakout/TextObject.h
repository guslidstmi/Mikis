#ifndef TEXTOBJECT_H_
#define TEXTOBJECT_H_
#pragma once

#include <SFML/Graphics.hpp>

class TextObject
{
	public:
		TextObject(sf::Font& font, int x = 0, int y = 0);
	
		sf::Text mText;

};

#endif // TEXTOBJECT_H_
