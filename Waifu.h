#pragma once

#include <SFML/Graphics.hpp>
#include "WaifuType.h"
#include <string.h>
#include <iostream>

using namespace sf;
using namespace std;

class Waifu {
private:
	String sName;
	
	Vector2f vPos;
	int nAffection;

protected:
	//Filled by subclasses
	string MiscDialogue[3];
	string HappiDialogue[3];
	string AngeryDialogue[3];

	//Set to sprite when the user chooses to change outfit of Waifu
	Texture tDefault,
			tUnlock1,
			tUnlock2;
	Sprite sImage;

	WaifuType Type;
public:
	//Waifu Builder 1.0
	Waifu(String Name, Vector2f Pos) {
		cout << "Making Waifu";
		//If it hits 0, Waifu runs away
		//If it hits 100, Waifu is here to stay
		//Outfits are unlocked also based on Waifu Affection level
		nAffection = 20;

		sName = Name;
		vPos = Pos;

		sImage.setPosition(vPos);
		sImage.setScale(Vector2f(2, 2));
	}

	~Waifu() {};

	//Getters
	Vector2f getPos() {
		return vPos;
	}

	String getName() {
		return sName;
	}

	Sprite getWaifu() {	
		sImage.setTexture(tDefault);
		return sImage;
	}

	WaifuType getType() {
		return Type;
	}

	int getAffection() {
		return nAffection;
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
	void addAffection(int affect) {
		if (nAffection += affect < 101) {
			nAffection += affect;
		}
		
		else if(nAffection += affect > 100){
			nAffection = 100;
		}

		else if (nAffection -= affect > 0) {
			nAffection -= affect;
		}

		else if (nAffection -= affect < 0) {
			nAffection = 0;
		}

		else {
			cout << "What even is math anyways?";
		}
	}

	//Functions to be defined later
	virtual void Speak() {};

	virtual void doAction() {};
};