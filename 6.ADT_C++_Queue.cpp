/*  This code shows usage of Queue ADT */
/* In this example we simulate retail store queue @billing counter */
#include <iostream>
#include <iomanip>

/* Including Queue Library provided by C++ STL */
#include <queue>
using namespace std;
/* Simulation parameters */

const int SIMULATION_TIME = 1000;
const double ARRIVAL_PROBABILITY = 0.2;
const int MIN_SERVICE_TIME = 5;
const int MAX_SERVICE_TIME = 15;
/* Private Function Prototype */
/* These functions are used to randomize the simulation */
int RandomInteger(int low, int high);
double RandomReal(double low, double high);
bool RandomeChance(double p);
void Randomize();
/* this is core function to run simulations */
void RunSimulation();
void ReportResults(int nServed, long totalWait, long totalLemgth);


/* Main Program */
int main(){
    /* Using randomize function to randomize entire simulation */
    Randomize();
    /* Run the simulation */
    RunSimulation();
    return 0;
}
/* Define all functions here */
int RandomInteger(int low, int high){
    /* Using in-built function Rand() to generate random integer */
    double d = double(rand()) / (double(RAND_MAX) + 1);
    int k = int(d * (high - low +1));
    return low + k;
}
double RandomReal(double low, double high){
    /* Using in-built function Rand() to generate random real number */
    double d = double(rand()) / (double(RAND_MAX) + 1);
    return low + d * (high -low);
}
 bool RandomeChance(double p) {
     /* Using in-built function Rand() to generate random probability  */
     /* This probability will be used to decide if user needs to be added to queue or not */
    return RandomReal(0,1) < p ;
 }

 void Randomize(){
    srand(int(time(NULL)));
 }

void RunSimulation(){
    queue<int> retailQueue ;
    int ServiceTimeRemaining = 0;
    int nServed =  0;
    long totalWait = 0;
    long totalLength = 0;
    for (int t = 0; t < SIMULATION_TIME; t++){
        if (RandomeChance(ARRIVAL_PROBABILITY)){
            retailQueue.emplace(t);
        }
        if (ServiceTimeRemaining > 0){
            ServiceTimeRemaining--;
            if(ServiceTimeRemaining == 0) nServed++;
        }
        else if(!retailQueue.empty()){
            totalWait += t - retailQueue.front();
            ServiceTimeRemaining = RandomInteger(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
            }
            totalLength = retailQueue.size();
    }
    ReportResults(nServed, totalWait, totalLength);
}


void ReportResults(int nServed, long totalWait, long totalLemgth){
    cout << "Simulation results given the following parameters:" << endl;
//    cout << fixed() << steprecision(2);
    cout << " SIMULATION_TIME: " << setw(4) << SIMULATION_TIME << endl;
    cout << " ARRIVAL_PROBABILITY: " << setw(4) << ARRIVAL_PROBABILITY << endl;
    cout << " MIN_SERVICE_TIME: " << setw(4) << MIN_SERVICE_TIME << endl;
    cout << " MAX_SERVICE_TIME: " << setw(4) << MAX_SERVICE_TIME << endl;
    cout << endl;
    cout << "Customers Served:  " << setw(4) << nServed << endl;
    cout << "Average waiting time " << setw(7) << double(totalWait) / nServed << endl;
    cout << "Average queue length: " << setw(7) << double(totalLemgth) / SIMULATION_TIME << endl;
}
