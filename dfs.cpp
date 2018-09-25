#include "dfs.h"
#include <string>
#include <vector>


DFS::DFS()
{

}


void DFS::setSourceDest(int x, int y)
{
    sourceNode.setName(x);
    destNode.setName(y);
}

void DFS::searchIterative(std::list<source>& pathway)
{
    std::vector<bool> visited(pathway.size(), false);

    theStack.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node

    while(!theStack.empty())
    {
        finder = theStack.top();
        theStack.pop();

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
                    theStack.push(finder);

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

void DFS::searchRecursive(std::list<source>& pathway)
{
    std::vector<bool> visited(pathway.size(), false);

    theStack.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node

    recursiveFunc(finder, visited, pathway);
}

void DFS::recursiveFunc(source finder, std::vector<bool>& visited, std::list<source>& pathway)
{
    finder = theStack.top();
    theStack.pop();

    visited[finder.getName()] = true;

    std::list<destination>::iterator iter = finder.getDestinations().begin();

    for(int i=0; i<finder.getDestinations().size(); i++)
    {
        destination helper(iter->getName());            //helper helps the finder find the source
        finder = findNode(pathway, helper.getName());

        if(visited[helper.getName()] == false)
        {
            theStack.push(finder);

            if(finder == destNode)
            {
                return;
            }
        }

        iter++;
    }
}



source& DFS::findNode(std::list<source>& pathway, int x)
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

