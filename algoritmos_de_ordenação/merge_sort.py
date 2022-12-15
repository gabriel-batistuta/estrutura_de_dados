import timeit
from pytools import file_read_vector, write_results

def merge_sort(lista):
    esquerda = lista[:len(lista)//2]
    direita = lista[len(lista)//2:]

    if len(esquerda) > 2:
        esquerda = merge_sort(esquerda)
    elif len(esquerda) == 2:
        e_part1 = esquerda[0]
        e_part2 = esquerda[1]
        esquerda = []

        if e_part1 <= 1:
            esquerda.append(e_part1)
            esquerda.append(e_part2)
        else:
            esquerda.append(e_part2)
            esquerda.append(e_part1)

    if len(direita) > 2:
        direita = merge_sort(direita)
    elif len(direita) == 2:
        d_part1 = direita[0]
        d_part2 = direita[1]
        direita = []

        if d_part1 <= 1:
            direita.append(d_part1)
            esquerda.append(d_part2)
        else:
            direita.append(d_part2)
            direita.append(d_part1)

    temp_lista = esquerda + direita
    lista = []
    for x in range(len(temp_lista)):
        lista.append(min(temp_lista))
        del(temp_lista[temp_lista.index(min(temp_lista))])

    return lista


if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    vetor = merge_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "heap_sort")
