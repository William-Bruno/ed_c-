#include <iostream>
#include <vector>


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

int main() {


}