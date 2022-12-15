import os
import random

def file_write_vector(num=10000):
    arquivo = open("vetor.txt", "w")
    vetor = [x for x in range(10000)]
    random.shuffle(vetor)

    for x in range(len(vetor)):
        arquivo.write("{}\n".format(vetor[x]))
    arquivo.close()

def file_read_vector():
    arquivo = open("vetor.txt", "r")
    vetor = list()

    for x in arquivo:
        vetor.append(int(x.rstrip("\n")))
    arquivo.close()

    return vetor

def write_results(result_time, result_name):
    if os.path.exists("results.csv"):
        data_results = list()
        arquivo = open("results.csv", "r")
        for x in arquivo:
            data_results.append(x.rstrip("\n"))
        arquivo.close()

    else:
        data_results = list()
        data_results.append("nome,tempo em segundos")

    arquivo = open("results.csv", "w")
    data_results.append("{},{}".format(result_name, result_time))

    for x in range(len(data_results)):
        arquivo.write("{}\n".format(data_results[x]))
    arquivo.close()

if __name__ == "__main__":
    file_write()
