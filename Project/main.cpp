#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "wall.hpp"
#include "action.hpp"
#include <vector>
#include "fstream"
#include "string"


class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
   const char * what() const override {
      return s.c_str();
   }
private:
   std::string s;
};


std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
   std::string s;
   input >> s;
   const struct { const char * name; sf::Color color; } colors[]{
       { "yellow", sf::Color::Yellow },
       { "red",    sf::Color::Red },
       . . . 
   };
   for( auto const & color : colors ){
       if( color.name == s ){ 
          rhs = color.color;
          return input;
       }
   }
   if( s == "" ){
      throw end_of_file();
   }
   throw unknown_color( s );
}


std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs ){
   char c;
   if( ! ( input >> c )){ throw end_of_file(); }
   if( c != '(' ){ throw invalid_position( c ); }

   if( ! ( input >> rhs.x )){ . . . }

   if( ! ( input >> c )){ . . . }
   . . . 
   if( ! ( input >> rhs.y )){ . . . }

   if( ! ( input >> c )){ . . . }
   if( c != ')' ){ throw invalid_position( c ); }

   return input;
}



screen_object * screen_object_read( std::ifstream & input ){
   sf::Vector2f position;
   std::string name;
   input >> position >> name;

   if( name == "CIRCLE" ){
      . . .
      return new circle( . . . );

   } else if( name == "RECTANGLE" ){
      . . .
      return new rectangle( . . . );

   } else if( name == "PICTURE" ){
      . . .
      return new picture( . . . );

   } else if( name == "" ){
      throw end_of_file();
   }

   throw unknown_shape( name );
}


drawable * factory(std::ifstream & input){
	std::string
}

int main( int argc, char *argv[] ){
	
	std::ifstream input( "objects.txt" );
	try {
		for(;;){
			screen_objects.add( screen_object_read( input ));
		}
	} catch ( end_of_file ){
		// do nothing
	} catch ( std::exception & problem ){
		std::cout << problem.what();
	}

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
