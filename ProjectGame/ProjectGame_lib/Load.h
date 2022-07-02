#include <iostream>

#ifndef PROJECTGAME_LOAD_H
#define PROJECTGAME_LOAD_H

/**
 * Supplementary functions for loading classes from files and strings.
 */
const std::string END_CHARACTERS = "\n\t\r\b\v";

std::string subString(const std::string &text, int element, char del);
int numberOfDels(const std::string &text, char del);
bool endCharacter(char ch);
std::string removeCharacters(const std::string &input);
#endif //PROJECTGAME_LOAD_H
