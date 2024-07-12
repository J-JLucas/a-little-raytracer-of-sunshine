#include "testMatrix.h"
#include "../src/Matrix.h"
#include "../src/Tuple.h"

void testMatrix1()
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

  // identity matrix
  Matrix I(4, {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1});
  Matrix J(4, {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32});

  assert((I * J == J) && "I * J should be equal to J");
  assert((I * t1 == t1) && "I * t1 should be equal to t1");

  // transpose
  Matrix K(4, {0, 9, 3, 0, 9, 8, 0, 8, 1, 8, 5, 3, 0, 0, 5, 8});
  Matrix L(4, {0, 9, 1, 0, 9, 8, 8, 0, 3, 0, 5, 5, 0, 8, 3, 8});

  assert((K.transpose() == L) && "K.Transpose() should be equal to L");

  // 2x2 determinate
  Matrix M(2, {1, 5, -3, 2});

  assert((M.determinate() == 17) && "M.determinate() should be 17");

  // submatrix
  Matrix N(3, {1, 5, 0, -3, 2, 7, 0, 6, -3});
  Matrix O(2, {-3, 2, 0, 6});

  assert((Matrix::submatrix(N, 0, 2) == O) &&
         "N.submatrix(0,2) should be equal to O");

  Matrix P(4, {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1});
  Matrix Q(3, {-6, 1, 6, -8, 8, 6, -7, -1, 1});

  assert((Matrix::submatrix(P, 2, 1) == Q) &&
         "P.submatrix(2,1) should be equal to Q");

  // minor
  Matrix R(3, {3, 5, 0, 2, -1, -7, 6, -1, 5});

  assert((Matrix::submatrix(R, 1, 0).determinate() == 25) &&
         "R.submatrix(1,0).determinate should be equal to 25");
  assert((Matrix::minor(R, 1, 0) == 25) &&
         "R.minor(1,0) should be equal to 25");

  // cofactor
  assert((Matrix::minor(R, 0, 0) == -12) &&
         "R.minor(0,0) should be equal to -12");
  assert((Matrix::cofactor(R, 0, 0) == -12) &&
         "R.cofactor(0,0) should be equal to -12");
  assert((Matrix::minor(R, 1, 0) == 25) &&
         "R.minor(1,0) should be equal to 25");
  assert((Matrix::cofactor(R, 1, 0) == -25) &&
         "R.cofactor(1,0) should be equal to -25");

  // determinate 3x3, 4x4
  Matrix S(3, {1, 2, 6, -5, 8, -4, 2, 6, 4});

  assert((Matrix::cofactor(S, 0, 0) == 56) &&
         "S.cofactor(0,0) should be equal to 56");
  assert((Matrix::cofactor(S, 0, 1) == 12) &&
         "S.cofactor(0,1) should be equal to 12");
  assert((Matrix::cofactor(S, 0, 2) == -46) &&
         "S.cofactor(0,2) should be equal to -46");
  assert((S.determinate() == -196) &&
         "S.determinate() should be equal to -196");

  Matrix T(4, {-2, -8, 3, 5, -3, 1, 7, 3, 1, 2, -9, 6, -6, 7, 7, -9});

  assert((Matrix::cofactor(T, 0, 0) == 690) &&
         "T.cofactor(0,0) should be equal to 690");
  assert((Matrix::cofactor(T, 0, 1) == 447) &&
         "T.cofactor(0,1) should be equal to 447");
  assert((Matrix::cofactor(T, 0, 2) == 210) &&
         "T.cofactor(0,2) should be equal to 210");
  assert((Matrix::cofactor(T, 0, 3) == 51) &&
         "T.cofactor(0,3) should be equal to 51");
  assert((T.determinate() == -4071) &&
         "T.determinate() should be equal to -4071");

  // check invertible
  Matrix U(4, {6, 4, 4, 4, 5, 5, 7, 6, 4, -9, 3, -7, 9, 1, 7, -6});

  assert((U.determinate() == -2120) &&
         "U.determinate() should be equal to -2120");
  assert((U.invertible()) && "U should be invertible");

  Matrix V(4, {-4, 2, -2, -3, 9, 6, 2, 6, 0, -5, 1, -5, 0, 0, 0, 0});

  assert((V.determinate() == 0) && "V.determinate() should be equal to 0");
  assert((!V.invertible()) && "V should not be invertible");

  // invert matrix
  Matrix W(4, {-5, 2, 6, -8, 1, -5, 1, 8, 7, 7, -6, -7, 1, -3, 7, 4});
  Matrix W_i = W.inverse();
  Matrix X(4, {0.21805, 0.45113, 0.24060, -0.04511, -0.80827, -1.45677,
               -0.44361, 0.52068, -0.07895, -0.22368, -0.05263, 0.19737,
               -0.52256, -0.81391, -0.30075, 0.30639});

  assert((W.determinate() == 532) && "W.determinate() should be equal to 532");
  assert((Matrix::cofactor(W, 2, 3) == -160) &&
         "W.cofactor(2,3) should be equal to -160");
  assert((W_i(3, 2) == -160.0f / 532.0f) && "W_i[3,2] should be -160/532");
  assert((Matrix::cofactor(W, 3, 2) == 105) &&
         "W.cofactor(3,2) should be equal to 105");
  assert((W_i(2, 3) == 105.0f / 532.0f) && "W_i[2,3] should be 105/532");

  assert((W_i == X) && "W_i should be equal to X");

  Matrix Y(4, {8, -5, 9, 2, 7, 5, 6, 1, -6, 0, 9, 6, -3, 0, -9, -4});
  Matrix Y_i = Y.inverse();
  Matrix Z(4, {-0.15385, -0.15385, -0.28205, -0.53846, -0.07692, 0.12308,
               0.02564, 0.03077, 0.35897, 0.35897, 0.43590, 0.92308, -0.69231,
               -0.69231, -0.76923, -1.92308});

  assert((Y_i == Z) && "Y_i should be equal to Z");

  Matrix AA(4, {9, 3, 0, 9, -5, -2, -6, -3, -4, 9, 6, 4, -7, 6, 6, 2});
  Matrix AA_i = AA.inverse();
  Matrix AB(4, {-0.04074, -0.07778, 0.14444, -0.22222, -0.07778, 0.03333,
                0.36667, -0.33333, -0.02901, -0.14630, -0.10926, 0.12963,
                0.17778, 0.06667, -0.26667, 0.33333});

  assert((AA_i == AB) && "AA_i should be equal to AB");

  // multiply by inverse

  Matrix AC(4, {3, -9, 7, 3, 3, -8, 2, -9, -4, 4, 4, 1, -6, 5, -4, 1});
  Matrix AD(4, {8, 2, 2, 2, 3, -1, 7, 0, 7, 0, 5, 4, 6, -2, 0, 5});
  Matrix AE = AC * AD;
  assert((AE * AD.inverse() == AC) &&
         "AE * AD.inverse() should be equal to AC");

  return;
}

