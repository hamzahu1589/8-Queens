#include <iostream>
#include <cmath>
using namespace std;
// NQueens Assignment

//Basic 1D Ok Function involving all the basic checks.
bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i) //Row Test and Diagonal Test
         return false;
   return true;
}
//Find solution
int nqueens(int n) {
   //Array to show queens position in every collum
   int* q = new int[n];
   q[0] = 0;
   int c = 0, solutions = 0;
   // Continue the loop as long as there are columns to explore.
   while (c >= 0) {
       //If we reach the last collumn we essentially backtrack
      if (c == n - 1) {
         ++solutions;
         --c;
      }
      
      else
         q[++c] = -1;
          //Searching for solutions through the collumns
      while (c >= 0) {
         ++q[c];
         //If all rows in the current collumn are passed through we must go back
         if (q[c] == n)
            --c;
         else if (ok(q, c))
         //Once the placement is good we break out
            break;
      }
   }
   delete[] q; // Deallocate free up memory.
   
   return solutions;
}

int main() {
    // Main Function
   //Declare Variable
   int numberOfQueens;
   //Ask user input
   cout<<"Enter Number of Queens: ";
  //For loop to print out the number of solutions from 1 until the number inputed or even one itself
   cin>>numberOfQueens;
   for (int i = 1; i <= numberOfQueens; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
