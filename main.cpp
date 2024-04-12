#include <iostream>
#include <string>
#include <map>
#include <list>
#include "./pseudo-hardware/cpu.cpp"
#include <fstream>

using namespace std;

int main(){
    ifstream fileIn; 
    string fileName = "trialRun.txt";

    string address, opcode, op1, op2, destination;

    fileIn.open(fileName);
    /* Code that stores instructions to memory */
    Memory memory;
    Process cpu;

    while(fileIn >> address >> opcode >> op1 >> op2 >> destination){
      memory.mems1.push_back(InstructionCell(address, opcode, op1, op2, destination));
    }
    fileIn.close();
    memory.printMemory();
    cpu.printRegisters(cpu);
    
    cout << endl;

    cpu.start_process(memory);

    memory.printMemory();
    cpu.printRegisters(cpu);
    return 0;
}
