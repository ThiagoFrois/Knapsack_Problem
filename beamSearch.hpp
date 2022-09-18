#pragma once

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include "knapsack.hpp"

#define POPULATION 4

class BeamSearch
{
  public:
    void GenInitialRandomStates();
    
    void SortBorder();
    
    void GenSons();
    void SelectSons();
    
    bool CheckObjectiveStates();

    bool compareTwoKnapsack(Knapsack one, Knapsack two);

    void Execute();

    BeamSearch();
    ~BeamSearch();

  private:
    Knapsack m_knapsacks[POPULATION];
    
    std::vector<Knapsack> m_border;
  };
