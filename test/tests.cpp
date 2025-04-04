// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(Test, test1) {
    Automata autom = Automata();
    autom.choise(1);
    STATES result = STATES::OFF;
    EXPECT_EQ(autom.getState(), result);
}
TEST(Test, test2) {
    Automata autom = Automata();
    autom.on();
    STATES result = STATES::WAIT;
    EXPECT_EQ(autom.getState(), result);
}
TEST(Test, test3) {
    Automata autom = Automata();
    autom.on();
    autom.cansel();
    STATES result = STATES::WAIT;
    EXPECT_EQ(autom.getState(), result);
}
TEST(Test, test4) {
    Automata autom = Automata();
    autom.on();
    autom.choise(1);
    STATES result = STATES::WAIT;
    EXPECT_EQ(autom.getState(), result);
}
TEST(Test, test5) {
    Automata autom = Automata();
    autom.on();
    autom.coin(200);
    STATES result = STATES::ACCEPT;
    EXPECT_EQ(autom.getState(), result);
}
TEST(Test, test6) {
    Automata autom = Automata();
    autom.on();
    autom.coin(200);
    autom.choise(7);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT, STATES::CHECK, STATES::COOK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}

TEST(Test, test7) {
    Automata autom = Automata();
    autom.on();
    autom.coin(5);
    autom.choise(7);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT, STATES::CHECK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}
TEST(Test, test8) {
    Automata autom = Automata();
    autom.on();
    autom.coin(5);
    autom.choise(7);
    autom.check();
    double res = 5;
    EXPECT_EQ(autom.get_cash(), res);
}
TEST(Test, test9) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.coin(100);
    autom.choise(0);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT, STATES::ACCEPT, STATES::CHECK, STATES::COOK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}
TEST(Test, test10) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.coin(100);
    autom.choise(0);
    autom.check();
    double res = 0;
    EXPECT_EQ(autom.get_cash(), res);
}
TEST(Test, test11) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.choise(0);
    autom.check();
    autom.coin(100);
    autom.choise(0);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT,STATES::CHECK,STATES::WAIT, STATES::ACCEPT, STATES::CHECK, STATES::COOK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}

TEST(Test, test12) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.choise(0);
    autom.cansel();
    autom.choise(2);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT, STATES::CHECK, STATES::COOK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}
TEST(Test, test13) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.choise(-1);
    autom.check();
    autom.choise(2);
    autom.check();
    vector<STATES> res = {STATES::OFF, STATES::WAIT, STATES::ACCEPT, STATES::CHECK, STATES::ACCEPT, STATES::CHECK, STATES::COOK, STATES::WAIT};
    EXPECT_EQ(autom.getHistory(), res);
}
TEST(Test, test14) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.choise(-1);
    autom.check();
    autom.choise(2);
    int res = 2;
    EXPECT_EQ(autom.get_id_drink(), res);
}
TEST(Test, test15) {
    Automata autom = Automata();
    autom.on();
    autom.coin(100);
    autom.choise(-1);
    autom.check();
    autom.choise(2);
    autom.check();
    EXPECT_EQ(autom.get_id_drink(), -1);
}