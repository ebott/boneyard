#include ".test.hpp"
#include "list_t.hpp"

TEST(basic)
{
   list_t* list = new list_t(1234);
   delete list;
}

TEST(push_back)
{
   list_t list(0xaaa);
   list.push_back(0xbbb);
   list.push_back(0xccc);
   list.push_back(0xddd);
   EQ(0xbbb, list.get_node_number(2)->value());
   EQ(0xddd, list.get_node_number(4)->value());
}

// Consider creating more test cases to exercise the rest of
// your list class. You may find that you want to make some
// of your other methods public. This breaks the
// encapsulatoin which you have preserved well. Balance your
// testing needs against your encapsulation needs.
