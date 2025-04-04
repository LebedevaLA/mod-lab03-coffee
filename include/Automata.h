// Copyright 2022 UNN-IASR
#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <utility>
#include <vector>
#include <string>

enum class STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata{
 public:
        Automata();
        void on();
        void off();
        void coin(double amount);
        void cansel();
        std::pair<std::vector<std::string>, std::vector<double>> getMenu();
        std::vector <STATES> getHistory();
        STATES getState();
        double get_cash();
        int get_id_drink();
        void choise(int drink_id);
        void check();
        void cook();
        void finish();
 private:
        double cash;
        std::vector<std::string> menu;
        std::vector<double> prices;
        int drink_id;
        STATES state;
        std::vector<STATES> history;
};
#endif  // INCLUDE_AUTOMATA_H_
