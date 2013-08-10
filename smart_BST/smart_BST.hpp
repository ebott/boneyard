#include <iostream>
#include "BST_smart_node.hpp"
#include <queue>

using namespace std;

struct smart_BST
{
   smart_BST(int root_key, string root_val)
      :root_(unique_ptr<BST_node>(new BST_node(root_key,root_val)))
   {}

   ~smart_BST()
   {
      delete root_;
   }

   void insert_node(int new_key, string new_val)
   {
      auto insert_fcn = [&] (BST_node* n)
      {
         BST_smart_node* new_node = 
            new BST_smart_node(new_key,new_val);
         if(new_key <= n->key())
         {
            n->l_child(new_node);
            new_node->parent(n);
         }
         else if(new_key > n->key())
         {
            n->r_child(new_node);
            new_node->parent(n);
         }
      };

      root_->binary_trans(new_key,insert_fcn,insert_fcn);
   }

   private:
      unique_ptr<BST_smart_node> root_;


};
