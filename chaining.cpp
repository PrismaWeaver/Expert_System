#include "knowledge.h"
#include "stack.h"

class Chaining{
    public
    std::string forward() {
        Forward forward;     //initialize a knowledge object of type Forward for accessing the variables, conclusions, and their relations
        Stack concStack = new Stack;
        for (int i = forward.ruleNum; i > -1; i++) {
            concStack.push ((i + 1) * 10);
        }
        std::vector<int> varsNav; //for keeping the vars that need to be checked 
        std:string response;
        while (conclusion == "") { //exits the loop once the conclusion is set
            varsNav = KB[concStack.peek()];
            for (int i = 0; 0 < varsNav.size(); i++) {
                    while (know.varsStatus[varsNav[i]] == -1) {
                        std::cout << "Does this repair work: " << know.varsList[varsNav[i]] << " enter T or F" << std:endl;
                        std::cin >> response;
                        if (toupper(response) == T) know.varsStatus[varsNav[i]] = 1;
                        else if (toupper(response) == F) know.varsStatus[varsNav[i]] = 0;
                        else std::cout << "Please enter either T or F" << std:endl;
                    }
                    if (know.varsStatus[varsNav[i]] == 1) {
                        if ((i + 1) == varsNav.size()) {
                            conclusion = ""; //need to do some fancy math here to get the correct conclusion
                            break;
                        }
                        continue;
                    }
                    if (know.varsStatus[varsNav[i]] == 0) {
                        concStack.pop();
                        break;
                    }
                }
        }
        delete[] concStack;
        return conclusion;
    }
};