//45:58m
#include <iostream>

//CONSTANTES
const int LADO {10};

/* 
    VARIAVEIS
    -snake_case = peso_dois
    -camelCase = PesoDois
    -inicia minusculo = pesoDois
*/

/*
    TIPOS PRIMITIVOS
    char umaLetra = 'w';
    int idade = 37
    bool temAlgo = true;
    float peso = 86.7f;
    double altura = 1.97
*/

/*
    PRECISÃO FLOAT
    #include <cstdio>
    printf("%02d:%02d\n", variavel, variavel)
    PRECISÃO DE 2 CASAS DECIMAIS
    printf("%.2f\n", variavel)
*/

/*
    CONVERSÃO DE TIPOS

*/

int main(){
    //INICIALIZAÇÃO
    int z {10};
    //ENTRADA
    std::cin >> z;
    //SAIDA     
    std::cout << "Numero Digitado: \n" << z;
}

//g++ -std=c++20 -Wall -Wextra -Werror solver.cpp -o solver.out