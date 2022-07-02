#include "Character.h"
#include <iostream>
#include <fstream>
/*
 * functions sets name to character
 */
void Character::setName() {
    setName("RandomName");
}
void Character::setName(std::string new_name) {
    name = new_name;
}
/*
 * function sets klass to character and his stats
 */
void Character::setKlass(Klass klass) {
    klassa = klass;
    setStats(level);
}
/*
 * function sets stats to character
 */
void Character::setStats(int &lvl) {
    stats.setMaxHP(klassa.getHp(lvl));
    stats.setCurrentHP(klassa.getHp(lvl));
    stats.setMaxMana(klassa.getMana(lvl));
    stats.setCurrentMana(klassa.getMana(lvl));
    stats.setPower(klassa.getPower(lvl));
    stats.setDefense(klassa.getDefense(lvl));
    stats.setMagic(klassa.getMagic(lvl));
}
/*
 * function adds experience to char and checks if he leveled up
 */
void Character::addExp(int exp) {
    this->experience += exp;
    if(checkLevelUp()){
        std::cout << "Congratulations for level up!";
    }
}
/*
 * function to check if character has enough experience for level up
 */
bool Character::checkLevelUp() {
    int cap = klassa.getExp(level);
    if (this->experience >= cap){
        levelUp(cap);
        return true;
    }
    return false;
}
/*
 * function to level up character
 */
void Character::levelUp(int cap) {
    this->level++;
    this->experience = this->getExp() - cap;
    setStats(level);
    std::cout << "You leveled up!"<< std::endl;
}
/*
 * function to change health of character and check if he died
 */
void Character::changeHP(bool plus, int value) {
    int current = stats.getCurrentHP();
    if (plus){
        current += value;
    } else {
        current -= value;
    }
    if(current <= 0){
        alive = false;
    }
    stats.setCurrentHP(current);
    if(stats.getCurrentHP() <= 0){
        alive = false;
    }
}
/*
 * functions to change character stats
 */
void Character::setMaxHP(int new_value) {
    if(new_value > stats.getMaxHP()){
        stats.setMaxHP(new_value);
    } else {
        changeHP(false, stats.getMaxHP() - new_value);
        stats.setMaxHP(new_value);
    }
}

void Character::changeMana(bool plus, int value) {
    int current = stats.getCurrentMana();
    if (plus){
        current += value;
    } else {
        current -= value;
    }
    stats.setCurrentMana(current);
}

void Character::changePower(bool plus, int value) {
    int current = stats.getPower();
    if (plus){
        current += value;
    } else {
        current -= value;
    }
    stats.setPower(current);
}

void Character::changeDefense(bool plus, int value) {
    int current = stats.getDefense();
    if (plus){
        current += value;
    } else {
        current -= value;
    }
    stats.setDefense(current);
}

void Character::changeMagic(bool plus, int value) {
    int current = stats.getMagic();
    if (plus){
        current += value;
    } else {
        current -= value;
    }
    stats.setMagic(current);
}
/*
 * function to learn new spell
 */
bool Character::learnSpell(Spell s) {
    for(auto it = spells.begin(); it != spells.end(); it++){
        Spell s2 = *it;
        if(s2 == s){
            return false;
        }
    }
    spells.push_back(s);
    spells_cooldown.insert(std::make_pair(s.getName(), 0));
    return true;
}
/*
 * function to create premade characters for tests
 */
void Character::createGoonOne() {
    name = "GoonONE";
    Klass k;
    k.createKlass();
    setKlass(k);
}

void Character::createGoonTwo() {
    name = "GoonTWO";
    Klass k;
    k.createKlass();
    setKlass(k);
}

void Character::createBoss() {
    name = "BigBOSS";
    Klass k;
    k.createKlassTwo();
    setKlass(k);
    Spell s1;
    s1.createTwo();
    learnSpell(s1);
}

void Character::createWarrior() {
    setName("PremadeWarrior");
    Klass k;
    k.createKlass();
    setKlass(k);
    Spell s1, s2;
    s1.createOne();
    s2.createTree();
    learnSpell(s1);
    learnSpell(s2);
}

