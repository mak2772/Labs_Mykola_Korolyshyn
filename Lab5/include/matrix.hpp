#ifndef MAT_HPP
#define MAT_HPP
#include <iostream>
#include <fstream>
#include <iomanip>
#include "wyjatki.hpp"

class Matrix
{
    private:
        double ** arr;
        int a_class {}, b_class {};
    public:

        int rows() const;
        int cols() const;
        Matrix(int a, int b);
        Matrix(int a);
        Matrix(string filename, string path);
        void set(int a, int b, double val);
        double get(int x, int y) const;
        Matrix operator +(const Matrix& m2);
        Matrix operator -(const Matrix& m2);
        Matrix operator *(const Matrix& m2);
        Matrix operator >>(int a);
        void operator +=(const Matrix& m2);
        void operator -=(const Matrix& m2);
        bool operator ==(const Matrix& m2);
        void operator ++(int inc);
        void operator [](int a);
        void store(string filename,string path);
        void print();
};

ostream& operator<<(ostream& os, const Matrix& m2);
#endif
