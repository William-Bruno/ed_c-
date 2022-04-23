#include <iostream>
#include <vector>

//Tipo de dado
template <typename T>
struct vector{
    int _size;
    int _capacity;
    T * _data;

                                //inicialização via construtor
    vector(int size = 0):_size (size), _capacity(size){
        //inicialização via atribuição
        this->_data = new T[size];
    }
    vector(int size, T value):vector(size){
        for(int i = 0; i < size; i++){
            _data[i] = value;
        }
    }
    //liberar memoria do new
    ~vector(){
        delete [] _data;
    }
    //aumentar ou diminuir a capacidade do vetor
    void reserve(int capacity){
        //criar novo bloco de memória;
        T * _new_data = new T[capacity];
        //verificar se está aumetando ou diminuindo o tamanho
        int amount = std::min(_size, capacity);
        //copiar o elementos
        for(int i = 0; i < amount; i++){
            _new_data[i] = _data[i];
        }
        //atualizar os valores dos atributos
        _size = amount; //maior ou menor
        _capacity = capacity;
        delete [] _data; //limpa bloco de memoria
        _data = _new_data; // atualiza a referencia
    }

    void push_back(int value){
        if(_size == _capacity){
            //vetor de tamanho 0 adiciona espaco para 1 elemento ou dobra o valor
            this->reserve(_capacity == 0 ? 1 : 2 * _capacity);
        }
        //adiciona o elemento com o indice em size, e aumenta o size em + 1
        _data[_size] = value;
        _size += 1;
    }

    void pop_back(){
        if(_size == 0){
            return;
        }
        _size -= 1;
    }
    //retorna o elemento com controle de excesão
    T& at(int index){
        if(index < 0 || index >= _size){
            //controle de excesão
        }
        return _data[index];
    }

    T * begin(){
        return &_data[0];
    }

    T * end(){
        return &_data[_size - 1];
    }

    void insert(T * it, T value){
        //quantidade de elementos até a posição
        int pos = it - _data;
        if(_size == _capacity){
            this->reserve(2*_capacity);
        }
        for(int i = _size; i > pos; --i){
            _data[i] = _data[i - 1];
        }
        _size += 1;
        _data[pos] = value;
    }

    void erase(T * it){
        int pos = it - _data;
        for(int i = pos; i < _size - 1; ++i){
            _data[i] = _data[i + 1];
        }
        _size -= 1;
    }

    //capacidade de elementos
    int capacity(){
        return _capacity;
    }

    //tamanho do vetor
    int size(){
        return _size;
    }

    //retorna a posição real do elemento na memória
    T& operator[](int index){
        return _data[index];
    }

    //primeiro elemento do vetor
    T& front(){
        return _data[0];
    }

    //ultimo elemento do vetor
    T& back(){
        return _data[_size - 1];
    }

    //imprimir o vetor completo
    void print(){
        std::cout << "[ ";
        for(int i = 0; i < _size; i++){
            std::cout << _data[i] << " ";
        }
        std::cout << "]" << std::endl;
    }    

};

int main() {

    vector<int> vet(10,1);
    std::cout << vet.size() << " " << vet.capacity() << "\n";
    vet[2] = 10;
    vet.front() = 5;
    vet.back() = 50;
    std::cout << vet[2] << " " << vet.front() << " " << vet.back() << "\n";
    vet.print();
    
    vet.push_back(100);
    vet.push_back(77);
    vet.print();
    
    vet.pop_back();
    vet.print();   

    //lendo com iterator
    for(auto it = vet.begin() + 1; it != vet.end() - 2; it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //lendo com foreach
    for(auto elem:vet){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    vet.insert(vet.begin() + 2, 300);
    vet.insert(vet.begin() + 1, 222);
    vet.print();
    vet.erase(vet.end() - 2);
    vet.print();
}