#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> fila(vector<string> entrada, vector<string> consultas){
    unordered_map<string, int> mapa;

    for(size_t i = 0; i < (int) entrada.size(); i++){
        mapa[entrada[i]] = i;
    }
}

void print(vector<int> vet){
    cout << "[ ";
    for(auto elem: vet){
        cout << elem << " ";
    }
    cout << "] " << endl;
}

int main() {
    int N{};
    cin >> N;
    vector<string> vet(N);
    for(int i = 0; i < N; i++){
        cin >> vet[i];
    }
    int v{};
    cin >> v;
    vector<string> M(v);
    if(v > 0){
        for(int j = 0; j < v; j++){
            cin >> M[j];
        }
    }
    print(fila(vet, M));
}