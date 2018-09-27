#include "documentation.h"

template <class T>
documentation<T>::documentation()
{
    //loads all the file documentation
    argv[0] = "SaveFile";

    argv[1] = "random10";
    argv[2] = "reverse10";
    argv[3] = "unique10";
    argv[4] = "semirandom10";

    argv[5] = "random1000";
    argv[6] = "reverse1000";
    argv[7] = "unique1000";
    argv[8] = "semirandom1000";

    argv[9] = "random10000";
    argv[10] = "reverse10000";
    argv[11] = "unique10000";
    argv[12] = "semirandom10000";


    argv[13] = "random100000";
    argv[14] = "reverse100000";
    argv[15] = "unique100000";
    argv[16] = "semirandom100000";


    //this handles how many files are loaded, it should be 1 higher than the last argv[x]
    argf = 1;
    argc = 17;
}

template <class T>
void documentation<T>::storeFile(T &data, int size, int file)
{
    std::ofstream outputFile(argv[file]);

    for(int i=0; i<size; i++)
    {
        outputFile << data[i] <<std::endl;
    }

    outputFile.close();
}

template <class T>
void documentation<T>::loadFile(T &data, int size, int file)
{
    std::ifstream readline(argv[file]);

    for(int i=0; i<size; i++)
    {
        readline >> data[i];
    }

    readline.close();
}

template <class T>
void documentation<T>::saveFile(T &data, int size)
{
    //SaveFile is the same as StoreFile except you know it needs to be saved in the SaveFile
    storeFile(data, size, 0);
}

template <class T>
void documentation<T>::saveFile(int NodesInPath, int NodesExplored, double speed, int distance, int cost)
{
    std::ofstream outputFile(argv[0], std::ios::app);

    outputFile << NodesInPath << ", " << NodesExplored << ", ";
    outputFile << speed << ", " << distance << ", " << cost <<std::endl;

    outputFile.close();
}

template <class T>
void documentation<T>::clearSaveFile()
{
    std::ofstream outputFile(argv[0], std::ofstream::out | std::ofstream::trunc);
    outputFile.close();
}



template class documentation<int*>;
template class documentation<float*>;
template class documentation<double*>;
template class documentation<char*>;
template class documentation<std::string*>;
