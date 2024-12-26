#include "Baccarat/Baccarat.h"
#include "Blackjack/Blackjack.h"
#include "Players/Croupier.h"
#include "OneHandadBandit/OneHandedBandit.h"
#include "Players/Player.h"
#include "Craps/Craps.h"
#include "Poker/Poker.h"

using namespace std;

int main()
{
    Croupier croupier("Krupier");
    Player player("Kryspin");
    Player player2("Bot");
    OneHandedBandit fruitMachine;
    Baccarat baccarat(player, croupier);
    Craps craps;
    Blackjack blackjack(player, croupier);
    Poker poker(player, croupier, player2);

    // fruitMachine.play();

    // baccarat.play();

    // craps.play();

    // blackjack.play();

    poker.play();
    return 0;
}
