#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> fila(vector<int> inicial, vector<int> sairam){
    vector<int> fila_final;
    unordered_set<int> mapa_fila(sairam.begin(), sairam.end());

    for(auto elem: inicial){   
        if(mapa_fila.find(elem) == mapa_fila.end()){
            fila_final.push_back(elem);
        }
    }
    return fila_final;
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
    vector<int> vet(N);
    for(int i = 0; i < N; i++){
        cin >> vet[i];
    }
    int v{};
    cin >> v;
    vector<int> M(v);
    if(v > 0){
        for(int j = 0; j < v; j++){
            cin >> M[j];
        }
    }
    print(fila(vet, M));
}