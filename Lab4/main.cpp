#include <iostream>
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>

#include "search.h"


using namespace std::chrono;


int main()
{
    //these variables set the starting conditions and are the only things that should ever need to be changed in main

    bool viewMode = false;      //change to true if you want to display the stats to the commmand prompt

    int points = 10;             //sets the number of nodes to randomize and search through
                                 //leave 0 if you wish to read in from a document, not recommended to go above 12



///////////////////changing anything beneath this line will fundamentally alter the code///////////////////
///////////////////////////////////////***alter with caution***////////////////////////////////////////////


    search<std::vector<point>> searcher;
    searcher.view(viewMode);

    //std::vector<point> graph;

    //this function creates a random set of points equal to the number set at 'points' above
    if(points > 2)
    {
        std::vector<point> graph;

        std::srand(std::time(0));

        for(int i=1; i<points+1; i++)
        {
            //gets a random float between 0 and 10
            float data1 = static_cast<float>(rand() % 1000) / 100;
            float data2 = static_cast<float>(rand() % 1000) / 100;
            float data3 = static_cast<float>(rand() % 1000) / 100;
            point node(i, data1, data2, data3);
            graph.push_back(node);
        }


        for(int i=0; i<graph.size(); i++)
        {
            //std::cout << "Node " << graph[i].getName() << ": ";
            //std::cout << graph[i].getX() << ", " << graph[i].getY() << ", " << graph[i].getZ() <<std::endl;
        }

        searcher.load(graph, 1, viewMode);
    }


    searcher.execute();
    if(viewMode==true)
    {searcher.stats();}
    searcher.save();

    searcher.select(2);
    searcher.execute();
    if(viewMode==true)
    {searcher.stats();}
    searcher.save();


    searcher.select(3);
    searcher.execute();
    if(viewMode==true)
    {searcher.stats();}
    searcher.save();

    searcher.select(4);
    searcher.execute();
    if(viewMode==true)
    {searcher.stats();}
    searcher.save();


    return 0;

}//end of main
