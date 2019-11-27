#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include <iostream>

circle::circle( sf::Vector2f position, float size ):
	drawable(position, sf::Color(0, 255, 0), 2 * size, 2 * size),
	size(size)
{}

void circle::draw( sf::RenderWindow & window ) const{
	sf::CircleShape circle2;
	circle2.setRadius(size);
	circle2.setPosition(position);
	circle2.setFillColor(color);
	window.draw(circle2);
}
