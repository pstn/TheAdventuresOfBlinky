#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity: public sf::Drawable, public sf::Transformable {
public:
	virtual void update(sf::Time delta) = 0;
	
	// Yes, every entity can be moved in this world.
	virtual void setDirection(float vx, float vy) = 0;
	
protected:
	// helper function
	virtual void animate() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif