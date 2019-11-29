#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle : public drawable{
public:
	circle( sf::Vector2f position, float size, sf::Color color);

	void draw( sf::RenderWindow & window ) const override;

	bool selected(sf::Vector2i mouseLocation)override {
		return (mouseLocation.x - (position.x + size)) * (mouseLocation.x - (position.x + size)) + (mouseLocation.y - (position.y + size)) * (mouseLocation.y - (position.y + size)) <= size * size;
	}

	void writeType(std::ostream & output)override { output << "CIRCLE "; }
	void writeObjectSpecificStuff(std::ostream& output)override {
		writeColor(output);
		output << size; 
	};
private:
	float size;
	sf::Vector2f nextMove = sf::Vector2f{1, 1};
};

#endif
