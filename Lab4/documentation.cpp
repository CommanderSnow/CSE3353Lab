#include "documentation.h"


documentation::documentation()
{
    //loads all the graph file documentation
    argv[0] = "SaveFile";

    argv[1] = "positions.txt";

    //this handles how many files are loaded, it should be 1 higher than the last argv[x]
    argf = 1;
    argc = 2;

    //Zeros the first value to keep the element equal to the node name
    point first(0, 0, 0, 0);

    graph.push_back(first);
}

int documentation::fileSize()
{
    int count = 0;
    string line;

    std::ifstream readFile(argv[1]);

    while(std::getline(readFile, line))
    {
        std::cout << line <<std::endl;
        count++;
    }

    std::cout << "Numbers of lines in the file : " << count << std::endl;

    return count;
}

void documentation::buildGraph()
{
    std::ifstream readPos(argv[1]);


    while(readPos.is_open())
    {
        //reads in the full line
        string s;
        std::getline(readPos, s);

        std::cout<< s <<std::endl;

        //skips inputs that are blank and breaks the graph
        if(s == "")
        {   break;  }

        std::stringstream ss( s );

        //used to hold the information necessary to create a location
        int f=0;
        point newPoint;

        //splits the line into seperate elements based on commas.
        while(ss)
        {
            string s2;
            std::getline(ss, s2, ',');

            if(s2 == "")    //removes errors with std::stoi
            {   break; }

            std::cout<< s2 <<std::endl;

            if(f==0)
            {
                newPoint.setName(std::stof(s2));
            }

            else if(f==1)
            {
                newPoint.setX(std::stof(s2));
            }

            else if(f==2)
            {
                newPoint.setY(std::stof(s2));
            }

            else if(f==3)
            {
                newPoint.setZ(std::stof(s2));
            }

            f++;
        }

        graph.push_back(newPoint);

    }

    readPos.close();

}

std::vector<point>& documentation::getGraph()
{
    return graph;
}

void documentation::clearSave()
{
    std::ofstream outputFile(argv[0], std::ofstream::out | std::ofstream::trunc);
    outputFile.close();
}

void documentation::saveFile(int selection, double speed, std::vector<int> &bestPath, float bestDist, int size)
{
    std::ofstream outputFile(argv[0], std::ios::app);

    if(selection == 1)
    {
        outputFile << "The shortest path for Brute Force is: " << bestPath[0];
    }

    else if(selection == 2)
    {
        outputFile << "The shortest path for Dynamic Programming is: " << bestPath[0];
    }

    else if(selection == 3)
    {
        outputFile << "The shortest path for Genetic Algorithm is: " << bestPath[0];
    }

    else if(selection == 3)
    {
        outputFile << "The shortest path for Tabu is: " << bestPath[0];
    }



    for(int i=1; i<size; i++)
    {
        outputFile << "->" << bestPath[i];
    }

    outputFile << " | Distance: " << bestDist <<std::endl;

    outputFile << "Time taken: " << speed <<std::endl;
}

void documentation::randomGraph(int points)
{
    graph;

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
}



