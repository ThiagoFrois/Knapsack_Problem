#pragma once

#define MAX_ITENS 10 // Total de itens que existem
#define CAPACITY 100 // Peso máximo que mochila suporta

struct Item
{
  int m_weight;
  int m_value;
};

class Knapsack
{
  public:
    int GetWeight();
    int GetValue();

    void RemoveItem(int itemNumber);
    void AddItem(int itemNumber);

    Knapsack();
    ~Knapsack();

  private:
    Item m_itens[MAX_ITENS];

    int m_itensWithin[10]{0};

    int m_totalWeight;
    int m_totalValue;

};
