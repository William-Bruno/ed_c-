#include <iostream>

int index_of(int vet[], int size, int value){
    if(size == 0){
        return -1;
    }
    if(vet[0] == value){
        return 0;
    } 
    int dist = index_of(vet + 1, size - 1, value);
    return dist == -1 ? -1 : dist + 1;
}
   
int index_of2(int *vet, int size, int value, int index = 0){
    if(size == 0){
        return -1;
    }
    if(vet[0] == value){
        return index;
    }
    return index_of2(vet + 1, size - 1, value, index + 1);
}

int main() {
   
   int vet[] = {1,2,3,4,5,6,7,8,9};
   int size = sizeof(vet) /sizeof(int);
   std::cout << index_of(vet, size, 5) << std::endl;
   std::cout << index_of2(vet, size, 2) << std::endl;
   
}