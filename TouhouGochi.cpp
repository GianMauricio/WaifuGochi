#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameState.h"
#include "MakeWaifuButton.h"
#include "WaifuData.h"
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
	Texture BGMenu,
			BGGame;
	sBG.setScale(Vector2f(2, 2));

	//Check system directory
	//system("dir");

	//Load stuff
	if (!BGGame.loadFromFile("Assets\\Screens\\Background_1.png"))
		cout << "LoadGame failed";
	if (!BGMenu.loadFromFile("Assets\\Interface\\Titlescreen.png"))
		cout << "LoadMenu failed";

	//Make Buttons
	MakeWaifuButton Save1 = MakeWaifuButton(nWindowLength - 246, 700,
		ButtonType::New, ButtonState::Inactive);

	MakeWaifuButton Save2 = MakeWaifuButton(nWindowLength - 246, 580,
		ButtonType::New, ButtonState::Inactive);

	MakeWaifuButton Save3 = MakeWaifuButton(nWindowLength - 246, 460,
		ButtonType::New, ButtonState::Inactive);

	//Ready Waifus for saving, not initialized
	WaifuData *Waifu1,
			  *Waifu2,
		 	  *Waifu3;

	while (window.isOpen())
	{
		//Clear last window state
		window.clear();

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

		else if (State == GameState::Waifu1){
			//Draw game background
			sBG.setTexture(BGGame);
			window.draw(sBG);

			//Draw Waifu
		}

		else if (State == GameState::Waifu2) {
			//Draw game background
			sBG.setTexture(BGGame);
			window.draw(sBG);

			//Draw Waifu
		}

		else if (State == GameState::Waifu3) {
			//Draw game background
			sBG.setTexture(BGGame);
			window.draw(sBG);

			//Draw Waifu
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				if (Save1.vectorCheck(Mouse::getPosition(window))) {
					
				}

				if (Save2.vectorCheck(Mouse::getPosition(window))) {

				}

				if (Save3.vectorCheck(Mouse::getPosition(window))) {

				}

			}
		}
		//Display new window
		window.display();
	}

	return 0;
}