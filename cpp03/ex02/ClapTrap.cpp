#include "ClapTrap.hpp"

/** PUBLIC **/
// constructor
ClapTrap::ClapTrap(std::string const &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::clog << "[ DEBUG ] ClapTrap constructor called : " << name << "\n";
}

// destructor
ClapTrap::~ClapTrap(void) {
  std::clog << "[ DEBUG ] ClapTrap destructor called : " << _name << "\n";
}

// actions
void ClapTrap::attack(std::string const &target) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left\n";
    return;
  }
  _energyPoints -= 1;
  std::cout << _name << " : ClapTrap attacks " << target << ", causing ";
  std::cout << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints < amount) {
    _hitPoints = 0;
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  _hitPoints -= amount;
  std::cout << _name << " : ClapTrap took damage and lost " << amount
            << " Hit points\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << _name << " : ClapTrap has no more hit points left\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << _name << " : ClapTrap has no more energy points left\n";
    return;
  }
  _energyPoints -= 1;
  _hitPoints += amount;
  std::cout << _name << " : ClapTrap has been repaired and gained " << amount
            << " Hit points\n";
}

// getter
std::string const &ClapTrap::getName(void) const { return (_name); }

unsigned int ClapTrap::getHitPoints(void) const { return (_hitPoints); }

unsigned int ClapTrap::getEnergyPoints(void) const { return (_energyPoints); }

unsigned int ClapTrap::getAttackDamage(void) const { return (_attackDamage); }

// setter
void ClapTrap::setName(std::string const &name) { _name = name; }

void ClapTrap::setHitPoints(unsigned int amount) { _hitPoints = amount; }

void ClapTrap::setEnergyPoints(unsigned int amount) { _energyPoints = amount; }

void ClapTrap::setAttackDamage(unsigned int amount) { _attackDamage = amount; }

// show
void ClapTrap::printStatus(void) const {
  std::cout << "===================== Current Status ====================\n";
  std::cout << " + Name : " << _name << "\n";
  std::cout << " + Hit Points : " << _hitPoints << "\n";
  std::cout << " + Energy Points : " << _energyPoints << "\n";
  std::cout << " + Attack Damage : " << _attackDamage << "\n";
  std::cout << "=========================================================\n";
}