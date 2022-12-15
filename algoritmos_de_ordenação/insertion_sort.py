import timeit
from pytools import file_read_vector, write_results

def insertion_sort(lista):
    for indice in range(1, len(lista)):
        indice2 = indice
        elemento = lista[indice]

        while lista[indice] < lista[indice2-1] and indice2 > 0:
            indice2 -= 1
        else:
            del(lista[indice])
            lista.insert(indice2, elemento)

    return lista

if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    vetor = insertion_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "insertion_sort")
