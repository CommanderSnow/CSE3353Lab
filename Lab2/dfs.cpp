#include "dfs.h"
#include <string>
#include <vector>


DFS::DFS()
{
    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}



void DFS::settings(std::list<source> graph, int x, int y)
{
    pathway = graph;

    sourceNode = findNode(x);
    destNode = findNode(y);
}

void DFS::searchIterative()
{
    std::vector<bool> visited(pathway.size(), false);

    theStack.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node
    source destFinder;  //a source node to help find the destinations of finder

    while(!theStack.empty())
    {
        finder = theStack.top();
        theStack.pop();

        NodesExplored++;

        bestPath.push_back(finder.getName());

        if(finder == destNode)
        {
            break;
        }

        //if the node has not been visited yet
        if(visited[finder.getName()] == false)
        {
            visited[finder.getName()] = true;

            std::list<destination>::iterator iter = finder.getDestinations().begin();
            int sizer = finder.getDestinations().size();

            for(int i=0; i<sizer; i++)
            {
                destination helper(iter->getName());            //helper helps the finder find the source
                destFinder = findNode(helper.getName());

                if(visited[helper.getName()] == false)
                {   theStack.push(destFinder);  }

                iter++;
            }
        }

        else
        {
            //visited[finder.getName()] = false;
            bestPath.pop_back();
        }
    }

    NodesInPath = bestPath.size();

}

void DFS::searchRecursive()
{
    std::vector<bool> visited(pathway.size(), false);

    theStack.push(sourceNode);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node

    recursiveFunc(finder, visited);

    NodesInPath = bestPath.size();

}

void DFS::recursiveFunc(source finder, std::vector<bool>& visited)
{
    source destFinder;  //a source node to help find the destinations of finder

    finder = theStack.top();
    theStack.pop();

    NodesExplored++;

    bestPath.push_back(finder.getName());

    if(finder == destNode)
    {
        //displayPath();
        return;
    }

    //if the node has not been visited yet
    if(visited[finder.getName()] == false)
    {
        visited[finder.getName()] = true;
    }

    std::list<destination>::iterator iter = finder.getDestinations().begin();

    for(int i=0; i<finder.getDestinations().size(); i++)
    {
        destination helper(iter->getName());            //helper helps the finder find the source
        destFinder = findNode(helper.getName());

        if(visited[helper.getName()] == false)
        {
            theStack.push(destFinder);
        }

        iter++;
    }

    recursiveFunc(finder, visited);

    visited[finder.getName()] = false;
    bestPath.pop_back();
}



source& DFS::findNode(int x)
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

void DFS::displayPath()
{
    std::cout << bestPath[0];

    for(int i=1; i<bestPath.size(); i++)
    {
        std::cout << "->" << bestPath[i];
    }

    std::cout <<std::endl;
}

void DFS::clear()
{
    pathway.clear();

    while(!theStack.empty())
    {   theStack.pop(); }

    bestPath.clear();

    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}

int DFS::getPath()
{
    return NodesInPath;
}

int DFS::getExplored()
{
    return NodesExplored;
}

int DFS::getDistance()
{
    return distance;
}

int DFS::getCost()
{
    return cost;
}


