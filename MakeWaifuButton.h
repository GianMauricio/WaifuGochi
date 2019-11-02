#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "ButtonState.h"

using namespace sf;
using namespace std;

class MakeWaifuButton {
private:
	Vector2f vPos;
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
	Texture tSprite;

public:
	MakeWaifuButton(int xPos, int yPos, ButtonType type, ButtonState state) {
		vPos.x = xPos;
		vPos.y = yPos;

		vWaifuPos = vPos;
		vWaifuPos.x += 180;

		State = state;
		Type = type;

		//Load all required textures depending on button type
		switch (Type) {
		case ButtonType::New:
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

			//Textures for sprite
			if (!tSprite.loadFromFile("Assets\\Titlescreen sprites\\UnmadeSprite.png")) {
				cout << "Failed to load titlescreen sprite of Button";
			}

			//Place stuff inside the button
			sImage.setTexture(tInactive);
			sImage.setPosition(vPos);
			sImage.setScale(2, 2);

			sWaifu.setTexture(tSprite);
			sWaifu.setPosition(vWaifuPos);
			sWaifu.setScale(2, 2);
			break;
		case ButtonType::Dog:
			break;
		case ButtonType::Neko:
			break;
		case ButtonType::Yama:
			break;
		case ButtonType::ShrineMaiden:
			break;
		}
	}

	~MakeWaifuButton(){}

	//Getters
	FloatRect getShape() {
		return sImage.getGlobalBounds();
	}

	Vector2f getPos() {
		return vPos;
	}

	Sprite getImageSprite() {
		return sImage;
	}

	Sprite getWaifuSprite() {
		return sWaifu;
	}

	//Setters
	void setSprite(Texture newImage) {
		sImage.setTexture(newImage);
	}

	void setPos(int xPos, int yPos) {
		vPos.x = xPos;
		vPos.y = yPos;

		sImage.setPosition(vPos);
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