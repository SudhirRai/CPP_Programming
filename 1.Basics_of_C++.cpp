/* This code shows basic syntax in C++ */
/* This program generate a table comparing values of n^2 and 2^n */

/* Below is the way to import C++ provided libraries.
** Here we are importing 2 libraries */
#include <iostream>
#include <iomanip>

// Always use below line to simplify many C++ statements
using namespace std;
/* declaring a constant */
// Note the constant naming convention
const int LOWER_LIMIT = 0 ;
const int UPPER_LIMIT = 12;
/* Private function prototype */
/* If main function calls a function before it is defined, you need to declare a bare bone function*/
int RaiseIntToPower(int n, int k);
/* main program: Execution starts from here */
int main(){
    /* To print on the screen */
    cout << "    |    2  |    N" << endl;
    cout << "  N |    N  |    2" << endl;
    cout << "----+-------+------" << endl;
    /* For loop in C++ */
    for(int n = LOWER_LIMIT; n<= UPPER_LIMIT; n++){
        cout << setw(3) << n << " |";
        cout << setw(4) << RaiseIntToPower(n, 2) << "   |" ;
        cout << setw(5) << RaiseIntToPower(2, n) << endl;

    }
    /* main function always return 0 */
    return 0;
}
/* define generic function RaiseIntToPower */

int RaiseIntToPower(int n, int k){
    /* declaring an integer */
    int result;
    result=1;
    for(int i = 0; i<k; i++){
        result *= n;
    }
    /* returning a result */
    return result;
}
