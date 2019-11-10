#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Waifu.h"
#pragma once

using namespace sf;
using namespace std;

class Dog : public Waifu {
public:
	Dog(String Name, Vector2f Pos) : Waifu(Name, Pos){
		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
			cout << "Failed to load doggo";
		}

		if (!tUnlock1.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
			cout << "Failed to load doggo";
		}

		if (!tUnlock2.loadFromFile("Assets\\Kyouko_character\\Kyouko_1.png")) {
			cout << "Failed to load doggo";
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

		//Set own type
		Type = WaifuType::Dog;
	}

	~Dog() {};

	//General use functions
	void Speak() {

	}

	void Fetch() {

	}
};