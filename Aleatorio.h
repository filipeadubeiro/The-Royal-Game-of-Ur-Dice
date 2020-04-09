#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <string>

int dados(int i)
{

    int array[4] = {};

    srand(time(NULL) + i + 1);
    int RandIndex = rand() % 2;
    array[i] = RandIndex;

    return array[i];

}



int lancarDado(int index)
{

    
    int i = 0;
    int arrayf[4];
    int soma[5];

    for (i = 0; i < 4; i++)
    {
        int result = dados(i);
        //std::cout << dados(i) << "  ";
        //sleep_for(300ms);
        arrayf[i] = result;

    }
    int s = arrayf[0] + arrayf[1] + arrayf[2] + arrayf[3];
    int sum[] = {arrayf[0], arrayf[1], arrayf[2], arrayf[3], s };
    
    return sum[index];

}

