import subprocess
import os
from enum import Enum
import numpy as np

################
# INPUTS
################
N_REPETICOES = 1
rodar_algoritmos = [1,2,3,4]
rodar_listas = [6]
nome_artefato = "lento"
nome_exe = "library_sort"
    

################
# CONSTANTES
################
raiz = os.path.abspath(os.path.dirname(__file__))
print(f"{raiz}")
EXE = os.path.join(raiz, nome_exe)
print(f"{EXE}")
PATH_RESULTADOS = os.path.join(raiz, "resultados")
ARQUIVO_FINAL = os.path.join(PATH_RESULTADOS, f'resultado_{nome_artefato}.txt')
dic_listas = {1: "ordenada",2: "inversa",3: "quase",4: "aleatoria"}
dic_tamanho = {1: "1e1",2: "1e2",3: "1e3",4: "1e4",5: "1e5",6: "1e6"}



#################
# RODAR ALGORITMO
#################
result_tempo=[]
result_comp=[]
result_regis=[]
print(dic_tamanho[2])
for algo in rodar_algoritmos:
    for qtde_lista in rodar_listas:
        print(f'RUN: {dic_listas[algo]} com {dic_tamanho[qtde_lista]} itens...')
        result_tempo=[]
        result_comp=[]
        result_regis=[]
        for _ in range(N_REPETICOES):
            output = subprocess.getoutput(f'{EXE} {algo} {qtde_lista}')
            metrica = output.split(';') 
            result_tempo.append(float(metrica[0].split('=')[1]))
            result_comp.append(float(metrica[1].split('=')[1]))
            result_regis.append(float(metrica[2].split('=')[1]))
            
        print("... calcular resultados")
        result_tempo = np.array(result_tempo)
        result_comp = np.array(result_comp)
        result_regis = np.array(result_regis)

        tempo_media = np.mean(result_tempo)
        tempo_std = np.std(result_tempo)
        
        comp_media = np.mean(result_comp)
        comp_std = np.std(result_comp)

        regis_media = np.mean(result_regis)
        regis_std = np.std(result_regis)

        print("...gerar txt")

        with open(ARQUIVO_FINAL, "a") as myfile:
            myfile.write(f"\n{dic_listas[algo]} {dic_tamanho[qtde_lista]}  \n")
            myfile.write(f"TEMPO: {tempo_media} e std:{tempo_std} \n")
            myfile.write(f"COMP: {comp_media} e std:{comp_std} \n")
            myfile.write(f"REGIS: {regis_media} e std:{regis_std} \n")
            myfile.write("------------------\n")
        # print(...)



