#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    //sample test code, might need to implement file reading to load instructions to memory sorry jasper hahahaha
    string command;
    ifstream fileIn; //input file manipulator
    string fileName = "instructionSet.txt"; //must have a .txt file in the repo that contains instructions 

    fileIn.open(fileName);
    /* Code that stores instructions to memory (preferrably unordered map) */
    fileIn.close();

    while(true){
        getline(cin, command);
        cout << command << endl;
    }
    return 0;
}
