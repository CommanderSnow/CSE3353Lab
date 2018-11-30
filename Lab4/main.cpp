#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

#include "search.h"

using namespace std::chrono;


int main()
{
    //these variables set the starting conditions and are the only things that should ever need to be changed in main

    bool viewMode = false;      //change to true if you want to display the stats to the commmand prompt

    int points = 0;             //sets the number of nodes to randomize and search through
                                 //leave 0 if you wish to read in from a document, not recommended to go above 12 for Brute Force or Dynamic Programming

    //bools to determine which algorithms you wish to see, set to true if you wish to see them
    bool Brute = false;
    bool DP = false;
    bool Genetic = true;
    bool Tabu = true;



///////////////////changing anything beneath this line will fundamentally alter the code///////////////////
///////////////////////////////////////***alter with caution***////////////////////////////////////////////


    search<std::vector<point>> searcher;
    searcher.view(viewMode);

    if(points > 2)
    {
        searcher.configure(points);
    }

    if(Brute==true)
    {
        searcher.execute();
        if(viewMode==true)
        {searcher.stats();}
        searcher.save();
    }

    if(DP==true)
    {
        searcher.select(2);
        searcher.execute();
        if(viewMode==true)
        {searcher.stats();}
        searcher.save();
    }

    if(Genetic==true)
    {
        searcher.select(3);
        searcher.execute();
        if(viewMode==true)
        {searcher.stats();}
        searcher.save();
    }

    if(Tabu==true)
    {
        searcher.select(4);
        searcher.execute();
        if(viewMode==true)
        {searcher.stats();}
        searcher.save();
    }

    return 0;

}//end of main
