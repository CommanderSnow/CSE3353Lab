#include "dfs.h"
#include <string>
#include <vector>


DFS::DFS()
{

}


void DFS::setSourceDest(int x, int y)
{
    sourceNode = x;
    destNode = y;
}

void DFS::search(std::list<source>& pathway)
{
    //
    if(sourceNode == destNode)
    {

    }


    std::vector<bool> visited(pathway.size(), false);

    //path.push(sourceNode);


}



source& DFS::findNode(std::list<source>& pathway, source x)
{
    int graphSize = pathway.size();

    std::list<source>::iterator iter = pathway.begin();


    for(int i=0; i<graphSize; i++)
    {
        if(x == *iter)
        {    return *iter;    }

        iter++;
    }

    std::cout << "Could not find node, returning last node instead" <<std::endl;

    return *iter;
}

