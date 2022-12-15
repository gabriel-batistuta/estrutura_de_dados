import timeit
from pytools import file_read_vector, write_results

def shell_sort(lista):
    for dist in range(len(lista), 0, -1):
        inicio = 0

        while inicio + dist < len(lista):
            if lista[inicio] > lista[inicio+dist]:
                comut = lista[inicio]
                lista[inicio] = lista[inicio+dist]
                lista[inicio+dist] = comut

            inicio += 1

    return lista

if __name__ == "__main__":
    vetor = file_read_vector()

    start = timeit.default_timer()
    vetor = shell_sort(vetor)
    stop = timeit.default_timer()

    write_results(stop - start, "shell_sort")

#comentarios pos creditos
'''a variavel dist quer dizer distancia, a cada iteração do laço while,
o algoritmo verifica se o elemento do indice zero é maior ou menor do
que o elemento do indice zero mais distancia, caso seja maior, será comutado

a cada iteração do laço for a variavel dist que representa uma distancia entre
os elementos comparados é decrementada, quando dist vale 1, o comportamento
do algoritmo se assemelha ao comportamento do bubble sort'''
