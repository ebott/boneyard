#include <iostream>
using namespace std;

//Q3: whats wrong with this C function?
//char* getpass()
//{
// char password[10];
// scanf("%s\n",password);
// return password;
// }

//my fixin:
char getpass() //return type passed fully
{
   char password[10];
   scanf("%10s", password); //axed \n from the input params
   cout << *password << endl; //increase the pointer by one in char array
   return *password; //pass by value
}

//try another thing get it to work passing reference
char* getpass2()  //keep reference pass
{
   char *password = new char[10];
   scanf("%s", password);
   cout << password << endl;
   return password;
}

//try another with a char array on the heap
char* getpass3()
{
   //char *password = new char[10];
   //whats the difference above and below?
   char* password = new char[10];
   scanf("%10s",password);
   return password;
}

int main()
{
   cout << "executing code snippet" << endl;
   char stringo[80];
   scanf("%s",stringo);
   cout << stringo << endl << endl;

   char* pswd = getpass3();
   cout << *(pswd+1) << endl;

   cout << "aaaaand done" << endl;
}
