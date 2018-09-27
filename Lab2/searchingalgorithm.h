#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <list>
#include "source.h"


template <class T>
class searchingAlgorithm
{
private:

    std::list<source> data;
    int start;
    int end;
    int selection;

    int NodesInPath;
    int NodesExplored;
    int distance;
    int cost;

public:

    searchingAlgorithm();
    searchingAlgorithm(std::list<source> &graph, int select, int starter, int dest);

    void setData(std::list<source> &graph, int select, int starter, int dest);

    void execute();

    void statistics();

    int& getPath();
    int& getExplored();
    int& getDistance();
    int& getCost();

};

#endif // SEARCHINGALGORITHM_H
