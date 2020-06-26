#pragma once
#include <string>

class MinigameDescriptor
{
private:
	std::string name,
		description,
		smallSprite,
		largeSprite;

public:

	MinigameDescriptor(std::string n, std::string desc, std::string smallSpriteLocation, std::string largeSpriteLocation)
	{
		name = n;
		description = desc;
		smallSprite = smallSpriteLocation;
		largeSprite = largeSpriteLocation;
	}

	MinigameDescriptor() : MinigameDescriptor("NULL", "NULL", "NULL", "NULL") {}
};