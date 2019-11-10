#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "ButtonState.h"
#include "Waifu.h"

using namespace sf;
using namespace std;

class MakeWaifuButton {
private:
	int nImages = 2,
		nText = 0;

	Vector2f vInactivePos,
			 vActivePos;
	Sprite sImage;
	Vector2f vWaifuPos;
	Sprite sWaifu;
	ButtonState State;
	ButtonType Type;

	//Load textures here
	Texture tInactive,
			tActive,
			tClicked;

	//Load title sprites here
	Texture tNewSprite,
			tDogSprite,
			tNekoSprite,
			tShidenSprite,
			tYamaSprite;

	//F O N T
	Font textFont;

	//Text stuff for buttons that have waifu saves
	Text tName,
		 tAffection;
	Vector2f vNamePos,
			 vAffectPos;
public:
	MakeWaifuButton(int xPos, int yPos, ButtonType type, ButtonState state) {
		vInactivePos.x = xPos;
		vInactivePos.y = yPos;

		vActivePos.x = vInactivePos.x - 246;
		vActivePos.y = vInactivePos.y;
		vNamePos.x = vActivePos.x + 16;
		vNamePos.y = vActivePos.y - 32;
		vAffectPos.x = vActivePos.x + 16;
		vAffectPos.y = vActivePos.y - 16;

		vWaifuPos = vInactivePos;
		vWaifuPos.x += 180;

		State = state;
		Type = type;

		//Textures for different states
		if (!tInactive.loadFromFile("Assets\\Interface\\Titleselector_inactive.png")) {
			cout << "Failed to load inactive state of Button";
		}

		if (!tActive.loadFromFile("Assets\\Interface\\Titleselector_active.png")) {
			cout << "Failed to load active state of Button";
		}

		if (!tClicked.loadFromFile("Assets\\Interface\\Selector.png")) {
			cout << "Failed to load clicked state of Button";
		}

		//Textures for sprites
		if (!tNewSprite.loadFromFile("Assets\\Titlescreen sprites\\UnmadeSprite.png")) {
			cout << "Failed to load default sprite";
		}

		if (!tDogSprite.loadFromFile("Assets\\Titlescreen sprites\\KyoukoSprite.png")) {
			cout << "Failed to load dog button";
		}

		if (!tNekoSprite.loadFromFile("Assets\\Titlescreen sprites\\ChenSprite.png")) {
			cout << "Failed to load cat button";
		}

		if (!tYamaSprite.loadFromFile("Assets\\Titlescreen sprites\\EikiSprite.png")) {
			cout << "Failed to load orge button";
		}

		if (!tShidenSprite.loadFromFile("Assets\\Titlescreen sprites\\ReimuSprite.png")) {
			cout << "Failed to load Shrine maiden button";
		}

		//Load font and texts
		if (!textFont.loadFromFile("Assets\\Interface\\RainyHearts.ttf")) {
			cout << "Failed to load button font";
		}

		tName.setFont(textFont);
		tAffection.setFont(textFont);

		//Initial setup for button images
		sImage.setTexture(tInactive);
		sImage.setPosition(vInactivePos);
		sImage.setScale(2, 2);

		sWaifu.setTexture(tNewSprite);
		sWaifu.setPosition(vWaifuPos);
		sWaifu.setScale(2, 2);
	}

	~MakeWaifuButton(){}

	//Getters
	FloatRect getShape() {
		return sImage.getGlobalBounds();
	}

	Vector2f getPos() {
		return vInactivePos;
	}

	Sprite getImage(int nElement) {
		switch (nElement) {
		case 0:
			return sImage;
			break;
		case 1:
			return sWaifu;
			break;
		}
	}

	Text getText(int nElement) {
		switch (nElement) {
		case 0:
			return tName;
			break;
		case 1:
			return tAffection;
			break;
		}
	}

	ButtonType getType() {
		return Type;
	}

	int getImageCount() {
		return nImages;
	}

	int getTextCount() {
		return nText;
	}

	//Setters
	void setSprite(Texture newImage) {
		sImage.setTexture(newImage);
	}

	//Changes the type and data of the button depending on the waifu given
	void setType(Waifu waifu) {
		switch (waifu.getType()) {
		case WaifuType::Dog:
			sImage.setTexture(tActive);
			sImage.setPosition(vActivePos);

			tName.setString(waifu.getName());
			tName.setPosition(vNamePos);

			tAffection.setString("Affection: " + waifu.getAffection());
			tAffection.setPosition(vAffectPos);

			nText = 2;
			sWaifu.setTexture(tDogSprite);
			break;

		case WaifuType::Neko:
			sImage.setTexture(tActive);
			sImage.setPosition(vActivePos);

			tName.setString(waifu.getName());
			tName.setPosition(vNamePos);

			tAffection.setString("Affection: " + waifu.getAffection());
			tAffection.setPosition(vAffectPos);

			nText = 2;
			sWaifu.setTexture(tNekoSprite);
			break;

		case WaifuType::Yama:
			sImage.setTexture(tActive);
			sImage.setPosition(vActivePos);

			tName.setString(waifu.getName());
			tName.setPosition(vNamePos);

			tAffection.setString("Affection: " + waifu.getAffection());
			tAffection.setPosition(vAffectPos);

			nText = 2;
			sWaifu.setTexture(tYamaSprite);
			break;

		case WaifuType::ShrineMaiden:
			sImage.setTexture(tActive);
			sImage.setPosition(vActivePos);

			tName.setString(waifu.getName());
			tName.setPosition(vNamePos);

			tAffection.setString("Affection: " + waifu.getAffection());
			tAffection.setPosition(vAffectPos);

			nText = 2;
			sWaifu.setTexture(tShidenSprite);
			break;

		case WaifuType::New:
			sImage.setTexture(tInactive);
			sImage.setPosition(vInactivePos);

			nText = 0;

			sWaifu.setTexture(tNewSprite);
			sWaifu.setPosition(vWaifuPos);
			break;
		}
	}

	//General use functions
	//Checks if the vector was inside the button
	bool vectorCheck(Vector2i click) {
		if (sImage.getGlobalBounds().contains(Vector2f(click.x, click.y))){
			cout << "Clicked";
			return true;
		}

		return false;
	}

	//Changes the State of the button
	void changeState(ButtonState newState) {
		State = newState;
	}

	//Changes the Type of the button
	void changeType(ButtonType newType) {
		Type = newType;
	}
};