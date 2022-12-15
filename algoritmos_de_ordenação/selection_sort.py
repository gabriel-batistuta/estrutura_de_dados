import timeit
from pytools import file_read_vector, write_results

def selection_sort(lista):
    lista_aux = []
    tamanho = len(lista)

    while len(lista_aux) != tamanho:
        lista_aux.append(min(lista))
        del(lista[lista.index(min(lista))])

    lista = lista_aux

    return lista

if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    vetor = selection_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "selection_sort")
