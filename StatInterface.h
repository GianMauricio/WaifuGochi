#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "Waifu.h"

using namespace sf;
using namespace std;

class Stats {
private:
	int nImages = 2,
		nText = 2;

	Vector2f vBGPos,
			 vNamePos,
			 vGenderPos,
			 vAffectionPos;

	Texture tGender,
			tBG;

	Sprite sGender,/*Always female until later installments*/
		   sBG;

	Font textFont;

	Text tName,
		 tAffect;

public:
	Stats(int posX, int posY, Waifu subject) {
		//Set up all positions and offet elements within the interface
		vBGPos.x = posX;
		vBGPos.y = posY;

		vNamePos.x = vBGPos.x;
		vNamePos.y = vBGPos.y - 70;

		vGenderPos.x = vBGPos.x + 80;
		vGenderPos.y = vBGPos.y - 40;

		vAffectionPos.x = vNamePos.x + 20;
		vAffectionPos.y = vNamePos.y + 32;

		//Load assets
		if (!textFont.loadFromFile("Assets\\Interface\\RainyHearts.ttf")) {
			cout << "Failed to load stat interface font";
		}

		if (!tBG.loadFromFile("Assets\\Interface\\Stat_interface.png")) {
			cout << "Failed to load stat interface";
		}

		//Assign assets
		sBG.setPosition(vBGPos);
		sBG.setTexture(tBG);
		sBG.setScale(1.25, 1.25);

		tName.setString(subject.getName());
		tName.setPosition(vNamePos);
		tName.setScale(1.25, 1.25);
	}

};