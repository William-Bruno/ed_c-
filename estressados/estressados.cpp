#include <iostream>
#include <vector>
#include <string>
#include <cstdio>


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
    int nothin = -1;
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }   
    return nothin;
}

int procurar_apartir(std::vector<int> fila, int x, int inicio){
    int nothin = -1;
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }
    return nothin;
}

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

float calcular_stress_medio(std::vector<int> fila){
    float stress_medio {0};
    for(int i = 0; i < (int) fila.size(); i++){
        stress_medio += fila[i];
    }
    int tamanho_fila = fila.size();
    stress_medio = stress_medio/tamanho_fila;
    return stress_medio;
}

std::string mais_homens_ou_mulheres(std::vector<int> fila){
    int homens {0};
    int mulheres {0};
    for(int elem: fila){
        if(elem > 0)
            homens++;
        else
            mulheres++;
    }

    if(homens > mulheres)
        return "homens\n";
    else if(mulheres > homens)
        return "mulheres\n";
    else    
        return "empate\n";
}

std::string qual_metade_eh_mais_estressada(std::vector<int> fila){
    int homens {};
    int mulheres {};

    for(int elem: fila){
            if(elem > 0)
                homens += elem; 
            if(elem < 0)
                mulheres += elem * -1;
    }

    if(homens > mulheres)
        return "primeira\n";
    else if(mulheres > homens)
        return "segunda\n";
    else    
        return "empate\n";

}



int main(){
    /*
    BUSCA
    //existe: Alguém com o valor X está na fila?
    std::cout << existe({-1, -50, -99}, -1) << "\n"; //true
    std::cout << existe({-1, -50, -99}, 10) << "\n"; //false
    //contar: Quantas vezes o valor X apareceu na fila?
    std::cout << contar({-1, -50, -1, -99}, -1) << "\n"; //false
    std::cout << contar({-1, -50, -1, -99}, 10) << "\n"; //false
    //procurar: Em que posição da fila aparece X pela primeira vez?
    std::cout << procurar({-1, -50, -1 -99}, -50) << "\n"; // 1
    std::cout << procurar({-1, -50, -1, -99}, 10) << "\n"; // -1
    //procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << "\n"; // 2
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << "\n"; // 4; // 2
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << "\n"; // 4 // 2
    */    
    /*
    MELHOR CASO
    */
    // std::cout << procurar_menor({5, 3, -1, -50, -1, -99}) << "\n"; // -99
    // std::cout << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << "\n"; //5
    // std::cout << procurar_pos_menor_apartir({5, 10, -10, -50, -10, 10, -70}, 3) << "\n";//3
    // std::cout << procurar_pos_melhor_se({5, 3, -1, -50, -1, -99}) << "\n";//1
    // std::cout << procurar_pos_melhor_se({-1, -50, -1, -99}) << "\n";//-1
    
    /*
    CONTAGEM
    */
    // std::cout << calcular_stress_medio({-1,-2,5,7,9}) << "\n";
   
    // std::cout <<  mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99})<< "\n"; // "mulheres"
    // std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99})<< "\n"; // "empate"
    // std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99})<< "\n"; // "homens"

    
    // std::cout << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99})<< "\n"; // "segunda"
    // std::cout << qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99})<< "\n"; // "empate"
    // std::cout << qual_metade_eh_mais_estressada({51, 99, 1, -50, -1, -99})<< "\n"; // "primeira"



}