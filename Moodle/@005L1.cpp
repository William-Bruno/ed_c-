#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>


void vet(std::vector<int> v){
    for(auto elem: v)
        std::cout << elem << ' ';
}

void rvet(std::vector<int> v){
    for(int i = (int) v.size()-1; i >=0; i--)
        std::cout << v[i] << ' ';
}

int sum(std::vector<int> v){
    int sum{};
    for(int elem:v){
        sum += elem;
    }
    return sum;
}

int mult(std::vector<int> v){
    int mult{1};
    for(int elem:v){
        mult *= elem;
    }
    return mult;
}

int min(std::vector<int> v){
    int menor = v[0];
    for(int i = 0; i < (int) v.size(); i++){
        if(v[i] < menor)
            menor = v[i];
    }
    return menor;
}

std::vector<int> inv(std::vector<int>& v){
    std::vector<int> rv(v);
    std::reverse(rv.begin(), rv.end());
    vet(rv);
}

int main() {
    std::string line;
    getline(std::cin, line);
    std::stringstream ss(line);
    std::vector<int> v;
    int value{};
    while (ss >> value){
        v.push_back(value);
    }

    std::cout << "vet: [ " ; vet(v); std::cout << "]";
    std::cout << std::endl;
    std::cout << "rvet: [ "; rvet(v);  std::cout << "]";
    std::cout << std::endl;
    std::cout << "sum: " << sum(v) << std::endl;
    std::cout << "mult: " << mult(v) << std::endl;
    std::cout << "min: " << min(v) << std::endl;
    std::cout << "inv: [ " ; inv(v);  std::cout << "]";

    
}