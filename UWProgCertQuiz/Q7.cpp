#include <iostream>

void possiblyTheWayTheyWantIt()
{
   char *sp = new char[250];
   sp[0] = 'e';
   *(sp+1) = 'r';
   sp[2] = 'i';
   sp[3] = 'c';
   //this in particular seems a little 'hackey'...(above)
   std::cout << *sp 
         << "..." 
         << *(sp+1) 
         << std::endl;
   //yeah this is long and boring...

   for(int i=0;sp[i];++i)
   {
      std::cout << *(sp+i);  
      //I wonder if theres a more elegant way to do this?
   }
   std::cout << std::endl;
   delete[] sp;
}

int main()
{
   std::string *s = new std::string;
   *s = "My name!";

   std::cout << *s << std::endl;
   std::cout << "max size: " << s->max_size() << std::endl << std::endl;
   delete s;

   possiblyTheWayTheyWantIt();
}
