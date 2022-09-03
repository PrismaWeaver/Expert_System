#include <vector>
#include <string>
#include <map>
#include "knowledge.cpp"
/**/
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

};