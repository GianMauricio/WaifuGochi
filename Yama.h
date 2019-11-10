#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Waifu.h"
#pragma once

using namespace sf;
using namespace std;

class Yama : public Waifu{
public:
	Yama(String Name, Vector2f Pos) : Waifu(Name, Pos){
		//Set up assets lists
		if (!tDefault.loadFromFile("Assets\\Eiki_character\\Eiki_1.png")) {
			cout << "Failed to load Eiki_1";
		}

		if (!tUnlock1.loadFromFile("Assets\\Eiki_character\\Eiki_3.png")) {
			cout << "Failed to load Eiki_3";
		}

		if (!tUnlock2.loadFromFile("Assets\\Eiki_character\\Eiki_4.png")) {
			cout << "Failed to load Eiki_4";
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

		//Set own type
		Type = WaifuType::Yama;
	}

	~Yama() {};

	//General use functions
	void Speak() {

	}

	void Growl() {

	}
};
