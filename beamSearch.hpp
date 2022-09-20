#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "knapsack.hpp"

#define POPULATION 2

class BeamSearch
{
  public:
    void RamdomNumbers(int a, int b);

    void GenInitialRandomStates();
    
    void SortBorder();
    
    void GenSons();
    void SelectSons();
    
    bool CheckObjectiveStates();

    void CleanBorder();

    void printBorder();

    static bool CompareTwoKnapsack(Knapsack one, Knapsack two);

    void Execute();

    BeamSearch();
    ~BeamSearch();

  private:
    Knapsack m_knapsacks[POPULATION]{Knapsack()};
    
    std::vector<Knapsack> m_border;

    Knapsack border[POPULATION*(MAX_ITENS + 2)];

    int tam{0};
};
