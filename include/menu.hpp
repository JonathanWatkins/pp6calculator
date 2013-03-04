#ifndef CALC_MENU_HPP
#define CALC_MENU_HPP

#include <string.h>
#include <iostream>

bool inChoices(char* list, int numChoices, char* choice);

int showMenu(std::string);

std::string loopMenu(char* choice, int numChoices);

#endif
