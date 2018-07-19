//
// Created by as on 19.07.18.
//

#ifndef RRR_ROWTABLE_H
#define RRR_ROWTABLE_H

#include <iostream>
#include <string>
#include <vector>

class RowTable {
public:
    std::string enterprise;
    std::string department;
    std::string placeHolder;
    RowTable(const char* enterprise, const char* department, const char* placeHolder);
    bool operator<(const RowTable &rhs) const;
    void print(bool ent, bool dep);
    static void print(std::vector<RowTable*> &tableRows);
};


#endif //RRR_ROWTABLE_H
