#include <iostream>
#include <vector>

//ACESSO
//retorna um novo vetor com os dados invertidos
std::vector<int> inverter_com_copia(const std::vector<int>& v){
    std::vector<int> vetor_invertido;
    for(int elem: v)
        vetor_invertido.push_back(elem);
    std::reverse(vetor_invertido.begin(), vetor_invertido.end());
    return vetor_invertido;
}

//inverte os valores do vetor de entrada sem uso de vetor auxiliar
void inverter_inplace(std::vector<int>& v){
    std::reverse(v.begin(), v.end());
}

//...................................
//swap(j por i % size)
//random_shuffle
//embaralha o vetor original
void embaralhar(std::vector<int>& v){
    std::random_shuffle(v.begin(), v.end());
}

//retorna aleatoriamente um elemento do vetor
int sortear(const std::vector<int>& v){
    srand(time(NULL));
    int indice = rand() % v.size();
    int aleatorio {};
    for(int i = 0; i < (int) v.size(); i++){
        if(indice == i)
            aleatorio = v[i];
    }
    return aleatorio;
}

//ordena o vetor original
void ordenar(std::vector<int>& v){
    std::sort(v.begin(), v.end());
}

int main() {

}