#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "action.hpp"
#include <vector>
#include "fstream"
#include "string"

drawable * factory(std::ifstream & input){
	std::string
}

int main( int argc, char *argv[] ){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	std::vector<drawable *> drawables = {&wall1, &wall2, &wall3, &wall4, &block, &my_ball, &my_ball2};

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ block.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ block.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ block.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ block.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ block.jump( sf::Mouse::getPosition( window )); }),};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		for(auto object : drawables){
				object->draw(window);
		}
		window.display();

		sf::sleep( sf::milliseconds( 20 ));

    sf::Event event;
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
	}

	std::cout << "Terminating application\n";
	return 0;
}
