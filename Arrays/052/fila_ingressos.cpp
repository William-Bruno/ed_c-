#include <iostream>
#include <vector>
#include <algorithm>

int pos(std::vector<int> vet, int value){
    for(int i = 0; i <(int) vet.size(); i++)
        if(vet[i] == value)
            return i;
    return -1;
}

std::vector<int> fila(std::vector<int>& vet, std::vector<int>& aux){
    for(int i = 0; i<(int) aux.size();i++)
        vet.erase(begin(vet) + pos(vet, aux[i]));   
    return vet;
}

void print(std::vector<int> vet){
    std::cout << "[ ";
    for(auto elem: vet){
        std::cout << elem << " ";
    }
    std::cout << "] " << std::endl;
}

int main() {
    int N{};
    std::cin >> N;
    std::vector<int> vet(N);
    for(int i = 0; i < N; i++){
        std::cin >> vet[i];
    }
    int v{};
    std::cin >> v;
    std::vector<int> M(v);
    if(v > 0){
        for(int j = 0; j < v; j++){
            std::cin >> M[j];
        }
    }
    fila(vet, M);
    print(vet);
}