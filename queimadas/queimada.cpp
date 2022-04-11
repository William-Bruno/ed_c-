#include <iostream>
#include <vector>
#include <fstream>


void imprimir_floresta(std::vector<std::string> mapa, int nivel){
    for(auto line: mapa)
        std::cout << line << '\n';
    //Interação do Enter
    getchar();
    std::cout << nivel << '\n';
}

int tocar_fogo(std::vector<std::string>& mapa, int pos_l, int pos_c, int nivel){
    int nl = mapa.size();
    int nc = mapa[0].size();
    if(pos_l < 0 || pos_l >= nl || pos_c < 0 || pos_c >= nc){
        return 0;
    }
    if(mapa[pos_l][pos_c] != '#'){
        return 0;
    }

    mapa[pos_l][pos_c] = 'x';
    imprimir_floresta(mapa, nivel);

    int total = 1 +
    //Esquerda
    tocar_fogo(mapa, pos_l, pos_c - 1, nivel + 1) +
    //Cima
    tocar_fogo(mapa, pos_l - 1, pos_c, nivel + 1) +
    // Direita
    tocar_fogo(mapa, pos_l, pos_c + 1, nivel + 1) +
    //Baixo
    tocar_fogo(mapa, pos_l + 1, pos_c, nivel + 1);

}

int main(){
    std::vector<std::string> mapa;
    std::ifstream dados("input.txt");
    int nl { }, nc { }, l_inicio { }, c_inicio{ }, nivel { };
    dados >> nl >> nc >> l_inicio >> c_inicio;
    for(int i = 0; i < nl; i++){
        std::string line;
        dados >> line;
        mapa.push_back(line);
    }

    imprimir_floresta(mapa, nivel);
    std::cout << tocar_fogo(mapa, l_inicio, c_inicio, 1) << std::endl;

    

    
}