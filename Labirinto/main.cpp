#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

//Mostrar Mapa de Caracteres(Paredes)
void mostrar_labirinto(std::vector<std::string>& mapa){
    for (auto line: mapa)
        std::cout << line << '\n';
    getchar();
}

struct Pos{
    int l, c;
    Pos(int l, int c): l(l), c(c){}
};

std::vector<Pos> pegar_vizinho(Pos p){
    auto [l, c] = p;
    return {{l, c-1}, {l-1, c}, {l,c+1}, {l+1,c}};
}

std::vector<Pos> embaralhar_caminhos(std::vector<Pos> p){
    std::random_shuffle(begin(p), end(p));
    return p;
}

bool verifica_vizinhos(std::vector<std::string>& mapa, Pos p){
    int nl = mapa.size();
    int nc = mapa[0].size();
    int contador {0};
    for(auto vizinho : pegar_vizinho(p)){
        auto [l,c] = p;
        if(l < 0 || l >= nl || c < 0 || c >= nc){
            continue;
        }
        if(mapa[vizinho.l][vizinho.c] == '#'){
            contador += 1;
        }
    }
    return (contador >= 3);
    
}

void furar_parede(std::vector<std::string>& mapa, Pos p){
    int nl = mapa.size();
    int nc = mapa[0].size();
    auto [l,c] = p;
    if(l < 0 || l >= nl || c < 0 || c >= nc)
        return;
    if(mapa[l][c] == '#'){
        return;
    }
    if(!verifica_vizinhos(mapa, p)){
        return;
    }
    mapa[l][c] = ' ';
    mostrar_labirinto(mapa);
    //Recursao com embaralhamento
    for(auto vizinho: embaralhar_caminhos(pegar_vizinho(p))){
        furar_parede(mapa, vizinho);
    }

}
 
int main(int argc, char * argv[]) {
    if(argc != 3){
        std::cout << "Numero de argumentos invalido.\n";
        std::cout << "./executavel nl nc \n";
        exit(1);
    }
 
    int nl {0}, nc {0};
    std::stringstream(argv[1]) >> nl;
    std::stringstream(argv[2]) >> nc;

    //Vetor de Strings
    std::vector<std::string> mapa (nl, std::string(nc, '#'));

    furar_parede(mapa, Pos(1,1));

}