#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include <iostream>

ball::ball( sf::Vector2f position, float size ):
	drawable(position, sf::Color(0, 255, 0), 2 * size, 2 * size),
	size(size)
{}

void ball::draw( sf::RenderWindow & window ) const{
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::update_position(){
	move(nextMove);
}

void ball::interact(drawable * other){
	if(hitbox.intersects(other->hitbox)){
		if(other->hitbox.left > hitbox.left + hitbox.width - 2){
			nextMove.x *= -1;
		}else if(other->hitbox.top > hitbox.top + hitbox.height - 2){
			nextMove.y *= -1;
		}else if(other->hitbox.left + other->hitbox.width < hitbox.left + 2){
			nextMove.x *= -1;
		}else if(other->hitbox.top + other->hitbox.height < hitbox.left + 2){
			nextMove.y *= -1;
		}else{
			nextMove.x *= -1;
			nextMove.y *= -1;
		}

	}
}
