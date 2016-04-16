#include "../Include/InputHandler.hpp"

#include <iostream>

Command* InputHandler::handleInput(const sf::Event& event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Down) {
			return new Command_Move(0.f, +150.f);
		} else if (event.key.code == sf::Keyboard::Up) {
			return new Command_Move(0.f, -150.f);
		} else if (event.key.code == sf::Keyboard::Left) {
			return new Command_Move(-150.f, 0.f);
		} else if (event.key.code == sf::Keyboard::Right) {
			return new Command_Move(+150.f, 0.f);
		}
	}
	return new Command_Empty();
}