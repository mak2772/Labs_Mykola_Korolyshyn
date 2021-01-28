#include "matrix.hpp"
#include <time.h>
#include <conio.h>
using namespace std;


int main(){
	
    srand(time(NULL));

    cout << "All methods:\n";

    cout << "\n-------------------------------------------------------";

    cout << "\nMatrix 8x8 filled by zero:\nMatrix 1:\n";
    Matrix M1{9, 9};
    M1.print();

    cout << "\nRng matrix:\nMatrix 1:\n";
    for (int i = 1; i <= M1.rows(); i++)
        for (int j = 1; j <= M1.cols(); j++)
            M1.set(i, j, rand() % 10);
    M1.print();

    cout << "\nGet rng Matrix\n";
    for (int i = 2; i < M1.rows(); i += 2){
        for (int j = 1; j <= M1.cols(); j++){
            cout << setw(4) << M1.get(i, j);
        }
        cout << endl;
    }

    cout << "\nPath to save place for M1 information:\n";
    string name, path;
    cout << "New file name: ";
    cin >> name;
    cout << "Save place: ";
    cin >> path;

    M1.store(name, path);
    cout << "Matrix M1 saved. Name: \'" << name << "\' Place: \'" << path << "\'\n";

    cout << "\n----------------------------------------------------------------------";


    cout << "\nRng matrix M1_1 size of 8x8:\n";
    cout << "Macierz M1_1:\n";
    Matrix M1_1{9, 9};

    for (int i = 1; i <= M1_1.rows(); i++)
        for (int j = 1; j <= M1_1.cols(); j++)
            M1_1.set(i, j, rand() % 10);
    M1_1.print();

    cout << "\n--------------------------------------------------------------------";


    cout << "\nCreating cubic matrix M2 size of 10x10 and filled by zero:\nMatrix M2:\n";
    Matrix M2{6};
    M2.print();

    cout << "\n-------------------------------------------------------------------";

    cout << "\nGive path to file where is matrix.\n";
    cout << "On top of file first digit will be amount of rows and second one colons.Example:(10 10) .\n";
    cout << "In the rest part of file must be elements of matrix.\n";
    cout << "Enter path to matrix file: ";
    cin >> path;

    Matrix M3{path};

    cout << "Matrix3 created. Based on file information " << M3.rows() << "x" << M3.cols() << endl;
    cout << "Matrix3:\n";
    M3.print();

    cout << "\n-----------------------------------------------";
    cout << "\nExample of addition, subtraction, and matrix multiplication.\n";
    cout << "\nAdd Matrix1 and Matrix2:\n";
    M1.add(M1_1).print();
    cout << "\nSub Matrix1 and Matrix2:\n";
    M1.substract(M1_1).print();
    cout << "\nMulti Matrix1 and Matrix2:\n";
    M1.multiply(M1_1).print();
    system("pause");
    return 0;
}
