#pragma once

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Waifu {
private:
	int nAffection;
	char sName[15];
	Sprite sImage;

	//Set to sprite when the user chooses to change outfit of Waifu
	Texture tDefault,
			tUnlock1,
			tUnlock2;

	Vector2f vPos;

public:
	Waifu(char Name[15], Vector2f Pos) {
		//If it hits 0, Waifu runs away
		//If it hits 100, Waifu is here to stay
		//Outfits are unlocked also based on Waifu Affection level
		nAffection = 20;

		strcpy(sName, Name);
		vPos = Pos;

		sImage.setTexture(tDefault);
	}

	~Waifu() {};

	//Getters
	Vector2f getPos() {
		return vPos;
	}

	String getName() {
		return sName;
	}

	//Setters
	void setOutfit(int OutfitNumber) {
		switch (OutfitNumber)
		{
		case 1:
			sImage.setTexture(tDefault);
			break;
		case 2:
			sImage.setTexture(tUnlock1);
			break;
		case 3:
			sImage.setTexture(tUnlock2);
			break;
		}
	}

	void setPos(Vector2f newPos) {
		vPos = newPos;
	}

	//General use functions
	void Speak() {

	}

	void doAction() {

	}
};