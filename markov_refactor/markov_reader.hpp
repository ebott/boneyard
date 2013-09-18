#include <iostream>
#include <fstream>
#include <string>
#include "markov_chainer.hpp"
using namespace std;

struct markov_reader
{

   markov_reader(string inputfile)
      :filename_(inputfile)
   {
      int PREFIX_LEN = 2;
      chain = new markov_chainer(PREFIX_LEN);
      read_lines();
   }

   ~markov_reader()
   {
      //TODO:  this???
      delete chain;
   }

   void read_lines()
   {
      string buff;
      ifstream infile (filename_);
      while(!getline(infile, buff).eof())
      {
         parse_words(buff);
      }
   }

   void generate(int outwords)
   { 
      chain->gen_output(outwords);
   }  

   private:
      string filename_;
      markov_chainer* chain;

      void parse_words(string& input_line)
      {
         int char_ptr = 0;
         int space_ptr = 0;
         int len = 0;
         string this_word = "";

         while(space_ptr != -1)
         {
            char_ptr = get_next_what(input_line,space_ptr,false);
            space_ptr = get_next_what(input_line,char_ptr,true);

            if(space_ptr != -1 && char_ptr != -1)
            {
               len = space_ptr - char_ptr;
               this_word = input_line.substr(char_ptr,len); 
               if(this_word.length() > 0)
               {
                  chain->add(this_word);
               }
            }
            char_ptr = space_ptr;
         }
      }

      int get_next_what(string str, int start, bool space)
      {
         //if looking for next char, bool space is false
         for(size_t i = start; i<str.length(); ++i)
         {
            if( (str.at(i) == ' ') == space)
            {
               return i;
            }
            if(space && (i == str.length()-1))
            {
               return i+1;
            }
         }
         return -1;
      }
};
