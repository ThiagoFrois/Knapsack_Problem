#pragma once

#include <vector>

#include "knapsack.hpp"

#define POPULATION 4

class BeamSearch
{
  public:
    void GenInitialRandomStates();
    void SortBorder();
    void GenSons();
    void Execute();

    BeamSearch();
    ~BeamSearch();

  private:
    Knapsack m_knapsacks[POPULATION];
    
    std::vector<Knapsack> m_border;
  };
