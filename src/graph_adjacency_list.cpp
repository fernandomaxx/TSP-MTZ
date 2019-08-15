//
// Created by fernando on 18/03/19.
//

#include "../include/graph_adjacency_list.h"

GraphAdjacencyList::GraphAdjacencyList( int size ) :
        size { size }
{
    adj = new std::vector< std::pair< int, int>  >[size];
    num_edges = 0;
}

void GraphAdjacencyList::addEdge( int v1, int v2, int weight )
{
    adj[v1].push_back( std::make_pair( v2, weight ));
    num_edges++;
}

bool GraphAdjacencyList::isAdjacent( int v1, int v2 )
{
    for ( int i = 0; i < adj[v1].size(); i++ )
    {
        if ( adj[v1][i].first == v2 )
            return true;
    }

    return false;
}

void GraphAdjacencyList::showGraph( void )
{
    for ( int i = 0; i < size; i++ )
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
                std::cout << adj[i][j].second << "\t";
        }
        std::cout << std::endl;
    }
}

int GraphAdjacencyList::getNum_edges( void ) const
{
    return num_edges;
}
