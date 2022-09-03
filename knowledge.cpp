#include <string>
#include <vector>

class Knowledge {
    public:
    const int varsNum = 20;         //default value for now until the actual variable number can be provided
    const int ruleNum = 30;     //default value for now until the actual rule numbers can be provided

    //the following have their values pre-defined
    std::vector<std::string> varsList = {/*a list of all automobile problems*/}; //Variable list
    std::vector<std::string> conclusionList = {/*a list of all automobile problem causes*/}; //conclusion list

    /*put a series of int vectors here for each item in conclusionList which include the indexes of the problems in varsList which make up those causes*/

    std::vector<std::vector<int>> clauseList = {/*a vector of the above int vectors*/}; //clause list
    
    //the following are initialized via functions
    std::vector<int> varsStatus = varsFill();    //variable T/F status; -1 for uninitialized, 0 for false, 1 for true
    std::vector<int> CVL = CVL_fill(clauseList);   //clause variable list

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
            for (auto varsIndex : clauseList[i]) {
                CVL[ref + varsIndex] = -1;
            }
        }
        return CVL;
    }
};