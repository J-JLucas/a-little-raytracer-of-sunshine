#include "testMatrix.h"
#include "../src/Matrix.h"
#include "../src/Tuple.h"

void testMatrix()
{
  /* Matrix A
i \ j
  |  1  |  2  |  3  |  4  |
  | 5.5 | 6.5 | 7.5 | 8.5 |
  |  9  |  10 | 11  | 12  |
  | 13.5| 14.5| 15.5| 16.5|
  */

  Matrix A(4, {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5, 15.5,
               16.5});
  assert((A(0, 0) == 1.0f) && "A[0,0] should be 1");
  assert((A(0, 3) == 4.0f) && "A[0,3] should be 4");
  assert((A(1, 0) == 5.5f) && "A[1,0] should be 5.5");
  assert((A(1, 2) == 7.5f) && "A[1,2] should be 7.5");
  assert((A(2, 2) == 11.0f) && "A[2,2] should be 11");
  assert((A(3, 0) == 13.5f) && "A[3,0] should be 13.5");
  assert((A(3, 2) == 15.5f) && "A[3,2] should be 15.5");

  Matrix B(2, {-3, 5, 1, -2});
  assert((B(0, 0) == -3.0f) && "B[0,0] should be -3");
  assert((B(0, 1) == 5.0f) && "B[0,1] should be 5");
  assert((B(1, 0) == 1.0f) && "B[1,0] should be 1");
  assert((B(1, 1) == -2.0f) && "B[1,1] should be -2");

  Matrix C(3, {-3, 5, 0, 1, -2, -7, 0, 1, 1});
  assert((C(0, 0) == -3.0f) && "C[0,0] should be -3");
  assert((C(1, 1) == -2.0f) && "C[1,1] should be -2");
  assert((C(2, 2) == 1.0f) && "C[2,2] should be 1");

  Matrix D(4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
  Matrix E(4, {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2});
  assert((D == E) && "D should be equal to E");

  Matrix F(4, {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8});
  assert((D != F) && "D should not be equal to F");

  Matrix G(
      4, {20, 22, 50, 48, 44, 54, 114, 108, 40, 58, 110, 102, 16, 26, 46, 42});

  // matrix multiplication
  assert((G == (D * F)) && "D * F should be equal to G");

  // matrix * tuple
  Matrix H(4, {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1});
  Tuple t1 = Tuple::Point(1, 2, 3);
  Tuple t2 = Tuple::Point(18, 24, 33);
  Tuple t3 = H * t1;
  assert((t3 == t2) && "H * T should be equal to T2");

  return;
}
