#include <iostream>
#include <vector>

void imprimir_vetor(std::vector<int> vet, int sword){
    for (int i = 0; i < (int) vet.size(); i++){
           std::cout <<vet[i] << "|" << i << (i == sword ? "> " : "  ") ;
    }
    std::cout << std::endl;    
}

int encontrar_vivo(std::vector<int>& v, int pos){
    do{
        // procura o valor true - mod circular
        pos = (pos + 1) % v.size();
    }while(v[pos] == false);
    return pos;
}

int main(){
    int size{}, sword {};
    std::cin >> size >> sword;
    std::vector<int> vet(size, true);
    sword -= 1;
    for(int i = vet.size(); i > 1; i--){
        imprimir_vetor(vet, sword);
        sword = encontrar_vivo(vet, sword);
        vet[sword] = false;
        sword = encontrar_vivo(vet, sword);
    }
}
