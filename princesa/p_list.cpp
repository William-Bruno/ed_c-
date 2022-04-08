#include <iostream>
#include <list>
#include <vector>

void imprimir_lista(std::list<int>& l, std::list<int>::iterator& sword) {
    for (auto it = l.begin(); it != l.end(); it++)
        std::cout << *it << (it == sword? "> " : "  ");
    std::cout << std::endl;
}

int main() {

    int size {}, sword {};
    std::cin >> size >> sword;
    std::list<int> l;
    for (int i = 0; i < size; i++)
        l.push_back(i + 1);
    auto it_sword = next(l.begin(), sword - 1);

    // loop circular
    auto fix_loop = [&l](auto it) {
        return it == l.end() ? l.begin() : it;
    };

    while(l.size() > 1) {
        imprimir_lista(l, it_sword);
        it_sword = fix_loop(next(it_sword, 1));
        it_sword = fix_loop(l.erase(it_sword));
    }
    imprimir_lista(l, it_sword);
}