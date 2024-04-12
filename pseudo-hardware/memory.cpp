#include <string>
#include <map>
#include <list>
#include <iostream>

using namespace std;

class Cell;
class InstructionCell;
class DataCell;

class Cell{
private:

public:
    string address;
};

class InstructionCell : public Cell{
private:

public:
    string opcode;
    string operand1;
    string operand2;
    string destination;

    InstructionCell(){
        address = "###";
        opcode = "##";
        operand1 = "###";
        operand2 = "###";
        destination = "###";
    }

    InstructionCell(string add, string op, string oper1, string oper2, string desti){
        address = add;
        opcode = op;
        operand1 = oper1;
        operand2 = oper2;
        destination = desti;
    }

    string returnOutput(){
        return (address + " " + opcode + operand1 + operand2 + destination);
    }
};

class DataCell : public Cell{
private:
    
public:
    string data;

    DataCell(){
        address = "###";
        data = "###########";
    }

    DataCell(string add, string d){
        address = add;
        data = d;
    }
    
    string returnOutput(){
        return (address + " " + data);
    }

};

class Memory{
private:
    
public:
    list<InstructionCell> mems1; //memory locations 000 - 7FF
    list<DataCell> mems2; //memory locations 800 - FFF

    void printMemory(){

        for(InstructionCell cell : mems1){
            cout << cell.returnOutput() << endl;
        }
        for(DataCell cell : mems2){
            cout << cell.returnOutput() << endl;
        }
        
    }

    void store(string add, string instance_data){
        mems2.push_back(DataCell(add, instance_data));
    }

    string retrieve(string address){
        for(DataCell cell : mems2){
            if(cell.data == address){
                return cell.data;
            }
        }
        return "###";
    }
};