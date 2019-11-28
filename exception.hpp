#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>


class unknown_color final : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown color [" } + name + "]" }
   {}
   const char * what() const noexcept override {
      return s.c_str();
   }
private:
   const std::string s;
};

class unknown_shape final : public std::exception {
public:
   unknown_shape( const std::string & name  ):
       s{ std::string{ "unknown shape [" } + name + "]" }
   {}
   const char * what() const noexcept override {
      return s.c_str();
   }
private:
   std::string s;
};

class end_of_file final : public std::exception {
public:

   const char * what() const noexcept override {
      return s.c_str();
   }
private:
   std::string s = "end of file";
};

class invalid_position final : public std::exception {
public:
   invalid_position( const char & name  ):
       s{ std::string{ "invalid position [" } + name + "]" }
   {}
   const const char * what() const noexcept override {
      return s.c_str();
   }
private:
   std::string s;
};

#endif
