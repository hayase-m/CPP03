#include "ClapTrap.hpp"
#include <climits>
#include <iostream>

ClapTrap::ClapTrap(void)
    : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap copy assignment operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoints,
                   unsigned int energyPoints, unsigned int attackDamage)
    : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints),
      _attackDamage(attackDamage) {
  std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

bool ClapTrap::canAct(const std::string &type) const {
  if (_hitPoints == 0) {
    std::cout << type << " " << _name
              << " cannot act because it has no hit points left." << std::endl;
    return false;
  }
  if (_energyPoints == 0) {
    std::cout << type << " " << _name
              << " cannot act because it has no energy points left."
              << std::endl;
    return false;
  }
  return true;
}

void ClapTrap::attack(const std::string &target) {
  if (!canAct("ClapTrap"))
    return;
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << " already has no hit points left."
              << std::endl;
    return;
  }
  if (amount >= _hitPoints)
    _hitPoints = 0;
  else
    _hitPoints -= amount;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage! Hit points left: " << _hitPoints
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (!canAct("ClapTrap"))
    return;
  if (_hitPoints > UINT_MAX - amount)
    _hitPoints = UINT_MAX;
  else
    _hitPoints += amount;
  _energyPoints--;
  std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount
            << " hit points! Hit points left: " << _hitPoints << std::endl;
}
