#ifndef TS_GENETIC_H
#define TS_GENETIC_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <random>
#include <chrono>
#include "point.h"
#include "documentation.h"

using std::vector;

class TS_Genetic
{
private:

    //chromosome population[10];
    bool viewMode;

    vector<vector<int>> population;
    float** table;
    vector<int> permutation;

    std::random_device randomizer;


    int selectionRate = 4;    //determines how many chromosomes are selected for crossover
    int crossoverRate = 3;    //determines the number of swappings two parents have
    int mutationRate = 10;     //determines how often any chromosome experiences a mutation (x out of 100 chance)



public:

    TS_Genetic();
    TS_Genetic(bool);

    //iterates through the entire graph and outputs the shortest path
    void findPath(vector<point> &graph, float &bestDist, std::vector<int> &bestPath);

    //creates a new random chromosome
    void createChromosome(vector<int> &chromosome);

    //determines the chromosome's fitness value
    float fitnessValue(vector<int> chromosome);

    //roulette wheel selects 4 chromosomes to survive
    int naturalSelection(vector<float> fitness);

    //combines two parent chromosomes together to create two children
    void crossover(vector<int>&, vector<int>&);

    //repopulates the population based on the survivors of the previous generation
    void nextGeneration(vector<int> survivors);

    //gives a chance to mutate each chromosome
    void mutator();

    //finds the distance between two points
    float distanceCalc(point start, point end);
};

#endif // TS_GENETIC_H
