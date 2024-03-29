#include "knapsack.hpp"

int Knapsack::GetWeight()
{
  return m_totalWeight;
}

int Knapsack::GetValue()
{
 return m_totalValue;
}

void Knapsack::SetWeight(int weight)
{
  m_totalWeight = weight;
}

void Knapsack::RemoveItem(int itemNumber)
{
  m_itensWithin[itemNumber] = 0;
  m_totalWeight -= m_itens[itemNumber].m_weight;
  m_totalValue -= m_itens[itemNumber].m_value;

}

void Knapsack::AddItem(int itemNumber)
{
  //std::cout << std::endl << "Adicionando: " << m_itens[itemNumber].m_value << " " << m_itens[itemNumber].m_weight << std::endl;

  //if (m_totalWeight + m_itens[itemNumber].m_weight <= CAPACITY)
  //{
    m_itensWithin[itemNumber] = 1;
    m_totalWeight += m_itens[itemNumber].m_weight;
    m_totalValue += m_itens[itemNumber].m_value;
    if (m_totalWeight > CAPACITY)
      m_totalValue = 0;
  //}
}

bool Knapsack::SearchItem(int itemNumber)
{
  if (m_itensWithin[itemNumber] == 1)
    return true;
  return false;
}

void Knapsack::Init()
{
  /*for(int i = 0; i < MAX_ITENS; i++)
  {
    m_itensWithin[i] = 0;
  }*/

  m_totalWeight = 0;
  m_totalValue = 0;

  m_itens[0].m_weight = 20;
  m_itens[0].m_value = 50;
  
  m_itens[1].m_weight = 5;
  m_itens[1].m_value = 10;

  m_itens[2].m_weight = 30;
  m_itens[2].m_value = 100;
  
  m_itens[3].m_weight = 14;
  m_itens[3].m_value = 3;
  
  m_itens[4].m_weight = 25;
  m_itens[4].m_value = 20;
  
  m_itens[5].m_weight = 9;
  m_itens[5].m_value = 22;
  
  m_itens[6].m_weight = 3;
  m_itens[6].m_value = 5;
  
  m_itens[7].m_weight = 7;
  m_itens[7].m_value = 7;
  
  m_itens[8].m_weight = 23;
  m_itens[8].m_value = 12;
  
  m_itens[9].m_weight = 6;
  m_itens[9].m_value = 2;
}

Knapsack::Knapsack() 
{
  Init();
}

Knapsack::~Knapsack()
{

}
