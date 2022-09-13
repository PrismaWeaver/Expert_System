#include <string>
#include <vector>
#include <map>

/*CVL is a vector which has a size = # of rules * # of conclusions and
is filled with what variables lead to each conclusion in order of their
appearance. varsStatus contains the empty/T/F status of each variable to 
compare to, which has the same index for the variables in varsList.*/

//base class to be inherrited by the forward and backward base
class Knowledge {
    public:
    const int varsNum = 20;     //default value for now until the actual variable number can be provided
    const int ruleNum = 30;     //default value for now until the actual rule numbers can be provided
    Stack concStack = new stack; //the stack which will hold each of the rules that need to be evaluated 
    std::string conclusion = ""; //what this whole thing returns eventually

    //the following have their values pre-defined in the subclasses
    std::vector<std::string> varsList; //list of named variables in hierarchy order within rules
    std::vector<std::string> conclusionList; //list of all named conclusions to be pushed to conclusion and returned
    //each conclusion should also have its own int vector that contains the 
    std::vector<std::vector<int>> clauseList; //contains a list of conclusions which contain the index of each variable related to said conclusion
    std::vector<int> conclusionIndex; 
    std::vector<std::vector<int>> varsCombo;

    //the following are initialized via functions
    std::vector<int> varsStatus = varsFill();    //variable T/F status; -1 for uninitialized, 0 for false, 1 for true
    std::vector<int> CVL = CVL_fill(clauseList);   //clause variable list
    std::vector<int> ruleCount = rule_fill(); //half of the knowledge base
    std::map<int, std::vector<int>> KB = KB_fill(ruleCount, varsCombo); //the knowledge base, weird this is in the rules class aint it?

    //the following are the initializer functions
    std::vector<int> varsFill() {
        std::vector<int> temp;
        for (int i = 0; i < varsNum; i++){
            temp.push_back(-1);
        }
        return temp;
    }
    std::vector<int> CVL_fill(std::vector<std::vector<int>> clauseList) {
        int clauseNum = clauseList.size(), ref;
        std::vector<int> CVL(ruleNum * clauseNum);
        for (int i = 0; i < clauseNum; i++) {
            ref = i * ruleNum;
            for (int u = 0; 0 < clauseList[i].size(); u++) {
                CVL[ref + u] = clauseList[i][u];
            }
        }
        return CVL;
    }

    std::map<int, std::vector<int>> KB_fill(std::vector<int> rule, std::vector<std::vector<int>> vars) {
        std::map<int, std::vector<int>> ruleVars;
        for (int i = 0; i < rule.size(); i++) {
            ruleVars[rule[i]] = vars[i];
        }
        return ruleVars;
    }
}

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
    
}

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
    
}