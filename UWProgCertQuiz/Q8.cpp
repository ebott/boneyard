#include <iostream>

void printNumbersValue(int a, int b)
{
   std::cout << a << "  " << b << std::endl;
}

void printNumbersPointerRef(int* a,int* b)
{
   std::cout << *a << "  " << *b << std::endl;
}

void printNumbersAddressOfRef(int& a, int& b)
{
   std::cout << a << "  " << b << std::endl;
}

int main()
{
   int x = 3;
   int y = 34359;
   
   int* xp = &x;
   int* yp = &y;
   printNumbersValue(x,y);
   std::cout << std::endl;
   printNumbersPointerRef(xp,yp);
   std::cout << std::endl;
   printNumbersAddressOfRef(x,y);
}
