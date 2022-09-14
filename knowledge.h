#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H
#include <string>
#include <vector>
#include <map>
#include "data.h"

/*CVL is a vector which has a size = # of rules * # of conclusions and
is filled with what variables lead to each conclusion in order of their
appearance. varsStatus contains the empty/T/F status of each variable to 
compare to, which has the same index for the variables in varsList.*/

/*To complete:
alter KB and CVL to reference a data struct of the variable index AND the required bool state for the rule/conclusion
doing so might require a constructor which accepts values from a text file which holds the bulk data without needing to over stuff the program
*/


//base class to be inherrited by the forward and backward base
class Knowledge {
    public:

    const int varsNum = varsList.size();     //keeps the number of vars as its own accessible variable
    const int ruleNum = 30;     //default value for now until the actual rule numbers can be provided
    int clauseNum = clauseList.size();   //keeps number of conclusions as its own accessible variable
    int maxVars = 4;  //a number related to the max number of variables related to a single conclusion or rule
    std::string conclusion = ""; //what this whole thing returns eventually

    //the following have their values pre-defined in the subclasses
    std::vector<std::string> varsList; //list of named variables in hierarchy order within decision tree
    std::vector<std::string> conclusionList; //list of all named conclusions to be pushed to conclusion and returned in order of appearance in the CVL
    //each conclusion should also have its own int vector that contains the 
    std::vector<std::vector<int>> clauseList; //contains a list of conclusions which contain data structs which include the varsIndex and their required bool state for it to be true

    //the following are initialized via functions
    std::vector<int> varsStatus = varsFill();    //variable T/F status; -1 for uninitialized, 0 for false, 1 for true
    std::vector<int> CVL = CVL_fill(clauseList);   //clause variable list, keeps the index of each vars related to each conclusion & their required bool state
    std::vector<int> ruleCount = rule_fill(); //half of the knowledge base, just intervals of 10
    std::map<int, std::vector<int>> KB = KB_fill(ruleCount, varsCombo); //the knowledge base

    //the following are the initializer functions
    std::vector<int> varsFill() {
        std::vector<int> temp;
        for (int i = 0; i < varsNum; i++){
            temp.push_back(-1);
        }
        return temp;
    }
    std::vector<int> rule_fill() {
        std::vector<int> rule_temp;
        for (int i = 0; i < ruleNum; i++) {
            rule_temp.push_back((i + 1) * 10);
        }
        return rule_temp;
    }

    std::vector<int> CVL_fill(std::vector<std::vector<int>> clauseList) {
       int ref;
        std::vector<int> CVL_temp(maxVars * clauseNum);
        for (int i = 0; i < clauseNum; i++) {
            ref = i * maxVars;
            for (int u = 0; 0 < clauseList[i].size(); u++) {
                CVL_temp[ref + u] = clauseList[i][u];
            }
        }
        return CVL_temp;
    }

    std::map<int, std::vector<int>> KB_fill(std::vector<int> rule, std::vector<std::vector<int>> vars) {
        std::map<int, std::vector<int>> ruleVars;
        for (int i = 0; i < rule.size(); i++) {
            ruleVars[rule[i]] = vars[i];
        }
        return ruleVars;
    }
};

class Forward: public Knowledge {
    public:
    std::vector<std::string> varsList; //list of named variables in hierarchy order within rules
    std::vector<std::string> conclusionList; //list of all named conclusions to be pushed to conclusion and returned
    //each conclusion should also have its own int vector that contains the 
    std::vector<std::vector<int>> clauseList;
    std::vector<int> conclusionIndex; 
    std::vector<std::vector<int>> varsCombo;

    std::vector<std::string> varsList = {/*a list of all automobile problems*/}; //Variable list
    std::vector<std::string> conclusionList = {/*a list of all automobile problem causes*/}; //conclusion list

    /*put a series of int vectors here for each item in conclusionList which include the indexes of the problems in varsList which make up those causes*/

    std::vector<std::vector<int>> clauseList = {/*a vector of the above int vectors*/}; //clause list
    
};

class Backward: public Knowledge {
    public:
    std::vector<std::string> varsList; //list of named variables in hierarchy order within rules
    std::vector<std::string> conclusionList; //list of all named conclusions to be pushed to conclusion and returned
    //each conclusion should also have its own int vector that contains the 
    std::vector<std::vector<int>> clauseList;
    std::vector<int> conclusionIndex; 
    std::vector<std::vector<int>> varsCombo;

    std::vector<std::string> varsList = {/*a list of all automobile problems*/}; //Variable list
    std::vector<std::string> conclusionList = {/*a list of all automobile problem causes*/}; //conclusion list

    /*put a series of int vectors here for each item in conclusionList which include the indexes of the problems in varsList which make up those causes*/

    std::vector<std::vector<int>> clauseList = {/*a vector of the above int vectors*/}; //clause list
    
};
#endif