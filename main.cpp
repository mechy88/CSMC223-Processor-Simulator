#include <iostream>
#include <string>
#include <map>
#include <list>
#include "./pseudo-hardware/memory.cpp"
#include <fstream>
#include <list>

using namespace std;

/*
TODO:
- Implement Memory
- Make print function to check memory contents
*/


int main(){
    //sample test code, might need to implement file reading to load instructions to memory sorry jasper hahahaha
    string command;
    ifstream fileIn; //input file manipulator
    string fileName = "instructionSet.txt"; //must have a .txt file in the repo that contains instructions 

    fileIn.open(fileName);
    /* Code that stores instructions to memory (preferrably list of structs) */
    fileIn.close();

    // load instructions to memory

    //don't stop the beating

    // for testing
    // while(true){
    //     getline(cin, command);
    //     cout << command << endl;
    // }

    //testing memory
    Memory memory;
    memory.mems1.push_back(InstructionCell("000", "1F", "943", "24A", "AAF"));
    memory.mems1.push_back(InstructionCell("001", "20", "777", "345", "FAA"));
    memory.mems2.push_back(DataCell("FBB", "12345678912"));

    memory.printMemory();
    return 0;
}
