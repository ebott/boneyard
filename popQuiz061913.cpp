#include <iostream>

void foo(int*& x)
{
   ++*x;
   std::cout
      << "foo sez x = "
      << *x
      << std::endl;
}

void bar(int*const& x)
{
      ++*x;
      std::cout
      << "bar sez x = "
      << *x
      << std::endl;
}

int main()
{
   int y = 10;
   int* yp = &y;
   foo(yp);
   bar(&y);
   // foo(&y); why no work?
   std::cout
      << "y = "
      << y
      << std::endl;
      return 0;
}
