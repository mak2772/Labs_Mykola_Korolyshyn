#include<iostream>
#include<fstream>
using namespace std;

class Matrix{
    private:
    int wiersze;
    int kolumny;
    double **tab;
    
	public:
    Matrix(int & ,int &);
    Matrix(int &);
    Matrix(string &);
    void set(int &n,int &m,double &val);
    double get(int &n,int &m);
    void print();
    Matrix add(Matrix &m2);
    Matrix substract(Matrix &m2);
    Matrix multiply(Matrix &m2);
    int rows();
    int cols();
    void store(string &filename, string &path);
};
