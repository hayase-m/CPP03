#include "ClapTrap.hpp"

int main(void) {
  ClapTrap robot("Bob");

  robot.attack("target");
  robot.takeDamage(4);
  robot.beRepaired(3);
  robot.takeDamage(100);
  robot.attack("target after defeat");
  robot.beRepaired(1);
  robot.takeDamage(1);

  return 0;
}
