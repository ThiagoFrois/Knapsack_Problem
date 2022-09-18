#include "knapsack.hpp"

int Knapsack::GetWeight()
{
  return m_totalWeight;
}

int Knapsack::GetValue()
{
 return m_totalValue;
}

void Knapsack::RemoveItem(int itemNumber)
{
  m_itensWithin[itemNumber] = 0;
  m_totalWeight -= m_itens[itemNumber].m_weight;
  m_totalValue -= m_itens[itemNumber].m_value;

}

void Knapsack::AddItem(int itemNumber)
{
  m_itensWithin[itemNumber] = 1;
  m_totalWeight += m_itens[itemNumber].m_weight;
  m_totalValue += m_itens[itemNumber].m_value;
}

Knapsack::Knapsack() : 
m_totalWeight{0}, m_totalValue{0}
{
  for(int i = 0; i < MAX_ITENS; i++) {
    m_itens[i].m_weight = (i + 1)*2;
    m_itens[i].m_value = (i + 1)*3;
  }
}

Knapsack::~Knapsack()
{

}
