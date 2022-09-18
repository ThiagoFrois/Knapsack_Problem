#include "beamSearch.hpp"

void BeamSearch::GenInitialRandomStates() 
{
  // Gerar k número aleatórios, um para cada uma das k mochilas.

  // Implentação sem gerar aleatóriamente
  for(int i = 0; i < POPULATION; i++) {
    m_knapsacks[i].AddItem(i + 1); 
  }
}

void BeamSearch::SortBorder() 
{

}

void BeamSearch::GenSons()
{

}

void BeamSearch::SelectSons()
{

}

bool BeamSearch::CheckObjectiveStates()
{
  while (True) 
  {
      GenSons();
      SortBorder();
      if(CheckObjectiveStates())
        return;
      SelectSons();
  }
}

BeamSearch::BeamSearch()
{
  GenInitialRandomStates();
}

BeamSearch::~BeamSearch()
{

}
