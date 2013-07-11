#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct functor_t
{
   double operator()(int x)
   {
      return x * 2.0;
   }

};

struct functor_t2
{
   double operator()(int x)
   {
      return x * 4.0;
   }

};

struct functor_2
{
   string operator()(int x)
   {
      if(x%2 == 0)
      {
         return "even!";
      }
      else
      {
         return "odd!";
      }
   }
};

struct functor_3
{
   string operator()(bool x)
   {
      if(x)
      {
         return "true!";
      }
      else
      {
         return "false!";
      }
   }
};

struct functor_4
{
   int operator()(bool x)
   {
      if(x)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }
};

void specific_type(vector<int> v, function<double(int)> func)
{
   for(int i : v)
   {
      cout << func(i) << endl;
   }
}

template <typename FunType>
void general_out(vector<int> v, FunType func)
{
   for(int i : v)
   {
      cout << func(i) << endl;
   }
}

template <typename FunType, typename T>
void general_in_and_out(vector<T> v, FunType func)
{
   for(auto i : v)
   {
      cout << func(i) << endl;
   }
}

int main () 
{
   function<double(int)> functor = functor_t();
   function<double(int)> functor2 = functor_t2();
   vector<int> vec = {1,2,3,4,5,6};
   
   specific_type(vec,functor);
   specific_type(vec,functor2);
   
   function<string(int)> evenoddtest = functor_2();
   general_out(vec,evenoddtest);

   vector<bool> vbool = {1,0,1,0,1};
   function<string(bool)> functor3 = functor_3();
   function<int(bool)> functor4 = functor_4();
   general_in_and_out(vbool,functor3);
   general_in_and_out(vbool,functor4);


   general_in_and_out(vec,functor);

}


