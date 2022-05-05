#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vet){
    cout << "[ ";
    for(auto elem:vet)
    cout << "]";
}


int main(){

    vector<int> vet{1,2,3,4,5};
    print(vet);

    return 0;
}