void testMatrix2()
{
  // translation
  Matrix A = Matrix::translation(5, -3, 2);
  Tuple p = Tuple::Point(-3, 4, 5);
  Tuple r1 = A * p;
  assert((r1 == Tuple::Point(2, 1, 7)) && "t2 should be equal to Point(2,1,7)");

  Matrix A_i = A.inverse();
  Tuple r2 = A_i * p;
  assert((r2 == Tuple::Point(-8, 7, 3)) &&
         "t2 should be equal to Point(-8,7,3)");

  Tuple v = Tuple::Vector(-3, 4, 5);
  Tuple r3 = A * v;
  assert((r3 == v) && "t3 should be equal to v");

  // scaling
  Matrix B = Matrix::scaling(2, 3, 4);
  Tuple p1 = Tuple::Point(-4, 6, 8);
  Tuple r4 = B * p1;
  assert((r4 == Tuple::Point(-8, 18, 32)) &&
         "r4 should be equal to Point(-8,18,32)");

  Tuple v1 = Tuple::Vector(-4, 6, 8);
  Tuple r5 = B * v1;
  assert((r5 == Tuple::Vector(-8, 18, 32)) &&
         "r5 should be equal to Vector(-8,18,32)");

  Matrix B_i = B.inverse();
  Tuple r6 = B_i * v1;
  assert((r6 == Tuple::Vector(-2, 2, 2)) &&
         "r6 should be equal to Vector(-2,2,2)");

  // Reflection
  Matrix C = Matrix::scaling(-1, 1, 1);
  Tuple p2 = Tuple::Point(2, 3, 4);
  Tuple r7 = C * p2;
  assert((r7 == Tuple::Point(-2, 3, 4)) &&
         "r7 should be equal to Point(-2,3,4)");

  return;
}
