//
// Created by ed020606 on 12/14/2023.
//



#include <iostream>

#include "Array/Graph/Graph.h"
#include <bits/stdc++.h>
using namespace array;
//using namespace std;
int main() {

    std::ifstream in("C:\\Users\\TEMP.OZUN.000\\Desktop\\turkish-dictionary.txt");
    array::Graph g = array::Graph(100);
    auto count = 0;
    while(!in.eof()) {

        std::string word;

        getline(in,word);

        std::cout << word << std::endl;
        count++;
    }

    std::cout << count << std::endl;

//    auto g = array::Graph(5);

    return 0;
}
