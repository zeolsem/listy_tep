//
// Created by szolim on 13.10.24.
//
#include <iostream>
#include "zad4.h"

#define DEFAULT_NAME "default_name"
#define DEFAULT_TABLE_LENGTH 8


class CTable {
    int *table;
    public:
        int len;
        std::string name;
        CTable() {
            len = DEFAULT_TABLE_LENGTH;
            name = DEFAULT_NAME;
            table = new int[len];
            std::cout << "bezp:" << name << std::endl;
        }

        CTable(const std::string &table_name, int table_length) {
            name = table_name;
            if (table_length <= 0) {
                std::cout << "array size must be greater than 0. initialising array of default length." << std::endl;
                len = DEFAULT_TABLE_LENGTH;
                table = new int[len];
                std::cout << "bezp:" << name << std::endl;
                return;
            }
            len = table_length;
            table = new int[len];
            std::cout << "parametr: " << name << std::endl;
        }

        CTable(const CTable &pcOther) {
            len = pcOther.len;
            name = pcOther.name + "_copy";
            table = new int[len];
            for (int i = 0; i < len; i++) {
                table[i] = pcOther.table[i];
            }
            std::cout << "kopiuj: " << name << std::endl;
        }

        ~CTable() {
            delete[] table;
            std::cout << "usuwam: " << name << std::endl;
        }

        void set_name(const std::string &table_name) {
            name = table_name;
        }

        bool set_new_size(const int new_size) {
            if (new_size <= 0) {
                return false;
            }
            delete[] table;
            len = new_size;
            table = new int[len];
            return true;
        }

        CTable *clone() const {
            return new CTable(*this);
        }
};


void zad4() {
    std::cout << "Zadanie 4: " << std::endl << std::endl;
    CTable table1;
    CTable table2("tablicatablica", -2);
    CTable table3 = table2;

    int default_table_length = DEFAULT_TABLE_LENGTH;

    std::cout << "Czy table1.len == default: " << int(table1.len == default_table_length) << std::endl << std::endl;

    std::cout << table2.len << "  " << table2.name << std::endl;
    std::cout << table3.len << "  " << table3.name << std::endl << std::endl;

    table3.name = "maslo";
    std::cout << table2.len << "  " << table2.name << std::endl;
    std::cout << table3.len << "  " << table3.name << std::endl << std::endl;
}
