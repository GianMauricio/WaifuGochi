#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "WaifuType.h"

using namespace std;
using namespace sf;

class WaifuPicker {
private:
	Texture tBG,
			tDog,
			tNeko,
			tShrineMaiden,
			tYama;

	Vector2f vPos;
	Sprite sSelectorBox;

	Vector2f vDogPos;
	Sprite sDog;

	Vector2f vNekoPos;
	Sprite sNeko;

	Vector2f vShrineMaidenPos;
	Sprite sShrineMaiden;

	Vector2f vYamaPos;
	Sprite sYama;

public:
	WaifuPicker(int xPos, int yPos) {
		vPos.x = xPos;
		vPos.y = yPos;

		//Load waifus
		if (!tDog.loadFromFile("Assets\\Titlescreen sprites\\KyoukoSprite.png")) {
			cout << "Failed to load Menu Sprite: Dog";
		}

		if (!tNeko.loadFromFile("Assets\\Titlescreen sprites\\ChenSprite.png")) {
			cout << "Failed to load Menu Sprite: Neko";
		}

		if (!tShrineMaiden.loadFromFile("Assets\\Titlescreen sprites\\ReimuSprite.png")) {
			cout << "Failed to load Menu Sprite: ShrineMaiden";
		}

		if (!tYama.loadFromFile("Assets\\Titlescreen sprites\\EikiSprite.png")) {
			cout << "Failed to load Menu Sprite: Ogre";
		}

		//Load selector box
		if (!tBG.loadFromFile("Assets\\Interface\\Selector.png")) {
			cout << "Faled to load selector box BG";
		}

		//Set textures to sprites
		sDog.setTexture(tDog);
		sNeko.setTexture(tNeko);
		sShrineMaiden.setTexture(tShrineMaiden);
		sYama.setTexture(tYama);
		sSelectorBox.setTexture(tBG);

		//Set appropirate positions and scales
		sDog.setScale(2, 2);
		sDog.setPosition(vDogPos);

		sNeko.setScale(2, 2);
		sNeko.setPosition(vNekoPos);

		sShrineMaiden.setScale(2, 2);
		sShrineMaiden.setPosition(vShrineMaidenPos);

		sYama.setScale(2, 2);
		sYama.setPosition(vYamaPos);

		sSelectorBox.setScale(2, 2);
		sSelectorBox.setPosition(vPos);
	}

	~WaifuPicker(){}

	//Getters
	Vector2f getPos() {
		return vPos;
	}

};