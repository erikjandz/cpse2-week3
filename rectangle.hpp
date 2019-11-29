#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class rectangle : public drawable{
public:
	rectangle( sf::Vector2f position, sf::Vector2f size , sf::Color color );

	void draw( sf::RenderWindow & window ) const override;

	bool selected(sf::Vector2i mouseLocation)override{
		return (position.x <= mouseLocation.x && mouseLocation.x <= (position.x + size.x)) && (position.y <= mouseLocation.y && mouseLocation.y <= (position.y + size.y));
	}

	void writeType(std::ostream & output)override { output << "RECTANGLE "; };
	void writeObjectSpecificStuff(std::ostream & output)override{ 
		writeColor(output);
		output << "(" << size.x << "," << size.y << ") "; 
	};

private:
  sf::Vector2f size;
};

#endif
