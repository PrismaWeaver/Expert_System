#include <iostream>
#include <cstring>
#include "CVL.h"
#include "queue.h"

class Chaining{
    public:
    Backward back;

    std::string getConc (int index) {
        return back.conclusionList[index];
    }

    bool prompt(std::string prompt) { //general form for prompting the user, returns a bool based on the response
        char response;
        while (response != 'T' && response != 'F') { //while a correct response has not yet been entered
            std::cout << prompt << ", please respond with T for true and F for false." << std::endl;
            std::cin >> response;
            response = toupper(response);
            if (response != 'T' && response != 'F') std::cout << "Please use either T or F as your response." << std::endl;
        }
        return (response == 'T');
    }

    std::string PG1 (int index) { //PG stands for prompt generator, this one is for the backward chaining
        std::string prompt = "Is the ";
        switch (index) {
            case 0:
                prompt = "Does the problem involve ";
                break;
            case 1: 
            case 2:
            case 3:
            case 4:
            case 5:
                prompt = "Does the leaking fluid ";
                break;
            case 6: 
                prompt = "Does the issue involve a ";
                break;
            case 7:
            case 8:
                prompt = "Does your problem involve the ";
                break;
            case 9: 
                prompt = "Does the dipstick show ";
                break;
            case 10: 
                break;
            case 11:
                prompt = "Does your problem involve the ";
                break;
            case 12: 
                prompt = "Are the ";
                break;
            case 13:
                prompt = "Is there a ";
                break;
            case 14:
                prompt = "Is there an issue with ";
                break;
            case 15: 
                prompt = "Has it been ";
                break;
            case 16:
                break;
            case 17:
                prompt = "Is the problem that the car ";
                break;
            case 18: 
                break;
            case 19: 
                prompt = "Do you hear a ";
                break;
            case 20:
                prompt = "Is it ";
                break;
            case 21:
                prompt = "Do you hear a ";
                break;
            case 22:
                break;
            case 23: 
                prompt = "Will the ";
                break;
            case 24: 
                break;
            case 25: 
                prompt = "Does a fuel pressure gauge on the ";
                break;
            case 26:
            case 27:
            case 28:
                prompt = "Is there a problem with your car's ";
                break;
            case 29: 
                prompt = "Do the headlights cast ";
                break;
            case 30:
                prompt = "Is there a problem with your car's ";
                break;
            case 31:
                prompt = "Will the ";
                break;
            case 32:
                prompt = "Is there a problem with the wipers ";
                break;
            default:
                prompt = "Is the ";
                break;
        }
        return prompt;
    }

    //returns the index of the conclusion which can be accessed via the class object pointer sent through it
    int backward () { 
        std::cout << "backward chaining has begun" << std::endl;
        Queue concQueue, varsQueue;
        int scope = back.clauseNum * back.maxVars, ref, index, peek;
        std::cout << "conQueue being filled" << std::endl;
        for (int i = 0; i < scope; i++) { //fills the queue with each conclusion
            concQueue.push(i);
        }
        std::cout << "entering decision tree" << std::endl;
        while (back.conclusion == -1) { //until the conclusion is found
            peek = concQueue.peek(); //check the current conclusion being tested
            ref = peek * back.maxVars; //a reference for the index of the CVL
            for (int u = 0; 0 <= back.maxVars; u++) { //navigates through the CVL for variable indexes
                index = back.CVL[ref + u];
                std::cout << "vars related to current conclusion being gathered" << std::endl;
                if (index != -1) { //prevents out of scope
                    if (back.varsStatus[index] == 0) { //if a required varriable is false, move to the next conclusion to be tested
                        concQueue.pop();
                        while (!varsQueue.isEmpty()) varsQueue.pop(); //if previous variables had been added to the queue, this removes them
                        break;
                    }
                    if (back.varsStatus[index] == -1) varsQueue.push(index); //if a variable hasn't been found yet, add it to the stack
                }
            }
            std::cout << "vars with unset states being gathered now" << std::endl;
            if (concQueue.peek() == peek) { //if we are still on the current conclusion (i.e. a required variable wasnt false)
                while (!varsQueue.isEmpty()) { //until the variable queue has emptied
                    index = varsQueue.peek(); //pulls the index from the queue
                    if (prompt(PG1(index) + back.varsList[index])) { //generates a prompt for the user, if T is entered, this procs
                        back.varsStatus[index] = 1;
                        varsQueue.pop();
                    }
                    else { //if F was entered, this procs
                        back.varsStatus[index] = 0;
                        while (!varsQueue.isEmpty()) varsQueue.pop();
                        concQueue.pop();
                    }
                }
            }
            if (concQueue.peek() == peek) back.conclusion = peek; //if this is still true at this point, then we have a conclusion!
            if (concQueue.isEmpty()) back.conclusion = 16; //if all conclusions visited, sets conclusion value to 16: No Issue
        }
        return back.conclusion;
    }

    //returns the index of the conclusion which can be accessed via the class object pointer sent through it, uses backwards class object to fill variable based on the conclusion
    /* COMMENTED OUT TO TEST BACKWARD CHAINING
    int forward(Backward *back, Forward *forw) { 
        
    }
    */
};