void Character::createMage() {
    setName("PremadeMage");
    Klass k;
    k.createKlassTwo();
    setKlass(k);
    Spell s1;
    s1.createTwo();
    learnSpell(s1);
}
/*
 * function to return spell from string name
 */
Spell Character::getSpellFromName(const std::string& name_of_spell) const {
    Spell s;
    for(auto it = spells.begin(); it != spells.end(); it ++){
        Spell s2 = *it;
        if(s2.getName() == name_of_spell){
            s = *it;
        }
    }
    return s;
}
/*
 * function casts random spell that is on cooldown
 */
int Character::castRandomSpell() {
    int damage_value = 0;
    bool casted = false;
    for(auto it = spells_cooldown.begin(); it != spells_cooldown.end(); it++){
        if(it->second == 0 && !casted){
            Spell s = getSpellFromName(it->first);
            if(s.getName() != it->first){
                return 0;
            }
            if(stats.getCurrentMana() >= s.getMana()){
                changeMana(false, s.getMana());
                damage_value = s.getPower();
                casted = true;
                it->second = 3;
            }
        } else {
            if(it->second != 0){
                it->second--;
            }
        }
    }
    return damage_value;
}
/*
 * function equips item to character
 */
bool Character::equipItem(const Item& i) {
    int value = i.getValue();
    if(i.getType() == "off"){
        changePower(true, value);
        equipment.push_back(i);
        return true;
    }
    if(i.getType() == "def"){
        changeDefense(true, value);
        equipment.push_back(i);
        return true;
    }
    return false;
}
/*
 * functions unequip item from character
 */
bool Character::unequipItem(const Item& i) {
    for(auto it = equipment.begin(); it != equipment.end(); it++){
        if(*it == i){
            int value = i.getValue();
            if(i.getType() == "off"){
                changePower(false, value);
                equipment.erase(it);
                return true;
            }
            if(i.getType() == "def"){
                changeDefense(false, value);
                equipment.erase(it);
                return true;
            }
        }
    }
    return false;
}

bool Character::unequipItem(const std::string& item_name) {
    for(auto it = equipment.begin(); it != equipment.end(); it++){
        if(item_name == it->getName()){
            return unequipItem(*it);
        }
    }
    return false;
}
/*
 * operator checks if 2 characters are same one
 */
bool Character::operator==(const Character& c) const {
    if(name != c.getName() || level != c.getLevel() || experience != c.getExp()){
        return false;
    }
    if(getPower() != c.getPower() || getDefense() != c.getDefense() || getMagic() != c.getMagic()){
        return false;
    }
    return true;
}
/*
 * function prints character info
 */
void Character::printStatus() {
    std::cout << "####################"<< std::endl;
    std::cout << "Name: "<< name << std::endl;
    std::cout << "Level: "<< level << std::endl;
    std::cout << "Exp: "<< experience << std::endl;
    std::cout << "Class: "<< klassa.getName() << std::endl;
    std::cout << "#------------------#"<< std::endl;
    std::cout << "Stats: "<< std::endl;
    std::cout << "HP: "<< stats.getCurrentHP()<< "/" << stats.getMaxHP() << std::endl;
    std::cout << "Mana: "<< stats.getCurrentMana()<< "/" << stats.getMaxMana() << std::endl;
    std::cout << "Power: "<< stats.getPower() << std::endl;
    std::cout << "Defense: "<< stats.getDefense() << std::endl;
    std::cout << "Magic: "<< stats.getMagic() << std::endl;
    std::cout << "#------------------#"<< std::endl;
    std::cout << "Spells: "<< std::endl;
    for(auto it = spells.begin(); it != spells.end(); it++){
        Spell s = *it;
        std::cout << "-> "<< s.getName() << std::endl;
    }
    std::cout << "Equipment: "<< std::endl;
    for(auto it = equipment.begin(); it != equipment.end(); it++){
        Item i = *it;
        std::cout << "-> "<< i.getName() << std::endl;
    }
    std::cout << "####################"<< std::endl;
}
/*
 * function loads character from string
 */
