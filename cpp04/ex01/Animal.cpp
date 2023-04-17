#include "Animal.hpp"
#include <iomanip>
#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"

Animal::Animal(void) : _type("") {
  std::clog << "[ DEBUG ] Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const &type) : _type(type) {
  std::clog << "[ DEBUG ] Animal string constructor called" << std::endl;
}

Animal::Animal(Animal const &other) : _type(other._type) {
  std::clog << "type : " << other._type << std::endl;
  std::clog << "[ DEBUG ] Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &other) {
  std::clog << "[ DEBUG ] Animal assignment operator called" << std::endl;
  _type = other._type;
  return (*this);
}

Animal::~Animal(void) {
  std::clog << "[ DEBUG ] Animal destructor  called" << std::endl;
}

void Animal::makeSound(void) const {
  if (_type.length() > 0)
    std::cout << std::setw(16) << std::left << "Animal( " + _type + " )";
  else
    std::cout << std::setw(16) << std::left << "Animal( ? )";
  std::cout << " : PUHAKHAKHAK! " << std::endl;
}

std::string Animal::getType(void) const { return (_type); }

Animal *Animal::clone(void)
{
  return (new Animal(*this));
}