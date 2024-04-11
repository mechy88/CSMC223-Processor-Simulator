#include <iostream>
#include <string>
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

class Process {
   private:

   public:
      void start_process() {
         int registers[4] = {0};
         int ac = 0, mdr = 0;
         string mar = "000", opcode, op1, op2, destination;

         /* Need q iaccess InstructionCell from the main.cpp thru this file para makuha ang data sa memory... HELP */

         for(InstructionCell cell : mems1) {

            if(cell.address != mar) { continue; }

            opcode = cell.opcode;
            op1 = cell.operand1;
            op2 = cell.operand2;
            destination = cell.destination;

            if(opcode == "00") { //mov
               registers[getDestination(cell.destination)] = stoi(cell.operand1, 0, 16);
            } else if(opcode == "01") { //store
               registers[getDestination(cell.destination)] = ac;
            } else if(opcode == "02") { //jmp
               string jumpTo = cell.destination;

               for(InstructionCell loc : mems1) { //logic error here sorry
                  if(loc.destination = jumpTo) {
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

            //mar should update here b4 next iteration
            
         }
      }
};