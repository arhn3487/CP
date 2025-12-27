#include<bits/stdc++.h>
using namespace std;

class Employee
{
    public:
    virtual int calculateSalary()
    {
        return 0;
    }
};

class fullTimeEmployee : public Employee
{
    int calculateSalary()
    {
        return 50000;
    }
};

class partTimeEmplotyee : public Employee
{
    private:
        int hour;
    public:
    partTimeEmplotyee(int x)
    {
        hour=x;
    }
    int calculateSalary()
    {
        return 50000+hour*300;
    }
};

void printSalary(Employee &e)
{
    int x = e.calculateSalary();
    cout<<x<<endl;
}

int main()
{
    fullTimeEmployee fe;
    cout<<"Enter working hour for part time employee\n";
    int a;
    cin>>a;
    partTimeEmplotyee pe(a);
    cout<<"Selary for full time employee is : ";
    printSalary(fe);
    cout<<"Selary for part3 time employee is : ";
    printSalary(pe);
}