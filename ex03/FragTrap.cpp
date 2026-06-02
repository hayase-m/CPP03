#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("", 100, 100, 30) {
  std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
  std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap " << _name << " copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
