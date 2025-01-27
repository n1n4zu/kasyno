#include "Baccarat/Baccarat.h"
#include "Blackjack/Blackjack.h"
#include "Players/Croupier.h"
#include "OneHandadBandit/OneHandedBandit.h"
#include "Players/Player.h"
#include "Players/Bot.h"
#include "Craps/Craps.h"
#include "Poker/Poker.h"
#include "Menu/Menu.h"
#include <unistd.h>

using namespace std;

int main()
{
    Croupier croupier("Krupier");
    Player player("Kryspin");
    Bot bob("Bob", 0.25);
    Bot john("John", 0.5);
    Bot tim("Tim", 0.8);
    OneHandedBandit fruitMachine;
    Baccarat baccarat(player, croupier);
    Craps craps;
    Blackjack blackjack(player, croupier);
    Poker poker(player, croupier, bob, john, tim);
    Menu menu;

    // menu.introductionMenu();
    // menu.mainMenu();
    // menu.instructionMenu();
    // menu.licenseMenu();
    // menu.baccaratInstruction();
    // menu.blackjackInstruction();
    // menu.crapsInstruction();
    // menu.pokerInstruction();
    // menu.oneHandedBanditInstruction();

    // sleep(10);

    // fruitMachine.play();

    // baccarat.play();

    // craps.play();

    // blackjack.play();

    // poker.play();

    return 0;
}
