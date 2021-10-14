// test_pointers.cpp
// COMPLETE include necessary headers
#include<iostream>
using namespace std;

int main(void)
{
  //
  // 1. declare a variable f as a pointer to a float
  
  float* f;
  
  // 2. create a float variable named pi, and store the value 3.14159f
  
  float pi = 3.14159f;
  
  // 3. make f points to pi
  
  f = &pi;
  
  // 4. print out the content of the memory location pointed to by f
  
  cout << "content of the memory of f is " << *f << endl << endl;

  //
  
  short a[] = {1, 2, 3, 4, 5};
  
  // 5. declare a variable ip as a pointer to a short integer
  
  short* ip;
  
  // 6. make ip points to the beginning of the array a
  
  ip = &a[0];
  
  // 7. print out what ip points to and the content of a[0] (verify they are the same)
  
  cout << "the value of ip is" << ip << endl 
    << "and, the value of a[0] is " << a[0] << endl << endl;
  
  // 8. increase ip by 3 and check that what it points to corresponds to a[3]
  
  ip+= 3;

  cout << "the value of ip is" << ip << endl 
  << "and, the value of a[3] is " << a[3] << endl << endl;
  
  // 9. make ip points to the last element of the array by increasing it by 1
  
  ip++;

  cout << "the value of ip is" << ip << endl;
  
  //     and check that what it points to corresponds to a[4]
  
  cout << "and, the value of a[4] is " << a[4] << endl << endl;



  // 
  
  int n = 10;
  int i;
  
  // 10. declare a variable d as a pointer to double and 
  // make it point to an array of "n" element of type "double" created on the heap
  double* d;

  d = (double *)malloc(n * sizeof(double));

  // 11. store in each d[i] (for i=0 to n-1) the value double(i) / 5.0;
  for(i = 0; i < n-1; i++)d[i] = double(i) /5.0;
  // 12. print out each element of d
  for(i = 0; i < n-1; i++)cout << "the element of d is " << d[i] << endl;
  // 13. delete the previously allocated memory
  free(d);
  //
  int m = 5;
  n = 20;
  double** dd;
  // 14. allocate memory for a 2d array of size m * n on the heap (i.e. m arrays of size n).  
  
  
  // Make dd points to this 2d array.
  
  
  // 15. set the element dd[i][j] to be equal to double(i)*double(j)
  
  
  // 16. delete the memory allocated for the 2d array

  return 0;
}
