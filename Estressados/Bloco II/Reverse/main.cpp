#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vet){
    for(auto elem:vet)
        cout << elem << ' ';
    cout << endl;
}

vector<int> reverse_vector(const vector<int>& vet){
    vector<int> reverse_vector(vet.end(), vet.begin());
    return reverse_vector;
}


void reverse_inplace(vector<int>& vet){
    reverse(vet.begin(), vet.end());
}


int main() {

    auto reverse = reverse_vector({-4,-1,1,3,7});
    print(reverse);
    vector<int> a ({-4,-1,1,3,7});
    reverse_inplace(a);
    print(a);

}