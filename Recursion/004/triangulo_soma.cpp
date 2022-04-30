#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vet){
    cout << "[ ";
    for(auto elem: vet)
        cout << elem << " ";
    cout << "] " << vet.size() << endl;
}

void triangle(vector<int> vet){
    if(vet.size() == 1){
        return;
    }
    vector<int> linha_up;    
    for(int i = 0; i < (int) vet.size() - 1; i++){
        linha_up.push_back(vet[i] + vet[i+1]);
    }
    triangle(linha_up);
    print(linha_up);
}

int main() {

    vector<int> vet = {1,1};
    triangle(vet);
    print(vet);

}