#pragma once

struct node_t
{
   node_t(int node_value)
      :value_(node_value)
      ,next_(nullptr)
   {}

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
