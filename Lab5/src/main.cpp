#include "matrix.hpp"
#include <iostream>
#include <ctime>

int main()
{
    try{
        srand(time(NULL));
        Matrix m1(6,5);

        cout << "\nm1: " << endl;
        cout << "Rows: " << m1.rows() << endl;
        cout << "Columns: " << m1.cols() << endl;

        for (int i = 0; i < m1.rows(); i++)
        {
            for (int j = 0; j < m1.cols(); j++)
            {
                m1.set(i, j, rand() % 10);
            }
        }
        m1.print();

        Matrix m2(6,5);
        cout << "\nm2: " << endl;
        cout << "Rows: " << m2.rows() << endl;
        cout << "Columns: " << m2.cols() << endl;

        for (int i = 0; i < m2.rows(); i++)
        {
            for (int j = 0; j < m2.cols(); j++)
            {
                m2.set(i, j, rand() % 10);
            }
        }
        m2.print();
        Matrix m3(5);
        cout << "\nm3: " << endl;
        cout << "Rows: " << m3.rows() << endl;
        cout << "Columns: " << m3.cols() << endl;

        for (int i = 0; i < m3.rows(); i++)
        {
            for (int j = 0; j < m3.cols(); j++)
            {
                m3.set(i, j, rand() % 10);
            }
        }

        m3.print();

        cout << "\nm1 + m2:" << endl;
        (m1+m2).print();
        cout << "\nm1 - m2:" << endl;
        (m1-m2).print();

        cout << "\nm1 * m3:" << endl;
        (m1*m3).print();
        cout << "m2+=m1: " << endl;
        m2+=m1;
        m2.print();
        cout << "m1++: " << endl;
        m1++;
        m1.print();
        cout << "m2-=m1: " << endl;
        m2-=m1;
        m2.print();

        if(m1==m2)
        {
            cout << "Macierze m1 oraz m2 sa identyczne" << endl;
        }else{
            cout << "Macierze m1 oraz m2 sa rozne" << endl;
        }
        cout << "m1[0]: ";
        m1[0];

        string filename, path;
        cout << "\nPodaj nazwe pliku do zapisu: ";
        cin >> filename;
        cout << "Podaj sciezke do zapisu(np. C:\\\\folder_name\\\\): ";
        cin >> path;


        ofstream file;
        file.open(path + filename, ios::out);

        if(file.is_open())
            file << m1;

        Matrix m4(filename, path);
        m4.print();
    }
    catch(Exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
