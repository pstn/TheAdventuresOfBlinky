#ifndef WORLD_HPP
#define WORLD_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Commands/Command_Types.hpp"
#include "Entities/Entity_Types.hpp"
#include "Maze.hpp"

class World : public sf::NonCopyable {
public:
	explicit World(sf::RenderWindow& window);
	
	void update(sf::Time delta);
	void draw();
	
	void input(Command* command);
private:
	void initMaze(unsigned int index);
	void initTrees();
	void initMonsters();
	void resetMonster(Entity_Character& monster);
	void banMonsters();
	void moveButton();
	void checkCollision();

private:
	sf::RenderWindow& window;
	
	std::vector<Entity_Background*> backgrounds;
	std::vector<Entity*> entities;
	std::vector<Entity_Character*> monsters;
	std::vector<Entity*> mazeAndWalls;
	
	sf::Music theme;
	
	Maze currentMaze;
	Entity_Character* playerChar;
	Entity_Character* bossMonster;
	
	Entity_Titlescreen *titleScreen;
	Entity_EndGame *endGame;
	
	Entity_Object* fireButton;
	Entity_Object* swapButton;

	float timer;
	
	int swapCounter;
};

#endif