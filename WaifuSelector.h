#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include "WaifuType.h"
#include "Neko.h"
#include "Dog.h"
#include "ShrineMaiden.h"
#include "Yama.h"

using namespace std;
using namespace sf;

class WaifuPicker {
private:
	int nImages = 7,
		nText = 4;

	Texture tBG,
			tDog,
			tNeko,
			tShrineMaiden,
			tYama;
		
	Vector2f vPos;
	Sprite sSelectorBox;

	Vector2f vNamePos;
	Sprite sNameBox;

	Vector2f vConfirm;
	Vector2f vConfirmText;
	Sprite sConfirm;
	Text tConfirm;

	Vector2f vDogPos;
	Sprite sDog;

	Vector2f vNekoPos;
	Sprite sNeko;

	Vector2f vShrineMaidenPos;
	Sprite sShrineMaiden;

	Vector2f vYamaPos;
	Sprite sYama;

	//F O N T 
	Font dFont;

	//Holds screen prompts
	Text tPrompt1;
	Vector2f vPrompt1;
	Vector2f vPromptDog;
	Vector2f vPromptNeko;
	Vector2f vPromptShrineMaiden;
	Vector2f vPromptYama;

	Text tPrompt2;
	Vector2f vPrompt2;

	//Will hold name of the new Waifu
	String sName;
	Text tName;
	Vector2f vName;

	//Will hold the data of the new Waifu for use in building her
	string Name;
	WaifuType Type;

public:
	WaifuPicker(int xPos, int yPos) {
		vPos.x = xPos;
		vPos.y = yPos;
		Name = " ";
		Type = WaifuType::New;

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

		//Load selector boxes
		if (!tBG.loadFromFile("Assets\\Interface\\Selector.png")) {
			cout << "Faled to load selector box BG";
		}

		//Load font
		if (!dFont.loadFromFile("Assets\\Interface\\Minecraft.ttf")) {
			cout << "Failed to load font";
		}

		//Set textures to sprites
		sDog.setTexture(tDog);
		sNeko.setTexture(tNeko);
		sShrineMaiden.setTexture(tShrineMaiden);
		sYama.setTexture(tYama);
		sSelectorBox.setTexture(tBG);
		sNameBox.setTexture(tBG);
		sConfirm.setTexture(tBG);

		//Load first prompt
		tPrompt1.setString("Pick your Waifu!");
		tPrompt1.setFillColor(Color::Black);
		tPrompt1.setFont(dFont);

		//Load second prompt
		tPrompt2.setString("Name your Waifu!");
		tPrompt2.setFillColor(Color::White);
		tPrompt2.setFont(dFont);

		//Ready the name prompt
		tName.setFont(dFont);
		tPrompt1.setFillColor(Color::White);

		//Load confirm prompt;
		tConfirm.setString("Confirm");
		tConfirm.setFillColor(Color::White);
		tConfirm.setFont(dFont);

		//Set positions
		vDogPos = vPos;
		vNekoPos = vPos;
		vShrineMaidenPos = vPos;
		vYamaPos = vPos;
		vPrompt1 = vPos;
		vPrompt2 = vPos;
		vNamePos = vPos;
		vConfirm = vPos;
		vConfirmText = vPos;
		vPromptDog = vPos;
		vPromptNeko = vPos;
		vPromptShrineMaiden = vPos;
		vPromptYama = vPos;

		//Offset positions of the waifu sprites
		vDogPos.x += 10;
		vNekoPos.x += 90;
		vShrineMaidenPos.x += 170;
		vYamaPos.x += 250;

		//Offsets
		vPrompt1.y -= 50;
		vPrompt1.x += 50;

		vPromptDog = vPrompt1;
		vPromptNeko = vPrompt1;
		vPromptShrineMaiden = vPrompt1;
		vPromptYama = vPrompt1;

		vPromptDog.x -= 40;
		vPromptNeko.x -= 40;
		vPromptShrineMaiden.x -= 80;
		vPromptYama.x -= 30;
		vPrompt2.y += 150;
		vPrompt2.x += 50;
		vNamePos.y += 200;
		vConfirm.y += 300;
		vConfirm.x += 80;
		vConfirmText.y += 300;
		vConfirmText.x += 100;

		//Set appropirate positions and scales
		sDog.setScale(2, 2);
		sDog.setPosition(vDogPos);

		sNeko.setScale(2, 2);
		sNeko.setPosition(vNekoPos);

		sShrineMaiden.setScale(2, 2);
		sShrineMaiden.setPosition(vShrineMaidenPos);

		sYama.setScale(2, 2);
		sYama.setPosition(vYamaPos);

		tPrompt1.setScale(1, 1);
		tPrompt1.setPosition(vPrompt1);

		tPrompt2.setScale(1, 1);
		tPrompt2.setPosition(vPrompt2);

		sSelectorBox.setScale(2, 2);
		sSelectorBox.setPosition(vPos);

		sNameBox.setScale(2, 2);
		sNameBox.setPosition(vNamePos);

		tName.setScale(1, 1);
		tName.setPosition(vNamePos);

		tConfirm.setScale(1, 1);
		tConfirm.setPosition(vConfirmText);

		sConfirm.setScale(1, 1);
		sConfirm.setPosition(vConfirm);
	}

