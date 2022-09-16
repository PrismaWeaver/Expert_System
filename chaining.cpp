#include "CVL.h"
#include "stack.h"

class Chaining{
    private:
    std::string prompt(int index, Knowledge know) {
        std::string response = "";
        while (response != "T" || response != "F") {
            std::cout << "enter prompt for variable here: " << know.varsList[index] << " please respond with T for true and F for false." << std::endl;
            std::cin << response;
            toupper(response);
            if (response != "T" || response != "F") std::cout << "Please use either T or F in your response." << std::endl;
        }
        return response;
    }

    public:
    std::string forward() {
        Forward forward;     //initialize a knowledge object of type Forward for accessing the variables, conclusions, and their relations
        Stack concStack;;
        for (int i = forward.ruleNum; i > -1; i++) {
            concStack.push ((i + 1) * 10);
        }
        std::vector<int> varsNav; //for keeping the vars that need to be checked 
        std::string response;
        while (forward.conclusion == "") { //exits the loop once the conclusion is set
            varsNav = KB[concStack.peek()];
            for (int i = 0; 0 < varsNav.size(); i++) {
                    while (know.varsStatus[varsNav[i]] == -1) {
                        response = prompt(varsNav[i], forward);
                        if (response == T) know.varsStatus[varsNav[i]] = 1;
                        else if (response == F) know.varsStatus[varsNav[i]] = 0;
                        else std::cout << "Please enter either T or F" << std::endl;
                    }
                    if (know.varsStatus[varsNav[i]] == 1) {
                        if ((i + 1) == varsNav.size()) {
                            forward.conclusion = ""; //need to do some fancy math here to get the correct conclusion
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
        return forward.conclusion;
    }
};