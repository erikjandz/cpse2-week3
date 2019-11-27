#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle : public drawable{
public:
	circle( sf::Vector2f position, float size = 30.0);

	void draw( sf::RenderWindow & window ) const override;

private:
	float size;
	sf::Vector2f nextMove = sf::Vector2f{1, 1};
};

#endif
