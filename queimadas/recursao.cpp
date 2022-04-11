#include <iostream>
#include <vector>
#include <string>

/*
    # - Arvore Verde
    . - Espaço Vazio
    o - Arvore Queimada

    Variáveis: 
    nl - Número de Linhas
    nc - Número de Colunas
    l,c - Linha e Coluna onde incia o fogo

    Regras:
    1 - Posição fora da matriz, retornar
    2 - Posição não for uma arvore, retornar
    3 - Queimar arvore
    4 - Recursão para todos os vizinhos

*/

void imprimir_matriz(std::vector<std::string> matriz){
    for(int i = 0; i < (int) matriz.size(); i++){
        std::cout << matriz[i] << "\n";
    }
}

void tocar_fogo(std::vector<std::string> &matriz, int l, int c){
    int nl = matriz.size();
    int nc = matriz[0].size();
    if(l > nl || c > nc){}
    
        
    
}

int main(){



}