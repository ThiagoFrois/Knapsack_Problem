#pragma once

#include <iostream>

#define MAX_ITENS 10 // Total de itens que existem
#define CAPACITY 30 // Peso máximo que mochila suporta

struct Item
{
  int m_weight{0};
  int m_value{0};
};

class Knapsack
{
  public:
    int GetWeight();
    int GetValue();

    void SetWeight(int weight);

    void RemoveItem(int itemNumber);
    void AddItem(int itemNumber);
    bool SearchItem(int itemNumber);

    Knapsack();
    ~Knapsack();

    void Init(); 


    Item m_itens[MAX_ITENS];

    int m_lastItem;

    int weight;
    int value;
  private:
    
    int m_itensWithin[MAX_ITENS]{0};

    int m_totalWeight;
    int m_totalValue;

   };
