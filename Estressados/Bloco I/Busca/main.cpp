#include <iostream>
#include <vector>

bool existe(std::vector<int> fila, int x){
    for(int elem: fila){
        if(elem == x)
            return true;
    }
    return false;    
}

int contar(std::vector<int> fila, int x){
    int c = 0;
    for(int elem: fila){
        if(elem == x){
            c++;
        }
    }
    return c;
}

int procurar(std::vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }   
    return -1;
}

int procurar_apartir(std::vector<int> fila, int x, int inicio){
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }
    return -1;
}

int main() {

}