#include <SFML/Graphics.hpp>
#include "rectangle.hpp"

rectangle::rectangle( sf::Vector2f position, sf::Vector2f size, sf::Color color):
	drawable(position, color),
	size(size)
{}

void rectangle::draw( sf::RenderWindow & window ) const{
	sf::RectangleShape rectangle2;
	rectangle2.setSize(size);
	rectangle2.setPosition(position);
	rectangle2.setFillColor(color);
	window.draw(rectangle2);
}
