#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool fit(string data, int lim, int index, char value){
    int size = data.size();
    int inicio = max(index - lim, 0);
    int final = min(index + lim + 1, size);
    for(int i = inicio; i < final; i++)
        if(data[i] == value)
            return false;
    return true;
}

int next_index(string data, int index){
    int size = data.size();
    for(int i = index + 1; i < size; i++)
        if(data[i] == '_')
            return i;
    return size;
}

char dig2char(int dig){return dig + '0';}



bool distance_create(string& data, int lim, int index){
    if(index == (int) data.size())
        return true;
    if(data[index]  != '_')
        return distance_create(data, lim, index + 1);
    for(char value = '0'; value <= dig2char(lim); value++){
        if(fit(data, lim, index, value)){
            data[index] = value;
            cout << data << '\n';
            if(distance_create(data, lim, index + 1))
                return true;
        }
    }
    data[index] = '_';
    return false;
}

int main() {

    string sequencia;
    int lim{};
    
    cin >> sequencia;
    cin >> lim;

    distance_create(sequencia,lim,0);

}