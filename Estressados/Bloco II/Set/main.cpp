#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<int> vet){
    for(auto elem:vet)
        cout << elem << " ";
    cout << endl;
}

vector<int> get_unique(vector<int> vet){
    unordered_set<int> unique;
    vector<int> triage;
    for(auto elem: vet){
        auto [it, rollback] = unique.insert(elem);
        if(rollback)
            triage.push_back(elem);

    }
    return triage;
}

vector<int> get_repeated(vector<int> vet){
    unordered_set<int> unique;
    vector<int> triage;
    for(auto elem:vet){
        auto[it,rollback] = unique.insert(elem);
        if(!rollback)
            triage.push_back(elem);
    }
    return triage;
}

int main() {
    auto unique = get_unique({-5,-5,-1,1,1,4,5,5,6});
    print(unique);
    auto repeated = get_repeated({-5,-5,-1,1,1,4,5,5,6});
    print(repeated);

}