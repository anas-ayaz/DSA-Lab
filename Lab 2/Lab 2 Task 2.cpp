#include<iostream>
using namespace std;

class Employee{
public:
virtual int calculateSalary() = 0;
};

class FullTimeEmployee:public Employee{
public:
int calculateSalary(){
return 10000;
}
};

class PartTimeEmployee:public Employee{
private:
int hours;
int hourlyRate;
public:

PartTimeEmployee(int hours,int hourlyRate){
this->hours=hours;
this->hourlyRate=hourlyRate;
}

int calculateSalary(){
    return hours * hourlyRate;
}
};

int main()
{
FullTimeEmployee fte;
PartTimeEmployee pte(10,100);
cout<<"Salary of full time employee is: "<<fte.calculateSalary()<<endl;
cout<<"Salary of part time employee is: "<<pte.calculateSalary()<<endl;
return 0;
}