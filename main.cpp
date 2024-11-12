#include "Baccarat/Baccarat.h"
#include "Blackjack/Blackjack.h"
#include "Players/Croupier.h"
#include "OneHandadBandit/OneHandedBandit.h"
#include "Players/Player.h"
#include "Craps/Craps.h"

using namespace std;

int main()
{
    Croupier croupier("Krupier");
    Player player("Kryspin");
    OneHandedBandit fruitMachine;
    Baccarat baccarat(player, croupier);
    Craps craps;
    Blackjack blackjack(player, croupier);

    // fruitMachine.play();

    // baccarat.play();

    // craps.play();

    blackjack.play();

    return 0;
}
