#include "matrix.hpp"
Matrix::Matrix(int &wwiersze,int &kkolumny)
{
    wiersze=wwiersze;
    kolumny=kkolumny;

    tab=new double*[wiersze+1];
    
    for(int i=0;i<wiersze;i++)
        {
            tab[i]=new double[kolumny+1];
            for(int j=0;j<kolumny;j++)
            {
                tab[i][j]=0;
            }
        }
}

Matrix::Matrix(int &kkwadrat)
{
        wiersze=kkwadrat;
        kolumny=wiersze;
        tab=new double*[wiersze+1];
        for(int i=0;i<wiersze;i++)
        {
            tab[i]=new double[wiersze+1];
            for(int j=0;j<wiersze;j++)
            {
                tab[i][j]=0;
            }
        }
}

void Matrix::set(int &n,int &m,double &val)
{
    if(n-1<0 || n-1>wiersze || m-1<0 || m-1>kolumny)
    {
        cout<<"Wpisales bledny indeksy ktore do Matrix"<<endl;
    }
    else {
    tab[n-1][m-1]=val;
    }
}

double Matrix::get(int &n,int &m)
{
     if(n-1<0 || n-1>wiersze || m-1<0 || m-1>kolumny)
    {
        cout<<"Wpisales indeksy ktore nie naleza do Matrix"<<endl;
        return 0;
    }
    else {
    return tab[n-1][m-1];
    }
}

void Matrix::print()
{
    for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                cout<<tab[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
}

Matrix Matrix::add(Matrix &m2)
    {
        int tempcol=m2.cols();
        int temprow=m2.rows();
        Matrix addm(temprow,tempcol);
        if(m2.cols()!=kolumny || m2.rows()!=wiersze)
        {
            cout<<"Dodania Matrix roznych wymiarow"<<endl;
            return addm;
        }
        for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                addm.tab[i][j]=tab[i][j]+m2.tab[i][j];
            }
        }
        return addm;
    }

Matrix Matrix::substract(Matrix &m2)
    {
        int tempcol=m2.cols();
        int temprow=m2.rows();
        Matrix subb(temprow,tempcol);
        if(m2.cols()!=kolumny || m2.rows()!=wiersze)
        {
            cout<<"Odjecia Matrix roznych wymiarow"<<endl;
            return subb;
        }
        for(int i=0;i<wiersze;i++)
        {
        
            for(int j=0;j<kolumny;j++)
            {
                subb.tab[i][j]=tab[i][j]-m2.tab[i][j];
            }
        }   
        return subb;
    }

Matrix Matrix::multiply(Matrix &m2)
    {
        int tempcol=m2.cols();
        int temprow=m2.rows();
        Matrix mnoz(wiersze,tempcol);
        if(temprow!=kolumny)
        {
            cout<<"Nieprawidlowe mnozenie Matrix"<<endl;
        }
        for(int i=0;i<wiersze;i++)
        {
            for(int j=0;j<kolumny;j++)
            {
                for(int k=0;k<kolumny;k++)
                {
                mnoz.tab[i][j]=mnoz.tab[i][j]+tab[i][k]*m2.tab[k][j];
                }
                }
        }   
        return mnoz;
    }

int Matrix::rows()
    {
    return wiersze;
    }

int Matrix::cols()
    {
    return kolumny;
    }

void Matrix::store(string &filename, string &path)
{
    ofstream plik;
    plik.open(path, ios_base::out);
    if(plik.good()!=true)
    {
        cout<<"Plik nie zostal otwarty";
    }
    plik<<rows()<<" "<<cols()<<endl;
    for(int i=0;i<wiersze;i++)
    {
        for(int j=0;j<kolumny;j++)
        {
            plik<<tab[i][j]<<" ";
        }
        plik<<endl;
    }
    plik.close();
}

Matrix::Matrix(string &a)
{
    ifstream read;
    read.open(a);
    int x,y;
    read>>x;
    read>>y;
    wiersze=x;
    kolumny=y;
    tab=new double*[wiersze+1];
    for(int i=0;i<wiersze;i++)
        {
        tab[i]=new double[wiersze+1];
        for(int j=0;j<wiersze;j++)
            {
                read>>tab[i][j];
            }
        }

}
