#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Matrix
{
 private:
    double** matrix;
    int m_N;
    int m_M;

 public:

    Matrix(int N, int M);
    Matrix(int N);
    Matrix(string path);

    Matrix add(Matrix& m2);
    Matrix substract(Matrix& m2);
    Matrix multiply(Matrix& m2);

    double get(int N, int M);

    int rows();
    int cols();


   void set(int N, int M, double Val);
   void print();
   void store(string filename, string path);
};
