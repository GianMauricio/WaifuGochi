#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "ButtonState.h"

using namespace sf;
using namespace std;

//Generalized button class... sorta

class InGameButton {
private:
	Vector2f vPos;
	Sprite sImage;
	ButtonState State;
	ButtonType Type;

	//Load textures here
	Texture tInactive,
			tActive,
			tClicked;

public:
	InGameButton(int xPos, int yPos, ButtonType BType, ButtonState BState) {
		vPos.x = xPos;
		vPos.y = yPos;

		State = BState;
		Type = BType;

		switch (Type) {
		case ButtonType::back:
			if (!tInactive.loadFromFile("Assets\\Interface\\backbutton.png")) {
				cout << "Failed to load inactive state of Button" << endl;
			}

			if (!tActive.loadFromFile("Assets\\Interface\\backbutton.png")) {
				cout << "Failed to load active state of Button" << endl;
			}

			if (!tClicked.loadFromFile("Assets\\Interface\\backbutton.png")) {
				cout << "Failed to load clicked state of Button" << endl;
			}

			sImage.setTexture(tInactive);
			sImage.setPosition(vPos);
			sImage.setScale(2, 2);
			break;

		case ButtonType::NoBulli:
			if (!tInactive.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load inactive state of Button" << endl;
			}

			if (!tActive.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load active state of Button" << endl;
			}

			if (!tClicked.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load clicked state of Button" << endl;
			}

			sImage.setTexture(tInactive);
			sImage.setPosition(vPos);
			sImage.setScale(2, 2);
			break;

		case ButtonType::Bulli:
			if (!tInactive.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load inactive state of Button" << endl;
			}

			if (!tActive.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load active state of Button" << endl;
			}

			if (!tClicked.loadFromFile("Assets\\Interface\\Selector.png")) {
				cout << "Failed to load clicked state of Button" << endl;
			}

			sImage.setTexture(tInactive);
			sImage.setPosition(vPos);
			sImage.setScale(2, 2);
			break;
		}
	}


	~InGameButton() {
	}

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

	//Setters
	void setSprite(Texture newImage) {
		sImage.setTexture(newImage);
	}

	void setPos(int xPos, int yPos) {
		vPos.x = xPos;
		vPos.y = yPos;

		sImage.setPosition(vPos);
	}

	bool vectorCheck(Vector2i click) {
		if (sImage.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Clicked" << endl;
			return true;
		}

		return false;
	}
};