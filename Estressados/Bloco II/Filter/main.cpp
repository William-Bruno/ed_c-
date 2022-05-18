#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vet){
    for(auto elem:vet)
        cout << elem << " ";
    cout << endl;
}

vector<int> get_men(const vector<int>& vet){
    vector<int> men;
    for(int elem: vet){
        if(elem > 0)
            men.push_back(elem);
    }
    return men;
}

vector<int> get_woman_calm(const vector<int>& vet){
    vector<int> woman_calm;
    for(int elem : vet)
        if(elem < 0 && elem > -10)
            woman_calm.push_back(elem);
    return woman_calm;
}


int main() {

    auto men = get_men({-3,-2,-1,6,7});
    print(men);
    auto woman = get_woman_calm({-5,-4,5,10,50,70});
    print(woman);

}