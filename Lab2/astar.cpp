#include "astar.h"
#include <string>
#include <vector>


AStar::AStar()
{
    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}



void AStar::settings(std::list<source> graph, int x, int y)
{
    pathway = graph;

    sourceNode = findNode(x);
    destNode = findNode(y);
}

void AStar::search()
{
    std::vector<bool> visited(pathway.size(), false);

    std::pair<int, std::vector<source>> pairy;

    std::vector<source> path;
    path.push_back(sourceNode);

    pairy.first = 0;
    pairy.second = path;
    thePQ.push(pairy);

    //eliminates trivial answers
    if(sourceNode == destNode)
    {
        return;
    }

    source finder;      //a source node to find other source node
    source destFinder;  //a source node to help find the destinations of finder

    while(!thePQ.empty())
    {
        path = thePQ.top().second;
        int edginess = thePQ.top().first;
        finder = path.back();

        NodesExplored++;

        if(finder == destNode)
        {
            if(bestPath.empty())
            {
                bestPath = path;
                cost = edginess;
            }

            if(path.size() < bestPath.size())
            {
                bestPath = path;
                cost = edginess;
            }

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
                {
                    std::vector<source> possPath = path;
                    possPath.push_back(destFinder);

                    int xDist = (destFinder.getxPos() - destNode.getxPos()) * (destFinder.getxPos() - destNode.getxPos());
                    int yDist = (destFinder.getyPos() - destNode.getyPos()) * (destFinder.getyPos() - destNode.getyPos());
                    int zDist = (destFinder.getzPos() - destNode.getzPos()) * (destFinder.getzPos() - destNode.getzPos());

                    int totalDist = xDist + yDist + zDist;

                    edginess = edginess + helper.getEdge() + totalDist;
                    pairy.first = edginess;
                    pairy.second = possPath;
                    thePQ.push(pairy);
                }

                iter++;
            }
        }

        else
        {
            thePQ.pop();
            visited[finder.getName()] = false;
        }
    }

    NodesInPath = bestPath.size();
    findDistance();

}


source& AStar::findNode(int x)
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

void AStar::displayPath()
{
    std::cout << bestPath[0].getName();

    for(int i=1; i<bestPath.size(); i++)
    {
        std::cout << "->" << bestPath[i].getName();
    }

    std::cout <<std::endl;
}

void AStar::clear()
{
    pathway.clear();

    while(!thePQ.empty())
    {   thePQ.pop();    }

    bestPath.clear();

    NodesInPath = 0;
    NodesExplored = 0;
    distance = 0;
    cost = 0;
}

void AStar::findDistance()
{
    int xDist = (sourceNode.getxPos() - destNode.getxPos()) * (sourceNode.getxPos() - destNode.getxPos());
    int yDist = (sourceNode.getyPos() - destNode.getyPos()) * (sourceNode.getyPos() - destNode.getyPos());
    int zDist = (sourceNode.getzPos() - destNode.getzPos()) * (sourceNode.getzPos() - destNode.getzPos());

    distance = xDist + yDist + zDist;
}

int AStar::getPath()
{
    return NodesInPath;
}

int AStar::getExplored()
{
    return NodesExplored;
}

int AStar::getDistance()
{
    return distance;
}

int AStar::getCost()
{
    return cost;
}
