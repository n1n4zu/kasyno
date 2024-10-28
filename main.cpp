#include "Baccarat.h"
#include "Croupier.h"
#include "OneHandadBandit.h"
#include "deck.h"
#include "Player.h"

using namespace std;

int main()
{
    Croupier croupier("Krupier");
    Player player("Kryspin");
    OneHandadBandit fruitMachine;
    Baccarat baccarat(player, croupier);

    // cout << fruitMachine.play() << endl;

    baccarat.play();

    return 0;
}
