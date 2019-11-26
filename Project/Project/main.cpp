#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "action.hpp"
#include <vector>

int main( int argc, char *argv[] ){
	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
	ball my_ball{ sf::Vector2f{ 320.0, 240.0 } };
	wall wall1{ sf::Vector2f{ 0, 0 } , sf::Vector2f{ 30, 480 }};
	wall wall2{ sf::Vector2f{ 0, 0 } , sf::Vector2f{ 640, 30 }};
	wall wall3{ sf::Vector2f{ 610, 0 } , sf::Vector2f{ 30, 480 }};
	wall wall4{ sf::Vector2f{ 0, 450 } , sf::Vector2f{ 640, 30 }};
	wall block{ sf::Vector2f{ 320.0, 120.0 } , sf::Vector2f{100, 100.0 }, sf::Color(0, 0, 255)};

	std::vector<drawable *> drawables = {&wall1, &wall2, &wall3, &wall4, &block};

	action actions[] = {
		action( sf::Keyboard::Left,  [&](){ block.move( sf::Vector2f( -1.0,  0.0 )); }),
		action( sf::Keyboard::Right, [&](){ block.move( sf::Vector2f( +1.0,  0.0 )); }),
		action( sf::Keyboard::Up,    [&](){ block.move( sf::Vector2f(  0.0, -1.0 )); }),
		action( sf::Keyboard::Down,  [&](){ block.move( sf::Vector2f(  0.0, +1.0 )); }),
		action( sf::Mouse::Left,     [&](){ block.jump( sf::Mouse::getPosition( window )); }),
		action( [](){ return true;}, [&](){ for(auto & drawable : drawables){my_ball.interact(drawable);} }),
		action( [](){ return true;}, [&](){ my_ball.update_position(); })};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();
		for(auto object : drawables){
				object->draw(window);
		}
		my_ball.draw(window);
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
