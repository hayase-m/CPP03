#include "ScavTrap.hpp"
#include <climits>
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("", 100, 50, 20) {
  std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
  std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap copy assignment operator called" << std::endl;
  if (this != &other)
    ClapTrap::operator=(other);
  return *this;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (!canAct("ScavTrap"))
    return;
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ScavTrap " << _name << " already has no hit points left."
              << std::endl;
    return;
  }
  if (amount >= _hitPoints)
    _hitPoints = 0;
  else
    _hitPoints -= amount;
  std::cout << "ScavTrap " << _name << " takes " << amount
            << " points of damage! Hit points left: " << _hitPoints
            << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
  if (!canAct("ScavTrap"))
    return;
  if (_hitPoints > UINT_MAX - amount)
    _hitPoints = UINT_MAX;
  else
    _hitPoints += amount;
  _energyPoints--;
  std::cout << "ScavTrap " << _name << " repairs itself, recovering " << amount
            << " hit points! Hit points left: " << _hitPoints << std::endl;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap " << _name << " is now in Gate keeper mode."
            << std::endl;
}
