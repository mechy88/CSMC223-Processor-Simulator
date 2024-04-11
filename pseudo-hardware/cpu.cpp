#include <iostream>
#include <string>
#include <sstream>
#include "./memory.cpp"

using namespace std;

//converts string to int that's used just for array indexing
int getDestination(string desti) {
   if(desti == "000")
      return 0;
   else if(desti == "001") 
      return 1;
   else if(desti == "002")
      return 2;
   else if(desti == "003")
      return 3;
}

string intToHex(int value) {
    stringstream stream;
    stream << uppercase << hex << value; 
    return stream.str(); 
}

class Process {
   private:

   public:
      void start_process(Memory memory) {
         int registers[4] = {0};
         int ac = 0, mdr = 0;
         string mar = "000", opcode, op1, op2, destination;

         for(InstructionCell cell : memory.mems1) {

            if(cell.address != mar) { continue; }

            opcode = cell.opcode;
            op1 = cell.operand1;
            op2 = cell.operand2;
            destination = cell.destination;

            if(opcode == "00") { //mov
               registers[getDestination(cell.destination)] = stoi(cell.operand1, 0, 16);
            } else if(opcode == "01") { //store
               //registers[getDestination(cell.destination)] = ac;

               memory.store(cell.address, intToHex(ac));
            } else if(opcode == "02") { //jmp
               string jumpTo = cell.destination;

               for(InstructionCell loc : memory.mems1) { 
                  if(loc.destination == jumpTo) {
                     mar = jumpTo; 
                     break;
                  }
               }
            } else if(opcode == "03") { //add
               mdr = stoi(op1);
               ac += mdr;
            } else if(cell.opcode == "04") { //sub
               mdr = stoi(op1);
               ac -= mdr;
            } else if(opcode == "05") { //mul
               mdr = stoi(op1);
               ac *= mdr;
            } else if(opcode == "06") { //div
               mdr = stoi(op1);
               ac /= mdr;
            }

            for(InstructionCell cell : memory.mems1) {
               if(stoi(mar) > stoi(cell.address)) {
                  continue;
               }
                  mar = cell.address;
            }
         }
      }
};