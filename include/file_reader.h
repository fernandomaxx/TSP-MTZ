//
// Created by fernando on 01/05/19.
//

#ifndef PROJETOFINALAPA_FILE_READER_H
#define PROJETOFINALAPA_FILE_READER_H


#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>

#include "graph_adjacency_matrix.h"
#include "graph_adjacency_list.h"

class FileReader
{
public:

    FileReader( std::string file, int *size );

    void createGraph( GraphAdjacencyList *graph, GraphAdjacencyMatrix *graph_m );

private:

    int size;
    GraphAdjacencyMatrix *graph_m;
    GraphAdjacencyList *graph_a;
    std::fstream *input_file;
};


#endif //PROJETOFINALAPA_FILE_READER_H
