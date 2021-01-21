/* This code shows usage of SENTINEL to break out of a loop in C++ */
/* This program adds list of numbers entered via key-board and terminates when encounters a a SENTINEL */

/* iosstream library is needed to read data from command prompt */
#include <iostream>
#include <iomanip>
using namespace std;

/* Sentinel declaration */
const int SENTINEL = 0;
/* main program */
int main(){
    cout << "This program adds a list of numbers. " << endl;
    cout << "Use " << SENTINEL << " to signal the end. " << endl;
    int total =0;
    while(true){
        cout << " ? ";
        /* declaring a variables to store data entered via command prompt */
        int value;
        /* cin is used to accept data from user via command prompt */
        cin >> value;
        /* Break out of the loop if value matches with SENTINEL */
        if(value == SENTINEL) break;
        /* Keep adding elements till encounter a SENTINEL */
        total += value;
    }
    cout << "The total is " << total << endl;
}
