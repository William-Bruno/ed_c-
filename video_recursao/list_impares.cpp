#include <iostream>
#include <list>


std::list<int> impares(int vet[], int size){
    if(size == 0){
        return std::list<int>();
    }
    if(vet[0] % 2 == 0){
        return impares(vet + 1, size - 1);
    }
    auto lista = impares(vet + 1, size - 1);
    lista.push_front(vet[0]);
    return lista;
}
    
std::list<int> impares2(int *vet, int size, std::list<int> acc){
    if(size == 0){
        return acc;
    }
    if(vet[0] % 2 == 0){
        return impares2(vet + 1, size - 1, acc);
    }
    acc.push_back(vet[0]);
    return impares2(vet + 1, size - 1, acc);
}

int main() {
   
   int vet[] = {1,2,3,4,5,6,7,8,9};
   int size = sizeof(vet) /sizeof(int);
   std::list<int> lista;
   for(auto elem:impares(vet, size)){
       std::cout << elem << " ";
   }
   std::cout << std::endl;
   for(auto elem:impares2(vet, size, lista)){
       std::cout << elem << " ";
   }
   std::cout << std::endl;
   
   
   
}