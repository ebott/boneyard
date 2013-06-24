#include <iostream>
using namespace std;

bool modTrue(int x, int y)
{
   /*
   if (x%y == 0)
   {
      return true;
   }
   return false;
   */
   bool res = x%y == 0;
   return res;
}


int main()
{
   for(int i=0; i<=100; ++i)
   {
      bool buzzed = false;

      if(modTrue(i,3))
      {
         buzzed = true;
         cout << "Fizz";
      } 
      
      
      if(modTrue(i,5))
      {
         buzzed = true;
         cout << "Buzz";
      }

      if(!buzzed)
      {
         cout << i;
      }

      cout << endl;
   }

}
