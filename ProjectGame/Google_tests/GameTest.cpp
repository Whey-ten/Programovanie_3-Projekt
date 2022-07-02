#include "gtest/gtest.h"
#include "Game.h"
/**
 * Tests creation of new game, it's functions and possible end of game.
 */

TEST(GameTestSuite, CreateGame){
    Character ch;
    ch.createWarrior();
    Game g;
    g.PreLoadGame();
    EXPECT_FALSE(g.getGameState());
    g.LoadPlayer(ch);
    EXPECT_TRUE(g.getGameState());
    EXPECT_EQ("Entry", g.getCurrentPosition());
    EXPECT_EQ("There might be something hidden here.", g.checkCurrentRoom());
    EXPECT_EQ("You found: Sword.And successfully equipped it.", g.cleanRoom());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    Room r = g.getCurrentRoom();
    EXPECT_EQ("empty", r.getStatus());

    EXPECT_EQ("room1", g.getNeighborRooms());
    EXPECT_TRUE(g.moveToRoom("room1"));
    EXPECT_EQ("room1", g.getCurrentPosition());
    EXPECT_EQ("You found enemies!!", g.checkCurrentRoom());
    std::cout << "FIGHT START"<<std::endl;
    EXPECT_EQ("You won fight and enemy died!", g.cleanRoom());
    r = g.getCurrentRoom();
    EXPECT_EQ(0, r.getNumberOfEnemies());
    ch = g.getPlayer();
    EXPECT_EQ(2, ch.getLevel());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ("There is still something on map, you are unable to finish game yet!", g.finnishGame());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ("Entry, BossRoom", g.getNeighborRooms());
    EXPECT_TRUE(g.moveToRoom("Entry"));
    EXPECT_FALSE(g.moveToRoom("BossRoom"));
    EXPECT_TRUE(g.moveToRoom("room1"));
    EXPECT_TRUE(g.moveToRoom("BossRoom"));
    EXPECT_EQ("You found enemies!!", g.checkCurrentRoom());
    EXPECT_EQ("You won fight and enemy died!", g.cleanRoom());
    EXPECT_EQ("Room is empty, move to other one.", g.checkCurrentRoom());
    EXPECT_EQ( "Congratulations! You beat the game. You can save your character and load new game.", g.finnishGame());
    EXPECT_FALSE(g.getGameState());
}