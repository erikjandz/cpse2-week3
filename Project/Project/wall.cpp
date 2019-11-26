#include <SFML/Graphics.hpp>
#include "wall.hpp"

wall::wall( sf::Vector2f position, sf::Vector2f size, sf::Color color):
	drawable(position, color, size.x, size.y),
  size(size)
{}

void wall::draw( sf::RenderWindow & window ) const{
	sf::RectangleShape rectangle;
	rectangle.setSize(size);
  rectangle.setPosition(position);
  rectangle.setFillColor(color);
	window.draw(rectangle);
}
