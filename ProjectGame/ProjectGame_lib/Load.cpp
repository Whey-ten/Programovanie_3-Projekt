#include "Load.h"


/*
 * function retruns substring of string
 */
std::string subString(const std::string &text, int element, char del) {
    if(text == "" || element == 0){
        return "";
    }
    std::string ret_value = "";
    int counter = 1;
    for(int i = 0; i < text.length(); i++){
        if(text[i] == del){
            counter++;
        } else {
            if(counter == element){
                ret_value += text[i];
            }
        }
    }
    return ret_value;
}
/*
 * function checks if character is end character
 */
bool endCharacter(char ch) {
    for (auto i = 0; i < END_CHARACTERS.size(); i++) {
        if (END_CHARACTERS[i] == ch)
            return true;
    }
    return false;
}
/*
 * function removes end characters
 */
std::string removeCharacters(const std::string &input) {
    std::string out;
    for (auto ch : input) {
        if (endCharacter(ch)) {
            continue;
        }
        out += ch;
    }
    return out;
}
/*
 * function return number of chars in string
 */
int numberOfDels(const std::string &text, char del){
    int count = 0;
    for(int i = 0; i < text.size(); i++){
        if(text[i] == del){
            count++;
        }
    }
    return count;
}