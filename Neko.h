#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Waifu.h"
#pragma once

using namespace sf;
using namespace std;

class Neko : public Waifu {
public:
	Neko(String Name, Vector2f Pos) : Waifu(Name, Pos){
		cout << "Neko Desu!!";
		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Chen_character\\Chen_1.png")) {
			cout << "Failed to load image";
		}

		if (!tUnlock1.loadFromFile("Assets\\Chen_character\\Chen_2.png")) {
			cout << "Failed to load image";
		}

		if (!tUnlock2.loadFromFile("Assets\\Chen_character\\Chen_4.png")) {
			cout << "Failed to load image";
		}

		//Set up dialogue
		MiscDialogue[0] = "*sniffing*";
		MiscDialogue[1] = "Konichiwassup~";
		MiscDialogue[2] = "Everything will be daijoubu";

		HappiDialogue[0] = "*happiness meow*";
		HappiDialogue[1] = "*rubs against you*";
		HappiDialogue[2] = "Arigathanks Gozaimasyou~";

		AngeryDialogue[0] = "*hissss*";
		AngeryDialogue[1] = "Master will get you for that!";
		AngeryDialogue[2] = "NOT DAIJOUBU!";

		//Set own type
		Type = WaifuType::Neko;
	}

	~Neko() {};

	//General use functions
	void Speak() {

	}

	void playYarn() {

	}

};