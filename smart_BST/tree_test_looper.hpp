#include <iostream>
#include "smart_BST.hpp"
#include <chrono>
#include <math.h>
#include <stdlib.h>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;

struct tree_test_looper
{

   tree_test_looper(int nodes, int loops)
      :nodes_(nodes)
      ,loops_(loops)
   {}

   long go()
   {
      //iterates through a number of loop for the specified
      //tree size
      
      long temp_timing = 0;
      for(int i = 0; i < loops_; ++i)
      {
         temp_timing += this->create_n_test();
      }
      temp_timing = temp_timing / loops_;

      return temp_timing;
   }

   long create_n_test()
   {
      smart_BST test_tree(297,"I am the mother of all trees");

      for(int i=0; i<nodes_; ++i)
      {
         int rando = rand() % (nodes_)+1;
         test_tree.insert_node(rando, "Rando string");
      }


      auto ti = high_resolution_clock::now();
      test_tree.find_node(100*nodes_);
      test_tree.find_node(nodes_);
      test_tree.find_node(nodes_*5);
      test_tree.find_node(nodes_*6);
      test_tree.find_node(nodes_*7);
      test_tree.find_node(nodes_*8);
      auto tf = high_resolution_clock::now();

      nanoseconds total_ns = std::chrono::duration_cast<nanoseconds>(tf-ti);
      return total_ns.count();
   }

   private:
      int nodes_;
      int loops_;
};


