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
      bool fizzed = false;

      if(modTrue(i,3))
      {
         fizzed = true;
      } 
      
      
      if(modTrue(i,5))
      {
         buzzed = true;
      }

      if(buzzed&&fizzed)
      {
           cout << "Fizzbuzz";
      }
      else if(buzzed)
      {
         cout << "Buzz";
      }
      else if(fizzed)
      {
         cout << "Fizz";
      }
      else
      {
         cout << i;
      }
      cout <<endl;
   }

}
