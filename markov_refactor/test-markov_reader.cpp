#include ".test.hpp"
#include "markov_reader.hpp"

TEST(basic)
{
   markov_reader testor("Ulysses.txt");
   testor.generate(50);
}
