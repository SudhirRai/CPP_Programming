/* This code uses STACK ADT to simulate an electronic calculator that uses reverse polish notation*/
#include <iostream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
/* including stack STL library */
#include <stack>
#include "stdlib.h"
#include <cstdlib>
using namespace std;
/* Private function prototype */
void ApplyOperator(char op, stack <double> & operandStack);
void HelpCommand();
void ClearStack(stack <double> & operandStack);


/* Main Program */
int main(){
    /* Declaring a Stack of double data type */
    stack<double> operandStack;
    cout << "RPN calculator simulation (type H for help)" << endl;
    while(true){
        cout << "> " ;
        string line;
        getline(cin,line);
        char ch = toupper(line[0]);
        if(ch == 'Q'){
            break;
        }
        else if (ch == 'C'){
            ClearStack(operandStack);
        }
        else if (ch == 'H'){
            HelpCommand();
        }
        else if (isdigit(ch)){
            /* pushing an element in a stack using in-built push() function */
             operandStack.push(ch);
        }
        else {
            ApplyOperator(ch, operandStack);
        }
    }
    return 0;
}

/* define ApplyOperator */
void ApplyOperator(char op, stack <double> &operandStack){
    double result;
    double rhs;
    double lhs;
    /* Getting top element of the stack using in-built function top() */
    rhs = operandStack.top();
    cout << rhs << endl;
    /* Removing top element of the stack using in-built function pop() */
    operandStack.pop();
    lhs = operandStack.top();
    cout << lhs << endl;
    switch (op) {
        case '+' : result = lhs + rhs ; break;
        case '-' : result = lhs - rhs ; break;
        case '*' : result = lhs * rhs ; break;
        case '/' : result = lhs / rhs ; break;
        default  : cout << "Invalid operator"; break;
    }
    cout << result << endl;
    operandStack.push(result);
}
void HelpCommand(){
    cout << "Still Under construction" << endl;
}
void ClearStack(stack <double> & stack){
    while(!stack.empty()){
            /* keep removing top element of the stack until all elements are removed */
        stack.pop();
    }
}
