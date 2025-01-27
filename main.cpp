#include "Baccarat/Baccarat.h"
#include "Blackjack/Blackjack.h"
#include "Players/Croupier.h"
#include "OneHandadBandit/OneHandedBandit.h"
#include "Players/Player.h"
#include "Players/Bot.h"
#include "Craps/Craps.h"
#include "Poker/Poker.h"
#include "Menu/Menu.h"
#include <iostream>
#include "functions/functions.h"

using namespace std;

int main() {
    string name;
    Croupier croupier("Krupier");

    cout << "Podaj swoje imię: " << endl << "> ";
    cin >> name;

    Player player(name);

    Bot bob("Bob", 0.25);
    Bot john("John", 0.5);
    Bot tim("Tim", 0.8);
    OneHandedBandit fruitMachine(player);
    Baccarat baccarat(player, croupier);
    Craps craps(player);
    Blackjack blackjack(player, croupier);
    Poker poker(player, croupier, bob, john, tim);
    Menu menu(player);
    int option;

    clear();

    menu.introductionMenu();

    cout << "> ";
    cin >> option;

    if (option == 1) {
        clear();

        while (true) {
            bool testValue = true;

            clear();

            menu.mainMenu();

            cout << "> ";
            cin >> option;

            clear();

            switch (option) {
                case 1:
                    baccarat.play();
                break;
                case 2:
                    craps.play();
                break;
                case 3:
                    blackjack.play();
                break;
                case 4:
                    poker.play();
                break;
                case 5:
                    fruitMachine.play();
                break;
                case 6:
                    while (testValue) {
                        clear();
                        menu.instructionMenu();
                        cout << "> ";
                        cin >> option;
                        clear();
                        switch (option) {
                            case 1:
                                menu.baccaratInstruction();
                                cout << endl << "Wciśnij Enter by kontynuować";
                                cin.ignore();
                                cin.get();
                            break;
                            case 2:
                                menu.crapsInstruction();
                                cout << endl << "Wciśnij Enter by kontynuować";
                                cin.ignore();
                                cin.get();
                            break;
                            case 3:
                                menu.blackjackInstruction();
                                cout << endl << "Wciśnij Enter by kontynuować";
                                cin.ignore();
                                cin.get();
                            break;
                            case 4:
                                menu.pokerInstruction();
                                cout << endl << "Wciśnij Enter by kontynuować";
                                cin.ignore();
                                cin.get();
                            break;
                            case 5:
                                menu.oneHandedBanditInstruction();
                                cout << endl << "Wciśnij Enter by kontynuować";
                                cin.ignore();
                                cin.get();
                            break;
                            case 6:
                                testValue = false;
                            break;
                            default:
                            break;
                        }
                    }
                break;
                case 7:
                    menu.licenseMenu();
                    cout << endl << "Wciśnij Enter by kontynuować";
                    cin.ignore();
                    cin.get();
                break;
                case 8:
                    return false;
                default:
                break;
            }
        }
    }

    return 0;
}
