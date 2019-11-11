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
	Sprite sImage;
	string MiscDialogue[3];
	string HappiDialogue[3];
	string AngeryDialogue[3];

	//Set to sprite when the user chooses to change outfit of Waifu
	Texture tDefault,
			tUnlock1,
			tUnlock2;

	Vector2f vPos;
	WaifuType Type;
	int nAffection,
		nGender;

public:
	//Waifu Builder 1.0
	Waifu(String Name, Vector2f Pos, WaifuType WType) {
		//If it hits 0, Waifu runs away
		//If it hits 100, Waifu is here to stay
		//Outfits are unlocked also based on Waifu Affection level
		nAffection = 20;

		Type = WType;

		sName = Name;
		vPos = Pos;

		//Sprite and dialogue loading depending on type of waifu chosen to be created
		if (WType == WaifuType::Neko) {

			//sprite loading
			if (!tDefault.loadFromFile("Assets\\Chen_character\\Chen_1.png")) {
				cout << "Failed to load Chen_1" << endl;
			}

			if (!tUnlock1.loadFromFile("Assets\\Chen_character\\Chen_3.png")) {
				cout << "Failed to load Chen_3" << endl;
			}

			if (!tUnlock2.loadFromFile("Assets\\Chen_character\\Chen_4.png")) {
				cout << "Failed to load Chen_4" << endl;
			}

			//dialogue loading
			MiscDialogue[0] = "*sniffing*";
			MiscDialogue[1] = "Konichiwassup~";
			MiscDialogue[2] = "Everything will be daijoubu";

			HappiDialogue[0] = "*happiness meow*";
			HappiDialogue[1] = "*rubs against you*";
			HappiDialogue[2] = "Arigathanks Gozaimasyou~";

			AngeryDialogue[0] = "*hissss*";
			AngeryDialogue[1] = "Master will get you for that!";
			AngeryDialogue[2] = "NOT DAIJOUBU!";
			
		}
		else if (WType == WaifuType::Dog) {
			if (!tDefault.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
				cout << "Failed to load doggo" << endl;
			}

			if (!tUnlock1.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
				cout << "Failed to load doggo" << endl;
			}

			if (!tUnlock2.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
				cout << "Failed to load doggo" << endl;
			}

			MiscDialogue[0] = "*sniffing*";
			MiscDialogue[1] = "*sweeping outside*";
			MiscDialogue[2] = "Master Byakuren would like this place";

			HappiDialogue[0] = "*licking you*";
			HappiDialogue[1] = "*happiness woof*";
			HappiDialogue[2] = "*happi smile*";

			AngeryDialogue[0] = "*growl*";
			AngeryDialogue[1] = "*lying down*";
			AngeryDialogue[2] = "*whimpering*";
		}
		else if (WType == WaifuType::ShrineMaiden) {
			if (!tDefault.loadFromFile("Assets\\Reimu_character\\Reimu_1.png")) {
				cout << "Failed to load Reimu_1" << endl;
			}

			if (!tUnlock1.loadFromFile("Assets\\Reimu_character\\Reimu_3.png")) {
				cout << "Failed to load Reimu_3" << endl;
			}

			if (!tUnlock2.loadFromFile("Assets\\Reimu_character\\Reimu_4.png")) {
				cout << "Failed to load Reimu_4" << endl;
			}

			MiscDialogue[0] = "*sipping tea*";
			MiscDialogue[1] = "*sleeping*";
			MiscDialogue[2] = "I wonder how Marisa's doing...";

			HappiDialogue[0] = "Thank you very much~";
			HappiDialogue[1] = "Maybe I won't need donations anymore~";
			HappiDialogue[2] = "*happiness chuckle*";
				
			AngeryDialogue[0] = "Seriously?";
			AngeryDialogue[1] = "Heh, fairies can hit harder";
			AngeryDialogue[2] = "If I hit back, You'd be on the other side of the world";
		}
		else if (WType == WaifuType::Yama) {
			if (!tDefault.loadFromFile("Assets\\Eiki_character\\Eiki_1.png")) {
				cout << "Failed to load Eiki_1" << endl;
			}

			if (!tUnlock1.loadFromFile("Assets\\Eiki_character\\Eiki_3.png")) {
				cout << "Failed to load Eiki_3" << endl;
			}

			if (!tUnlock2.loadFromFile("Assets\\Eiki_character\\Eiki_4.png")) {
				cout << "Failed to load Eiki_4" << endl;
			}

			MiscDialogue[0] = "*sitting silently*";
			MiscDialogue[1] = "Are you atoning for your sins?";
			MiscDialogue[2] = "*sips tea*";

			HappiDialogue[0] = "Th-this won't excempt you from judgement...";
			HappiDialogue[1] = "I may be the Yama, but...";
			HappiDialogue[2] = "I guess this is okay every once and a while...";

			AngeryDialogue[0] = "How dare you?!";
			AngeryDialogue[1] = "You sins continue to increase...";
			AngeryDialogue[2] = "Judgement will be swift for you...";
		}

		sImage.setTexture(tDefault);
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
		return sImage;
	}

	WaifuType getType() {
		return Type;
	}

	int getAffection() {
		return nAffection;
	}

	int getGender() {
		return nGender;
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
			cout << "What even is math anyways?" << endl;
		}
	}

	void Speak() {

	}

	void doAction() {

	}
};