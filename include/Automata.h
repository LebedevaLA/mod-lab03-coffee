#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
        pair<vector<string>, vector<double>> getMenu();
        vector <STATES> getHistory();
        STATES getState();
        double get_cash();
        int get_id_drink();
        void choise(int drink_id);
        void check();
        void cook();
        void finish();
    private:
        double cash;
        vector<std::string> menu;
        vector<double> prices;
        int drink_id;
        STATES state;
        vector<STATES> history;
};
#endif