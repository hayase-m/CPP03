#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
  ScavTrap scav("Scavy");
  FragTrap frag("Fraggy");

  scav.attack("target");
  scav.guardGate();

  frag.attack("target");
  frag.takeDamage(40);
  frag.beRepaired(10);
  frag.highFivesGuys();

  FragTrap copy(frag);
  copy.highFivesGuys();

  FragTrap assigned("Assigned");
  assigned = frag;
  assigned.highFivesGuys();

  return 0;
}
