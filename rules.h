#include <vector>
#include <string>
#include <map>
#include "knowledge.h"
#include "stack.h"

#ifndef RULES_H
#define RULES_H

/*the knowledge base is filled with the multiple of 10 equal to the rule and
the indexes of the variables required to be true (whos value can be input into
varsStatus from the knowledge.cpp to get said T/F status)*/

class Rules{
    private:
    std::string conclusion = ""; //what this whole thing returns eventually
    std::vector<int> ruleCount = {/*multiples of ten for each rule node*/}; //half of the knowledge base
    std::vector<int> conclusionIndex = {/*index of conclusions in conclusionList (see knowledge.cpp) relevant to each rule in ruleCount*/}; //used for reference to knowledge class obj
    std::vector<std::vector<int>> varsCombo = {
        {/*required variables for rule at each index to be satisfied*/}
    }; //the other half of the knowledge base
    std::map<int, std::vector<int>> KB = KB_fill(ruleCount, varsCombo); //the knowledge base, weird this is in the rules class aint it?
    Stack concStack = new stack; //the stack which will hold each of the rules that need to be evaluated 

    std::map<int, std::vector<int>> KB_fill(std::vector<int> rule, std::vector<std::vector<int>> vars) {
        std::map<int, std::vector<int>> ruleVars;
        for (int i = 0; i < rule.size(); i++) {
            ruleVars[rule[i]] = vars[i];
        }
        return ruleVars;
    }

    public:
    Rules();
    ~Rules();
    std::string forward();
}

#endif