#include <iostream>
#include <vector>
#include <algorithm>
#include "RowTable.h"

bool comparator(RowTable* one, RowTable* two) {
    return *one < *two;
}

int main() {
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
    RowTable::print(*tableRows);
    std::cout << "===================\n";
    std::sort(tableRows->begin(), tableRows->end(), comparator);
    RowTable::print(*tableRows);
    return 0;
}