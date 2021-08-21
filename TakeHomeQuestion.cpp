#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(std::vector<int> input_matrix) {
  int matrix_size, i;
  // Please write your code here.
  //first element of array corresponds to the size of the input square matrix
  matrix_size = input_matrix[0];
 
  for (i=matrix_size+1; i<(input_matrix.size()); i++)
  {     /*Excludes all the elements in the first row and column and computes other elements of the matrix*/
        if(i% matrix_size!=1)
        {//checks if the element in this position is '1'
          if(input_matrix[i]==1)
          {
           input_matrix[i]=min((min(input_matrix[i-1],input_matrix[i-matrix_size])),input_matrix[i-matrix_size-1])+1;
          }
        }
  }
  /* the biggest element in the array will be the size of the largest square submatrix that can be formed .*/
  int submatrix_size = *max_element(input_matrix.begin()+1,input_matrix.end());

  return submatrix_size;
}

int main() {
  /*
  Hey,
  you are given following task:
  You have a square matrix with only "0" and "1" entries. How big is the largest square submatrix,
  whose elements are all "1"? The matrix is provided as a vector of integers, whereby the first
  value corresponds to the size "n" of the square matrix followed by the entries row-wise, e.g. the
  input [3,0,1,1,0,1,1,0,1,0] corresponds to following matrix:
  [0,1,1]
  [0,1,1]
  [0,1,0]
  In this case, the biggest square submatrix containing only "1" has size "2" (the upper right
  submatrix), so that the expected return value is "2". You can test your code against a couple of
  test cases.

  Please code as you would code for a final review of your work!
  */
  assert(2== solution({3, 0, 1, 1, 0, 1, 1, 0, 1, 0}));
  cout<<"Largest square submatrix has size 2"<<endl;
  assert(3== solution({3, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  cout<<"Largest square submatrix has size 3"<<endl;
  assert(4== solution({4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  cout<<"Largest square submatrix has size 4"<<endl;
  assert(1 == solution({4, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0}));
  cout<<"Largest square submatrix has size 2"<<endl;
  assert(3 == solution({4, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0}));
  cout<<"Largest square submatrix has size 3"<<endl;
  assert(0 == solution({2, 0, 0, 0, 0}));
  cout<<"Largest square submatrix has size 0"<<endl;
  assert(1 == solution({1, 1}));
  cout<<"Largest square submatrix has size 1"<<endl;
  assert(0 == solution({1, 0}));
  cout<<"Largest square submatrix has size 0"<<endl;

  return 0;
}
