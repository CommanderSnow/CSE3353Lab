#include <iostream>
#include "datasets.h"
#include "sort.h"
#include "documentation.h"


int main()
{
    //these variables set the starting conditions and are the only things that should ever need to be changed in main

    int sizes[] = {10, 1000, 10000, 100000};    //sets the possible sizes of the data
    int loops = 3;                              //sets which position in sizes[loops] you want it to stop at, 0 = data size stops at 10, 3 = 100,000

    int num_of_datasets = 4;                    //sets the number of datasets to be used
    int num_of_algorithms = 3;                  //sets the number of algorithms to be used

    int saveMode = 1;                           //change to 1 if you want to output the most recently sorted data to the SaveFile
    int viewMode = 0;                           //change to 1 if you want to display the contents of the array before and after being sorted
                                                //Warning: Gets messy at large data sizes




///////////////////changing anything beneath this line will fundamentally alter the code///////////////////
///////////////////////////////////////***alter with caution***////////////////////////////////////////////

    datasets array;
    sort<int*> sorter;
    int* data;
    documentation<int*> loader;



    //these variables ensure the while loops work properly
    int f1 = 1;     //governs the while loop that determines which dataset to use
    int f2 = 1;     //governs the while loop that determines which algorithm to use

    for(int i=0; i<=loops; i++)
    {
        array.setSize(sizes[i]);
        data = new int[sizes[i]];

        while(f1<=num_of_datasets)
        {
            array.createData(f1);
            array.displayType();
            std::cout <<std::endl;

            while(f2<=num_of_algorithms)
            {
                //displayed the presorted data
                if(viewMode == 1)
                {   array.viewData();   }

                loader.loadFile(data, sizes[i], array.getFile());

                //loads the data, the size of the data, and which algorithm it should be sorted by
                sorter.load(data, array.getSize(), f2);
                sorter.execute();

                if(viewMode == 1)
                {   sorter.display();   }

                if(saveMode == 1)
                {   sorter.save();  }

                sorter.stats();
                std::cout <<std::endl;

                f2++;
                array.createData(f1);
            }//end of 2nd while loop

            f2=1;
            f1++;
        }//end of 1st while loop

        delete[] data;
        f1=1;
    }//end of for loop

    return 0;
}//end of main
