#include "Menu.h"
#include <string>
#include <iostream>

using namespace std;

void Menu::introductionMenu() {
    introduction.open("../resources/init.txt", ios::in);

    string line;

    while (!introduction.eof()) {
        getline(introduction, line);
        cout << line << endl;
    }

    introduction.close();
}

void Menu::mainMenu() {
    menu.open("../resources/menu.txt", ios::in);

    cout << "Imię: " << player.getName() << " Pieniądze: " << player.getCash() << endl;

    string line;

    while (!menu.eof()) {
        getline(menu, line);
        cout << line << endl;
    }

    menu.close();
}

void Menu::instructionMenu() {
    instruction.open("../resources/instruction.txt", ios::in);

    string line;

    while (!instruction.eof()) {
        getline(instruction, line);
        cout << line << endl;
    }

    instruction.close();
}

void Menu::licenseMenu() {
    license.open("../resources/license.txt", ios::in);

    string line;

    while (!license.eof()) {
        getline(license, line);
        cout << line << endl;
    }

    license.close();
}

void Menu::baccaratInstruction() {
    baccarat.open("../resources/baccarat.txt", ios::in);

    string line;

    while (!baccarat.eof()) {
        getline(baccarat, line);
        cout << line << endl;
    }

    baccarat.close();
}

void Menu::blackjackInstruction() {
    blackjack.open("../resources/blackjack.txt", ios::in);

    string line;

    while (!blackjack.eof()) {
        getline(blackjack, line);
        cout << line << endl;
    }

    blackjack.close();
}

void Menu::crapsInstruction() {
    craps.open("../resources/craps.txt", ios::in);

    string line;

    while (!craps.eof()) {
        getline(craps, line);
        cout << line << endl;
    }

    craps.close();
}

void Menu::pokerInstruction() {
    poker.open("../resources/poker.txt", ios::in);

    string line;

    while (!poker.eof()) {
        getline(poker, line);
        cout << line << endl;
    }

    poker.close();
}

void Menu::oneHandedBanditInstruction() {
    oneHandedBandit.open("../resources/fruitmachine.txt", ios::in);

    string line;

    while (!oneHandedBandit.eof()) {
        getline(oneHandedBandit, line);
        cout << line << endl;
    }

    oneHandedBandit.close();
}

