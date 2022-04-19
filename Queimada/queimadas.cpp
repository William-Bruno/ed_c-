#include <iostream>
#include <vector>
#include <fstream>

void mostrar_floresta(std::vector<std::string> mapa){
    for(int l = 0; l < (int) mapa.size(); l++)
        std::cout << mapa[l] << "\n";
}

bool verificacao(std::vector<std::string> &mapa, int l, int c){
    int nl = mapa.size();
    int nc = mapa[0].size();

    if(l < 0 || l >= nl || c < 0 || c >= nc){
        return true;
    }
    return false;
}

int queimar(std::vector<std::string> &mapa, int l, int c){
    if(verificacao(mapa, l,c) || mapa[l][c] != '#'){
        return 0;
    }
    int total = 1;
    mapa[l][c] = 'o';
    total +=
    queimar(mapa, l-1,c) +
    queimar(mapa, l, c+1) +
    queimar(mapa, l+1, c) +
    queimar(mapa, l, c-1);
    mapa[l][c] = 'x';
    return total;
}

int main(){
    std::ifstream arquivo("queimada.txt");
    int nl{}, nc{}, l{}, c{};
    arquivo >> nl >> nc >> l >> c;
    std::vector<std::string> mapa;
    for(int l = 0; l < nl; l++){
        std::string line;
        arquivo >> line;
        mapa.push_back(line);
    }
    int arvores_queimadas = queimar(mapa, l, c);
    mostrar_floresta(mapa);
    std::cout << "Arvores Queimadas: " << arvores_queimadas << std::endl;
}