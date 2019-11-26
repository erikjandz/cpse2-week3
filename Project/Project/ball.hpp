#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable{
public:
	ball( sf::Vector2f position, float size = 30.0);

	void draw( sf::RenderWindow & window ) const override;

	void update_position();

	void interact(drawable * other)override;
private:
	float size;
	sf::Vector2f nextMove = sf::Vector2f{1, 1};
};

#endif
