#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.h"
#include "MakeWaifuButton.h"
#include "Waifu.h"
#include "WaifuSelector.h"

using namespace sf;
using namespace std;

int main()
{
	//Define base parameters
	int nWindowLength = 720,
		nWindowHeight = 800;
	RenderWindow window(VideoMode(nWindowLength, nWindowHeight), "WaifuGochi!");
	GameState State = GameState::Menu;

	//Backgrounds
	Sprite sBG;
	Sprite sFG;
	Texture BGMenu,
			BGGame,
			FGGame;
	sBG.setScale(Vector2f(2, 2));
	sFG.setScale(Vector2f(2, 2));

	//Additional 

	//Check system directory
	//system("dir");

	//Load stuff
	if (!BGGame.loadFromFile("Assets\\Screens\\Background_1.png"))
		cout << "LoadGame failed";
	if (!BGMenu.loadFromFile("Assets\\Interface\\Titlescreen.png"))
		cout << "LoadMenu failed";
	if (!FGGame.loadFromFile("Assets\\Interface\\Game_interface.png"))
		cout << "LoadInterface failed";

	//Make Buttons
	MakeWaifuButton Save1 = MakeWaifuButton(nWindowLength - 246, 700,
		ButtonType::New, ButtonState::Inactive);

	MakeWaifuButton Save2 = MakeWaifuButton(nWindowLength - 246, 580,
		ButtonType::New, ButtonState::Inactive);

	MakeWaifuButton Save3 = MakeWaifuButton(nWindowLength - 246, 460,
		ButtonType::New, ButtonState::Inactive);

	//Make selector
	WaifuPicker Selector = WaifuPicker(nWindowLength/7, nWindowHeight - (nWindowHeight * 3/4));

	//Ready Waifus for saving, not initialized
	Waifu *Waifu1 = nullptr,
		  *Waifu2 = nullptr,
		  *Waifu3 = nullptr;

	while (window.isOpen())
	{
		//Clear last window state
		window.clear();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				if (Save1.vectorCheck(Mouse::getPosition(window))) {
					//Set game mode to selection
					State = GameState::MakingWaifu1;
				}

				if (Save2.vectorCheck(Mouse::getPosition(window))) {
					//Set up button to resume waifu instead of creating a new one
					State = GameState::MakingWaifu2;
				}

				if (Save3.vectorCheck(Mouse::getPosition(window))) {
					//Set up button to resume waifu instead of creating a new one
					State = GameState::MakingWaifu3;
				}

				if (Selector.vectorCheck(Mouse::getPosition(window))) {
					cout << "Generating Waifu";

					switch (State) {
					case GameState::MakingWaifu1:
						Waifu1 = new Waifu(Selector.GenerateWaifu());
						State = GameState::Waifu1;
						break;

					case GameState::MakingWaifu2:
						Waifu2 = new Waifu(Selector.GenerateWaifu());
						State = GameState::Waifu2;
						break;

					case GameState::MakingWaifu3:
						Waifu3 = new Waifu(Selector.GenerateWaifu());
						State = GameState::Waifu3;
						break;
					}

				}
			}

			if (event.type == Event::TextEntered) {
				if (event.text.unicode == '\b') {
					Selector.deleteName();
				}

				else {
					Selector.setName(event.text.unicode);
				}
			}
		}

		//Display objects depending on what game state is curretnly active
		//Menu
		if (State == GameState::Menu) {
			//Draw menu background
			sBG.setTexture(BGMenu);
			window.draw(sBG);
			window.draw(Save1.getImageSprite());
			window.draw(Save1.getWaifuSprite());
			window.draw(Save2.getImageSprite());
			window.draw(Save2.getWaifuSprite());
			window.draw(Save3.getImageSprite());
			window.draw(Save3.getWaifuSprite());
		}

		//Making Waifu
		else if (State == GameState::MakingWaifu1) {
			sBG.setTexture(BGMenu);
			window.draw(sBG);

			//Draw images of the selector screen
			for (int i = 0; i < Selector.getImageCount(); i++) {
				window.draw(Selector.getSprite(i));
			}

			//Draw text of selector screen
			for (int i = 0; i < Selector.getTextCount(); i++) {
				window.draw(Selector.getText(i));
			}
		}

		else if (State == GameState::MakingWaifu2) {
			sBG.setTexture(BGMenu);
			window.draw(sBG);

			//Draw images of the selector screen
			for (int i = 0; i < Selector.getImageCount(); i++) {
				window.draw(Selector.getSprite(i));
			}

			//Draw text of selector screen
			for (int i = 0; i < Selector.getTextCount(); i++) {
				window.draw(Selector.getText(i));
			}
		}

		else if (State == GameState::MakingWaifu3) {
			sBG.setTexture(BGMenu);
			window.draw(sBG);

			//Draw images of the selector screen
			for (int i = 0; i < Selector.getImageCount(); i++) {
				window.draw(Selector.getSprite(i));
			}

			//Draw text of selector screen
			for (int i = 0; i < Selector.getTextCount(); i++) {
				window.draw(Selector.getText(i));
			}
		}

		else if (State == GameState::Waifu1) {
			//Draw game background
			sBG.setTexture(BGGame);
			sFG.setTexture(FGGame);
			window.draw(sBG);
			window.draw(sFG);

			//Draw Waifu
			window.draw(Waifu1->getWaifu());
		}

		else if (State == GameState::Waifu2) {
			//Draw game background
			sBG.setTexture(BGGame);
			sFG.setTexture(FGGame);
			window.draw(sBG);
			window.draw(sFG);

			//Draw Waifu
			window.draw(Waifu2->getWaifu());
		}

		else if (State == GameState::Waifu3) {
			//Draw game background
			sBG.setTexture(BGGame);
			sFG.setTexture(FGGame);
			window.draw(sBG);
			window.draw(sFG);

			//Draw Waifu
			window.draw(Waifu3->getWaifu());
		}

		//Display new window
		window.display();
	}

	return 0;
}