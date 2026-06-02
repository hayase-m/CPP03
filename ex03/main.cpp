#include "DiamondTrap.hpp"

int main(void) {
  DiamondTrap diamond("Diamond");

  diamond.whoAmI();
  diamond.attack("target");
  diamond.takeDamage(40);
  diamond.beRepaired(10);
  diamond.guardGate();
  diamond.highFivesGuys();

  DiamondTrap copy(diamond);
  copy.whoAmI();

  DiamondTrap assigned("Assigned");
  assigned = diamond;
  assigned.whoAmI();

  DiamondTrap empty;
  empty.whoAmI();

  return 0;
}
