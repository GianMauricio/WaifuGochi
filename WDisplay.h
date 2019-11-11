#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Waifu.h"

using namespace sf;
using namespace std;

class WDisplay {
private:
	string WName;

	int WAffection;
	int WGender;

	Vector2f vPos;

	Sprite sImage;
	Texture tdisplayFrame;

	Text tName,
		 tAffection;

public:

	WDisplay(int xPos, int yPos, Waifu subject) {
		vPos.x = xPos;
		vPos.y = yPos;

		WName = subject.getName();
		WAffection = subject.getAffection();
		WGender = subject.getGender();

		if (!tdisplayFrame.loadFromFile("Assets\\Interface\\Stat_interface.png")) {
			cout << "Failed to load Stat display" << endl;
		}

		sImage.setTexture(tdisplayFrame);
		sImage.setPosition(vPos);
		sImage.setScale(2, 2);
	}

	~WDisplay() {
	}

	//Getters
	FloatRect getShape() {
		return sImage.getGlobalBounds();
	}

	Vector2f getPos() {
		return vPos;
	}

	Sprite getImageSprite() {
		sImage.setTexture(tdisplayFrame);
		return sImage;
	}

	//Setters
	void setPos(int xPos, int yPos) {
		vPos.x = xPos;
		vPos.y = yPos;

		sImage.setPosition(vPos);
	}
};
