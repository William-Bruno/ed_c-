#include <iostream>

// Conta digitos recursivo
int conta_numero_de_digitos(int value){
    if(value < 10)
        return 1;
    return 1 + conta_numero_de_digitos(value/10);
}

// Conta digitos recursivo v2 - enxuto
int conta_numero_de_digitos2(int value){
    return value < 10 ? 1 : 1 + conta_numero_de_digitos(value/10);
}
 
int main() {

    int value {123489};
    std::cout << "Recursivo: " << conta_numero_de_digitos(value) << std::endl;
    std::cout << "Recursivo2: " << conta_numero_de_digitos2(value) << std::endl;
 
}