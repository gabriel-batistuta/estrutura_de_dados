import timeit
from pytools import file_read_vector, write_results

def quick_sort(lista):
    pivo = lista[0]
    esquerda = []
    direita = []

    for x in range(len(lista)):
        if lista[x] < pivo:
            esquerda.append(lista[x])
        elif lista[x] > pivo:
            direita.append(lista[x])

    if len(esquerda) > 0:
        esquerda = quick_sort(esquerda)
    if len(direita) > 0:
        direita = quick_sort(direita)

    lista = esquerda
    lista.append(pivo)
    for x in range(len(direita)):
        lista.append(direita[x])

    return lista


if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    quick_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "quick_sort")
