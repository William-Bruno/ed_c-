#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <map>
#include <algorithm>


bool existe(std::vector<int> fila, int x){
    for(int elem: fila){
        if(elem == x)
            return true;
    }
    return false;    
}

int contar(std::vector<int> fila, int x){
    int c = 0;
    for(int elem: fila){
        if(elem == x){
            c++;
        }
    }
    return c;
}

int procurar(std::vector<int> fila, int x){
    int nothin = -1;
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }   
    return nothin;
}

int procurar_apartir(std::vector<int> fila, int x, int inicio){
    int nothin = -1;
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] == x)
            return i;
    }
    return nothin;
}

int procurar_menor(std::vector<int> fila){
    int menor {0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < menor)
            menor = fila[i];
    }
    return menor;
}

int procurar_pos_menor(std::vector<int> fila){
    int pos_menor {0};
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] < pos_menor)
            pos_menor = i;
    }
    return pos_menor;
}

int procurar_pos_menor_apartir(std::vector<int> fila, int inicio){
    int menor {0};
    for(int i = inicio; i < (int) fila.size(); i++){
        if(fila[i] < menor)
            menor = fila[i];
    }
    for(int j = 0; j < (int) fila.size(); j++){
        if(fila[j] == menor)
            menor = j;
    }
    return menor;
}

int procurar_pos_melhor_se(std::vector<int> fila){
    std::vector<int> aux;
    for(int i = 0; i < (int) fila.size(); i++){
        if(fila[i] > 0)
             aux.push_back(fila[i]);
    }
    int nothin {-1};
    if(aux.empty())
        return nothin;

    int menor {100};
    for(int j = 0; j < (int) aux.size(); j++){
        if(aux[j] < menor)
            menor = aux[j];
    }

    int pos_menor {0};
    for(int k = 0; k < (int) fila.size(); k++){
        if(fila[k] == menor)
            pos_menor = k;  
    }
    return pos_menor;
    
}

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

// FILTER
// clonar: retorna um novo vetor copiando os valores do vetor de entrada
std::vector<int> clonar(const std::vector<int>& v){
    std::vector<int> novo_vetor;
    for(int elem : v){
        novo_vetor.push_back(elem);
    }
    return novo_vetor;
}
// pegar_homens: retorne uma lista com os homens (valores positivos)
std::vector<int> pegar_homens(const std::vector<int>& v){
    std::vector<int> homens;
    for(int elem: v){
        if(elem > 0)
            homens.push_back(elem);
    }
    return homens;
}
// pegar_calmos: retorne uma lista com as pessoas com stress menor que 10 (abs)
std::vector<int> pegar_calmos(const std::vector<int>& v){
    std::vector<int> calmos;
    for(int elem : v)
        if(elem < 10 && elem > -10)
            calmos.push_back(elem);
    return calmos;        
}
// pegar_mulheres_calmas: retorne uma lista com as mulheres com nível de stress menor que 10.(negativos menor que 10)
std::vector<int> pegar_mulheres_calmas(const std::vector<int>& v){
    std::vector<int> mulheres_calmas;
    for(int elem : v)
        if(elem < 0 && elem > -10)
            mulheres_calmas.push_back(elem);
    return mulheres_calmas;
}

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

// MANIPULAÇÃO
std::vector<int> sozinhos(const std::vector<int>& v){
        
        std::vector<int> abandonado(clonar(v));
        std::vector<int> sozinho{};

        ordenar(abandonado);
        
        for(int i = 0; i < (int) v.size(); i++){
            abandonado[i] = std::abs(v[i]);
          for(int j = i+1; j < i; j++){
              if(abandonado[i] != v[j]){
                  sozinho.push_back(+1);
              }
          }
        }    
        return sozinho;
    }
int mais_ocorrencias(std::vector<int>& v){
    std::vector<int> unicos;
    std::vector<int> contagem;
    std::vector<int> maiores; 

    for(int elem: v){
        int pos = procurar(v, elem);
        if(pos == -1){
            unicos.push_back(elem);
            contagem.push_back(1);
        }else{
            contagem[pos] += 1;
        }
    }
    int maiorValor;

    int maior_valor = *std::max_element(contagem.begin(), contagem.end());


    return maior_valor;
    


}
std::vector<int> mais_recorrentes(const std::vector<int>& v){

}

// PROXIMIDADE
int briga(const std::vector<int>& v){}
// briga({50, 98, 31, -51, 31, -99});  // 2

std::vector<int> apaziguados(const std::vector<int>& v){}
// apaziguados({83, -4, 65, 8, -99, 12 });  // {0, 4}

// SEQUENCIAS
int quantos_times(const std::vector<int>& v){}
// quantos_times({5, 3, 1, -11, 1, 99, -11, -1, -2, 44});  // 3
// quantos_times({1, 1, 1, -1, 1, -1, -1});  // 2
// quantos_times({ 28,  26,  1,  6,  39});  // 1

