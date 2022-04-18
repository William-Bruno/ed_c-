#include <iostream>
#include <vector>

void show(std::vector<std::string> mapa){
    for(int i = 0; i < (int) mapa.size(); i++){
        std::cout << mapa[i] << "\n";
    }
    getchar();
}

void tocar_fogo(std::vector<std::string>& mapa, int l, int c){
    int nl = mapa.size();
    int nc = mapa[0].size();

    if(l < 0 || l >= nl || c < 0 || c >= nc){
        return;
    }
    if(mapa[l][c] != '#'){
        return;
    }

    mapa[l][c] = 'o';
    
    tocar_fogo(mapa, l-1,c);//Esquerda
    tocar_fogo(mapa, l,c+1);//Cima
    tocar_fogo(mapa, l+1,c);//Direita
    tocar_fogo(mapa, l, c-1);//Baixo
}


int main() {
   int nl{}, nc{}, l{}, c{};
   std::cin >> nl >> nc >> l >> c;
   std::vector<std::string> mapa;
   for(int i = 0; i < nl; i++){
       std::string line;
       std::cin >> line;
       mapa.push_back(line);       
   }
   
   tocar_fogo(mapa,l,c);
   show(mapa);
}