#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> vet){
    for(auto elem:vet)
        cout << elem << ' ';
    cout << endl;
}

vector<int> sort_value_absolute(vector<int> vet){   
    for(auto & elem: vet)
        elem = abs(elem);
    sort(vet.begin(), vet.end());
    return vet;
}

vector<int> sort_stress(vector<int> vet){   
    sort(vet.begin(), vet.end());
    return vet;
}



int main() {

    auto value_absolute = sort_value_absolute({-3,1,-4,3,4,70});
    print(value_absolute);
    auto level_stress = sort_stress({-3,1,-4,3,4,70});
    print(level_stress);
}