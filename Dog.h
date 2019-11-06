#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#pragma once

using namespace sf;
using namespace std;

class Dog {
private:
	Sprite sImage;

	//Set to sprite when the user chooses to change outfit of Waifu
	Texture tDefault;

	Vector2f vPos;

public:
	Dog(char Name[15], Vector2f Pos) {
		//If it hits 0, Waifu runs away
		//If it hits 100, Waifu is here to stay
		//Outfits are unlocked also based on Waifu Affection level
		vPos = Pos;

		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
			cout << "Failed to load image";
		}

		//Set sprite image to default
		sImage.setTexture(tDefault);
	}

	~Dog() {};

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

		default:
			cout << "Outfit missing";
			break;
		}
	}

	void setPos(Vector2f newPos) {
		vPos = newPos;
	}

	//General use functions
	void Speak() {

	}

	void Fetch() {

	}
};