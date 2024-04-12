#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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
   else
      return -1;
}

string intToHex(int value) {
    stringstream stream;
    stream << uppercase << hex << value; 
    return stream.str(); 
}

string formatString(string s, int l){
   stringstream stream;
   stream << setfill('0') << setw(l) << s; 
   return stream.str();
}

class Process {
   private:

   public:
      int registers[4] = {0};
      int ac = 0, mdr = 0;
      string mar = "000", opcode, op1, op2, destination;
      void start_process(Memory &memory) {

         for(InstructionCell cell : memory.mems1) {

            if(cell.address != mar) { continue; }

            opcode = cell.opcode;
            op1 = cell.operand1;
            op2 = cell.operand2;
            destination = cell.destination;

            if(opcode == "00") { //mov register to register movement
               registers[getDestination(cell.destination)] = stoi(cell.operand1, 0, 16);
            } else if(opcode == "01") { //store
               //registers[getDestination(cell.destination)] = ac;

               //
               memory.store(cell.address, formatString(intToHex(ac), 11));
            } else if(opcode == "02") { //jmp
               string jumpTo = cell.destination;

               // fast forward
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
            } else if(opcode == "07"){//loads data from memory location to a general purpose register
               registers[stoi(cell.destination)] = stoi(memory.retrieve(cell.operand1));
            } 

            for(InstructionCell cell : memory.mems1) {
               if(stoi(mar) > stoi(cell.address)) {
                  continue;
               }
                  mar = cell.address;
            }
         }
      }

      void printRegisters(){
         cout << "Register1 " << registers[1] << endl;
         cout << "Register2 " << registers[2] << endl;
         cout << "Register3 " << registers[3] << endl;
         cout << "Register4 " << registers[4] << endl;
         cout << "ac " << ac << endl;
         cout << "mdr " << mdr << endl;
         cout << "mar " << mar << endl;
      }
   };