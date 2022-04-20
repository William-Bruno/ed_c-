#include <iostream>
#include <climits>
 
int menor_elemento(int vet[], int size){
    if(size == 1)
        return vet[0];
    return std::min(vet[0], menor_elemento(vet + 1, size - 1));
}

int menor_elemento2(int vet[], int size, int acc = INT_MAX){
    if(size == 0)
        return acc;
    return menor_elemento2(vet + 1, size - 1, std::min(acc, vet[0]));
}
 
int main() {
    int vet[] {3,2,1,5,6,7,2,9};
    int size = sizeof(vet) / sizeof(int);

    std::cout << "Calda | Menor: " << menor_elemento(vet, size) << std::endl;
    std::cout << "Acumulador | Menor2: " << menor_elemento(vet, size) << std::endl;
}