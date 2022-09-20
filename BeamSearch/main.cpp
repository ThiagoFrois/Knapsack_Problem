#include <cstdlib>
#include <ctime>

#include "principal.hpp"

int main()
{

  unsigned int seed;
  seed = time(0);
  srand(seed);

  Problem problem;

  problem.ExecuteBeamSearch();

  return 0;
}
