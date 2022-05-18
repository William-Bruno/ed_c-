#include <iostream>
#include <fstream>
#include <vector>
   
bool verifica_insercao(std::string& line, int index, int value, int proximidade){
    for(int i = index + 1; i < index + 1 + proximidade; i++){
        if(i < (int)line.size() && line[i] == value + '0'){
            return false;
        }
    }
    for(int i = index - proximidade; i < index; i++){
        if(i >= 0 && line[i] == value + '0'){
            return false;
        }
    }
    return true;
}

bool preencher(std::string& line, int index, int limite, int proximidade){
    if((int)line.size() == index){
        std::cout << line << " <------\n";
        return true;
    }
    if(line[index]  != '.'){
        return preencher(line, index + 1, limite, proximidade);
    }
    for(int value = 0; value <= limite; value++){
        if(verifica_insercao(line, index, value, proximidade)){
            line[index] = value + '0';
            std::cout << line << "\n";
            if(preencher(line, index + 1, limite, proximidade)){
                return true;
            }
        }
    }
    line[index] = '.';
    std::cout << line << "\n";
    return false;
}
   
int main() {
    std::ifstream arquivo("distance.txt");
    std::string line;
    int proximidade = 0;
    arquivo >> line >> proximidade;
    int limite = 2;
    preencher(line, 0, limite, proximidade);
}
