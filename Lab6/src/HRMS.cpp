#include <employee.hpp>
#include <HRMS.hpp>

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class WrongOpenFile : public exception
{
    virtual const char *what() const throw()
    {
        return "Exception2: Error folder";
    }
};


void hrms::read_from_file_workers()
{
    fstream fold1;
    fold1.open("workers.txt");
    if(fold1.good())
    {
        while(!fold1.eof())
        {
            string name, id, surname, depertment, position;

            getline(fold1, id);
            getline(fold1, name);
            getline(fold1, surname);
            getline(fold1, depertment);
            getline(fold1, position);

            workers.push_back(employee{id, name, surname, depertment, position});
        }
    }
    else
    {
        throw WrongOpenFile();
    }
    fold1.close();
}


void hrms::read_from_file_salary()
{
    fstream fold2;
    fold2.open("salary.txt");
    if(fold2.good())
    {
        while(!fold2.eof())
        {
            string ID;
            double sal;

            fold2>>ID;
            fold2>>sal;
            salary.push_back(make_pair(ID,sal));
        }
    }
    else
    {
        throw WrongOpenFile();
    }
    fold2.close();
}


void hrms::add_new_worker(employee worker)
{

    fstream fold3;
    fstream fold5;

    fold3.open("workers.txt", std::ios::app);
    fold5.open("salary.txt", std::ios::app);
    if(fold3.good())
    {
        fold3 << endl;
        fold3 << worker.id << endl;
        fold3 << worker.name << endl;
        fold3 << worker.surname << endl;
        fold3 << worker.departmentId << endl;
        fold3 << worker.position;
    }
    else throw WrongOpenFile();
    if(fold5.good())
    {
        fold5 << endl;
        fold5 << worker.id;
    }
    else throw WrongOpenFile();
    fold5.close();
    fold3.close();
}


void hrms::print_workers()
{
    int number =1;
    cout <<left<<setw(6)<< "Lp"<<setw(10)<< "ID"<<setw(15)<<"Imie"<<setw(15)<<"Nazwisko"<<setw(15)<<"Department"<<setw(15)<<"Position"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    for(int i=0;i<workers.size();i++)
    {
        workers[i].print(number);
        number++;
    }
}


void hrms::new_map()
{
    for(int i=0;i<workers.size();i++)
    {
        map_workers[workers[i].departmentId].push_back(workers[i].id);
    }
}


void hrms::print_map()
{
    int how_many = map_workers.size();
    map<string, vector <string>>::iterator it = map_workers.begin();

    cout<<setw(10)<<"DEPARTMENT"<<setw(10)<<"ID"<<endl;
    cout<<"--------------------------------"<<endl;
    for(int i=0; i<how_many; i++)
    {
        string depart = it->first;
        for(int j=0; j <map_workers[it->first].size(); j++)
        {
            cout << setw(10)<<depart <<setw(10)<< map_workers[depart][j] << endl;
        }
        *it++;
    }
}


void hrms::print_salary()
{
    int size_of_vector=salary.size();

    cout<<size_of_vector<<endl;
    cout <<left<<setw(6)<< "ID"<<setw(15)<<"Name"<<setw(15)<<"Surname"<<setw(15)<<"Department"<<setw(15)<<"Position"<<setw(15)<<"Salary" <<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;

    for(int i=0;i<size_of_vector;i++)
    {
        string actual_id=salary[i].first;
        int k;
        for(k=0; workers[k].id!=actual_id; ++k);

        cout <<left<<setw(6)<<actual_id<<setw(15)<<workers[k].name<<setw(15)<<workers[k].surname<<setw(15)<<workers[k].departmentId<<setw(15)<<workers[k].position<<setw(15)<<salary[i].second<<endl;
        cout<<"-------------------------------------------------------------------------------------"<<endl;
    }
}


void hrms::print_sorted_salary()
{
    sort(salary.begin(), salary.end(), [](auto &left, auto &right) { return left.second < right.second; });
    print_salary();
}


void hrms::add(employee employee, std::string departmentid, double sal)
{
    fstream fold5;
    fold5.open("salary.txt", std::ios::app);

    workers.push_back(employee);
    map_workers[workers[workers.size() - 1].departmentId].push_back(workers[workers.size() - 1].id);
    salary.push_back(make_pair(employee.id,sal));

    if(fold5.good())
    {
        fold5 << endl;
        fold5 << sal;
    }
    else throw WrongOpenFile();
    fold5.close();
}


void hrms::changeSalary(string enmployeeId, double sal)
{
    int size_of_vector=salary.size();
    for(int i=0;i<size_of_vector;i++)
    {
        string actualid=salary[i].first;
        if(actualid==enmployeeId)
        {
            salary[i].second=sal;
        }
    }
}


void hrms::print_depart(string departmentid)
{
    int how_many = map_workers[departmentid].size();

    cout<<"Amount of workers in: "<<departmentid<<" = "<<how_many<<endl;
    cout<<setw(10)<<"DEPARTMENT"<<setw(10)<<"ID"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for(int i=0; i<how_many; i++)
    {
        std::cout <<setw(10)<< departmentid <<setw(10)<< map_workers[departmentid][i] << '\n';
    }
}
