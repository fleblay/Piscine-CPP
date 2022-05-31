#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << GREEN;
	std::cout << "Default FragTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << GREEN;
	std::cout << "Parametric FragTrap Constructor called" << std::endl;
	std::cout << RESET;
	this->setHitPointsInit(100);
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << GREEN;
	std::cout << "Copy FragTrap Constructor called" << std::endl;
	std::cout << RESET;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << GREEN;
	std::cout << "Default FragTrap Destructor called" << std::endl;
	std::cout << RESET;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << GREEN;
	std::cout << "FragTrap Assignation overload operator called" << std::endl;
	std::cout << RESET;
	this->_Name = rhs.getName();
	this->_HitPoints = rhs.getHitPoints();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_HitPointsInit = rhs.getHitPointsInit();
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (!this->canDoAction("attack"))
		return ;
	this->_EnergyPoints--;
	std::cout << GREEN;
	std::cout	<< "FragTrap " << this->_Name
				<< " attacks " << target
				<< ", causing " << this->_AttackDamage
				<< " points of damage!" << std::endl;
	std::cout << RESET;
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::string	answer;
	int	remaining_tries = 3;

	std::cout << "Can I get a high five dude ? (y/n)" << std::endl;
	std::getline(std::cin, answer);
	if (!std::cin.good())
	{
		if (std::cin.eof())
			std::cout << "EOF encountered" << std::endl;
		else
			std::cout << "Failure encountered" << std::endl;
		return ;
	}
	while (--remaining_tries && answer.compare("y") && answer.compare("yes"))
	{
		std::cout << "Come on mannnnnnnnnnnnnnn !" << std::endl;
		std::getline(std::cin, answer);
		if (!std::cin.good())
		{
			if (std::cin.eof())
				std::cout << "EOF encountered" << std::endl;
			else
				std::cout << "Failure encountered" << std::endl;
			return ;
		}
	}
	if (!remaining_tries)
		std::cout << "You ain't fun dude :(" << std::endl;
	else
		std::cout << "*SSSSSSSCCCCHLAAAACK SOUND*" << std::endl;
}
