#include "matrix.hpp"

Matrix::Matrix(int a, int b)
{
    if(a <= 0 || b <= 0)
    {
        throw Exception("Error: Wrong size of an array");
    }

    a_class = a;
    b_class = b;

    arr = new double *[a_class];

    for (int i = 0; i < a_class; i++)
    {
        arr[i] = new double[b_class];
    }

    for (int i = 0; i < a_class; i++)
    {
        for (int j = 0; j < b_class; j++)
        {
            arr[i][j] = 0;
        }
    }
}
Matrix::Matrix(int a)
{
    if(a <= 0)
        throw Exception("Error: Wrong size of a square array");

    a_class = a;
    b_class = a;

    arr = new double *[a_class];
    for (int i = 0; i < a; i++)
    {
        arr[i] = new double[a_class];
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            arr[i][j] = 0;
        }
    }
}
Matrix::Matrix(string filename, string path)
{
    ifstream in;
    in.open(path + filename);
    if (!in.is_open())
    {
        throw Exception("Error: Cannot open the file");
    }
    in >> a_class;
    in >> b_class;

    arr = new double* [a_class];
    for (int i = 0; i < a_class; i++)
        arr[i] = new double[b_class];

    for (int i = 0; i < a_class; i++)
        for (int j = 0; j < b_class; j++)
            in >> arr[i][j];

    in.close();


}



void Matrix::set(int a, int b, double val)
{
    if (a > rows() || a < 0 || b > cols() || b < 0)
        throw Exception("Index error");

    arr[a][b] = val;
}

double Matrix::get(int a, int b) const
{
    if (a > rows() || a < 0 || b > cols() || b < 0)
        throw Exception("Index error");

    return arr[a][b];
}

int Matrix::rows() const
{
    return a_class;
}

int Matrix::cols() const
{
    return b_class;
}

Matrix Matrix::operator +(const Matrix& m2)
{
    Matrix madd(rows(),cols());

    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                madd.arr[i][j] = arr[i][j] + m2.arr[i][j];
            }
        }
    }else{
        throw Exception("Error: Addition is impossible");
    }

    return madd;
}

Matrix Matrix::operator -(const Matrix& m2)
{
    Matrix msub(rows(),cols());
        if (rows() == m2.rows() && cols() == m2.cols())
        {
            for (int i = 0; i < a_class; i++)
            {
                for (int j = 0; j < b_class; j++)
                {
                    msub.arr[i][j] = arr[i][j] - m2.arr[i][j];
                }
            }
        }else{
            throw Exception("Error: Subtraction is impossible");
        }
        return msub;
}

Matrix Matrix::operator *(const Matrix& m2)
{
    Matrix mmul(rows(),cols());

    if (cols() != m2.rows())
    {
        throw Exception("Error: Multiplication is impossible");
    }

    for (int i = 0; i < a_class; i++)
    {
        for (int j = 0; j < b_class; j++)
        {
            for (int k = 0; k < b_class; k++)
                mmul.arr[i][j] += arr[i][k] * m2.arr[k][j];
        }
    }
    return mmul;
}

void Matrix::operator +=(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                arr[i][j] += m2.arr[i][j];
            }
        }

    }else{
        throw Exception("Error: Addition is impossible");

    }
}

void Matrix::operator ++(int inc)
{
    if(inc!=0)
    {
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                arr[i][j]+=inc;
            }
        }
    }
    else{
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                arr[i][j]++;
            }
        }
    }
}


void Matrix::operator -=(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                arr[i][j] -= m2.arr[i][j];
            }
        }

    }else{
        throw Exception("Error: Subtraction and assigning is impossible");
    }
}

bool Matrix::operator ==(const Matrix& m2)
{
    if (rows() == m2.rows() && cols() == m2.cols())
    {
        for (int i = 0; i < a_class; i++)
        {
            for (int j = 0; j < b_class; j++)
            {
                if(arr[i][j] != m2.arr[i][j])
                   return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

ostream& operator<<(ostream& os, const Matrix& m2)
{

    os << m2.rows() << " " << m2.cols() << endl;
    for (int i = 0; i < m2.rows(); i++)
    {
        for (int j = 0; j < m2.cols(); j++)
        {
            os << setw(4) << m2.get(i,j) << "  ";
        }
        os << endl;
    }

    return os;
}


void Matrix::operator [](int a)
{
    if(a > rows() || a < 0)
    {
        throw Exception("Error: The given number is not in the availability range");
    }
    for(int j = 0; j < b_class; j++)
        cout << arr[a][j] << setw(4);
    cout << endl;
}

void Matrix::print()
{
    for (int i = 0; i < a_class; i++)
    {
        for (int j = 0; j < b_class; j++)
        {
            cout << setw(4) << get(i,j) << "  ";
        }
        cout << endl;
    }
}
