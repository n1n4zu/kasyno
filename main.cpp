#include "Baccarat/Baccarat.h"
#include "Blackjack/Blackjack.h"
#include "Players/Croupier.h"
#include "OneHandadBandit/OneHandedBandit.h"
#include "Players/Player.h"
#include "Players/Bot.h"
#include "Craps/Craps.h"
#include "Poker/Poker.h"

using namespace std;

int main()
{
    Croupier croupier("Krupier");
    Player player("Kryspin");
    Bot bob("Bob", 0.05);
    Bot john("John", 0.15);
    Bot tim("Tim", 0.8);
    OneHandedBandit fruitMachine;
    Baccarat baccarat(player, croupier);
    Craps craps;
    Blackjack blackjack(player, croupier);
    Poker poker(player, croupier, bob, john, tim);

    // fruitMachine.play();

    // baccarat.play();

    // craps.play();

    // blackjack.play();

    poker.play();
    return 0;
}
