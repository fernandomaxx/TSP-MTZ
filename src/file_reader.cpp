//
// Created by fernando on 01/05/19.
//

#include <complex>
#include "../include/file_reader.h"

FileReader::FileReader( std::string filename, int *size )
{
    this->input_file = new std::fstream( filename, std::ios::in);
    if ( !input_file->is_open() )
    {
        std::cout << "Error opening file, check path.\n";
        exit(1);
    }
    std::string line;
    getline( *input_file, line );
    std::cout << line << std::endl;
    getline( *input_file, line );
    std::cout << line << std::endl;
    getline( *input_file, line );
    std::cout << line << std::endl;
    getline( *input_file, line );
    std::stringstream ss( line );
    ss >> line >> this->size;
    *size = this->size;
    std::cout << *size << std::endl;
    getline( *input_file, line );
    getline( *input_file, line );
    std::cout << line << std::endl;
    printf("\n");
}

void FileReader::createGraph( GraphAdjacencyList *graph_adj, GraphAdjacencyMatrix *graph_mtx )
{
//    freopen( "out", "w", stdout );
//    GraphAdjacencyMatrix g(size);
//    GraphAdjacencyList d( size );
    std::vector< std::pair< double, double >> vet;
    std::pair< double, double > point, point_2;
    std::string line;
    double v, x, y;

    while ( getline( *input_file, line ) and line != "EOF" )
    {
        std::stringstream ss( line );
        ss >> v >> x >> y;
        std::cout << v << " " << x << " " << y << std::endl;
        vet.push_back( std::make_pair( x, y ));
    }

    for ( int i = 0; i < size; i++ )
    {
        point = vet[i];
        for ( int j = 0; j < size; j++ )
        {
            point_2 = vet[j];
            double distance = std::sqrt( std::pow( point_2.first - point.first, 2 ) + std::pow( point_2.second - point.second, 2 ));
            int weight = ( int ) round( distance );
            if ( weight )
                graph_adj->addEdge( i, j, weight );
            graph_mtx->addEdge( i, j, weight );
        }
    }

    std::cout << graph_mtx->matrix[0][0] << " " << graph_mtx->matrix[1][1] << " " << graph_mtx->matrix[size-1][size-1] << " \n" ;

}
