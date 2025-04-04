#include "Automata.h"

Automata::Automata() : cash(0.0), state(STATES::OFF),
    menu({"Латте", "Эспрессо", "Американо", "Капучино", "Какао", "Горячий шоколад", "Чай", "Раф"}),
    prices({190, 70, 95, 190, 150, 195, 45, 200}) {
    history.push_back(STATES::OFF);
};

void Automata::on(){
    if (state == STATES::OFF){
        state = STATES::WAIT;
        cout << "Started" << endl;
        history.push_back(STATES::WAIT);
    }else cout << "Had already started" << endl;
}
void Automata::off(){
    if (state == STATES::WAIT){
        state = STATES::OFF;
        history.push_back(STATES::OFF);
    }cout << "Cant 'off' before finish order";
}
void Automata::coin(double amount){
    if(state == STATES::WAIT || state == STATES::ACCEPT){
        state = STATES::ACCEPT;
        cash += amount;
        cout << "Current amount:"<< cash << endl;
        history.push_back(STATES::ACCEPT);
    }
    
}
void Automata::cansel(){
    if (state == STATES::ACCEPT){
        cout << "The choice is canceled, choose anoter one"<<endl;
    }
    if (state == STATES::CHECK){
        cout << "Not enough money"<<endl;
        state = STATES::WAIT;
        history.push_back(STATES::WAIT);
    }
    drink_id = -1;
}
pair<vector<string>, vector<double>> Automata::getMenu(){
    return {menu, prices};
}
STATES Automata::getState(){
    return state;
}
double Automata::get_cash(){
    return cash;
}
vector <STATES> Automata::getHistory(){
    return history;
}
int Automata::get_id_drink(){
    return (drink_id);
}
void Automata::choise(int drink_id){
    if (state == STATES::ACCEPT) {
        this -> drink_id = drink_id;
    }
}
void Automata::check(){
    state = STATES::CHECK;
    history.push_back(STATES::CHECK);
    if (drink_id < 0 || drink_id > menu.size()-1){
        state = STATES::ACCEPT;
        history.push_back(STATES::ACCEPT);
        cansel();
        return;
    }
    else if (prices[drink_id] > cash ){
        cansel();
        return;
    }else{
        if (prices[drink_id] < cash){
            cout<< "Youre change:" << cash - prices[drink_id]<<endl;
        }
        state = STATES::COOK;
        history.push_back(STATES::COOK);
        cook();
    }
}
void Automata::cook(){
    if (state == STATES::COOK){
        cout<<"Here you are"<<endl;
        finish();
    }
}
void Automata::finish(){
    if (state == STATES::COOK)
    {
        cash = 0;
        drink_id = -1;
        state = STATES::WAIT;
        history.push_back(STATES::WAIT);
    }
}

