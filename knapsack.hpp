#pragma once

#include <iostream>

#define MAX_ITENS 4 // Total de itens que existem
#define CAPACITY 100 // Peso máximo que mochila suporta

struct Item
{
  int m_weight{1};
  int m_value{1};

  Item()
  {
    m_weight = 1;
    m_value = 1;
  }
};

class Knapsack
{
  public:
    int GetWeight();
    int GetValue();

    void RemoveItem(int itemNumber);
    void AddItem(int itemNumber);
    bool SearchItem(int itemNumber);

    Knapsack();
    ~Knapsack();

    Item m_itens[MAX_ITENS];
  private:
    
    int m_itensWithin[10]{0};

    int m_totalWeight;
    int m_totalValue;

};
