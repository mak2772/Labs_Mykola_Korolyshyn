#include "matrix.hpp"
using namespace std;


Matrix::Matrix(int N, int M){
    if (N > 0 && M > 0){
        m_N = N;
        m_M = M;

        matrix = new double* [M];
        for (int i = 0; i < N; i++)
            matrix[i] = new double[N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                matrix[i][j] = 0;
    }
    else{
        cout << "Error: Problem with size.\n";
        exit(0);
    }
}

Matrix::Matrix(int N){
    if (N > 0){
        m_N = N;
        m_M = N;

        matrix = new double* [N];
        for (int i = 0; i < N; i++)
            matrix[i] = new double[N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                matrix[i][j] = 0;
    }
    else{
        cout << "Error: Problem with size.\n";
        exit(1);
    }
}

Matrix::Matrix(string path){
    ifstream file;
    file.open(path);
    if (file.is_open()){
        file >> m_N;
        file >> m_M;

        matrix = new double* [m_N];
        for (int i = 0; i < m_N; i++)
            matrix[i] = new double[m_M];

        for (int i = 0; i < m_N; i++)
            for (int j = 0; j < m_M; j++)
                file >> matrix[i][j];

        file.close();
    }
    else{
        cout << "Error: Problem with opening file.\n";
        exit(8);
    }
}

void Matrix::set(int N, int M, double Val){
    if ((N > 0 && M > 0) && (N <= m_N && M <= m_M)){
        matrix[N - 1][M - 1] = Val;
    }
    else{
        cout << "Error: With entering value.\n";
        exit(2);
    }
}

double Matrix::get(int N, int M){
    if ((N > 0 && M > 0) && (N <= m_N && M <= m_M)){
        return matrix[N - 1][M - 1];
    }
    else{
        cout << "Error: Problem with getting element of entered position.\n";
        exit(3);
    }
}

Matrix Matrix::add(Matrix& m2){
    Matrix sum{m_N, m_M};

    if (m_N == m2.m_N && m_M == m2.m_M){
        for (int i = 0; i < m_N; i++)
            for (int j = 0; j < m_M; j++)
                sum.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];

        return sum;
    }
    else{
        cout << "Error: Matrix are of diffrent size.\n";
        exit(4);
    }
}

Matrix Matrix::substract(Matrix& m2){
    Matrix difference{m_N, m_M};

    if (m_N == m2.m_N && m_M == m2.m_M){
        for (int i = 0; i < m_N; i++)
            for (int j = 0; j < m_M; j++)
                difference.matrix[i][j] = matrix[i][j] - m2.matrix[i][j];

        return difference;
    }
    else{
        cout << "Error: subtruction matrix of different size is impossible.\n";
        exit(5);
    }
}

Matrix Matrix::multiply(Matrix& m2){
    Matrix product{m_N, m_M};

    if (m_M == m2.m_N){
        for (int i = 0; i < m_N; i++)
            for (int j = 0; j < m2.m_M; j++)
                for (int k = 0; k < m_M; k++)
                   product.matrix[i][j] += matrix[i][k] * m2.matrix[k][j];

        return product;
    }
    else{
        cout << "Error: Problem values.\n";
        exit(6);
    }
}

int Matrix::cols(){
    return m_M;
}

int Matrix::rows(){
    return m_N;
}

void Matrix::print(){
    for (int i = 0; i < m_N; i++){
        for (int j = 0; j < m_M; j++){
            cout << setprecision(3) << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void Matrix::store(string filename, string path){
    ofstream file;
    file.open(path + filename);
    if (file.is_open()){
        file << m_N << " " << m_M << endl;

        for (int i = 0; i < m_N; i++){
            for (int j = 0; j < m_M; j++){
                file << setw(4) << matrix[i][j];
            }
            file << endl;
        }

        file.close();
    }
    else{
        cout << "Error: Problem with creation of file.\n";
        exit(7);
    }
}
