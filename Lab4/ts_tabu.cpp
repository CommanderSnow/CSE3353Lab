#include "TS_Tabu.h"

using std::vector;


TS_Tabu::TS_Tabu()
{
    viewMode = false;
}

TS_Tabu::TS_Tabu(bool viewer)
{
    viewMode = viewer;
}

void TS_Tabu::findPath(std::vector<point> graph, float &bestDist, std::vector<int> &bestPath)
{
    size = graph.size();

    //creates an X by X matrix of floats
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

    std::vector<int> permutation;

    for(int i=0; i<size; i++)
    {
        permutation.push_back(i);
    }


    //creates the inital greedy path
    vector<int> initialState;
    initialState.push_back(permutation[0]);
    int prevNode = permutation[0];
    int nextNode = permutation[1];      //initializing this here can prevent errors below

    for(int k=1; k<permutation.size(); k++)
    {
        int shortest = 9999999; //might be cases where a path is not found because its too far away, increase this number in that case


        //go through each point to find the shortest distance that is not already in the path
        for(int i=0; i<permutation.size(); i++)
        {
            bool inPath = false;

            if(shortest > table[prevNode][i])
            {
                //checks if the point is in the path already
                for(int j=0; j<initialState.size(); j++)
                {
                    if(initialState[j] == i)
                    {   inPath = true;  }
                }

                if(inPath == false)
                {
                    shortest = table[prevNode][i];
                    nextNode = i;
                }
            }

        }

        initialState.push_back(nextNode);

        prevNode = nextNode;

    }


    float initialLength = getLength(initialState);


    vector<vector<int>> neighborhood;


    for(int k=0; k<10; k++)
    {

        TabuList.push_back(initialState[0]);
        TabuList.push_back(initialState[size-1]);

        bool moreNeighbors = true;

        //while(moreNeighbors == true)
        for(int i=0; i<10; i++)
        {
            moreNeighbors = createNeighbor(neighborhood, initialState);
            //break;
        }

        int best = -1;
        int pathLength;

        //once a neightborhood is complete, search though all of them and find the best one
        for(int i=0; i<neighborhood.size(); i++)
        {
            pathLength = getLength(neighborhood[i]);
            if(pathLength < initialLength)
            {
                best = i;
                initialLength = pathLength;
            }
        }


        //if best is never updated, that means a better neighbor has not been found
        if(0 < best)
        {
            initialState = neighborhood[best];
        }


        //clear the lists and start again
        TabuList.clear();
        neighborhood.clear();

    }


    for(int i=0; i<size; i++)
    {
        bestPath[i] = initialState[i]+1;
    }

    bestDist = getLength(initialState);


}


float TS_Tabu::getLength(vector<int> neighbor)
{
    float length=0;

    length += table[neighbor[0]][neighbor[neighbor.size()-1]];


    for(int i=1; i<neighbor.size(); i++)
    {
        length += table[neighbor[i-1]][neighbor[i]];
    }


    return length;
}


//returns false if it cannot create another neighbor
bool TS_Tabu::createNeighbor(vector<vector<int>>& neighborhood, vector<int> initialState)
{
    int rand1;
    int rand2;
    int rejections = 0;
    bool rejected = false;



    //selects two positions that are not the same point
    while(true)
    {
        rejected = false;
        rand1 = std::rand() % (size-1) + 1;
        rand2 = std::rand() % (size-1) + 1;

        if(rand1 == rand2)
        {   continue;  }

        //if one of the random slots is on the Tabu list, increase rejections
        for(int i=0; i<TabuList.size(); i++)
        {
            if(initialState[rand1] == TabuList[i] && initialState[rand2] == TabuList[i])
            {
                rejections++;
                rejected = true;

                //states that no more neighbors can be found after a set number of rejections
                if(rejections>10)
                {   return false;   }

                break;
            }
        }


        if(rejected==true)
        {   continue;   }

        break;
    }

    if(TabuList.size() < tabuSize)
    {
        TabuList.push_back(initialState[rand1]);
        TabuList.push_back(initialState[rand2]);
    }



    else
    {
        //resets the pointer to prevent overflow
        if(tabuSize <= tabuPtr)
        {   tabuPtr = 0;    }

        TabuList[tabuPtr++] = initialState[rand1];
        TabuList[tabuPtr++] = initialState[rand2];
    }

    //swaps the two nodes and adds it to the neighborhood
    vector<int> neighbor = initialState;

    int temp = neighbor[rand1];
    neighbor[rand1] = neighbor[rand2];
    neighbor[rand2] = temp;

    neighborhood.push_back(neighbor);

    return true;
}



float TS_Tabu::distanceCalc(point start, point end)
{
    float Xdist = start.getX() - end.getX();
    float Ydist = start.getY() - end.getY();
    float Zdist = start.getZ() - end.getZ();

    return std::sqrt(Xdist * Xdist + Ydist * Ydist + Zdist * Zdist);
}

