#include <iostream>
using namespace std;

bool modTrue(int x, int y)
{
   if (x%y == 0)
   {
      return true;
   }
   return false;
}


int main()
{
   for(int i=0; i<=100; ++i)
   {
      if(modTrue(i,3))
      {
         cout << "Fizz" << endl;
      } 
      else if(modTrue(i,5))
      {
         cout << "FizzBuzz" << endl;
      }
      else
      {
         cout << i << endl;
      }
   }

}
