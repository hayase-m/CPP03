#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
    : ClapTrap("_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("") {
  std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", 100, 50, 30), ScavTrap(name),
      FragTrap(name), _name(name) {
  std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
  std::cout << "DiamondTrap " << _name << " copy constructor called"
            << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    _name = other._name;
  }
  return *this;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "DiamondTrap name: " << _name << std::endl;
  std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
