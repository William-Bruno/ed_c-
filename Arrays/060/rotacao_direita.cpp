#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rotacionar(vector<int>& vet, int r){
    vector<int> aux;
    r = r % vet.size();

    if(r == 0){
        return vet;
    }else{
        for(int i = (int) vet.size() - 1; i > (int) vet.size() - 1 - r; --i){
            aux.push_back(vet[i]);
        }
        sort(aux.begin(), aux.end());

        for(int i = 0; i < (int) vet.size() - r; ++i){
            aux.push_back(vet[i]);
        }
    }
    vet.clear();
    vet = aux;
    aux.clear();
    return vet;
}

void print(vector<int> vet){
    cout << "[ ";
    for(auto elem: vet){
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void print_of(vector<int> vet){
    for(auto elem: vet){
        cout << elem << " ";
    }
    cout << endl;
}


int main(){
    int T, R;
    cin >> T;
    vector<int> vet;
    for(int i = 1; i <= T; i++){
        vet.push_back(i);
    }
    cin >> R;
    print_of(vet);
    rotacionar(vet, R);
    print(vet);
}