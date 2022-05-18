#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vet){
    for(auto elem:vet)
        cout << elem << ' ';
    cout << endl;
}

bool in(std::vector<int> fila, int x){
    for(int elem: fila){
        if(elem == x)
            return true;
    }
    return false;    
}

int index_of(std::vector<int> fila, int x){
    int c = 0;
    for(int elem: fila){
        if(elem == x){
            c++;
        }
    }
    return c;
}

int find_if(std::vector<int> fila, int x){
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }   
    return -1;
}

int min_element(std::vector<int> fila){
    int pos_menor {0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < pos_menor)
            pos_menor = i;
    }
    return pos_menor;
}

int find_min_if(std::vector<int> fila, int x, int inicio){
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }
    return -1;
}

int main() {

}