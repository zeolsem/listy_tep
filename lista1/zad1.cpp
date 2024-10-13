//
// Created by szolim on 13.10.24.
//
#include <iostream>
#include "zad1.h"

void v_alloc_table_fill_34(int iSize) {
    if (iSize <= 0) {
        std::cout << "Array size must be greater than o" << std::endl;
        return;
    }

    int *table = new int[iSize];
    // fill the table
    for (int i = 0; i < iSize; i++) {
        table[i] = 34;
    }
    // print out the table
    std::cout << "Wypisuje tablice: " << std::endl;
    for (int i = 0; i < iSize; i++) {
        std::cout << "table[" << i << "]: " << table[i] << std::endl;
    }

    //deallocate the table
    delete[] table;

    // Czy wartosc 34 powinna wystepowac bezposrednio w kodzie? No nie bardzo
    // aczkolwiek w tym przypadku wystepuje ona w nazwie funkcji, zatem mozna wnioskowac
    // ze jesst to bardzo scisla funkcja ktorej zadaniem jest wypelnienie tablicy specjalna wartoscia
    // czyli 34. ale raczej to blad w nazewnictwie i zbyt duze ograniczenie funkcjonalnosci tej funkcji
}

void zad1() {
    std::cout << "Zadanie 1: " << std::endl << std::endl;
    v_alloc_table_fill_34(-1);
    v_alloc_table_fill_34(0);
    v_alloc_table_fill_34(1);
    v_alloc_table_fill_34(3);
}
