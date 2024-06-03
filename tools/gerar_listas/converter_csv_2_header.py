import csv
import os.path

##########
# GLOBAL #
##########
raiz = os.path.dirname(__file__)

##########
# FUNC   #
##########


def salvar_lista_header(lista, nome):
    N_lista = len(lista)
    file = os.path.join(raiz, 'output', f'lista_{nome}_{N_lista}.h')
    lista_to_save = ','.join([str(i) for i in lista])
    with open(f'{file}', 'w', newline='') as myfile:
        myfile.write(f"#pragma once\n")
        myfile.write(f"static int {nome}_{N_lista}[{N_lista}] = ")
        myfile.write(r"{ ")
        myfile.write(lista_to_save)
        myfile.write(r" };")

    print(f'lista_{nome}_{N_lista}.csv')


def carrregar_lista_csv(nome):
    csv_file_path = f'listas/{nome}.csv'
    print(csv_file_path)
    with open(csv_file_path, 'r') as file:
        csv_reader = csv.reader(file)
        data_list = []
        for row in csv_reader:
            data_list.append(row)

    lista_2_save = [int(i[0]) for i in data_list]
    # print(lista_2_save)
    return lista_2_save


if __name__ == '__main__':
    # for i in [10, 100, 1_000, 10_000, 100_000, 1_000_000]:
    #     gerar_lista_aleatoria(i)
    #     gerar_lista_inversa(i)
    #     gerar_lista_ordenada(i)
    import os

    folder = os.listdir('listas')
    folder.sort()
    for file in folder:
        nome = file.split('.')[0]
        # lista = carrregar_lista_csv(nome)
        # nome = nome.split('_')[1]
        print(nome)
        # salvar_lista_header(lista, nome)
