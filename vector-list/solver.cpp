#include <iostream>
#include <vector>
#include <list>
#include <string>



int main(){
    // INICIALIZAÇÕES
    {
        // Vetor vazio
        std::vector<int> v;
        //Vetor com total e elemento
        std::vector<int> v(5, 1);
        // Tamanho
        size_t v_size {v.size()};
        // Capacidade
        size_t v_capacity {v.capacity()};
        // Reservar espaço
        v.reserve(5);

        v_size = v.size(); 
        v_capacity = v.capacity();

        // Com copia
        std::vector<int> v = {1,2,3,4,5};
        std::list<int> l (v.begin(), v.end());
    }
    // ADICIONANDO ELEMENTOS
    {
        // VECTOR
        // Adiciona no final
        std::vector<std::string> cores = {"azul", "preto"};
        cores.push_back("cinza");
        size_t s_cores {cores.size()};
        size_t c_cores {cores.capacity()};
        cores.push_back("lilás");

        // Adiciona no inicio com iterator --Custoso
        cores.insert(cores.begin(), "vermelho");
        //primeira posição + 1 (saltos);
        cores.insert(cores.begin() + 1, "branco");

        // LIST
        // Adicionando no final
        std::list<std::string> nomes = {"Bruno", "Willian", "Carlos"};
        nomes.push_back("Silva");
        nomes.push_back("Elma");

        // Adicionando no inicio
        nomes.push_front("Elsa");
        nomes.push_front("Garen");
        nomes.insert(nomes.begin(), "Ashe");
        
        //Insere um novo elemento em determinada posição
        nomes.insert(std::next(nomes.begin(), 1), "Zyra");

    }
    // ACESSANDO
    {
        // VECTOR
        std::vector<int> v = {1,2,3,4,5,6};

        // por iterator, direto
        std::cout << v.front() << " " << v.back() << std::endl;
        //Pelo índice;
        std::cout << v[1] << std::endl;
        // Método seguro de índice mas lento
        std::cout << v.at(2) << std::endl;
        // é feio kkk
        std::cout << *(v.begin() + 2) << std::endl;

        // LIST
        std::list<int> l (v.begin(), v.end());

        // iteraror, acesso direto
        std::cout << l.front() << " " << l.back() << std::endl;
        //custoso
        std::cout << *(std::next(l.begin(), 2)) << '\n';

    }
    //REMOVENDO
    {
        // VECTOR
        std::vector<int> v = {1,2,3,4,5,6,7,8,9};
        // primeiro
        v.pop_back();
        // segundo
        v.erase(v.begin() + 1);
        // penultimo
        v.erase(v.end() -2);

        // LIST
        std::list<int> l = {1,2,3,4,5,6};
        // ultimo
        l.pop_back();
        // primeiro
        l.pop_front();

        // segundo
        l.erase(std::next(l.begin())); 
        // escolhendo posição - penultimo
        l.erase(std::prev(l.end(), 2));

    }
    // Percorrendo por cópia
    {
        // Vector
        std::vector<int> v = {1,2,3,4,5,6,7,8,9};
        for(int elem: v){
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        // List
        std::list<int> l = {1,2,3,4,5,6};
        for(int elem : l){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    // Percorrendo por referência
    {
        // Vector e List
        std::vector<int> v = {1,2,3,4,5,6,7,8,9};
        for(int &elem: v){
            elem += 2;
        }
        for(int elem : v){
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    // Percorrendo por iterador
    {
        // Vector e List
        std::list<int> l = {1,2,3,4,5,6};
        // std::prev | std::prev
        for(auto it = l.begin(); it != l.end(); it++){
            std:: cout << *it << " ";
        }
        std::cout << std::endl;
    }

    // EXEMPLOS
    // removendo os pares da lista
    {
        std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
        for(auto it = l.begin(); it != l.end();){
            if(*it % 2 == 0)
                it = l.erase(it);
            else
                it++;
        }
        for(auto i : l){
            std::cout << i << " ";
        }

        std::cout << std::endl;
        
    }
    //perorrendo com rbegin(fim) - de forma reserva
    {
        std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
        for(auto it = l.rbegin(); it != l.rend(); it++){
            std::cout << *it << " ";
        }
    }
    //percorrendo ao contrário com iterador
    {
        std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
        for(auto it = l.end(); it != l.begin();){
            it--;
            std::cout << *it << " ";
        }
        std::cout <<std::endl;
    }
    {
        //problemas
        std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
        std::prev(l.begin());
        std::next(l.end());
        //compila, mas é errado e não faz sentido
        std::vector<int> m = {};
        m.front();
        m[6];
    }
}