#include <iostream>
 
// Recursão de calda - Melhor otimizado
int soma_vetor(int vet[], int size){
    return size == 0 ? 0 : vet[0] + soma_vetor(vet + 1, size - 1);
}
// Recursão do inicio para o fim / valor armazenado no acc
int soma_vetor2(int vet[], int size, int acc = 0){
    return size == 0 ? acc : soma_vetor2(vet + 1, size - 1, acc + vet[0]);
}

 
int main() {
    int vet[] {3,2,1,5,6,7,2,9};
    int size = sizeof(vet) / sizeof(int);
    std::cout << "Calda: " << soma_vetor(vet, size) << std::endl;
    std::cout << "Inicio: " <<soma_vetor2(vet, size) << std::endl;
    
}