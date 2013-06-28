#include ".test.hpp"
#include "node_t.hpp"

TEST(basic)
{
   node_t n(10);
   EQ(10, n.value());
   n.value(20);
   EQ(20, n.value());

   // this is ugly but Boost.Test requires types passed
   // to BOOST_REQUIRE_EQUAL to be ostreamable and
   // equality comparable. For whatever reason,
   // std::nullptr_t is not ostreamable by default. You can
   // see my attempt to remedy the situation in .test.hpp
   // which came to no avail. This cast to ptrdiff_t is
   // heavy handed. FWIW, ptrdiff_t is useful to know
   // because it is guaranteed to be wide enough to store a
   // pointer as an integer. This will help prepare your
   // code for 64-bitness even if you are running it
   // presently on 32-bit machines.
   EQ(ptrdiff_t(nullptr), ptrdiff_t(n.next()));
}
