#include "ScavTrap.hpp"

int main(void) {
  ScavTrap guard("Gatekeeper");

  guard.attack("target");
  guard.takeDamage(30);
  guard.beRepaired(10);
  guard.guardGate();

  ScavTrap copy(guard);
  copy.attack("copy target");

  ScavTrap assigned("Assigned");
  assigned = guard;
  assigned.guardGate();

  ScavTrap tired("Tired");

  for (int i = 0; i < 50; i++)
    tired.attack("training target");
  tired.attack("target without energy");
  tired.beRepaired(1);

  return 0;
}
