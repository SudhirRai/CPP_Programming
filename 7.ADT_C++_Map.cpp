/* This code shows use of map ADT in C++ */
#include <iostream>
#include <fstream>
#include <string>
/* Include Map library  */
#include <map>
using namespace std;

/* Private function prototype */

void ReadCodeFile( map <string, string> & m, string prompt);
bool containsKey(map<string, string> m, string key);

/* Main Program */

int main() {
    /* Declaring Map variable of string type */
    /* Double, float etc type of Map variables can be declared similarly */
    map <string, string> airportCodes;
    /* Give file name and full path which contains airport codes */
    ReadCodeFile(airportCodes, "Input file: ");
    while (true){
        cout << "Airport code: ";
        string code;
        /* Reading airport code from key board */
        cin >> code;
        if (code =="Q") break;
        /* Checking if code is present in Map */
        if (containsKey(airportCodes,code)){
            cout << code << " is in " << airportCodes.at(code) << endl;
        } else {
            cout << "There is no such airport code" << endl;
        }

    }
    return 0;
}
// Function to check if the key is present or not
bool containsKey(map<string, string> m, string key)
{
    // Key is not present
    if (m.find(key) == m.end())
        return false;

    else return true;
}

/* Read Data file and store airport code and description in a Map */
/* Notice that a map is passed by reference to the function */
void ReadCodeFile( map <string, string> & m, string prompt){
    ifstream infile;
    cout << prompt;
    string filename;
    cin >> filename;
    infile.open(filename.c_str());
    if (infile.fail()){
        cout << "Error: can't read data file" << endl;
    }
    while(true){
        string line;
        getline(infile, line);
        if (infile.fail()) break;
        if(line.length() < 5 || line[4] != '='){
            cout << "Error Illegal data file line: " + line;
        }
        string code = line.substr(0,4);
        /* insert key values in the Map */
        m.insert({ code, line.substr(5)});

    }
}
