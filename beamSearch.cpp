#include "beamSearch.hpp"

void BeamSearch::GenInitialRandomStates() 
{
  m_knapsacks[0].AddItem(0);
  m_knapsacks[1].AddItem(1);
  m_knapsacks[2].AddItem(2);
  m_knapsacks[3].AddItem(3);
}

void BeamSearch::SortBorder() 
{
  // Precisa arrumar o problema dos elementos duplicados
  std::sort(std::begin(border), std::end(border), CompareTwoKnapsack);
}

void BeamSearch::GenSons()
{
  for(int i = 0; i < POPULATION; i++)
  {
    for(int j = 0; j < MAX_ITENS; j++)
    {
      if(!m_knapsacks[i].SearchItem(j))
      {
        border[tam] = m_knapsacks[i];
        border[tam].AddItem(j);
        tam++;
        Knapsack k = border[tam];
      }
    }
  }
}


void BeamSearch::SelectSons()
{
  for(int i = 0; i < POPULATION; i++)
  {
    m_knapsacks[i] = border[i];
  }
}

bool BeamSearch::CheckObjectiveStates()
{
  return true;
}

void BeamSearch::CleanBorder()
{
  // Precisa arrumar essa parte - O programa esá gastando muita memória
  for(int i = 0; i < tam; i++)
  {
    border[tam] = Knapsack();
  }
  tam = 0;
}

void BeamSearch::printBorder()
{
  for(int i = 0; i < tam; i++)
  {
    std::cout << "Custo-benefício (border): " << border[i].GetValue()/(float)border[i].GetWeight() << "( " << border[i].GetValue() << " / " << border[i].GetWeight
        () << ")" << std::endl;
  }
}

bool BeamSearch::CompareTwoKnapsack(Knapsack one, Knapsack two)
{
  return (one.GetValue()/(float)one.GetWeight() >= two.GetValue()/(float)two.GetWeight());
}

void BeamSearch::Execute()
{
  //while (true) 
  for(int i = 0; i < 5; i++)
  {
    GenSons();
    SortBorder();
    printBorder();
    if(!CheckObjectiveStates())
      break;
    SelectSons();
    CleanBorder();

    std::cout << std::endl << "---------------- Knapsacks ---------------" << std::endl;
    for(int j = 0; j < POPULATION; j++)
    {
      std::cout << m_knapsacks[j].GetValue()/(float)m_knapsacks[j].GetWeight() << std::endl;
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;
  }
}

BeamSearch::BeamSearch()
{
  GenInitialRandomStates();
}

BeamSearch::~BeamSearch()
{

}
