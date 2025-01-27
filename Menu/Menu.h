#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "../Players/Player.h"

using namespace std;

class Menu {
    fstream introduction;
    fstream menu;
    fstream baccarat;
    fstream blackjack;
    fstream craps;
    fstream poker;
    fstream oneHandedBandit;
    fstream license;
    fstream instruction;
    Player player;

public:
    Menu(Player& player) : player(player){}
    void introductionMenu();
    void mainMenu();
    void instructionMenu();
    void licenseMenu();
    void baccaratInstruction();
    void blackjackInstruction();
    void crapsInstruction();
    void pokerInstruction();
    void oneHandedBanditInstruction();
};



#endif