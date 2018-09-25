#include "bfs.h"
#include <string>
#include <vector>


BFS::BFS()
{

}


void BFS::setSourceDest(int x, int y)
{
    sourceNode = x;
    destNode = y;
}

void BFS::searchIterative(std::list<source>& pathway)
{
    std::vector<bool> visited(pathway.size(), false);

    theQ.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node

    while(!theQ.empty())
    {
        finder = theQ.front();
        theQ.pop();

        //if the node has not been visited yet
        if(visited[finder.getName()] == false)
        {
            visited[finder.getName()] = true;

            std::list<destination>::iterator iter = finder.getDestinations().begin();

            for(int i=0; i<finder.getDestinations().size(); i++)
            {
                destination helper(iter->getName());            //helper helps the finder find the source
                finder = findNode(pathway, helper.getName());

                if(visited[helper.getName()] == false)
                {
                    theQ.push(finder);

                    if(finder == destNode)
                    {
                        return;
                    }
                }

                iter++;
            }
        }
    }

    std::cout << "The path could not be found" <<std::endl;

}

void BFS::searchRecursive(std::list<source>& pathway)
{
    std::vector<bool> visited(pathway.size(), false);

    theQ.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node

    recursiveFunc(finder, visited, pathway);
}

void BFS::recursiveFunc(source finder, std::vector<bool>& visited, std::list<source>& pathway)
{
    finder = theQ.front();
    theQ.pop();


    visited[finder.getName()] = true;

    std::list<destination>::iterator iter = finder.getDestinations().begin();

    for(int i=0; i<finder.getDestinations().size(); i++)
    {
        destination helper(iter->getName());            //helper helps the finder find the source
        finder = findNode(pathway, helper.getName());

        if(visited[helper.getName()] == false)
        {
            theQ.push(finder);

            if(finder == destNode)
            {
                return;
            }
        }

        iter++;
    }
}



source& BFS::findNode(std::list<source>& pathway, int x)
{
    int graphSize = pathway.size();

    std::list<source>::iterator iter = pathway.begin();

    source compare(x);


    for(int i=0; i<graphSize; i++)
    {
        if(compare == *iter)
        {    return *iter;    }

        iter++;
    }

    std::cout << "Could not find node, returning last node instead" <<std::endl;

    return *iter;
}

