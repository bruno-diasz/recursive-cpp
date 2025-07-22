import pandas as pd
import matplotlib.pyplot as plt

arquivo_fatorial = "fibonacci_analise.txt"
dados_fatorial = pd.read_csv(arquivo_fatorial, sep=',')

eixo_y1 = dados_fatorial["tempo_recursivo_ns"]
eixo_y2 = dados_fatorial["tempo_iterativo_ns"]

eixo_x = dados_fatorial["entrada"]

plt.plot(eixo_x, eixo_y1,marker="o", color="b", label="Fibonacci Recursivo")
plt.plot(eixo_x, eixo_y2,marker="o", color="r", label="Fibonacci Iterativo")

plt.ylabel("Tempo(ns)")
plt.xlabel("Entrada")
plt.legend()

plt.grid(True)

plt.savefig("fibonacci_graf")

plt.show()