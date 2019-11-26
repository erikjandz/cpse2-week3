#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable{
public:
  drawable(	sf::Vector2f position, sf::Color color, float sizex, float sizey):
    position{ position },
    color{color}
    {
      hitbox = sf::Rect<float>{position, sf::Vector2f{sizex, sizey}};
    }
  virtual void draw( sf::RenderWindow & window ) const = 0;

  virtual void interact( drawable * other){}

  void move( sf::Vector2f delta ){
  	position += delta;
    hitbox.left += delta.x;
    hitbox.top += delta.y;
  }

  void jump( sf::Vector2f target ){
  	position = target;
    hitbox.left = target.x;
    hitbox.top = target.y;
  }

  void jump( sf::Vector2i target ){
  	jump( sf::Vector2f(
  		static_cast< float >( target.x ),
  		static_cast< float >( target.y )
  	));
  }

  virtual void update_position(){};

  virtual void interact(){};

  sf::Rect<float> hitbox;
protected:
	sf::Vector2f position;
  sf::Color color;
};
#endif