std::vector<int> maior_time(const std::vector<int>& v){}

// maior_time({-5, 3, -1, 15, 1, -99, 11, 1 }); // {15, 1}
// maior_time({-5, 3, -1, 15, -1, 99, -11, 1 }); // {}
// maior_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }); // {-11, -1, -7}

int sem_time(std::vector<int> vet){}
// sem_time({-5, 3, 1, -15, -1, 99, -11, -1, -7 }); // 2
// sem_time({-5, -3, -1, -15, -1, -99, -11, -1, -7 }); // 0
// sem_time({-5, 3, 1, 15, -1, -99, -11, -1, -7 }); // 1

// GRUPOS
// casais: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress são formados. O 3 e o -3 formam um casal. Os participantes fossem orientados a sair da fila e procurar seu par. Quantos casais poderiam ser formados?
// trios: Pedimos pros participantes se organizassem em trios. Todos os 3 deveriam estar com o mesmo nível de stress.Quantos trios podem ser formados?

// ALTERAÇÃO
// remove: Dado a pessoa X, como fica a fila após remover X?
// insert: Como fica a fila se eu inserir a pessoa X na posição Y.
// dance: O coordenador disse: se você está do lado de alguém da com o mesmo nível de stress que você, saia da fila com ele. Quando os pares saiam, as vezes se formavam novos pares que também saíam. Quem ficou na fila?


void imprimir_vector(std::vector<int> v){
    for(auto& elem: v)
        std::cout << elem << " ";
}

int main(){
    /*
    BUSCA
    //existe: Alguém com o valor X está na fila?
    std::cout << existe({-1, -50, -99}, -1) << "\n"; //true
    std::cout << existe({-1, -50, -99}, 10) << "\n"; //false
    //contar: Quantas vezes o valor X apareceu na fila?
    std::cout << contar({-1, -50, -1, -99}, -1) << "\n"; //false
    std::cout << contar({-1, -50, -1, -99}, 10) << "\n"; //false
    //procurar: Em que posição da fila aparece X pela primeira vez?
    std::cout << procurar({-1, -50, -1 -99}, -50) << "\n"; // 1
    std::cout << procurar({-1, -50, -1, -99}, 10) << "\n"; // -1
    //procurar_apartir: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 0) << "\n"; // 2
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 3) << "\n"; // 4; // 2
    std::cout << procurar_apartir({5, 3, -1, -50, -1, -99}, -1, 4) << "\n"; // 4 // 2
    */    
    /*
    MELHOR CASO
    */
    // std::cout << procurar_menor({5, 3, -1, -50, -1, -99}) << "\n"; // -99
    // std::cout << procurar_pos_menor({5, 3, -1, -50, -1, -99}) << "\n"; //5
    // std::cout << procurar_pos_menor_apartir({5, 10, -10, -50, -10, 10, -70}, 3) << "\n";//3
    // std::cout << procurar_pos_melhor_se({5, 3, -1, -50, -1, -99}) << "\n";//1
    // std::cout << procurar_pos_melhor_se({-1, -50, -1, -99}) << "\n";//-1
    
    /*
    CONTAGEM
    */
    // std::cout << calcular_stress_medio({-1,-2,5,7,9}) << "\n";
    // std::cout <<  mais_homens_ou_mulheres({5, 3, -1, -50, -1, -99})<< "\n"; // "mulheres"
    // std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, -99})<< "\n"; // "empate"
    // std::cout << mais_homens_ou_mulheres({5, 3, 1, -50, -1, 99})<< "\n"; // "homens"
    // std::cout << qual_metade_eh_mais_estressada({5, 3, -1, -50, -1, -99})<< "\n"; // "segunda"
    // std::cout << qual_metade_eh_mais_estressada({50, 98, 2, -50, -1, -99})<< "\n"; // "empate"
    // std::cout << qual_metade_eh_mais_estressada({51, 99, 1, -50, -1, -99})<< "\n"; // "primeira"

    // FILTER
    // imprimir_vector(clonar(v));
    // imprimir_vector(pegar_homens(v));
    // imprimir_vector(pegar_calmos(v));
    // imprimir_vector(pegar_mulheres_calmas(v));

    // std::cout << sortear(v) << "\n";

    // std::vector<int> v {1, 3, 4, 3, -1, -2, -2};

    // imprimir_vector(inverter_com_copia(v));
    // inverter_inplace(v);
    // imprimir_vector(v);
    // std::cout << sortear(v) << "\n"; // "primeira"
    // embaralhar(v);
    // imprimir_vector(v);   


    //CONJUNTOS
    // imprimir_vector(exclusivos(v));
    // imprimir_vector(diferentes(v));
    // imprimir_vector(abandonados(v));

    
    std::vector<int> v {1, 3, 4, 3, -1, -3, -3}; // -> {4}

    // BLOCO III
    // MAP
    
    std::cout << mais_ocorrencias(v) << "\n";
    
    


    

    

}