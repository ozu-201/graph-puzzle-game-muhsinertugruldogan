cmake_minimum_required(VERSION 3.23)
project(graph-puzzle-game-muhsinertugruldogan)
set(CMAKE_CXX_STANDARD 20)

add_library(graph-puzzle-game-muhsinertugruldogan
        src/Main.cpp
        src/Array/Element.cpp
        src/Array/Element.h src/Array/Stack.cpp src/Array/Stack.h  src/Array/Queue.cpp src/Array/Queue.h
        src/Array/Hash.cpp src/Array/Hash.h  src/Array/Heap/Heap.cpp src/Array/Heap/Heap.h src/Array/Heap/HeapNode.cpp
        src/Array/Heap/HeapNode.h src/Array/Heap/DHeap.cpp src/Array/Heap/DHeap.h src/Array/Set.cpp src/Array/Set.h src/Array/DisjointSet.cpp
        src/Array/DisjointSet.h src/Array/Graph/Graph.cpp src/Array/Graph/Graph.h
        src/General/Path.cpp src/General/Path.h src/General/AbstractGraph.cpp
        src/General/AbstractGraph.h src/Array/Heap/MaxHeap.cpp src/Array/Heap/MaxHeap.h src/Array/Heap/MaxDHeap.cpp src/Array/Heap/MaxDHeap.h
        src/Array/Heap/MinHeap.cpp src/Array/Heap/MinHeap.h src/Array/Heap/MinDHeap.cpp src/Array/Heap/MinDHeap.h )

add_executable( Main src/Main.cpp
        src/Array/Element.cpp
        src/Array/Element.h src/Array/Stack.cpp src/Array/Stack.h  src/Array/Queue.cpp src/Array/Queue.h
        src/Array/Hash.cpp src/Array/Hash.h  src/Array/Heap/Heap.cpp src/Array/Heap/Heap.h src/Array/Heap/HeapNode.cpp
        src/Array/Heap/HeapNode.h src/Array/Heap/DHeap.cpp src/Array/Heap/DHeap.h src/Array/Set.cpp src/Array/Set.h src/Array/DisjointSet.cpp
        src/Array/DisjointSet.h src/Array/Graph/Graph.cpp src/Array/Graph/Graph.h
        src/General/Path.cpp src/General/Path.h src/General/AbstractGraph.cpp
        src/General/AbstractGraph.h src/Array/Heap/MaxHeap.cpp src/Array/Heap/MaxHeap.h src/Array/Heap/MaxDHeap.cpp src/Array/Heap/MaxDHeap.h
        src/Array/Heap/MinHeap.cpp src/Array/Heap/MinHeap.h src/Array/Heap/MinDHeap.cpp src/Array/Heap/MinDHeap.h )
#add_executable(main "src/Main.cpp")