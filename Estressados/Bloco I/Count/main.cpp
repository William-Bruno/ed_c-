#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> fila, int x){
    int count{0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            count++;
    }   
    return count;
}

float average(vector<int> fila){
    float stress_medio {0};
    for(int i = 0; i < (int) fila.size(); i++){
        stress_medio += fila[i];
    }
    int tamanho_fila = fila.size();
    stress_medio = stress_medio/tamanho_fila;
    return stress_medio;
}

string half_compares(vector<int> fila){
    int homens {};
    int mulheres {};

    for(int elem: fila){
            if(elem > 0)
                homens += elem; 
            if(elem < 0)
                mulheres += elem * -1;
    }

    if(homens > mulheres)
        return "first\n";
    else if(mulheres > homens)
        return "second\n";
    else    
        return "draw\n";

}

string more_men_or_woman(vector<int> fila){
    int homens {0};
    int mulheres {0};
    for(int elem: fila){
        if(elem > 0)
            homens++;
        else
            mulheres++;
    }

    if(homens > mulheres)
        return "men\n";
    else if(mulheres > homens)
        return "woman\n";
    else    
        return "draw\n";
}

string sex_batle(vector<int> vet){
    int c_men{0}, c_woman{0};
    float men{0}, woman{0};
    for(auto elem:vet){
        if(elem < 0){
            men += abs(elem);
            c_men++;
        }
        if(elem > 0){
            woman += elem;
            c_woman++;
        }
    }
    men = men/c_men;
    woman = woman/c_woman;
    if(men > woman)
       return "men\n";
    else if(woman > men)
        return "woman\n";
    else
        return "draw\n";
}


int main() {

    vector<int> teste ({-1,-1,-1,1,1,1});
    sex_batle(teste);

}