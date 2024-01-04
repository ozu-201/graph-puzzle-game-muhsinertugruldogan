/**
 * Author: Muhsin Ertugrul Dogan.
 * It is my word puzzle game.
 * You can play the game in Main.cpp file.
 *
 * I have helper functions and my main breadth first search functions. I will explain them later.
 *
 *
 */


#include <iostream>
/**Basically, I use array representation of graph.
 * */
#include "Array/Graph/Graph.h"
#include "Array/Queue.h"
#include <bits/stdc++.h>
#include <fstream>
#include <string>

using namespace array;
using namespace std;


/**
 * One word difference is crucial for our game.
 * This method controls the one word difference between the words in the dictionary.
 */
bool isOneWordDifference(const string &w1, const string &w2) {
    if (w1.length() != w2.length()) {
        return false;
    }
    int diff = 0;
    for (int i = 0; i < w1.length(); i++) {
        if (w1[i] != w2[i]) {
            diff++;
        }
    }
    return diff == 1;
}

/**
 * This method constructs the our word graph. We check the one word difference condition.
 * If condition is true, we add an edge between these two word.
 */
Graph constructGraph(const vector<string> &vector) {
    int sz = vector.size();
    auto graph = Graph(sz);

    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            if (i != j) {
                if (isOneWordDifference(vector[i], vector[j])) {
                    graph.addEdge(i, j);
                }
            }

        }
    }
    return graph;
}

/**
 * We search the words according to their indexes in the word list.
 * So, we should know the index value of the word. This method checks the
 * index and returns the index value. If the word is not in the list,
 * this method returns -1.
 */
int searchIndex(const string &w, const vector<string> &words) {
    int index = 0;
    for (const auto &item: words) {
        if (item == w)
            return index;
        index++;
    }

    return -1;
}

/**
 * This method helps us to read file and collect the words are desired length.
 * It returns the list of the words.
 * In addition, our dictionary is in the cmake-build-debug directory. If you want to
 * read another file from another location, you can change the directory.
 */
vector<string> readFile(const string &directory, int size) {
    ifstream in(directory);
    vector<string> words{};
    if (in.is_open()) {
        string line;
        while (getline(in, line)) {
            if (line.length() == size) {
                words.push_back(line);
                /**
                 * If you want to see all words with desired size in dictionary, you can uncomment that line.
                 */
//                cout << line << endl;
            }
        }
        in.close();
    } else {
        cout << "File cannot open" << endl;
    }
    return words;
}

/**
 * BFS method is our main search method.
 * It use the breath first search. I change the structure of BFS.
 * BHS search the all neighbor nodes of the start node.
 */
void BFS(Graph &graph, const vector<string> words, int start, int finish) {
    cout << "Start word: " << words[start] << endl;
    cout << "Target word: " << words[finish] << endl;

    int vertexCount = words.size();
    vector<bool> visit(vertexCount, false);

    Queue q(vertexCount);
    q.enqueue(Element(start));
    visit[start] = true;

    /**
     * I create a prev vector to store the previous visited nodes.
     */
    vector<int> prev(vertexCount, -1);

    while (!q.isEmpty()) {
        int currentNode = q.dequeue().getData();
        //If you want oto see all visited nodes when we are going to target node, uncomment that line.
//        cout << currentNode << " " << words[currentNode] << endl;
        if (currentNode == finish) {
            cout << "Shortest path: " << endl;

            vector<int> shortestPath;
            int index = finish;

            while (index != -1) {
                shortestPath.push_back(index);
                index = prev[index];
            }
            /**
             * I use the built in algorithm reverse to reverse the shortest path vector.
             */
            reverse(shortestPath.begin(), shortestPath.end());

            for (int i = 0; i < shortestPath.size(); i++) {
                cout << words[shortestPath[i]];
                if (i != shortestPath.size() - 1) {
                    cout << " -> ";
                }
            }
            cout << endl;
            return;
        }
        for (int neighborNode = 0; neighborNode < vertexCount; ++neighborNode) {
            if (graph.getEdges()[currentNode][neighborNode] && !visit[neighborNode]) {
                visit[neighborNode] = true;
                q.enqueue(Element(neighborNode));
                prev[neighborNode] = currentNode;
            }
        }
    }

    cout << "Can not reach the target word!" << endl;
}


int main() {

    /**
     * You can enter the directory of dictionary and word size here.
     */
    auto words = readFile("english-dictionary.txt", 4);
    auto wordGraph = constructGraph(words);

    /**
     * Enter the start and target word.
     */
    string startWord = "aare";
    string targetWord = "nome";

    int startIndex = searchIndex(startWord, words);
    int targetIndex = searchIndex(targetWord, words);

    /**
     * Shortest path appear in console after that line executed.
     */
    BFS(wordGraph, words, startIndex, targetIndex);

    return 0;
}

