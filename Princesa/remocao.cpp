#include <iostream>
#include <vector>

void imprimir_vetor(std::vector<int> vet, int sword){
    for (int i = 0; i < (int) vet.size(); i++){
           std::cout <<vet[i] << "|" << i << (i == sword ? "> " : "  ") ;
    }
    std::cout << std::endl;    
}

int main(){
    int size{}, sword {};
    std::cin >> size >> sword;
    std::vector<int> vet(size);
    for(int i = 1; i < size; i++){
        vet[i] = i;
    }
    sword -= 1;
    
    for(int i = vet.size(); i > 1; i--){
        imprimir_vetor(vet, sword);
        sword = (sword + 1) % vet.size();
        vet.erase(vet.begin() + sword);
        sword = sword % vet.size();
    }
}
