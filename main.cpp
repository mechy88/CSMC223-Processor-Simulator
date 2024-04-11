#include <iostream>
#include <string>
#include <map>
#include <list>
#include "./pseudo-hardware/memory.cpp"

using namespace std;

/*
TODO:
- Implement Memory
- Make print function to check memory contents
*/


int main(){
    //sample test code, might need to implement file reading to load instructions to memory sorry jasper hahahaha
    string command;

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