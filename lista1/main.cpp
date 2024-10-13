#include <iostream>

#define DEFAULT_NAME "default_name"
#define DEFAULT_TABLE_LENGTH 8

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
    for (int i = 0; i < iSize; i++) {
        std::cout << table[i] << std::endl;
    }

    //deallocate the table
    delete[] table;

    // Czy wartosc 34 powinna wystepowac bezposrednio w kodzie? No nie bardzo
    // aczkolwiek w tym przypadku wystepuje ona w nazwie funkcji, zatem mozna wnioskowac
    // ze jesst to bardzo scisla funkcja ktorej zadaniem jest wypelnienie tablicy specjalna wartoscia
    // czyli 34. ale raczej to blad w nazewnictwie i zbyt duze ograniczenie funkcjonalnosci tej funkcji
}

bool b_alloc_table_2_dim(int ** &piTable, int iSizeX, int iSizeY) {
    if (iSizeX <= 0 || iSizeY <= 0) {
        std::cout << "Array size must be greater than 0" << std::endl;
        return false;
    }

    piTable = new int*[iSizeX];

    if (piTable == NULL) {
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        piTable[i] = new int[iSizeY];

        if (piTable[i] == NULL) {
            for (int j = 0; j < i; j++) {
                delete[] piTable[j];
            }
            delete[] piTable;
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
        return false;
    }

    for (int i = 0; i < iSizeX; i++) {
        delete [] piTable[i];
    }
    delete [] piTable;

    return true;
}

class CTable {
    int *table;
    public:
        std::string name;
        CTable() {
            name = DEFAULT_NAME;
            table = new int[DEFAULT_TABLE_LENGTH];
            std::cout << "bezp:" << name << std::endl;
        }

        CTable(const std::string &table_name, int table_length) {
            name = table_name;
            table = new int[table_length];
            std::cout << "parametr: " << name << std::endl;
        }

        CTable(const CTable &pcOther) {
            name = pcOther.name + "_copy";
            const int table_length = sizeof(pcOther.table) / sizeof(int);
            table = new int[table_length];
            for (int i = 0; i < table_length; i++) {
                table[i] = pcOther.table[i];
            }
            std::cout << "kopiuj: " << name << std::endl;
        }

        ~CTable() {
            delete[] table;
            std::cout << "usuwam: " << name << "std::endl";
        }

        void set_name(const std::string &table_name) {
            name = table_name;
        }

        bool set_new_size(const int new_size) {
            if (new_size <= 0) {
                return false;
            }
            delete[] table;
            table = new int[new_size];
            return true;
        }

        CTable *clone() const {
            return new CTable(*this);
        }
};

int main() {
    // zad 1
    v_alloc_table_fill_34(5);

    // zad 2
    int **piTable;
    std::cout << b_alloc_table_2_dim(piTable, 5, 5) << std::endl;

    // zad 3
    std::cout << b_dealloc_table_2_dim(piTable, 5) << std::endl;

    return 0;
}
