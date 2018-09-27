#include "graphdocumentation.h"


graphDocumentation::graphDocumentation()
{
    //loads all the graph file documentation
    argv[0] = "SaveFile";

    argv[1] = "graph.txt";
    argv[2] = "positions.txt";
    argv[3] = "weights.txt";

    //this handles how many files are loaded, it should be 1 higher than the last argv[x]
    argf = 1;
    argc = 4;
}


void graphDocumentation::buildGraph()
{
    std::ifstream readGraph(argv[1]);
    std::ifstream readPos(argv[2]);
    std::ifstream readWeight(argv[3]);


    while(readGraph.is_open())
    {
        //reads in the full line
        string s;
        std::getline(readGraph, s);

        if(s == "")
        {   break;  }

        //std::cout<< s <<std::endl;

        std::stringstream ss( s );

        //used to hold the information necessary to create a location
        std::vector<int> node;

        //splits the line into seperate elements based on commas.
        while(ss)
        {
            string s2;
            std::getline(ss, s2, ',');

            if(s2 == "")    //removes errors with std::stoi
            {   break; }


            //std::cout<< s2 <<std::endl;

            node.push_back(std::stoi(s2));
        }

        source sourceNode(node[0]);
        int size = node.size();

        for(int i=1; i<size; i++)
        {
            sourceNode.addDestination(node[i]);
        }

        graph.emplace_back(sourceNode);
    }



    while(readWeight.is_open())
    {
        //reads in the full line
        string s;
        std::getline(readWeight, s);

        if(s == "")
        {   break;  }

        std::stringstream ss( s );

        //used to hold the information necessary to create a location
        std::vector<int> node;

        //splits the line into seperate elements based on commas.
        while(ss)
        {
            string s2;
            std::getline(ss, s2, ',');

            if(s2 == "")    //removes errors with std::stoi
            {   break; }

            //std::cout<< s2 <<std::endl;

            node.push_back(std::stoi(s2));
        }

        //find the source, then the destination, then sets the edge
        source compare(node[0]);
        source modifier = findNode(compare);
        destination setter = modifier.findNode(node[1]);
        setter.setEdge(node[2]);

    }



    while(readPos.is_open())
    {
        //reads in the full line
        string s;
        std::getline(readPos, s);

        //std::cout<< s <<std::endl;


        if(s == "")
        {   break;  }

        std::stringstream ss( s );

        //used to hold the information necessary to create a location
        std::vector<int> node;

        //splits the line into seperate elements based on commas.
        while(ss)
        {
            string s2;
            std::getline(ss, s2, ',');

            if(s2 == "")    //removes errors with std::stoi
            {   break; }

            //std::cout<< s2 <<std::endl;

            node.push_back(std::stoi(s2));
        }

        //finds the source and set the positions
        source compare(node[0]);
        source modifier = findNode(compare);
        modifier.setxPos(node[1]);
        modifier.setyPos(node[2]);
        modifier.setzPos(node[3]);
    }

    readGraph.close();
    readWeight.close();
    readPos.close();

}


source& graphDocumentation::findNode(source x)
{
    int graphSize = graph.size();

    std::list<source>::iterator iter = graph.begin();


    for(int i=0; i<graphSize; i++)
    {
        if(x == *iter)
        {    return *iter;    }

        iter++;
    }

    std::cout << "Could not find node, returning last node instead" <<std::endl;

    return *iter;
}


std::list<source>& graphDocumentation::getGraph()
{
    return graph;
}


