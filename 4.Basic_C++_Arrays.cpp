/* This program shows an example of using arrays in C++ */
/* This program calculates the avg of gymnastic score using an arrays */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/* Declare constants */
const int MAX_JUDGES = 100 ;
const double MIN_SCORE = 0 ;
const double MAX_SCORE = 10.0 ;

/* Private function prototype */
/* Function to read scores from key board */
void ReadAllScores(double scores[], int nJudges) ;
/* Function to get score for each judge and the scores that fulfill certain conditions */
double GetScore(int judge) ;
/* Function to calculate average of score */
double Mean(double arrar[], int n);

/* Main Program */

int main(){
    /* Declaring an array in C++ of double data type */
    double scores[MAX_JUDGES] ;
    int nJudges;
    cout << "Enter number of judges: " ;
    cin >> nJudges ;
    if(nJudges > MAX_JUDGES){
            cout << "Error: Too many judges";
    }
    else{
        /* reading scores from key board */
        ReadAllScores(scores, nJudges);
        /* Printing Average score to the screen */
        cout << "The average score is: " << Mean(scores, nJudges) << endl;
    }
    return 0;
}

/* Define ReadAllScore */

void ReadAllScores(double scores[], int nJudges){
    for (int i = 0; i < nJudges; i++){
            /* saving score of each judge in an array */
        scores[i] = GetScore(i+1) ;
    }
}
/* define GetScore */

double GetScore(int judge){
    while(true){
        cout << "Score for judge #" << judge << ": ";
        double score;
        cin >> score;
        if(score >= MIN_SCORE && score <= MAX_SCORE){
            return score;
        }
        else{
            cout << "That score is out of range. Try again. " << endl;
        }
    }
}

/* Define Mean function */
double Mean(double arrary[], int n){
    double total = 0 ;
    for(int i = 0; i< n; i++){
        total += arrary[i];
    }
    return total/n;
}
