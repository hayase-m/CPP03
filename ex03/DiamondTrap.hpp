#ifndef DIAMONDTRAP_HPP
#define DIAMONTTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
private:
  std::string _name;

public:
  DiamondTrap(void);
  DiamondTrap(std::string name);
  DiamondTrap(const DiamondTrap &other);
  DiamondTrap &operator=(const DiamondTrap &other);
  ~DiamondTrap(void);

  using ScavTrap::attack;

  void whoAmI(void);
};

#endif
