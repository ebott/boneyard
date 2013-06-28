#pragma once

#include <iosfwd>
#include "node_t.hpp"

/**
 * @file
 */

/**
 * A classic forward linked list.
 */
struct list_t
{
   // explain why, not how or what with your comments.
   // rationale: your reader is a c++ programmer, let him
   // know the how and the what from the code itself. if you
   // do something edgy or interesting, explain yourself
   // with comments. this leads the programmer to write code
   // which is largely self explanatory with minimal
   // commentary.
   //
   // also, this project is set up to use doxygen (pacman -S
   // doxygen). I'll add doxygen documentation to print_list
   // and get_node_number for you as examples. Just run
   // doxygen at the command line to generate the
   // documentation. It will appear under a new directory
   // called html (and latex). Open index.html. Even without
   // adding any doxygen markup, you'll see that there is a
   // decent amount of documentation doxygen can generate
   // for you anyway. 
 
   //constructor
   list_t(int initial_val)
      :head_node_(new node_t(initial_val))
   {}

   // ~list_t()? valgrind it out :)

   /**
    * Write the list to stdout.
    */
   void print_list() const
   {
      // consider implementing this as operator<< over an
      // ostream and a const ref to list_t. see .test.hpp
      // for an example
      std::cout << "Printing List..." << std::endl;
      node_t* iter_node = head_node_;
      do      
      {
         std::cout << "Current List..."
            << iter_node->value() << "  "
            << iter_node  << "  "
            << iter_node->next() << "  "
            << std::endl;
         iter_node = iter_node->next();
      } while(iter_node != nullptr);
   }

   void push_back(int new_val)
   {
      // what is the runtime complexity of this operation?
      node_t* new_node = new node_t(new_val);
      node_t* end_node = get_end_node();
      end_node->next(new_node);
   }

   void insert_after(int value, int position)
   {
      // what is the runtime complexity of this operation?
      node_t* splice_before = get_node_number(position);
      node_t* splice_after = get_node_number(position+1);
      node_t* new_node = new node_t(value);

      splice_before->next(new_node);
      new_node->next(splice_after);
   }

   void insert_before(int value, int position)
   {
      // what if I try to insert before the head?
      insert_after(value,position-1);
   }

   void delete_node(int position)
   {
      node_t* pre_doomed_node = get_node_number(position-1);
      node_t* post_doomed_node = get_node_number(position+1);
      pre_doomed_node->next(post_doomed_node);
      // what is the runtime complexity of this operation?
      // what is the expected runtime complexity of deleting
      // a node from a linked list?
      // what is the fate of the deleted node?
   }

   void sort_list()
   {
      //le bubble oui!
      //bubble sort the list.  
      bool sorting = true;
      while(sorting)
      {
         std::cout << "New Pass" << std::endl;
         sorting = false;
         node_t* node_T = head_node_;
         node_t* node_A = head_node_->next();
         node_t* node_B = head_node_->next()->next();
         // what happens if you try to sort a list of two,
         // one, or zero nodes?

         //check to see if we need to swap the head
         if(node_T->value() > node_A->value())
         {
            swap_head(node_A, node_B);
            sorting = true;
            print_list();
            node_T = head_node_;
            node_A = head_node_->next();
         }
         while(node_B->next() != nullptr)
         {
            if(node_A->value() > node_B->value())
            {
               swap_pairs(node_T, node_A, node_B);
               print_list();
               sorting = true;
            }
            //shift fwd
            node_T = node_T->next();
            node_A = node_T->next();      //only one again, its the new node_T
            node_B = node_T->next()->next();
         }
         //check to see if we need to swap tail
         if(node_A->value() > node_B->value())
         {
            swap_tail(node_T,node_A,node_B);
            sorting = true;
            print_list();
         }
      }
   }

   void reverse_list()
   {
      // cool! (this is a classic interview question)
      node_t* prev_node = head_node_;
      node_t* reverser = head_node_->next();
      // what happens when you try to reverse a list of only
      // one element?
      node_t* next_node = reverser;
      do
      {
         next_node = next_node->next();
         reverser->next(prev_node);
         prev_node = reverser;
         reverser = next_node;
      } while(next_node->next() != nullptr);
      //point to new head, kill ptr at new tail
      head_node_->next(nullptr);
      head_node_ = next_node;
      head_node_->next(prev_node);
   }

   private:
      struct node_t* head_node_;
      
      //methods, private to list
      void swap_pairs(node_t* node_T, node_t* node_A, node_t* node_B) const
      {
         //swaps A with B, also needs Trailer (T)
         //operation: T->A->B => T->B->A
         if(node_T->next() == node_A && node_A->next() == node_B)
         {
            node_T->next(node_B);
            node_A->next(node_B->next());
            node_B->next(node_A);
         }
         else
         {
            std::cout << "not concurrent pairs!" <<std::endl;
            throw "ack!";
         }
      }

      void swap_head(node_t* node_A, node_t* node_B)
      {
         //special cass at beginnging of list
         //T->A->B => A->T->B
         node_A->next(head_node_);
         head_node_->next(node_B);
         head_node_ = node_A;
  
      }

      void swap_tail(node_t* node_T, node_t* node_A, node_t* node_B) const
      {  
         //special case at end of list
         //T->A->B => T->B->A
         node_A->next(nullptr);
         node_B->next(node_A);
         node_T->next(node_B); 
      }

      node_t* get_end_node() const
      {
         // the runtime complexity questions above are
         // intended to take you here. The unit of currency
         // of a linked list is the node. It is reasonable
         // to take a node_t* as the index of the node to
         // delete. This allows you to achieve the following
         // runtime complexities:
         // insertion: O(1)
         // deletion: O(1)
         // push_back: O(1)
         // push_front: O(1)
         // Finding a value without knowing its position is
         // O(n), of course. Sorting will be similar in
         // complexity to what you have achieved which is
         // sort of a triangular n^2 or O(n(n-1)).
         node_t* iter_node = head_node_;
         while(iter_node->next() != nullptr)
         {
            iter_node = iter_node->next();
         }
         return iter_node;
      }
   
public:
      // I made this public for the purposes of the unit
      // test. Consider adding an operator[] to get a node
      // at an index. This will of course be O(n). Try not
      // to use this function throughout the class. Try to
      // deal strictly in node_t pointers.

      /**
       * Access a node by index.
       * @param[in] position one-based offset from the head
       * of the list
       * @return pointer to the node
       */
      node_t* get_node_number(int position) const
      {
         // zero indexed would be less surprising to
         // traditional C and C++ people. Scott Meyers talks
         // about the principle of least surprise. When
         // given two viable alternatives, choose the less
         // surprising one.
         node_t* iter_node = head_node_;
         for(int i=0; i<position-1; ++i)
         {
            if(iter_node->next() == nullptr)
            {
               return iter_node;
            }
            else
            {
               iter_node = iter_node->next();
            }
         }
         return iter_node;
      }

};
