#include "chaining.cpp"
#include "CVL.h"

int main(int argc, char *argv[]) {
    std::cout << "Welcome to our group's Automobile Repair program. This program will follow a \n" 
    << "decision tree and prompt you (the user) to enter true/false statements for \n" 
    << "various common problems related to cars to determine the issue with your \n" 
    << "vehicle and steps to fix it!" << std::endl;
    Chaining chain;
    std::cout << "chain created" << std::endl;
    int conclusion = chain.backward(); 
    std::cout << "The issue with your vehicle appeared to be: " << chain.getConc(conclusion) << std::endl;
}