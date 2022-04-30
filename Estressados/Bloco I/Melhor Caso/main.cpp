#include <iostream>
#include <vector>


int procurar_menor(std::vector<int> fila){
    int menor {0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < menor)
            menor = fila[i];
    }
    return menor;
}


int procurar_pos_menor(std::vector<int> fila){
    int pos_menor {0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < pos_menor)
            pos_menor = i;
    }
    return pos_menor;
}

int procurar_pos_menor_apartir(std::vector<int> fila, int inicio){
    int menor {0};
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] < menor)
            menor = fila[i];
    }
    for(int j = 0; j < (int) fila.size(); j++){
        if(fila[j] == menor)
            menor = j;
    }
    return menor;
}

int procurar_pos_melhor_se(std::vector<int> fila){
    std::vector<int> aux;
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] > 0)
             aux.push_back(fila[i]);
    }
    int nothin {-1};
    if(aux.empty())
        return nothin;

    int menor {100};
    for(int j = 0; j < (int) aux.size(); j++){
        if(aux[j] < menor)
            menor = aux[j];
    }

    int pos_menor {0};
    for(int k = 0; k < (int) fila.size(); k++){
        if(fila[k] == menor)
            pos_menor = k;  
    }
    return pos_menor;
    
}

int main() {

}