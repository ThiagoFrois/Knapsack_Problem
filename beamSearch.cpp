#include "beamSearch.hpp"

void BeamSearch::GenInitialRandomStates() 
{
  // Gerar k número aleatórios, um para cada uma das k mochilas.

  // Implentação sem gerar aleatóriamente
  //std::cout << m_knapsacks[0].GetValue() << " " << m_knapsacks[0].GetWeight() << std::endl;
  m_knapsacks[0].AddItem(9);
  std::cout << "Mochila 01: " << m_knapsacks[0].GetValue()/(float)m_knapsacks[0].GetWeight() << std::endl;
  m_knapsacks[1].AddItem(1);
  std::cout << "Mochila 02: " << m_knapsacks[1].GetValue()/(float)m_knapsacks[1].GetWeight() << std::endl;
  m_knapsacks[2].AddItem(3);
  std::cout << "Mochila 03: " << m_knapsacks[2].GetValue()/(float)m_knapsacks[2].GetWeight() << std::endl;
  m_knapsacks[3].AddItem(7);
  std::cout << "Mochila 04: " << m_knapsacks[3].GetValue()/(float)m_knapsacks[3].GetWeight() << std::endl << std::endl;
}

void BeamSearch::SortBorder() 
{
  //sort(m_border.begin(), m_border.end(), compareTwoKnapsack);
}

void BeamSearch::GenSons()
{
  for(int i = 0; i < POPULATION; i++)
  {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Mochila " << i + 1 << std::endl;
    std::cout << "------------------------------------" << std::endl;
    for(int j = 0; j < MAX_ITENS; j++)
    {
      if(!m_knapsacks[i].SearchItem(j))
      {
        m_border.push_back(m_knapsacks[i]);
        m_border.front().AddItem(j);
        //std::cout << "Weight: " << m_border.front().GetWeight() << std::endl;
        //std::cout << "Value: " << m_border.front().GetValue() << std::endl;
        std::cout << "Medida: " << m_border.front().GetValue()/(float)m_border.front().GetWeight() << std::endl;
      }
    }
  }
}


void BeamSearch::SelectSons()
{
  for(int i = 0; i < POPULATION; i++)
  {
    m_knapsacks[i] = m_border[i];
  }
}

bool BeamSearch::CheckObjectiveStates()
{
  return true;
}

bool BeamSearch::compareTwoKnapsack(Knapsack one, Knapsack two)
{
  return one.GetValue()/one.GetWeight() > two.GetValue()/two.GetWeight();
}

void BeamSearch::Execute()
{
  while (true) 
  {
    GenSons();
    SortBorder();
    if(CheckObjectiveStates())
      break;
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
