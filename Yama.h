#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#pragma once

using namespace sf;
using namespace std;

class Yama {
private:
	Sprite sImage;

	//Set to sprite when the user chooses to change outfit of Waifu
	Texture tDefault,
		tUnlock1,
		tUnlock2,
		tUnlock3;

	Vector2f vPos;

public:
	Yama(char Name[15], Vector2f Pos) {
		//If it hits 0, Waifu runs away
		//If it hits 100, Waifu is here to stay
		//Outfits are unlocked also based on Waifu Affection level
		vPos = Pos;

		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Eiki_character\\Eiki_1.png")) {
			cout << "Failed to load image";
		}

		if (!tUnlock1.loadFromFile("Assets\\Eiki_character\\Eiki_2.png")) {
			cout << "Failed to load image";
		}

		if (!tUnlock2.loadFromFile("Assets\\Eiki_character\\Eiki_3.png")) {
			cout << "Failed to load image";
		}

		if (!tUnlock3.loadFromFile("Assets\\Eiki_character\\Eiki_4.png")) {
			cout << "Failed to load image";
		}

		//Set sprite image to default
		sImage.setTexture(tDefault);
	}

	~Yama() {};

	//Getters
	Vector2f getPos() {
		return vPos;
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
		case 4:
			sImage.setTexture(tUnlock3);
			break;
		}
	}

	void setPos(Vector2f newPos) {
		vPos = newPos;
	}

	//General use functions
	void Speak() {

	}

	void Growl() {

	}
};
