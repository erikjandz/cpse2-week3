#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <fstream>
#include "exception.hpp"

std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs ){
   std::string s;
   input >> s;
   const struct { const char * name; sf::Color color; } colors[]{
       { "yellow", sf::Color::Yellow },
       { "red",    sf::Color::Red },
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
   if( ! ( input >> rhs.x )){ throw end_of_file(); }
   if( ! ( input >> c )){ throw end_of_file(); }
   if( ! ( input >> rhs.y )){ throw end_of_file(); }
   if( ! ( input >> c )){ throw end_of_file(); }
   if( c != ')' ){ throw invalid_position( c ); }

   return input;
}


drawable * screen_object_read( std::ifstream & input ){
   sf::Vector2f position;
   std::string name;
   input >> position >> name;

   if( name == "CIRCLE" ){
      return new circle(position);
   } else if( name == "RECTANGLE" ){
      return new rectangle(position);
   } else if( name == "PICTURE" ){
      return new rectangle(position);
   } else if( name == "" ){
      throw end_of_file();
   }
   throw unknown_shape( name );
}


#endif
