//
// Created by fernando on 19/03/19.
//

#ifndef GRAPHALGORITHMS_GRAPH_ADJACENCY_MATRIX_H
#define GRAPHALGORITHMS_GRAPH_ADJACENCY_MATRIX_H

#include <iostream>


class GraphAdjacencyMatrix
{
public:

    GraphAdjacencyMatrix( int size );

    ~GraphAdjacencyMatrix( void );

    void addEdge( int v1, int v2, int weight );

    bool isAdjacent( int v1, int v2 );

    void showGraph( void );

    int getNum_edges( void ) const;

    int setSize( int size );

    int **matrix;

private:

    int size;
    int num_edges;

};


#endif //GRAPHALGORITHMS_GRAPH_ADJACENCY_MATRIX_H
