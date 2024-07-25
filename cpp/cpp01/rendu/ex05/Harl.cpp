#include "Harl.hpp"

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug( void ) {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info( void ) {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}
void Harl::warning( void ) {
  std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void ) {
  std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain( std::string level ) {
  void (Harl::* funcptr) (void);

  if (level.empty())
  {
    std::cout << "empty" << std::endl;
    return ;
  }
  std::map<std::string, void (Harl::*)()> funcMap;
  funcMap["DEBUG"] = &Harl::debug;
  funcMap["INFO"] = &Harl::info;
  funcMap["WARNING"] = &Harl::warning;
  funcMap["ERROR"] = &Harl::error;

  if (level == "DEBUG" || level == "INFO" || level == "WARNING" || level == "ERROR")
    funcptr = funcMap.at(level);
  else
    return ;
  (this->*funcptr)();
}
