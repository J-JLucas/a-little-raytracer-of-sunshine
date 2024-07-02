#include "testMatrix.h"
#include "../src/Matrix.h"
#include <iostream>

void testMatrix()
{
  /* Matrix A
i \ j
  |  1  |  2  |  3  |  4  |
  | 5.5 | 6.5 | 7.5 | 8.5 |
  |  9  |  10 | 11  | 12  |
  | 13.5| 14.5| 15.5| 16.5|
  */

  Matrix B(4);
  B(0, 0) = 1.0f;
  assert((B(0, 0) == 1.0f) && "B[0,0] should be 1");

  Matrix A(4, {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5, 15.5,
               16.5});
  assert((A(0, 0) == 1.0f) && "A[0,0] should be 1");
  assert((A(0, 3) == 4.0f) && "A[0,3] should be 4");
  assert((A(1, 0) == 5.5f) && "A[1,0] should be 5.5");
  assert((A(1, 2) == 7.5f) && "A[1,2] should be 7.5");
  assert((A(2, 2) == 11.0f) && "A[2,2] should be 11");
  assert((A(3, 0) == 13.5f) && "A[3,0] should be 13.5");
  assert((A(3, 2) == 15.5f) && "A[3,2] should be 15.5");

  A.print();

  return;
}
