//
// Created by ed020606 on 12/14/2023.
//



#include <iostream>

#include "Array/Graph/Graph.h"
#include "Array/Queue.h"
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
using namespace array;
using namespace std;

bool isOneWordDifference(const string& w1, const string& w2) {
    if(w1.length() != w2.length()) {
        return false;
    }
    int diff = 0;
    for(int i = 0; i < w1.length(); i++) {
        if(w1[i] != w2[i]) {
            diff++;
        }
    }
    return diff == 1;
}

Graph constructGraph(const vector<string>& vector) {
    int sz = vector.size();
    auto graph = Graph(sz);

    for(int i = 0; i < sz; i++) {
        for(int j = 0; j < sz; j++) {
            if(isOneWordDifference(vector[i],vector[j])) {
                graph.addEdge(i,j);
            }
        }
    }

    return graph;
}

void BFS(Graph& graph, const vector<string> words, int start, int finish) {
    int vertexCount = words.size();
    vector<bool> visit(vertexCount, false);

    Queue q(vertexCount);
    q.enqueue(Element(start));
    visit[start] = true;

    vector<int> prev(vertexCount,-1);

    while(!q.isEmpty()) {
        int currentNode = q.dequeue().getData();

        if(currentNode == finish) {
            cout << "Shortest path: " << endl;

            vector<int> shortestPath;
            int index = finish;

            while(index != -1) {
                shortestPath.push_back(index);
                index = prev[index];
            }

            reverse(shortestPath.begin(), shortestPath.end());

            for(auto i = 0; i < shortestPath.size(); ++i) {
                cout << words[shortestPath[i]];
                if(i != shortestPath.size()-1) {
                    cout << " -> ";
                }
                cout << endl;
                return;
            }

            for(int neighbor = 0; neighbor < vertexCount; ++neighbor) {
                if(graph.getEdges()[currentNode][neighbor] && !visit[neighbor]) {
                    visit[neighbor] = true;
                    q.enqueue(Element(neighbor));
                    prev[neighbor] = currentNode;
                }
            }
        }
    }

    cout << "Can not reach the target word!" << endl;
}

int searchIndex(const string& w, const vector<string>& words) {
    int index = 0;
    for(const auto& item : words) {
        if(item == w)
            return index;
        index++;
    }

    return -1;
}

vector<string> readFile(const string& directory, int size) {
    ifstream in(directory);
    vector<string> words{};
    if(in.is_open()) {
        string line;
        while(getline(in,line)) {
            if(line.length() == size) {
                words.push_back(line);
            }
        }
        in.close();
    } else {
        cout << "File cannot open" << endl;
    }
    return words;
}


int main() {


    return 0;
}
