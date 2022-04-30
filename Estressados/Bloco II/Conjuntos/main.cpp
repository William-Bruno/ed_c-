#include <iostream>
#include <vector>

bool existe(std::vector<int> vet, int value);

// FUNÇÕES
//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, -1, -2}
std::vector<int> exclusivos(const std::vector<int>& v){
    std::vector<int> exclusivos;
    for(int elem : v){
        if(!existe(exclusivos, elem))
            exclusivos.push_back(elem);
    }
    return exclusivos;
}

//{1, 3, 4, 3, -1, -2, -2} -> {1, 3, 4, 2}
std::vector<int> diferentes(const std::vector<int>& v){
    std::vector<int> diferentes;
    for(int elem : v){
        elem = std::abs(elem);
        if(!existe(diferentes, elem))
            diferentes.push_back(elem);
    }
    return diferentes;

}
//AQUI
//{1, 3, 4, 3, -1, -2, -2} -> {3, -2}
std::vector<int> abandonados(const std::vector<int>& v){
    std::vector<int> exclusivos;
    std::vector<int> abandonados;

    for(int elem : v){
        if(!existe(exclusivos, elem))
            exclusivos.push_back(elem);
        else
            abandonados.push_back(elem);
    }
    return abandonados;
}

//std::pair
//return make_pair

int main() {

}