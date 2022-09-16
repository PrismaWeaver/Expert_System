#include <iostream>
#include <cstring>
#include "CVL.h"
#include "stack.h"
#include "queue.h"

class Chaining{
    public:
    bool prompt(int index, Knowledge *know, std::string prompt) { //general form for prompting the user, returns a bool based on the response
        char response;
        while (response != 'T' && response != 'F') { //while a correct response has not yet been entered
            std::cout << prompt << know->varsList[index] << ", please respond with T for true and F for false." << std::endl;
            std::cin >> response;
            response = toupper(response);
            if (response != 'T' && response != 'F') std::cout << "Please use either T or F as your response." << std::endl;
        }
        return (response == 'T');
    }

    std::string PG1 (int index) { //PG stands for prompt generator
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
    int backward (Backward *back) { 
        Queue concQueue, varsQueue;
        int scope = back->clauseNum * back->maxVars, ref, index, peek;
        for (int i = 0; i < scope; i++) { //fills the queue with each conclusion
            concQueue.push(i);
        }
        while (back->conclusion == -1) {
            peek = concQueue.peek();
            ref = peek * back->maxVars;
            for (int u = 0; 0 <= back->maxVars; u++) { //navigates through the CVL by variable linked to conclusion
                index = back->CVL[ref + u];
                if (index != -1) {
                    if (back->varsStatus[index] == 0) { //if a required varriable 
                        concQueue.pop();
                        break;
                    }
                    if (back->varsStatus[index] == -1) varsQueue.push(index);
                }
            }
            if (concQueue.peek() == peek) {
                while (!varsQueue.isEmpty()) {
                    index = varsQueue.peek();
                    if (prompt(index, back, PG1(index))) {
                        back->varsStatus[index] = 1;
                        varsQueue.pop();
                    }
                    else {
                        back->varsStatus[index] = 0;
                        while (!varsQueue.isEmpty()) varsQueue.pop();
                        concQueue.pop();
                    }
                }
            }
        }
    }

    //returns the index of the conclusion which can be accessed via the class object pointer sent through it, uses backwards class object to fill variable based on the conclusion
    int forward(Backward *back, Forward *forw) { 
        Forward forward;     //initialize a knowledge object of type Forward for accessing the variables, conclusions, and their relations
        forw->varsStatus[back->conclusion] = 1; //sets the variable in foward reference by the conclusion from backward to True
        
        
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