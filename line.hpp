#ifndef LINE_HPP
#define LINE_HPP

#include "drawable.hpp"

class line : public drawable{
public:
	line(sf::Vector2f position, sf::Vector2f size, sf::Color color):
		drawable{position, color},
		size{size}
	{
		lines = sf::VertexArray(sf::LinesStrip, 2);
		lines[0].position = position;
		lines[1].position = position + size;
		lines[0].color = color;
		lines[1].color = color;
	}

	void jump(sf::Vector2f target) override {
		position = target;
		lines[0].position = position;
		lines[1].position = position + size;
	}

	void draw(sf::RenderWindow& window)const override {
		window.draw(lines);
	}

	bool selected(sf::Vector2i mouseLocation)override {
		return (lines[0].position.x <= mouseLocation.x && mouseLocation.x <= lines[1].position.x) && (lines[0].position.y <= mouseLocation.y && mouseLocation.y <= lines[1].position.y);
		//return lines[0].position == sf::Vector2f(mouseLocation) || lines[1].position == sf::Vector2f(mouseLocation);
	}

	void writeType(std::ostream& output) override { output << "LINE "; }

	void writeObjectSpecificStuff(std::ostream& output) override {
		writeColor(output);
		output << "(" << size.x << "," << size.y << ") ";
	}
private:
	sf::Vector2f size;
	sf::VertexArray lines;
};

class picture : public drawable {
public:
	picture(sf::Vector2f position, std::string filename):
		drawable{ position, sf::Color::Black },
		filename{filename}
	{
		texture.loadFromFile(filename);
		sprite.setTexture(texture);
		sprite.setPosition(position);
		sprite.setScale(sf::Vector2f(0.1, 0.1));
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

	void writeType(std::ostream & output) override{ output << "PICTURE "; }

	void writeObjectSpecificStuff(std::ostream& output) override{
		output << filename;
	}
private:
	std::string filename;
	sf::Texture texture;
	sf::Sprite sprite;
};
#endif