	~WaifuPicker(){}

	//Getters
	Vector2f getPos() {
		return vPos;
	}

	//Returns sprite based on requested element
	Sprite getSprite(int nElement) {
		switch (nElement) {
		case 0:
			return sSelectorBox;
			break;

		case 1:
			return sDog;
			break;

		case 2:
			return sNeko;
			break;

		case 3:
			return sShrineMaiden;
			break;

		case 4:
			return sYama;
			break;

		case 5:
			return sNameBox;

		case 6:
			return sConfirm;
			break;

		default:
			cout << "Element does not exist";
			break;
		}
	}

	//Returns text based on requested element
	Text getText(int nElement) {
		switch (nElement) {
		case 0:
			return tPrompt1;
			break;

		case 1:
			return tPrompt2;
			break;

		case 2:
			return tName;
			break;

		case 3:
			return tConfirm;
			break;

		default:
			cout << "Element does not exist";
			break;
		}
	}

	int getImageCount() {
		return nImages;
	}

	int getTextCount() {
		return nText;
	}

	//Setters
	//Adds a letter to the name based on entry
	void setName(char letter) {
		if (Name.size() < 15) {
			Name += static_cast<char>(letter);
			tName.setString(Name);
		}
	}

	//Deletes last letter added
	void deleteName() {
		if (!Name.empty()) {
			Name.erase(Name.size() - 1, 1);
			tName.setString(Name);
		}
	}

	void setType(WaifuType newType) {
		Type = newType;
	}

	//General use functions
	bool vectorCheck(Vector2i click) {
		if (sDog.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Dog";
			Type = WaifuType::Dog;
			tPrompt1.setString("You picked a Dog Girl!");
			tPrompt1.setPosition(vPromptDog);
		}

		else if (sNeko.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Neko";
			Type = WaifuType::Neko;
			tPrompt1.setString("You picked a Cat Girl!");
			tPrompt1.setPosition(vPromptNeko);
		}

		else if (sShrineMaiden.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "ShrineMaiden";
			Type = WaifuType::ShrineMaiden;
			tPrompt1.setString("You picked a Shrine Maiden!");
			tPrompt1.setPosition(vPromptShrineMaiden);
		}

		else if (sYama.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Yama";
			Type = WaifuType::Yama;
			tPrompt1.setString("You picked an Orge!");
			tPrompt1.setPosition(vPromptYama);
		}

		if (sConfirm.getGlobalBounds().contains(Vector2f(click.x, click.y))) {
			cout << "Waifu is done";
			return true;
		}

		return false;
	}

	void Reset() {
		//Delete last name input
		Name.erase(0, Name.size() - 1);

		//Reset type, waifu selector is now ready to give a new waifu
		Type = WaifuType::New;
	}

	//Creates the waifu depending on the current data 
	Waifu GenerateWaifu() {
		if (Type != WaifuType::New){
			cout << "Waifu ready";
			Vector2f WaifuPos;

			if (Type == WaifuType::Neko) {
				WaifuPos = Vector2f(300, 80);
				return Neko(sName, WaifuPos);
			}
				
			else if (Type == WaifuType::Dog) {
				WaifuPos = Vector2f(300, 80);
				return Dog(sName, WaifuPos);
			}
				
			else if (Type == WaifuType::ShrineMaiden) {
				WaifuPos = Vector2f(350, 80);
				return ShrineMaiden(sName, WaifuPos);
			}
				
			else if (Type == WaifuType::Yama) {
				WaifuPos = Vector2f(350, 80);
				return Yama(sName, WaifuPos);
			}
				
		}
	}
};