#include <employee.hpp>
#include <HRMS.hpp>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
 
int main()
{
    system("cls");
    
    bool p=true;
    
    hrms nw;
    nw.read_from_file_workers();
    nw.read_from_file_salary();
    nw.new_map();
    
    while(p)
    {
        try
        {
         cout<<"Choose option:"<<endl;
         cout<<"1. Print all workers info"<<endl;
         cout<<"2. Print map of workers and departments"<<endl;
         cout<<"3. Print info about workers of some department"<<endl;
         cout<<"4. Print earnings of workers with their ID"<<endl;
         cout<<"5. Print sorted list of earnings with inf.about workers."<<endl;
         cout<<"6. Chnage worker salary"<<endl;
         cout<<"7. Add new worker and salary"<<endl;
         cout<<"0. End"<<endl;
        
		 int ch;
         cin>>ch;
         
         switch(ch)
         {
            case 0:
            {
                p=false;
                break;
            }
            case 1:
            {
                cout << "Print all workers" <<endl;
                nw.print_workers();
                
				break;
            }
            case 2:
            {
                cout << "Print map of workers and departments"<<endl;
                nw.print_map();
                
				break;
            }
            case 3:
            {
                cout << "Enter number of department:" << endl;
                string dep;
                cin >> dep;
                nw.print_depart(dep);
                
				break;
            }
            case 4:
            {
                cout << "Earnings:" << endl;
                nw.print_salary();
                
				break;
            }
            case 5:
            {
                cout << "Sorted earnings of workers:" << endl;
                nw.print_sorted_salary();
                
				break;
            }
            case 6:
            {
                string new_id;
                double new_salary;
                
				cout << "Enter ID of worker which salary you want to change:" <<endl;
                cin >> new_id;
                cout << "Enter new salary:" << endl;
                cin >> new_salary;
                nw.changeSalary(new_id,new_salary);
                
				break;
            }
            case 7:
            {
                cout << "Add new worker" <<endl;
                double new_salary;
                
				string id,name,surname,depart,position;
                
				cout << "Enter ID" <<endl;
                cin >> id;
                
				cout << "Enter name" <<endl;
                cin >> name;
                
				cout << "Enter surname" <<endl;
                cin >> surname;
                
				cout << "Enter ID of department" << endl;
                cin >> depart;
                
				cout << "Enter position" << endl;
                cin >> position;
                
				cout << "Enter salary" << endl;
                cin >> new_salary;
                
				employee add_worker(id, name, surname, depart, position);
                nw.add(add_worker, depart, new_salary);
                nw.add_new_worker(add_worker);
                
				break;
            }
            default:
            {
                cout << "Choose again" <<endl;
                
				break;
            }
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return 0;
}
