#include <iostream>
#include <vector>

// FILTER
// clonar: retorna um novo vetor copiando os valores do vetor de entrada
std::vector<int> clonar(const std::vector<int>& v){
    std::vector<int> novo_vetor;
    for(int elem : v){
        novo_vetor.push_back(elem);
    }
    return novo_vetor;
}
// pegar_homens: retorne uma lista com os homens (valores positivos)
std::vector<int> pegar_homens(const std::vector<int>& v){
    std::vector<int> homens;
    for(int elem: v){
        if(elem > 0)
            homens.push_back(elem);
    }
    return homens;
}
// pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
std::vector<int> pegar_calmos(const std::vector<int>& v){
    std::vector<int> calmos;
    for(int elem : v)
        if(elem < 10 && elem > -10)
            calmos.push_back(elem);
    return calmos;        
}
// pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)
std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v){
    std::vector<int> mulheres_calmas;
    for(int elem : v)
        if(elem < 0 && elem > -10)
            mulheres_calmas.push_back(elem);
    return mulheres_calmas;
}

int main() {

}