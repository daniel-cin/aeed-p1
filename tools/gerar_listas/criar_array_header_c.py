import numpy as np
import os.path
from random import shuffle


##########
# GLOBAL #
##########
raiz = os.path.dirname(__file__) 
lista_ordenada = [int(i) for i in range(1_000_000)]

def salvar_lista_header(lista, N_lista, nome):
    file = os.path.join(raiz,'output', f'lista_{nome}_{N_lista}.h')
    lista_to_save = ','.join([str(i) for i in lista])
    with open(f'{file}', 'w', newline='') as myfile:
        myfile.write(f"#pragma once\n")
        myfile.write(f"static int {nome}_{N_lista}[{N_lista}] = ")
        myfile.write(r"{ ")
        myfile.write(lista_to_save)
        myfile.write(r" };")

        # wr = csv.writer(myfile, quoting=csv.QUOTE_NONNUMERIC, delimiter=f'\n')
        # wr.writerow(lista)
    print(f'lista_{nome}_{N_lista}.csv')



def gerar_lista_ordenada(N_lista):
    lista=lista_ordenada[0:N_lista]
    salvar_lista_header(lista, N_lista, "ordenada")

def gerar_lista_inversa(N_lista):
    lista=lista_ordenada[0:N_lista]
    lista.reverse()
    salvar_lista_header(lista, N_lista, "inversa")

def gerar_lista_aleatoria(N_lista):
    lista = np.array( lista_ordenada[0:N_lista] )
    np.random.shuffle(lista)
    salvar_lista_header(lista, N_lista, "aleatoria")
    
#TODO
def gerar_lista_quase_ordenada(N_lista,passo=10):
    lista=lista_ordenada[0:N_lista]
    for i in range(passo):
        inicio = i*passo
        fim = inicio + passo
        embaralhar = lista[inicio:fim]
        print(embaralhar)
        shuffle(embaralhar)
        print(embaralhar)
        lista[inicio:fim] = embaralhar

    print(lista)

    salvar_lista_header(lista, N_lista, "quase")
   


if __name__ == '__main__':
    # for i in [10, 100, 1_000, 10_000, 100_000, 1_000_000]:
    #     gerar_lista_aleatoria(i)
    #     gerar_lista_inversa(i)
    #     gerar_lista_ordenada(i)
    gerar_lista_inversa(1_000_000)

    # gerar_lista_quase_ordenada(1_000_000, passo=50_000)
    #passos: 3, 10, 100, 500, 5000, 50_000

    




