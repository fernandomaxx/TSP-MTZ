//
// Created by fernando on 18/03/19.
//

#ifndef GRAPHALGORITHMS_GRAPH_ADJACENCY_LIST_H
#define GRAPHALGORITHMS_GRAPH_ADJACENCY_LIST_H

#include <vector>
#include <iostream>

class GraphAdjacencyList
{
public:

    explicit GraphAdjacencyList( int size );

    void addEdge( int v1, int v2, int weight );

    bool isAdjacent( int v1, int v2 );

    void showGraph( void );

    int getNum_edges( void ) const;

    std::vector < std::pair< int, int> > *adj;

private:

    int size;
    int num_edges;

};


#endif //GRAPHALGORITHMS_GRAPH_ADJACENCY_LIST_H
