#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H
#include <string>
#include <vector>

//base class to be inherrited by the forward and backward base
//this sets up the basics that both forward and backward chaining require:
//      >a conclusion string which should hold the conclusion which was found to be true for the user's input
//      >a list of variables
//      >a list of conclusions (in order of the rules they apply to)
//      >a clause list which contains the above list of conclusions at the same index values 
//       (which contain a list of the indexes for each variable related to them, which can be used to fetch either the variable itself or its bool state)
//      >a list of the bool states for each variable (in order of the index of the string vector) which is initialized to -1 so the program knows if the state has been set yet
//      >the CVL itself, which has a size equal to the size of the clauseList * the max # of Vars associated with a single conclusion (which is itself a const variable)
//       to navigate through the CVL: take the index of the rule you're working on, multiply by four (this gets you the starting index in the CVL for your rule, to get subsequent vars indexes itterate +1)
//       to get the rule from the CVL: take the index of the CVL, divide by four (no remainder), and add 1
class Backward {
    public:
    int varsNum = 32;     //keeps the number of vars as its own accessible variable
    int clauseNum = 32;   //keeps number of conclusions as its own accessible variable
    int maxVars = 4;  //a number related to the max number of variables related to a single conclusion or rule
    int conclusion = -1; //what this whole thing returns eventually, used to access the conclusionList to return the specified conclusion

    //the following have their values pre-defined
    std::vector<std::string> varsList = {"Leaking Fluid", "Smell of Gasoline", "Have a Green or Pink Color", "Have a Red Color", "Have a Yellow/Dark Brown Color", "Appear Viscous or Oily", //0-5
                                        "Sensor Problem", "Engine Light", "Oil Warning Light", "Low Oil Levels", "Engine Worn", "Tire Pressure Light", "Tires not Filled", "Leak in a Tire", "Low Gas Mileage", "Over 5000 Miles Since Last Oil Change", "Air Filter Clogged", //6-16
                                        "Won't Start", "Gas Empty", "Cranking Sound from Engine", "Cold outside", "Clicking Sound from Engine", "Stearing Wheel Locked", "Headlights Turn On", "Fuel Filter Clogged", "Fuel Line Read Zero", //17-25
                                        "Parts", "Hood", "Headlights", "Any Light at All", "Wipers", "Wipers Turn On", "Streaking"}; //26-32
    std::vector<std::string> conclusionList ={"Gasoline Leak", "Coolant/Antifreeze Leak" , "Transmission Fluid Leak", "Oil Leak", "Brake Fluid Leak", "Water Leak", //0-5
                                              "Engine Light Code", "Refuel Oil", "Engine Problem", "Oil Sensor Broken", "Refill Tires", "Plug Tire Leak", "Tire Pressure Sensor Broken", "Oil Change Needed", "Change Air Filter", "Change Spark Plugs", "No Issue", //6-16
                                              "Refill Gasoline", "Warm Battery", "Replace Battery", "Electrical Problem in Engine", "Steering Wheel Locked", "Replace Ignition Coil", "Replace Fuel Filter", "Fuel Pump Failure", "Timing Belt Failure", //17-25
                                              "Latch Broken", "Headlights Foggy", "Wiring Issue in Headlights", "Fluid Pipe Clogged", "Replace Wipers", "Electrical Issue in Wipers", "No Parts Need Replacing"}; //26-32
    std::vector<std::vector<int>> clauseList = {
        {0, 1, -1, -1}, {0, 2, -1, -1}, {0, 3, -1, -1}, {0, 4, -1, -1}, {0, 5, -1, -1}, {0, -1, -1, -1}, //0-5
        {6, 7, -1, -1}, {6, 8, 9, -1}, {6, 8, 10, -1}, {6, 8, -1, -1}, {6, 11, 12, -1}, {6, 11, 13, -1}, {6, 11, -1, -1}, {6, 14, 15, -1}, {6, 14, 16, -1}, {6, 14, -1}, {6, -1, -1, -1}, //6-16
        {17, 18, -1, -1}, {17, 19, 20, -1}, {17, 19, -1, -1}, {17, 21, -1, -1}, {17, 22, -1, -1}, {17, 23, -1, -1}, {17, 24, -1, -1}, {17, 25, -1, -1}, {17, -1, -1, -1}, //17-25
        {26, 27, -1, -1}, {26, 28, 29, -1}, {26, 28, -1, -1}, {26, 30, 31, 32}, {26, 30, 31, -1}, {26, 30, -1, -1}, {26, -1, -1, -1} //26-32
    };

    //the following are initialized via functions
    std::vector<int> varsStatus = varsFill();    //variable T/F status; -1 for uninitialized, 0 for false, 1 for true
    std::vector<int> CVL = CVL_fill(clauseList);   //clause variable list, keeps the index of each vars related to each conclusion & their required bool state

    //the following are the initializer functions
    std::vector<int> varsFill() { //initializes the varsStatus with -1 which inform the program that the variable's bool state has not been set yet
        std::vector<int> temp;
        for (int i = 0; i < varsNum; i++){
            temp.push_back(-1);
        }
        return temp;
    }    

    std::vector<int> CVL_fill(std::vector<std::vector<int>> clauseList) {
        std::vector<int> CVL_temp(maxVars * clauseNum); //sets size of the vector
        auto ref = CVL_temp.begin();
        for (int i = 0; i <= clauseNum ; i++) { //itterates through the conclusions
            ref = CVL_temp.begin() + i * maxVars; //gets the reference point within the CVL for the related conclusion
            for (int u = 0; u < maxVars; u++) { //itterates through the the spaces within the conclusions slot in the CVL
                CVL_temp.insert(ref + u, clauseList[i][u]);
            }
        }
        return CVL_temp;
    }
};
#endif