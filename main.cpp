#include "chaining.cpp"
#include "CVL.h"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to our group's Automobile Repair program. This program will follow a " 
    << "decision tree and prompt you (the user) to enter true/false statements for " 
    << "various common problems related to cars to determine the issue with your " 
    << "vehicle and steps to fix it!" << std::endl;
    Backward back;
    Chaining chain;
    int conclusion = chain.backward(); 
    std::cout << "The issue with your vehicle appeared to be: " << back.conclusionList[conclusion] << std::endl;
}