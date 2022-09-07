#include <vector>
#include <string>
#include <map>
#include "knowledge.cpp"

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

    std::map<int, std::vector<int>> KB_fill(std::vector<int> rule, std::vector<std::vector<int>> vars) {
        std::map<int, std::vector<int>> ruleVars;
        for (int i = 0; i < rule.size(); i++) {
            ruleVars[rule[i]] = vars[i];
        }
        return ruleVars;
    }
    public:
    //need to add:
    //>the stack which holds the current rule being evaluated
    //a method to navigate through the stack, check the T/F status of variables
    //and prompt the user to fill in the variables reuired, and skip the rule if
    //variables are found to not match the rule, and if all variable conditions are
    //met, return the concluson whos index is pointed to by the rule # / 10
};