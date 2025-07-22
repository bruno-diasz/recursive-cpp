#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long fatorial_recursivo(int n)
{
    if (n == 0)
        return 1;
    return (fatorial_recursivo(n - 1) * n);
}

long long fatorial_interativo(int n)
{
    long long fatorial = 1;
    for (int i = 1; i <= n; i++)
        fatorial *= i;
    return fatorial;
}

long long fibonacci_recursivo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

long long fibonacci_interativo(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long a = 0, b = 1, fibonacci = 0;
    for (int i = 2; i <= n; i++)
    {
        fibonacci = a + b;
        a = b;
        b = fibonacci;
    }
    return fibonacci;
}

int main()
{
    while (true)
    {
        int op = 0;
        cout << "Qual algoritmo você deseja executar ?" << endl;
        cout << "[1]Fatorial | [2]Fibonacci | [9]Encerrar" << endl;
        cin >> op;

        if (op == 1)
        {
            op = 0;
            cout << "Qual versão do algoritmo deseja executar?" << endl;
            cout << "[1]Fatorial Recursiva | [2]Fatorial Interativa | [3]Análise de Desempenho" << endl;
            cin >> op;

            if (op == 1)
            {
                long long n, resultado;
                cout << "Digite 1 número para executar o algoritmo: " << endl;
                cin >> n;
                resultado = fatorial_recursivo(n);
                cout << "O fatorial de " << n << "! = " << resultado << endl;
            }
            else if (op == 2)
            {
                long long n, resultado;
                cout << "Digite 1 número para executar o algoritmo: " << endl;
                cin >> n;
                resultado = fatorial_interativo(n);
                cout << "O fatorial de " << n << "! = " << resultado << endl;
            }
            else if (op == 3)
            {
                ofstream arquivo("fatorial_analise.txt", ios::app);
                arquivo << "entrada,tempo_recursivo_ns,tempo_iterativo_ns\n";


                for (int i = 0; i < 5; i++)
                {
                    int n;
                    cout << "Digite 1 número para iniciar a análise: " << endl;
                    cin >> n;

                    auto inicio_rec = high_resolution_clock::now();
                    long long resultado_recursivo = fatorial_recursivo(n);
                    auto fim_rec = high_resolution_clock::now();

                    auto inicio_int = high_resolution_clock::now();
                    long long resultado_interativo = fatorial_interativo(n);
                    auto fim_int = high_resolution_clock::now();

                    auto duracao_rec = duration_cast<nanoseconds>(fim_rec - inicio_rec);
                    auto duracao_int = duration_cast<nanoseconds>(fim_int - inicio_int);

                    arquivo << n << "," << duracao_rec.count() << "," << duracao_int.count() << endl;
                }
                arquivo.close();
            }
        }
        else if (op == 2)
        {
            op = 0;
            cout << "Qual versão do algoritmo deseja executar?" << endl;
            cout << "[1]Fibonacci Recursiva | [2]Fibonacci Interativa | [3]Análise de Desempenho" << endl;
            cin >> op;

            if (op == 1)
            {
                long long n, resultado;
                cout << "Digite 1 número para executar o algoritmo: " << endl;
                cin >> n;
                resultado = fibonacci_recursivo(n);
                cout << "O fibonacci de " << n << " = " << resultado << endl;
            }
            else if (op == 2)
            {
                long long n, resultado;
                cout << "Digite 1 número para executar o algoritmo: " << endl;
                cin >> n;
                resultado = fibonacci_interativo(n);
                cout << "O fibonacci de " << n << " = " << resultado << endl;
            }
            else if (op == 3)
            {
                ofstream arquivo("fibonacci_analise.txt", ios::app);
                arquivo << "entrada,tempo_recursivo_ns,tempo_iterativo_ns\n";

                for (int i = 0; i < 5; i++)
                {
                    int n;
                    cout << "Digite 1 número para iniciar a análise: " << endl;
                    cin >> n;

                    auto inicio_rec = high_resolution_clock::now();
                    long long resultado_recursivo = fibonacci_recursivo(n);
                    auto fim_rec = high_resolution_clock::now();

                    auto inicio_int = high_resolution_clock::now();
                    long long resultado_interativo = fibonacci_interativo(n);
                    auto fim_int = high_resolution_clock::now();

                    auto duracao_rec = duration_cast<nanoseconds>(fim_rec - inicio_rec);
                    auto duracao_int = duration_cast<nanoseconds>(fim_int - inicio_int);
                    arquivo << n << "," << duracao_rec.count() << "," << duracao_int.count() << endl;

                }
                arquivo.close();
            }
        }
        else if (op == 9)
        {
            break;
        }
    }

    return 0;
}
