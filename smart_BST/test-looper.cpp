#include ".test.hpp"
#include "tree_test_looper.hpp"


TEST(tree_looper)
{
   cout << "Testing looper" << endl;

   tree_test_looper looper(1000,100);
   cout << looper.go() << endl;

   tree_test_looper looper10(10000,100);
   cout << looper10.go() << endl;

   tree_test_looper looper100(100000,100);
   cout << looper100.go() << endl;
}
