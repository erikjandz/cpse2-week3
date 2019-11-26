#ifndef WALL_HPP
#define WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall : public drawable{
public:
	wall( sf::Vector2f position, sf::Vector2f size = sf::Vector2f(30.0, 30.0), sf::Color color = sf::Color(255, 0, 0));

	void draw( sf::RenderWindow & window ) const override;
private:
  sf::Vector2f size;
};

#endif
