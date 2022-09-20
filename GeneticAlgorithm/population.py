#Classe que gera uma população de acordo com o tamanho recebido e a capacidade da mochila para validar o estado(Individuo) gerado
from individuo import Individuo
import random

class Population:
    def __init__(self, tam, cap, itens):
        self.populacaoAtual = []
        self.proxGeracao = []
        for i in range(tam):
            self.populacaoAtual.append(Individuo(cap, itens))

        print("População iniciada! \n")
        for i in range(len(self.populacaoAtual)):
            print('Individuo: ' + str(i))
            print('Dna: ' + str(self.populacaoAtual[i].dna))
            print('Fitness: ' + str(self.populacaoAtual[i].fitness))

    def torneio(self):
        populacao = []
        candidatos = []

        for i in self.populacaoAtual:
            populacao.append(i)

        while populacao != []:
            if len(populacao) > 1:
                duelistas = random.sample(populacao, 2)
                candidatos.append(max(duelistas, key = lambda individuo: individuo.fitness))
                for i in range(len(duelistas)):
                    populacao.remove(duelistas[i])
            else:
                populacao.clear()
            #    duelistas = populacao
            #    candidatos.append(duelistas[0])


        print("\n\nCandidatos para Cruzamento selecionados!")
        return candidatos


    def cruzamento(self, candidatos):
        i = len(candidatos[0].dna)

        dnaProxGeracao = []
        #print("\nPonto de divisao do dna: "+ str(corte))
        print("\n\nGerando Filhos!")

        for n in range(0,len(candidatos),2):
            corte = random.randint(1,i-1)
            dnaFilho1 = []
            dnaFilho2 = []

            if n+1 < len(candidatos):
                for m in range(corte):
                    dnaFilho1.append(candidatos[n].dna[m])
                    dnaFilho2.append(candidatos[n+1].dna[m])
                for m in range(corte,i):
                    dnaFilho2.append(candidatos[n].dna[m])
                    dnaFilho1.append(candidatos[n+1].dna[m])
                dnaProxGeracao.append(dnaFilho1)
                dnaProxGeracao.append(dnaFilho2)

        print("Filhos Gerados!")
        candidatos.clear()
        return(dnaProxGeracao)
#-----


    def gerarProxGeracao(self, dnaProxGeracao, cap, itens):
        print("Calculando geração seguinte!")
        for i in range(len(dnaProxGeracao)):
            ind = Individuo(cap, itens)
            ind.dna = dnaProxGeracao[i]
            if ind.calculaFitness(itens) <= cap:
                self.proxGeracao.append(ind)

    def escolherSobreviventes(self):
        populacaoTotal = []

        for o in self.populacaoAtual:
            populacaoTotal.append(o)
        for o in self.proxGeracao:
            populacaoTotal.append(o)

        populacaoTotal = sorted(populacaoTotal, key = lambda individuo: individuo.dna, reverse = 1)

        x = len(self.populacaoAtual)

        for i in range(len(populacaoTotal)):
            if i+1 < len(populacaoTotal):
                if populacaoTotal[i].dna == populacaoTotal[i+1].dna and len(populacaoTotal) > x:
                    populacaoTotal.remove(populacaoTotal[i])


        populacaoTotal = sorted(populacaoTotal, key = lambda individuo: individuo.fitness, reverse = 1)


        self.populacaoAtual.clear()
        for i in range(x):
            self.populacaoAtual.append(populacaoTotal[i])
        self.proxGeracao.clear()
