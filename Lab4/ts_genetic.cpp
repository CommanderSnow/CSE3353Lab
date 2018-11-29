#include "TS_Genetic.h"

using std::vector;


TS_Genetic::TS_Genetic()
{
    viewMode = false;

}

TS_Genetic::TS_Genetic(bool viewer)
{
    viewMode = viewer;
}

void TS_Genetic::findPath(vector<point> &graph, float &bestDist, int *&bestPath)
{
    int size = graph.size();

    //creates an X by X matrix of floats for Tabulation Dynamic Programming
    table = new float*[size];
    for(int i=0; i<size; i++)
    {   table[i] = new float[size]; }

    //populates the matrix with the distance calculations
    for(int i=0; i<size; i++)
    {
        for(int k=0; k<size; k++)
        {
            table[i][k] = distanceCalc(graph[i], graph[k]);
        }
    }

    for(int i=0; i<size; i++)
    {
        permutation.push_back(i);
    }

    vector<int> chromosome;

    for(int i=0; i<10; i++)
    {
        population.push_back(chromosome);
        createChromosome(population[i]);
    }

    vector<int> survivors(selectionRate);
    vector<float> fitness(10);
    documentation saver;

    //continues for a number of generations equal to limit
    int limit = 10;

    for(int generations=0; generations<limit; generations++)
    {
        //gets the fitness value of the chromosomes
        for(int i=0; i<limit; i++)
        {
            fitness[i] = fitnessValue(population[i]);
        }        

        //std::cout << "Chromosomes Selected: ";


        //selects which chromosomes survive and cross over
        for(int i=0; i<selectionRate; i++)
        {
            survivors[i] = naturalSelection(fitness);

            //std::cout << survivors[i] << ", ";
        }

        //creates the next generation by crossing over the survivors of the previous generation
        nextGeneration(survivors);

        //mutates chromosome
        mutator();
    }

    //finds the fitness of the last generation
    for(int i=0; i<limit; i++)
    {
        fitness[i] = fitnessValue(population[i]);
    }

    bestDist = 0;

    for(int i=0; i<fitness.size(); i++)
    {
        if(bestDist <= fitness[i])
        {
            bestDist = 1/fitness[i];
            //bestPath = &population[i][0];


            for(int k=0; k<size; k++)
            {
                bestPath[i] = population[i][k]+1;
            }

        }
    }


    //when bestPath returns, bestPath[0] gets corrupted sometimes and I can't figure out why
    //bestPath[0] is correct at this point in the code
}

void TS_Genetic::createChromosome(vector<int> &chromosome)
{
    std::random_shuffle(permutation.begin(), permutation.end());
    chromosome = permutation;
}


float TS_Genetic::fitnessValue(vector<int> chromosome)
{
    float fitness = 0;
    int size = chromosome.size();

    int k = 0;

    for(int i=0; i<size; i++)
    {
        fitness += table[k][permutation[i]];
        k = permutation[i];
    }

    fitness += table[k][0];

    return 1/fitness;
}

int TS_Genetic::naturalSelection(vector<float> fitness)
{
    float totalFitness = 0;

    //adds the fitness values of all chromosomes
    for(int i=0; i<fitness.size(); i++)
    {
        totalFitness += fitness[i];
    }

    std::seed_seq seed{randomizer(), randomizer(), randomizer(), randomizer(), randomizer(), randomizer(), randomizer()};
    std::mt19937 engine(seed);

    std::uniform_real_distribution<float> dist(0, totalFitness);
    float random = dist(engine);

    for(int i=0; i<fitness.size(); i++)
    {
        random -= fitness[i];

        if(random <= 0)
        {
            return i;
        }
    }

    return fitness.size();

}


void TS_Genetic::crossover(vector<int>& parent1, vector<int>& parent2)
{

    for(int i=0; i<crossoverRate; i++)
    {
        int gene = std::rand()% parent1.size();

        //swaps two points from the parents
        int tempGene1 = parent1[gene];
        int tempGene2 = parent2[gene];
        parent1[gene] = parent2[gene];

        //replaces the duplicated points with the swapped points
        for(int j=0; j<parent1.size(); j++)
        {
            if(j == gene)
            {
                continue;
            }

            else
            {
                if(parent1[j] == parent1[gene])
                {   parent1[j] = tempGene1; }

                if(parent2[j] == parent2[gene])
                {   parent2[j] = tempGene2; }
            }
        }
    }

}


void TS_Genetic::nextGeneration(vector<int> survivors)
{
    //create selection rate number of new chromosomes
    vector<vector<int>> newPopulation(selectionRate);

    //put selected chromosomes into them
    for(int i=0; i<selectionRate; i++)
    {
        int selector = survivors[i];
        newPopulation[i] = population[selector];
    }

    int rand1;
    int rand2;

    //fills out the new population with random selections of each chromosome
    for(int i=0; i<10; i++)
    {
        //selects two parents that are not the same chromosome
        while(true)
        {
            rand1 = rand() % selectionRate;
            rand2 = rand() % selectionRate;

            if(rand1 != rand2)
            {   break;  }
        }

        //replaces the population with sets that will crossover
        population[i] = newPopulation[rand1];
        i++;    //ensures the for loop goes by two
        population[i] = newPopulation[rand2];

        //crosses over the parents
        crossover(population[i-1], population[i]);
    }
}

void TS_Genetic::mutator()
{
    for(int i=0; i<10; i++)
    {
        int mutation = rand() % 100;

        //mutates the chromosome if it hits the random chance
        if(mutation <= mutationRate)
        {
            int rand1 = rand() % population[i].size();
            int rand2 = rand() % population[i].size();

            int temp = population[i][rand1];
            population[i][rand1] = population[i][rand2];
            population[i][rand2] = temp;
        }
    }
}


float TS_Genetic::distanceCalc(point start, point end)
{
    float Xdist = start.getX() - end.getX();
    float Ydist = start.getY() - end.getY();
    float Zdist = start.getZ() - end.getZ();

    return std::sqrt(Xdist * Xdist + Ydist * Ydist + Zdist * Zdist);
}

