#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class Button {
private:
	Vector2f vPos,
		     vTextPos;

	Sprite sBG;
	Texture tBG;

	Font textFont;
	Text tTitle;
public:
	Button(int xPos, int yPos, String sTitle) {
		vPos.x = xPos;
		vPos.y = yPos;

		vTextPos.x = xPos + 16;
		vTextPos.y = yPos;

		if (!tBG.loadFromFile("Assets\\Interface\\Selector.png")) {
			cout << "Basic button failed to load";
		}

		if (!textFont.loadFromFile("Assets\\Interface\\RainyHearts.ttf")) {
			cout << "Text font failed to load";
		}

		sBG.setTexture(tBG);
		sBG.setPosition(vPos);

		tTitle.setString(sTitle);
		tTitle.setPosition(vTextPos);
		tTitle.setFont(textFont);
	}

	~Button(){}

	//Getters
	Sprite getBG() {
		return sBG;
	}

	Text getTitle() {
		return tTitle;
	}

	//Setters
	void setScale(float ScaleX, float ScaleY) {
		sBG.setScale(ScaleX, ScaleY);
		tTitle.setScale(ScaleX, 1);
	}

	//General use functions
	bool vectorCheck(Vector2i click) {
		if (sBG.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Clicked";
			return true;
		}

		return false;
	}
};