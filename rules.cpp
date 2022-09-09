#include "rules.h"

class Rules{
    public:

    Rules();

    ~Rules() {
        delete concStack;
    }

    std::string forward() {
        Knowledge know;     //initialize a knowledge object for accessing the variables, conclusions, and their relations
        int stack[know.ruleNum];       //initialize the "stack"
        for (int i = 0; i < 30; i++) {  //fill the array with references to the index of KB that holds which variables need to be checked at each rule
            stack[i] = (i + 1) * 10;
        }
    }
    //need to add:
    //>the stack which holds the current rule being evaluated
    //a method to navigate through the stack, check the T/F status of variables
    //and prompt the user to fill in the variables reuired, and skip the rule if
    //variables are found to not match the rule, and if all variable conditions are
    //met, return the concluson whos index is pointed to by the rule # / 10
};