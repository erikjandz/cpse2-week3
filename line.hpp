#ifndef LINE_HPP
#define LINE_HPP

#include "drawable.hpp"

class line : public drawable{};

class picture : public drawable {
public:
	picture(sf::Vector2f position, std::string filename):
		drawable{ position, sf::Color::Black },
		filename{filename}
	{
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(sf::Vector2f(0.2, 0.2));
	}

	void draw( sf::RenderWindow & window)const override {
		window.draw(sprite);
	}

	void jump(sf::Vector2f target) override{
		position = target;
		sprite.setPosition(position);
	}

	bool selected(sf::Vector2i mouseLocation)override { 
		sf::Rect<float> rect = sprite.getGlobalBounds();
		return (rect.left <= mouseLocation.x && mouseLocation.x <= (rect.left + rect.width)) && (rect.top <= mouseLocation.y  && mouseLocation.y <= (rect.top + rect.height));
	};

	void writeType(std::ostream& output) override{ output << "PICTURE "; }

	void writeObjectSpecificStuff(std::ostream& output) override{
		output << filename;
	}
private:
	std::string filename;
	sf::Texture texture;
	sf::Sprite sprite;
};
#endif
