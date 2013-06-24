#include <iostream>

struct Employee
{
   std::string fName;   
   std::string lName;
   int EIN;
   double salary;
};

void printEmployee(Employee p)
{
   std::cout << "This is "
      << p.fName
      << " "
      << p.lName
      << ".  He only makes $"
      << p.salary
      << " a year, so be nice to him."
      << std::endl;
}


int main()
{
   Employee winston;
   winston.fName = "Winston";
   winston.lName = "Smith";
   winston.EIN = 666;
   winston.salary = 23.45;

   printEmployee(winston);
   std::cout << std::endl;
   //try an initializer list
   Employee franko = { "Frank", "OoooSnap", 12345, 600000 };

   printEmployee(franko);
}
