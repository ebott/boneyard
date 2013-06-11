#include <iostream>


void DoPrint()
{
   std::cout << "AHEM.  Line." << std::endl;
}

void forPlay(int boob)
{
   using namespace std;
   cout << boob << '\n';
   
   int v[4] = {1,2,4,7};
   for (auto x : v) cout << v[x] << '\n';
}

void increment()
{
   int v[7] = {9,10,11,12,13,14,15};

   for (auto& x : v)
   {
      ++x;
      std::cout << x <<  std::endl;
   }

}

void pointertime()
{
   //reference time!
   int v[3] = {13,22,36};
   int& x = v[1];
   std::cout << ++x << std::endl;
   std::cout << v[1] << std::endl;
   x = 98;
   std::cout << v[1] << std::endl;

   //pointer time!
   int* p = &v[0];
   std::cout << p << std::endl;
   std::cout << *p << std::endl;
   ++p;
   std::cout << p << "    " << *p << std::endl;
   ++*p;
   std::cout << p << "    " << *p << std::endl;
}

int main()
{
   std::cout << "Hello Bitches!" << std::endl;

   //DoPrint();
   //forPlay(42);
   //increment();
   pointertime();

   return 0;
}
