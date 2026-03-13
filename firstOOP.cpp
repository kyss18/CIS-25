#include<iostream>
#include<vector>
using namespace std;
class Employee {
protected:
    string name;
public:
    Employee(string name){
        this->name=name;
    };
    virtual double calculateSalary() = 0;
    virtual void printInfo() = 0;
    virtual ~Employee() {}
};
class FullTimeEmployee:public Employee{
    private:
        int baseSalary;
        int bonus;
    public:
        FullTimeEmployee(string name,int baseSalary,int bonus):Employee(name){
            this->baseSalary=baseSalary;
            this->bonus=bonus;
        }
        double calculateSalary(){
            return baseSalary+bonus;
        }
        void printInfo() override {
            cout<<"Name:"<<name<<"| Type: Fulltime"<<endl<<"Salary:"<<calculateSalary();
        }

};
class PartTimeEmployee:public Employee{
    private:
        int hoursWorked;
        int hourlyRate;
    public:
        PartTimeEmployee(string name,int hoursWorked,int hourlyRate):Employee(name){
            this->hoursWorked=hoursWorked;
            this->hourlyRate=hourlyRate;
        }
        double calculateSalary(){
            return hoursWorked*hourlyRate;
        }
        void printInfo() override {
            cout<<"Name:"<<name<<"| Type: PartTime"<<endl<<"Salary:"<<calculateSalary();
        }
};
class Intern:public Employee{
    private:
        int allowance;
    public: 
        Intern(string name,int allowance):Employee(name){
            this->allowance=allowance;
        }
        double calculateSalary(){
            return allowance;
        }
         void printInfo() override {
            cout<<"Name:"<<name<<"| Type: Intern"<<endl<<"Salary:"<<calculateSalary();
        }
    
};
int main (){
    vector<Employee*> staff;
    staff.push_back(new FullTimeEmployee("Alice", 3000, 500));
staff.push_back(new PartTimeEmployee("Bob", 80, 20));
staff.push_back(new Intern("Charlie", 800));
    for (Employee *s :staff){
        s->printInfo();
        cout<<endl;
    }

}