bool Character::loadFromString(const std::string& str) {
    int c = numberOfDels(str, ';');
    if(c != 5){
        return false;
    }
    std::string subs;
    std::string name_of = subString(str,1,';');
    std::string lvl = subString(str,2,';');
    std::string exp = subString(str,3,';');
    std::string klass = subString(str,4,';');
    std::string spell = subString(str,5,';');
    std::string item = subString(str,6,';');
    //
    setName(name_of);
    //
    level = std::stoi(lvl);
    //
    experience = std::stoi(exp);
    //
    Klass k;
    if(!k.loadFromString(klass)){
        return false;
    }
    setKlass(k);
    //
    char ch = spell[0];
    c = ch - '0';
    for(int i = 0; i < c; i++){
        Spell s;
        subs = subString(spell,i+2,'@');
        if(!s.loadFromString(subs)){
            return false;
        }
        learnSpell(s);
    }
    //
    ch = item[0];
    c = ch - '0';
    for(int i = 0; i < c; i++){
        Item item_i;
        subs = subString(item,i+2,'@');
        if(!item_i.loadFromString(subs)){
            return false;
        }
        equipItem(item_i);
    }
    return true;
}
/*
 * function load character from file
 */
bool Character::loadFromFile(const std::string& file_name) {
    std::ifstream inFile;
    inFile.open(file_name);
    if(!inFile){
        std::cout<<"Wrong File"<<std::endl;
        return false;
    }
    std::string line;
    std::string clean_line;
    int clock;
    //first line - name
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    name = clean_line;
    //second line level
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    level = std::stoi(clean_line);
    //third line experience
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    experience = std::stoi(clean_line);
    //4th line klass
    Klass k;
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    k.loadFromString(clean_line);
    setKlass(k);
    //5th line #spells
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    clock = std::stoi(clean_line);
    for(int i = 0; i < clock; i++){
        std::getline(inFile, line);
        clean_line = removeCharacters(line);
        Spell spell;
        if(!spell.loadFromString(clean_line)){
            return false;
        }
        learnSpell(spell);
    }
    //6+nth line #items
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    clock = std::stoi(clean_line);
    for(int i = 0; i < clock; i++){
        std::getline(inFile, line);
        clean_line = removeCharacters(line);
        Item item;
        if(!item.loadFromString(clean_line)){
            return false;
        }
        equipItem(item);
    }
    return true;
}
/*
 * functions to save character to file
 */
bool Character::saveToFile() {
    return saveToFile(getName());
}

bool Character::saveToFile(const std::string& file_name) {
    if(!isAlive()){
        return false;
    }
    std::string f_name = file_name + ".txt";
    std::ofstream outfile (f_name);
    outfile << getName() << std::endl;
    outfile << getLevel() << std::endl;
    outfile << getExp() << std::endl;
    std::string klass_string = klassa.getFileString();
    outfile << klass_string << std::endl;
    outfile << spells.size() << std::endl;
    for(auto it = spells.begin(); it != spells.end(); it++){
        std::string spell_string = it->getFileString();
        outfile << spell_string << std::endl;
    }
    outfile << equipment.size() << std::endl;
    for(auto it = equipment.begin(); it != equipment.end(); it++){
        std::string item_string = it->getFileString();
        outfile << item_string << std::endl;
    }
    outfile.close();
    return true;
}
/*
 * function returns string value of character
 */
std::string Character::getFileString() {
    std::string str = "";
    str += getName() + ";";
    str += std::to_string(getLevel()) + ";";
    str += std::to_string(getExp()) + ";";
    std::string klass_string = klassa.getFileString();
    str += klass_string + ";";
    //
    str += std::to_string(spells.size());
    for(auto it = spells.begin(); it != spells.end(); it++){
        str += "@";
        std::string spell_string = it->getFileString();
        str += spell_string;
    }
    str += ";";
    //
    str += std::to_string(equipment.size());
    for(auto it = equipment.begin(); it != equipment.end(); it++){
        str += "@";
        std::string item_string = it->getFileString();
        str += item_string;
    }
    return str;
}