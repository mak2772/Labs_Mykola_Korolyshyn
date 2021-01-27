#include "matrix.hpp"
int main(){
	
	char c;
    int a=4,b=5;
    
Matrix MTest_1(a,b);
    cout<<"Matrix 4x5 stworzona przeciazonym konstuktorem Matrix(int , int)"<<endl;
    MTest_1.print();
    
	Matrix MTest_2(b);
    cout<<"Matrix 5x5 stworzona przeciazonym konstuktorem Matrix(int)"<<endl;
    
	MTest_2.print();
    cout<<"Wypelnienie Matrixy 5x5 metoda set(n,m,val)"<<endl;
    
	int kol=MTest_2.cols(),wie=MTest_2.rows();
    
	for(int i=1;i<=wie;i++)
    {
        for(int j=1;j<=kol;j++)
        {
            double war=1.2+i*j;
            MTest_2.set(i,j,war);
        }
    }
    
	MTest_2.print();
    cout<<"Metoda wypisujaca dowolny element Matrixy get(n,m)"<<endl;
    
	int licz=3;
    
    cout<<"Wartosc elementu (3,4) w Matrix MTest_2 wynosi "<<MTest_2.get(licz,b)<<endl;
    cout<<"Dodanie dwoch Matrix 5x5"<<endl;
    Matrix M_temp1(b,b);
    Matrix M_temp2(b,b);
    
    int kol1=M_temp1.cols();
    int wie1=M_temp1.rows();
    
    for(int i=1;i<=wie1;i++)
    {
        for(int j=1;j<=kol1;j++)
        {
            double war1=1.2+i*j;
            double war2=3.8+2*i-j;
            M_temp1.set(i,j,war1);
            M_temp2.set(i,j,war2);
        }
    }
    cout<<"Matrix 1 M_temp1"<<endl;
    M_temp1.print();

    cout<<"Matrix 1 M_temp2"<<endl;
    M_temp2.print();

    cout<<"Dodawania metoda add(Matrix m2).Wynik:"<<endl; 
    Matrix M_dodaj=M_temp1.add(M_temp2);
    M_dodaj.print();

    Matrix M_odejmij=M_temp1.substract(M_temp2);
    cout<<"Odejmowania metoda substract(Matrix m2).Wynik:"<<endl;
    M_odejmij.print();

    Matrix M_pomnoz=M_temp1.multiply(M_temp2);
    cout<<"Mnozenie metoda multiply(Matrix m2).Wynik:"<<endl;
    M_pomnoz.print();

    cout<<"Kolumny w Matrix mnozonej wynosi: "<<M_pomnoz.cols()<<", ilosc wierszy: "<<M_pomnoz.rows()<<endl;
    cout<<endl;

    cout<<"Print wykorzystane do wypisania kazdej Matrix"<<endl;
    cout<<endl;

    string sciezka=("D:\\Mykola\\student\\jipplab\\lab3\\plik.txt");
    string nazwa=("plik.txt");
    M_pomnoz.store(nazwa,sciezka);
    
    cout<<"Wywolana metoda store na Matrix wymnozonej, wynik w pliku plik.txt"<<endl;
    cout<<endl;
    Matrix Matrix_z_pliku(nazwa);
    
    cout<<"Konstruktor pobierajacy Matrix z pliku"<<endl;
    cout<<"Matrix z pliku:"<<endl;
    Matrix_z_pliku.print();
    
    cin>>c;
} 
