/* This program shows example of functions and their usage in C++ */

/* This program calculates the roots of a quadratic equation */

#include <iostream>
#include <iomanip>

/* This is math library. This is needed for mathematical calculations */
#include <cmath>
using namespace std;

/* declare private function prototype */

/* & is used to pass variables by reference to a function */
void GetCoefficients(double & a, double & b, double & c);
/* x1, x2 pass by reference */
void SolveQuadratic(double a, double b, double c, double & x1, double & x2);

/* Pass variables by value example */
void DisplayRoots(double x1, double x2);

/* main program */

int main(){
    /* Declaring multiple double variables in single line */
    double a, b, c, r1, r2;
    /* Calling functions in C++ */
    GetCoefficients(a,b,c);
    SolveQuadratic(a,b,c,r1,r2);
    DisplayRoots(r1, r2);
    return 0;
}

/* define functions in C++ */
/* Notice that return type is Void as the function get variable by reference */
/* Due to this all changes are at the memory address of the variable itself */
 void GetCoefficients(double & a, double & b, double & c){
    cout << "Enter coefficients for quadratic equation:" << endl;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;
}

/* define Solve quadratic */
void SolveQuadratic(double a, double b, double c, double & x1, double & x2){
    double disc;
    /* Example of if-else in C++ */
    if(a==0){
        cout << "Error: Coeficient a must be non-zero" << endl;
        //break;
    }
    else {
            disc = b * b - 4 * a * c;
    }
    if(disc <0){
        cout << "Error: The solutions are complex numbers" << endl;
        //break;
    }
    else {
        /* sqrt() is a function in cmath library */
        double sqrtDisc = sqrt(disc);
        x1 = (-b + sqrtDisc) / (2 * a);
        x2 = (-b - sqrtDisc) / (2 * a);

    }

}
/* define Display Roots function */
void DisplayRoots(double x1, double x2){
    if(x1 == x2){
        cout << " There is double root at " << x1 << endl;
        }
        else {
            cout << "The roots are " << x1 << " and " << x2 << endl;
        }

    }
