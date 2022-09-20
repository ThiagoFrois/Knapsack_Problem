#Classe que gera cada individuo da população
import random

class Individuo():
    """docstring for ."""

    def __init__(self, cap, itens):
        self.dna = []
        self.fitness = 0

        valid = 0
        while valid != 1:
            for i in range(len(itens)):
                self.dna.append(random.randint(0,1))
            if self.calculaFitness(itens) <= cap:
                valid = 1
            else:
                self.dna = []

    def calculaFitness(self, itens):
        peso = 0
        valor = 0
        n = len(self.dna)
        for i in range(n):
            if self.dna[i] == 1:
                peso = peso + itens[i][0]
                valor = valor + itens[i][1]
        if peso != 0:
            self.fitness = valor
        return peso
