#include "matrixChain.h"

#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

MatrixChain::MatrixChain(int* dimensions, int num){

  this->dimensions = dimensions;
  this->num = num;

  for(int i=0;i<num;i++){
    generate_matrix(dimensions[i],dimensions[i+1]);
  }
}

void MatrixChain::generate_matrix(int rows, int cols){
  srand(time(0));

  Matrix matrix(rows, vector<int>(cols,0));
  for (int j=0;j<rows;j++){//row
    for (int k=0;k<cols;k++){//
          matrix[j][k] = rand()%NUM+1;
      }
  }
  chain.push_back(matrix);
}

//Matrix MatrixChain::multiply(Matrix a, Matrix b){
  //implement here the simple multiplication between two matrices
//}

/*
d = deminsions
n = size of N table (num)
k2 = which order of mulitplication we are choosing. I wanted to use a seperate variable
other than k to track the k value becuase k was used in the final for loop as an
iterator and I was getting confused.
*/
Matrix MatrixChain::dynamicChain(){
  Matrix N(num, vector<int>(num, -1));
  Matrix K(num, vector<int>(num, -1));
  int n = num + 1;

  for(int i = 0; i < n - 1; i++)
  {
    N[i][i] = 0;
    K[i][i] = 0;
  }
  for(int b = 1; b < (n - 1); b++)
  {
    for(int i = 0; i < (n - b - 1); i++)
    {
      int j = i + b;
      N[i][j] = 999999999;
      int k2 = 0;
      /*I made a slight change from the original algorithm here. The original algorithm
      goes to j - 1 but when I did that I would skip the very first index in the K matrix,
      which meant that everything was being compared to 999999999 which was no good.*/
      for(int k = i; k < (j); k++)
      {
        if(N[i][j] > N[i][k] + N[k+1][j] + (dimensions[i] * dimensions[k+1] * dimensions[j+1]))
        {
          N[i][j] = N[i][k] + N[k+1][j] + (dimensions[i] * dimensions[k+1] * dimensions[j+1]);
          K[i][j] = k2;
        }
        k2++;
      }
    }
  }

  cout << "Min steps = " << N[0][num-1] << endl;
  cout << "K value = " << K[0][num-1] << endl << endl;

  return N;
}
