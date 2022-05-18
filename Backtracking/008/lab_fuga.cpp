#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void mostrar_labirinto(vector<string> mapa){
    for (auto line: mapa)
        cout << line << '\n';
    getchar();
}

struct Pos{
    int l, c;
    Pos(int l, int c): l(l), c(c){};
};

vector<Pos> pegar_vizinho(Pos p){
    auto [l, c] = p;
    return {{l, c-1}, {l-1, c}, {l,c+1}, {l+1,c}};
}

vector<Pos> embaralhar_caminhos(vector<Pos> p){
    random_shuffle(p.begin(), p.end());
    return p;
}

int verifica_vizinhos(vector<string>& mapa, Pos p){
    int nl = mapa.size();
    int nc = mapa[0].size();
    int contador {0};
    for(auto vizinho : pegar_vizinho(p)){
        auto [l,c] = vizinho;
        if(l < 0 || l >= nl || c < 0 || c >= nc){
            continue;
        }
        if(mapa[vizinho.l][vizinho.c] == '#'){
            contador += 1;
        }
    }
    return  (contador >= 3); 
    
}

void furar_parede(vector<string>& mapa, Pos p){
    int nl = mapa.size();
    int nc = mapa[0].size();
    auto [l,c] = p;
    if(l < 0 || l >= nl || c < 0 || c >= nc)
        return;
    if(mapa[l][c] != '#'){
        return;
    }
    if(!verifica_vizinhos(mapa, p)){
        return;
    }
    mapa[l][c] = ' ';
    for(auto vizinho: embaralhar_caminhos(pegar_vizinho(p))){
        furar_parede(mapa, vizinho);
    }
}

bool fugir(vector<string>& mapa, Pos atual, Pos destino){
    if(atual.l == destino.l && atual.c == destino.c)
        return true;
    if(mapa[atual.l][atual.c] != ' '){
        return false;
    }
    mapa[atual.l][atual.c] = '.';
    mostrar_labirinto(mapa);
    for(auto vizinho : embaralhar_caminhos(pegar_vizinho(atual))){
        if(fugir(mapa, vizinho, destino)){
            return true;
        }
    }
    mapa[atual.l][atual.c] = 'x';
    return false;
}
 
int main(int argc, char * argv[]) {
    if(argc != 3){
        cout << "Numero de argumentos invalido.\n";
        cout << "./executavel nl nc \n";
        exit(1);
    }
 
    int nl {0}, nc {0};
    stringstream(argv[1]) >> nl;
    stringstream(argv[2]) >> nc;

    vector<string> mapa (nl, string(nc, '#'));

    furar_parede(mapa, Pos(1,1));
    mostrar_labirinto(mapa);

    fugir(mapa, Pos(1,1), Pos(8,19));
    mostrar_labirinto(mapa);
    

}