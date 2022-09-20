## Lista de itens Peso,valor
from population import Population

cap = 50
tamPopulacao = 100
geracoes = 40

itens = [(3,1), (8,3),(12,1),(2,8),(4,3),(4,2),(5,8),(1,5),(1,1),(8,1),(6,6),(4,3),(3,2),(3,5),(5,2),(7,3),(3,8),(5,9),(7,3),(4,2),(3,4),(7,5),(2,4),(3,3),(5,1),(4,3),(3,2),(7,15), (2,9), (12,50)]
populacao = Population(tamPopulacao, cap, itens)

print("\n-------------INICIO-----------------------------------------------------------------------------------------------------\n")


for i in range(geracoes):
    print("\nGeração: " + str(i))
    candidatos = populacao.torneio()
    dnaProxGeracao = populacao.cruzamento(candidatos)
    populacao.gerarProxGeracao(dnaProxGeracao, cap, itens)
    populacao.escolherSobreviventes()

print('\n\nSelecionados: ')
for o in populacao.populacaoAtual:
    print('Dna do Individuo: '+ str(o.dna))
    print('Fitness: '+ str(o.fitness))
