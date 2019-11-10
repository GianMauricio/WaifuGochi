#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Waifu.h"
#pragma once

using namespace sf;
using namespace std;

class ShrineMaiden : public Waifu{
public:
	ShrineMaiden(String Name, Vector2f Pos) : Waifu(Name, Pos){
		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Reimu_character\\Reimu_1.png")) {
			cout << "Failed to load Reimu_1";
		}

		if (!tUnlock1.loadFromFile("Assets\\Reimu_character\\Reimu_3.png")) {
			cout << "Failed to load Reimu_3";
		}

		if (!tUnlock2.loadFromFile("Assets\\Reimu_character\\Reimu_4.png")) {
			cout << "Failed to load Reimu_4";
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

		//Set own type
		Type = WaifuType::ShrineMaiden;
	}

	~ShrineMaiden() {};

	//General use functions
	void Speak() {

	}

	void Bow() {

	}
};