#include <iostream>
#include "Load.h"
#ifndef PROJECTGAME_ITEM_H
#define PROJECTGAME_ITEM_H

/**
 * Header file for class Item from project.
 * Class includes name of item, its type and value it adds up.
 */

class Item {
    std::string name = "";
    std::string type = "";
    int value = 0;
public:
    std::string getName()const{return name;}
    std::string getType()const{return type;}
    int getValue()const{return value;}
    //
    void setName(std::string s){name = s;}
    void setType(std::string s){type = s;}
    void setValue(int i){value = i;}
    bool operator==(const Item& i) const;
    //
    void createItemOne();
    void createItemTwo();
    //
    bool loadFromString(const std::string& str);
    std::string getFileString() const;
};


#endif //PROJECTGAME_ITEM_H
