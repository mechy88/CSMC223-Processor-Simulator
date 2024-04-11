#include <iostream>
#include <string>
#include <map>
#include <list>
#include "./pseudo-hardware/memory.cpp"
#include "./pseudo-hardware/cpu.cpp"
#include <fstream>

using namespace std;

/*
TODO:
- Implement Memory
- Make print function to check memory contents
*/


int main(){
    ifstream fileIn; 
    string fileName = "instructionSet.txt";

    string address, opcode, op1, op2, destination;

    fileIn.open(fileName);
    /* Code that stores instructions to memory */
    extern Memory memory;

    while(fileIn >> address >> opcode >> op1 >> op2 >> destination){
      memory.mems1.push_back(InstructionCell(address, opcode, op1, op2, destination));
    }
    fileIn.close();

    memory.printMemory();
    return 0;
}
