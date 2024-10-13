//
// Created by szolim on 13.10.24.
//

#include <iostream>
#include "zad2_and_3.h"

bool b_alloc_table_2_dim(int ** &piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0) {
        std::cout << "Array size must be greater than 0" << std::endl;
        piTable = NULL;
        return false;
    }

    piTable = new int*[iSizeX];

    for (int i = 0; i < iSizeX; i++) {
        piTable[i] = new int[iSizeY];

        if (piTable[i] == NULL) {
            for (int j = 0; j < i; j++) {
                delete[] piTable[j];
            }
            delete[] piTable;
            piTable = NULL;
            return false;
        }
    }

    return true;
    // gdyby referencja byla niemozliwa, trzeba by uzyc ***, co stworzyloby kopie piTable, i ją zaalokowalo
}

bool b_dealloc_table_2_dim(int ** &piTable, int iSizeX) {
    if (iSizeX <= 0) {
        std::cout << "It is not a proper value for array size." << std::endl;
        return false;
    }
    if (piTable == NULL) {
        piTable = NULL;
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        if (!piTable[i] == NULL) {
            delete [] piTable[i];
        }
    }
    delete [] piTable;
    piTable = NULL;

    return true;
}

void zad2_and_3() {
    std::cout << "Zadania 2 i 3: " << std::endl << std::endl;
    int **piTable;
    std::cout << b_alloc_table_2_dim(piTable, 5, 3) << std::endl;
    piTable[3][2] = 7;
    std::cout << "piTable[3][2]: " << piTable[3][2] << std::endl;
    std::cout << b_dealloc_table_2_dim(piTable, 5) << std::endl << std::endl;

    std::cout << b_alloc_table_2_dim(piTable, -1, -1) << std::endl;
    std::cout << b_dealloc_table_2_dim(piTable, -1) << std::endl << std::endl;

    std::cout << b_alloc_table_2_dim(piTable, 0, 2) << std::endl;
    std::cout << b_dealloc_table_2_dim(piTable, 0) << std::endl << std::endl;

    std::cout << b_alloc_table_2_dim(piTable, 4, 0) << std::endl;
    std::cout << b_dealloc_table_2_dim(piTable, 4) << std::endl << std::endl;

    std::cout << b_alloc_table_2_dim(piTable, 10, 10) << std::endl;
    piTable[6][4] = 2;
    std::cout << "piTable[6][4]: " << piTable[6][4] << std::endl;
    std::cout << b_dealloc_table_2_dim(piTable, 10) << std::endl << std::endl;
}
