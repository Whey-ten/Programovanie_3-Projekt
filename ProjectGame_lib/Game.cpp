#include <iostream>
#include <fstream>
#include <unistd.h>
#include "Game.h"


/*
 * Function loads premade game in code.
 */
void Game::PreLoadGame() {
    Map m;
    m.createMap();
    map = m;
    current_room = m.getEntryRoom();
    game_state = false;
}

/*
 * Function loads premade character
 */
void Game::LoadPlayer(Character new_player) {
    player = new_player;
    game_state = true;
    current_room = map.getEntryRoom();
    std::cout << "New character was loaded, you start in " << current_room.getName() <<"." << std::endl;
}

/*
 * Function allows player to move to other rooms
 */

bool Game::moveToRoom(const std::string& new_room_name) {
    if(!game_state){
        std::cout <<"Game is currently over, start new one or load new player character.";
        return false;
    }
    Room r;
    r = map.getRoom(new_room_name);
    if(map.isNeighbor(current_room.getName(), new_room_name)){
        if(r.getName() == new_room_name){
            map.updateRoom(current_room.getName(), current_room);
            current_room = r;
            return true;
        }
    }
    return false;
}

int randomNumber(){
    return 1 + ( std::rand() % ( 10 - 1 + 1 ) );
}

/*
 * simple simualtion of battle, casting random spells and random order of fighters
 */

std::string Game::battleSimulation(Character enemy) {
    if(!game_state){
        return "Game is currently over, start new one or load new player character.";
    }
    int p1, e1;
    int dmg;
    while (player.isAlive() && enemy.isAlive()){
        p1 = randomNumber();
        e1 = randomNumber();
        if(p1 > e1){
            p1 = player.castRandomSpell();
            if(p1 == 0){
                dmg = player.getPower() - enemy.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                enemy.changeHP(false, dmg);
            } else {
                dmg = p1 + player.getMagic() - enemy.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                enemy.changeHP(false, dmg);
            }
            if (!enemy.isAlive()){
                player.addExp(fight_experience);
                return "You won fight and enemy died!";
            }
            //
            e1 = enemy.castRandomSpell();
            if(e1 == 0){
                dmg = enemy.getPower() - player.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                player.changeHP(false, dmg);
            } else {
                dmg = e1 -+ enemy.getMagic() - player.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                player.changeHP(false, dmg);
            }
            if (!player.isAlive()){
                game_state = false;
                return "You lost fight and died!";
            }
        } else {
            e1 = enemy.castRandomSpell();
            if(e1 == 0){
                dmg = enemy.getPower() - player.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                player.changeHP(false, dmg);
            } else {
                dmg = e1 + enemy.getMagic() - player.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                player.changeHP(false, dmg);
            }
            if (!player.isAlive()){
                game_state = false;
                return "You lost fight and died!";
            }
            //
            p1 = player.castRandomSpell();
            if(p1 == 0){
                dmg = player.getPower() - enemy.getDefense() ;
                if(dmg < 0){
                    dmg = 1;
                }
                enemy.changeHP(false, dmg);
            } else {
                dmg = p1 + player.getMagic() - enemy.getDefense();
                if(dmg < 0){
                    dmg = 1;
                }
                enemy.changeHP(false, dmg);
            }
            if (!enemy.isAlive()){
                player.addExp(fight_experience);
                return "You won fight and enemy died!";
            }
        }
    }
    return "";
}
/*
 * function scans room to check if something is there and cleans it if there is
 */
std::string Game::cleanRoom() {
    if(!game_state){
        return "Game is currently over, start new one or load new player character.";
    }
    std::string battle_result;
    std::string room_status = current_room.checkRoom();
    if(room_status == "You found enemies!!"){
        std::vector<Character> enemies = current_room.getEnemies();
        for(auto it = enemies.begin(); it != enemies.end(); it++){
            battle_result = battleSimulation(*it);
            if(battle_result == "You lost fight and died!"){
                game_state = false;
                return "You lost battle and died!";
            }
            current_room.eraseEnemy(*it);
        }
        current_room.setStatus("empty");
        return battle_result;
    } else if (room_status == "There might be something hidden here."){
        Item i = current_room.findItem();
        std::string message = "You found: ";
        message += i.getName();
        message +=".";
        if (player.equipItem(i)){
            message += "And successfully equipped it.";
        } else {
            message += "Failed to equip it.";
        }
        if(current_room.getNumberOfEnemies() == 0 && current_room.getNumberOfItems() == 0){
            current_room.setStatus("empty");
            return message;
        }
        return message;
    }
    return "Room was cleaned, you found nothing.";
}
/*
 * function checks room if something is there
 */
std::string Room::checkRoom() {
    if(status == "empty"){
        return "Room is empty, move to other one.";
    } else if(status == "full"){
        return "You found enemies!!";
    } else if(status == "hidden"){
        return "There might be something hidden here.";
    }
    return "Something went wrong... are you dreaming!??";
}
/*
 * function checks if players cleared all rooms
 */
std::string Game::finnishGame() {
    map.updateRoom(current_room.getName(), current_room);
    std::vector<Room> rm = map.getAllRooms();
    for(auto it = rm.begin(); it != rm.end(); it++){
        Room r = *it;
        if(r.getStatus() != "empty"){
            return "There is still something on map, you are unable to finish game yet!";
        }
    }
    game_state = false;
    return "Congratulations! You beat the game. You can save your character and load new game.";
}
/*
 * function loads game from file
 */
bool Game::loadGame(const std::string &file_name) {
    Map m;
    int clock;
    std::ifstream inFile;
    inFile.open(file_name);
    if(!inFile){
        std::cout<<"Wrong File"<<std::endl;
        char tmp[256];
        getcwd(tmp, 256);
        std::cout << "Current working directory: " << tmp << std::endl;
        return false;
    }
    std::string line;
    std::string clean_line;
    //first line - name
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    m.setName(clean_line);
    //second line - numebr of rooms
    std::getline(inFile, line);
    clean_line = removeCharacters(line);
    clock = std::stoi(clean_line);
    // n- lines rooms
    for(int i = 0; i < clock; i++){
        std::getline(inFile, line);
        clean_line = removeCharacters(line);
        Room r;
        if(!r.loadFromString(clean_line)){
            std::cout<<"room"<<std::endl;
            return false;
        }
        m.addRoom(r);
    }

    // 2+nline - number of ways to travel
    std::getline(inFile, line);
    clean_line = removeCharacters(line);

    clock = std::stoi(clean_line);

    // n-lines ways of travel
    for(int i = 0; i < clock; i++){
        std::getline(inFile, line);
        clean_line = removeCharacters(line);
        std::string r1 = subString(clean_line, 1, ',');
        std::string r2 = subString(clean_line, 2, ',');
        m.addWay(r1, r2);
    }
    map = m;
    current_room = map.getEntryRoom();
    return true;
}
/*
 * functions save the game to file
 */
bool Game::saveGame() {
    return map.saveToFile();
}

bool Game::saveGame(const std::string& file_name) {
    if(!saveCharacter()){
        return false;
    }
    return map.saveToFile(file_name);
}
/*
 * functions allow player to save his current character
 */
bool Game::saveCharacter() {
    return player.saveToFile();
}
bool Game::saveCharacter(std::string file_name) {
    return player.saveToFile(file_name);
}