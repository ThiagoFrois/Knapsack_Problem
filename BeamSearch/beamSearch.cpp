#include "beamSearch.hpp"

void BeamSearch::RamdomNumbers(int a, int b)
{
  for(int i = 0; i < 10; i++)
  {
    std::cout << rand() % b << std::endl;
  }
}

void BeamSearch::GenInitialRandomStates() 
{
  int number;

  int choices[MAX_ITENS]{0};
  //std::cout << "Gerando estado iniciais..." << std::endl;

  std::cout << "Geração 0" << std::endl;
  for(int i = 0; i < POPULATION; i++)
  {
    m_knapsacks[i].Init();
    number = rand()%MAX_ITENS;
    number = rand()%MAX_ITENS;
    while(choices[number] == 1)
    {
      number = rand()%MAX_ITENS;
      number = rand()%MAX_ITENS;
    }
    //std::cout << "Adicionando item: " << number << std::endl;
    std::cout << "Mochila " << i << ": ";
    m_knapsacks[i].AddItem(number);
    tam++;
    border[i] = m_knapsacks[i];
    std::cout << "Custo-benefício (border): " << m_knapsacks[i].GetValue()/(float)m_knapsacks[i].GetWeight() << "( " << m_knapsacks[i].GetValue() << " / " << m_knapsacks[i].GetWeight() << ")" << std::endl;
    choices[number] = 1;
  }

  /*m_knapsacks[0].AddItem(0);
  m_knapsacks[1].AddItem(1);
  m_knapsacks[2].AddItem(2);
  m_knapsacks[3].AddItem(3);

  std::cout << "Geração 0" << std::endl;
  for(int i = 0; i < POPULATION; i++)
  {
    std::cout << "Custo-benefício (border): " << m_knapsacks[i].GetValue()/(float)m_knapsacks[i].GetWeight() << "( " << m_knapsacks[i].GetValue() << " / " << m_knapsacks[i].GetWeight
        () << ")" << std::endl;
  }*/
}

void BeamSearch::SortBorder() 
{
  // Precisa arrumar o problema dos elementos duplicados
  std::sort(border, border + tam, CompareTwoKnapsack);
}

void BeamSearch::GenSons()
{
  // Gera todos os filhos dde cada estado
  // Para estados que ultrapassam o a capacidade da atribuir custo-benefício 0
  for(int i = 0; i < POPULATION; i++)
  {
    for(int j = 0; j < MAX_ITENS; j++)
    {
      if(!m_knapsacks[i].SearchItem(j))
      {
        border[tam] = m_knapsacks[i];
        //std::cout << "Peso antigo: " << border[tam].GetWeight() << std::endl;
        border[tam].AddItem(j);
        //std::cout << "Resultado: " << border[tam].GetValue()/(float)border[tam].GetWeight() << std::endl;
        //if (border[tam].GetWeight() > CAPACITY)
          //border[tam].SetWeight(0);
        //else if (border[tam].GetWeight() == CAPACITY)
          //border[tam] = m_knapsacks[i];  
        //std::cout << "Peso atual: " << border[tam].GetWeight() << std::endl;
        border[tam].m_lastItem = j;
        tam++;
      }
    }
  }
}


void BeamSearch::SelectSons()
{
  // Seleciona os k melhores filhos com base na ordenação da fronteira
  printf("-----------------------\n");
  for(int i = 0; i < POPULATION; i++)
  {
    m_knapsacks[i] = border[i];
    printf("Escolhidos: %d %d\n", m_knapsacks[i].GetValue(), m_knapsacks[i].GetWeight());
  }
  printf("-----------------------\n");
}

bool BeamSearch::CheckObjectiveStates()
{

  if (border[0].GetWeight() >= CAPACITY)
  {
    //border[0].RemoveItem(border[0].m_lastItem);
    //std::cout << "Weight: " << border[0].GetWeight() << std::endl;
    return true;
  }

  // Precisa implementar a verificação de objetivo
  // Provavelmente será não ser possível inserir mais nenhum item na mochila.
  return false;
}

void BeamSearch::CleanBorder()
{
  // Precisa arrumar essa parte - O programa esá gastando muita memória
  for(int i = 0; i < tam; i++)
  {
    //border[tam].Init();
  }

  tam = 0;
}

void BeamSearch::printBorder()
{
  for(int i = 0; i < tam; i++)
  {
    std::cout << "Mochila " << i << ": ";
    std::cout << "Custo-benefício (border): " << border[i].GetValue()/(float)border[i].GetWeight() << "( " << border[i].GetValue() << " / " << border[i].GetWeight
        () << ")" << std::endl;
  }
}

bool BeamSearch::CompareTwoKnapsack(Knapsack one, Knapsack two)
{
  // Função de comparação entre dois estados da mochila
  return (one.GetValue()/(float)one.GetWeight() >= two.GetValue()/(float)two.GetWeight());
}

void BeamSearch::Execute()
{
  // Algoritmo do Beam Search
  // Precisa implementar a verificação para parar somente quando atingir o objetivo, não for possível inserir mais nenhum item na mochila.
  int i = 0;
  /*tam = 0;
  int flag = false;
  for(int j = 0; j < POPULATION; j++)
  {
    if (m_knapsacks[i].GetWeight() >= CAPACITY)
    {
      flag = true;
      break;
    }
  }

  if(flag)
    return;*/

  SortBorder();
  if (border[0].GetWeight() >= CAPACITY)
  {
    std::cout << "Estado final: " << border[0].GetValue() << " " << border[0].GetWeight() << std::endl;
    return;
  }

  while (true) 
  {
    CleanBorder();
    std::cout << "Geração " << i + 1 << std::endl;
    i++;
    GenSons();
    //printBorder();
    SortBorder();
    printBorder();
    if(CheckObjectiveStates())
    {
      std::cout << "Estado final: " << m_knapsacks[0].GetValue() << " " << m_knapsacks[0].GetWeight() << std::endl;
      break;
    }
    //std::cout << "Border: " << border[0].GetWeight() << std::endl;
    SelectSons();
    // Comentário inicio
    /*std::cout << std::endl << "---------------- Knapsacks ---------------" << std::endl;
    for(int j = 0; j < POPULATION; j++)
    {
      std::cout << m_knapsacks[j].GetValue()/(float)m_knapsacks[j].GetWeight() << std::endl;
    }
    std::cout << std::endl << "------------------------------------------" << std::endl;*/
    // Comentário fim
  }
}

BeamSearch::BeamSearch()
{
  // Gera os estados iniciais aleatórios da mochila
  GenInitialRandomStates();
}

BeamSearch::~BeamSearch()
{

}
