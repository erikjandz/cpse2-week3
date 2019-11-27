#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include "rectangle.hpp"
#include "action.hpp"
#include <vector>
#include <fstream>
#include <string>
#include "exception.hpp"
#include "factory.hpp"

int main( int argc, char *argv[] ){
  std::vector<drawable * > drawables = {};

	std::ifstream input( "objects.txt" );
	try {
		for(;;){
			drawables.push_back( screen_object_read( input ));
		}
	} catch ( end_of_file ){
		// do nothing
	} catch ( std::exception & problem ){
		std::cout << problem.what();
	}

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	/*action actions[] = {
		action( sf::Keyboard::Left,  [&](){ block.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ block.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ block.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ block.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ block.jump( sf::Mouse::getPosition( window )); }),};
    */

	while (window.isOpen()) {
		/*for( auto & action : actions ){
			action();
		}

		window.clear();
		for(auto object : drawables){
				object->draw(window);
		}
		window.display();
    */
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
