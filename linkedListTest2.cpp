#include <iostream>

struct node_t
{
   node_t(int node_value)
      :value_(node_value)
      ,next_(nullptr)
   {
      //std::cout << "Constructing..." << std::endl;
   }

   int value() const
   {
      return value_;
   }

   void value(int new_value)
   {
      value_ = new_value;
   }

   node_t* next() const
   {
      return this->next_;
   }

   void next(node_t* next_node)
   {
      this->next_ = next_node;
   }

   private:
      int value_;
      struct node_t* next_;   
      
};

struct list_t
{
   //constructor
   list_t(int initial_val)
      :head_node_(new node_t(initial_val))
   {}

   //methods, public
   void print_list()
   {
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
      node_t* new_node = new node_t(new_val);
      node_t* end_node = get_end_node();
      end_node->next(new_node);
   }

   void insert_after(int value, int position)
   {
      node_t* splice_before = get_node_number(position);
      node_t* splice_after = get_node_number(position+1);
      node_t* new_node = new node_t(value);

      splice_before->next(new_node);
      new_node->next(splice_after);
   }

   void insert_before(int value, int position)
   {
      insert_after(value,position-1);
   }

   void delete_node(int position)
   {
      node_t* pre_doomed_node = get_node_number(position-1);
      node_t* post_doomed_node = get_node_number(position+1);
      pre_doomed_node->next(post_doomed_node);
   }

   void TEMP_SWAP()
   {
      node_t* node_T = get_node_number(2);
      node_t* node_A = get_node_number(3);
      node_t* node_B = get_node_number(4);

      swap_pairs(node_T, node_A, node_B);     
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

   private:
      struct node_t* head_node_;
      //methods, private to list
      void swap_pairs(node_t* node_T, node_t* node_A, node_t* node_B)
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

      void swap_tail(node_t* node_T, node_t* node_A, node_t* node_B)
      {  
         //special case at end of list
         //T->A->B => T->B->A
         node_A->next(nullptr);
         node_B->next(node_A);
         node_T->next(node_B); 
      }

      node_t* get_end_node()
      {
         node_t* iter_node = head_node_;
         while(iter_node->next() != nullptr)
         {
            iter_node = iter_node->next();
         }
         return iter_node;
      }
   
      node_t* get_node_number(int position)
      {
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

int main()
{
   std::cout << "Trying for a linked list..." << std::endl;
   list_t* mList = new list_t(498784);
   mList->push_back(3333);
   mList->push_back(375);
   mList->push_back(1);

   mList->insert_after(2345,2);
   mList->insert_after(2,2);
   mList->insert_after(3,2);
   mList->print_list();

   mList->sort_list();
   mList->print_list();
}
