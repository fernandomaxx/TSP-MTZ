#include <stdio.h>
#include <vector>
#include <iostream>
#include "../include/file_reader.h"
#include <ilcplex/ilocplex.h>

int main(int argc, char *argv[])
{
    int n;

    /*
    std::string path = "instance/";
    GraphAdjacencyList *graph;
    GraphAdjacencyMatrix *graph_m;
    FileReader fileReader(path + argv[0], &n);
    graph = new GraphAdjacencyList(n);
    graph_m = new GraphAdjacencyMatrix(n);
    fileReader.createGraph(graph, graph_m);
    */

    std::vector<std::vector<int> >weight(n, std::vector<int>(n));

    
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> weight[i][j];
        }   
    }
    
    IloEnv env;
    IloModel model(env);

    IloArray<IloIntVarArray> x(env, n);
    IloArray<IloIntArray> d(env, n);

    /* Variaveis */
    for (int i = 0; i < n; i++)
    {
        d[i] = IloIntArray(env);
        for (int j = 0; j < n; j++)
        {
            d[i].add(weight[i][j]);
            //d[i].add(graph_m->matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
        x[i] = IloIntVarArray(env, n, 0, 1);


    /* Função Objetivo */
    IloExpr obj(env);
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
            obj += d[i][j] * x[i][j];
        }	
	}
	model.add(IloMinimize(env, obj));    

    /* Restrições */
    for (int i = 0; i < n; i++)
    {
        IloExpr sum_ij(env);
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            sum_ij += x[i][j];
        }
        
        model.add(sum_ij == 1);
    }

    for (int i = 0; i < n; i++)
    {
        IloExpr sum_ji(env);
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            sum_ji += x[j][i];
        }

        model.add(sum_ji == 1);
    }

    IloIntVarArray u(env, n, 1, n);

    for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i == j) continue;
				
			model.add(u[i] - u[j] + (n - 1)*x[i][j] <= (n - 2));
		}
    }
	
    /* Resolve o Modelo */
	std::cout << std::endl;
	IloCplex cplex(model);
    cplex.setParam(IloCplex::TiLim, 2*60*60);
    //cplex.setParam(IloCplex::Threads, 8);
    cplex.exportModel("model.lp");

    try
   	{
    	if(cplex.solve())
		{
			env.out() << "\nSolution Status = " << cplex.getStatus() << std::endl;
			env.out() << "Solution value = " << cplex.getObjValue() << std::endl;
			/*
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
					if(i == j)
					{
						std::cout << "0 ";
						continue;
					}
					else std::cout << abs(cplex.getValue(x[i][j])) << " ";
				std::cout << std::endl;
			}
            */
		}
   	}
   	catch(IloException& e)
   	{
		std::cout << e;
		
   	}
    
}