import timeit
from pytools import file_read_vector, write_results

def bubble_sort(lista):
    interruptor = 0

    while interruptor != len(lista)-1:
        interruptor = 0

        for indice in range(len(lista)-1):
            if lista[indice] > lista[indice+1]:
                x = lista[indice]
                lista[indice] = lista[indice+1]
                lista[indice+1] = x

        for indice in range(len(lista)-1):
            if lista[indice] < lista[indice+1]:
                interruptor += 1

    return lista

if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    vetor = bubble_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "bubble_sort")
