#include <iostream>
#include <sstream>

struct Vector{
    int capacity;
    int size;
    int * data;
};

Vector * vector_create(int capacity){
    //crie um vetor dinâmicamente
    //cria a struct
    //crie o vetor data
    //inicialize size e capacity
}

void vector_destroy(Vector * vector){
    //destrua data
    //destrua a struct
}

void vector_add(Vector * vector, int value){
    //utilize capacity e size para verificar se ainda existe espaço
}

//retorne a string no formato 
// [ a b c ]
std::string vector_show(Vector * vector){
    //retorne uma string com os dados do vetor
    //você pode usar uma stringstream como buffer
    //stringstream ss;
    //ss << 5 << " eh inteiro";
    //ss.str() será "5 eh inteiro"
}


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    std::string line, cmd;
    int value;
    Vector * v = vector_create(0);
    while(true){
        getline(std::cin, line);
        std::cout << "$" << line << std::endl;
        std::stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            if(v != nullptr)
                vector_destroy(v);
            v = vector_create(value);
        } else if(cmd == "status"){
            std::cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show"){
            std::cout << vector_show(v) << std::endl;
        } else {
            std::cout << "fail: comando invalido\n";
        }
    }
    vector_destroy(v);
}