#pragma once

#include "beamSearch.hpp"

class Problem
{
  public:
    void ExecuteBeamSearch();
    void ExecuteGeneticAlgorithm();

    Problem();
    ~Problem();

  private:
    BeamSearch agentOne;
};

