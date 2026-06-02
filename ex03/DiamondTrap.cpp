#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
    : ClapTrap("_clap_name", 100, 50, 30), ScavTrap(), FragTrap(), _name("") {}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap("name_clap_name", 100, 50, 30), ScavTrap(name), FragTrap(name),
      _name("name") {}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other) {}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}
DiamondTrap::~DiamondTrap(void) {}

void DiamondTrap::whoAmI(void){}