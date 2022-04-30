#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> rotacionar(std::vector<int>& vet, int r){
    std::vector<int> aux;
    //mod para circular
    r = r % vet.size();

    if(r == 0){
        return vet;
    }else{
        //do fim até a posição do elemento que será rotacionado
        for(int i = (int) vet.size() - 1; i > (int) vet.size() - 1 - r; --i){
            aux.push_back(vet[i]);
        }
        //ordena o vetor adicionado
        std::sort(aux.begin(), aux.end());

        //adiciona o restante dos elementos do vetor
        for(int i = 0; i < (int) vet.size() - r; ++i){
            aux.push_back(vet[i]);
        }
    }
    //limpando a mem
    vet.clear();
    //copia o vetor
    vet = aux;
    //limpa a mem
    aux.clear();
    return vet;
}

void print(std::vector<int> vet){
    std::cout << "[ ";
    for(auto elem: vet){
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}



int main(){
    int T, R;
    std::cin >> T;
    std::vector<int> vet;
    for(int i = 1; i <= T; i++){
        vet.push_back(i);
    }
    std::cin >> R;
    print(vet);
    rotacionar(vet, R);
    print(vet);
}