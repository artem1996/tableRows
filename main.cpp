#include <iostream>
#include <vector>
#include <algorithm>
#include "RowTable.h"

bool comparator(RowTable* one, RowTable* two) {
    return *one < *two;
}

void doit() {
    auto tableRows = new std::vector<RowTable*>;
    tableRows->push_back(new RowTable("Mai", "12", "Artem"));
    tableRows->push_back(new RowTable("Mai", "12", "Anton"));
    tableRows->push_back(new RowTable("", "56", "Anton"));
    tableRows->push_back(new RowTable("", "57", "Anton"));
    tableRows->push_back(new RowTable("", "57", "Artem"));
    tableRows->push_back(new RowTable("Ya", "", "Anton"));
    tableRows->push_back(new RowTable("Ya", "", "Artem"));
    tableRows->push_back(new RowTable("Ya", "49", "Anton"));
    tableRows->push_back(new RowTable("Ya", "49", "Artem"));
    tableRows->push_back(new RowTable("Ya", "50", "Artem"));
    tableRows->push_back(new RowTable("", "", "Anton"));
    tableRows->push_back(new RowTable("", "", "Artem"));
//    RowTable::print(*tableRows);
//    std::cout << "===================\n";
    std::sort(tableRows->begin(), tableRows->end(), comparator);
    for (auto &tableRow : *tableRows)
        delete tableRow;
    tableRows->clear();
    delete tableRows;
//    RowTable::print(*tableRows);
}

int main() {
    for (int i = 0; i < 1000000; i++) {
        doit();
    }
    return 0;
}