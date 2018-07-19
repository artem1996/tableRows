//
// Created by as on 19.07.18.
//

#include "RowTable.h"

RowTable::RowTable(const char* enterprise, const char* department, const char* placeHolder)
        : enterprise(enterprise), department(department), placeHolder(placeHolder) {}

bool RowTable::operator<(const RowTable &rhs) const {
    if(enterprise == rhs.enterprise) {
        if(department == rhs.department)
            return placeHolder < rhs.placeHolder;
        else
            return department < rhs.department;
    } else {
        return enterprise < rhs.enterprise;
    }
}

void RowTable::print(bool ent, bool dep) {
    std::cout << (ent ? enterprise.empty() ? "nil" : enterprise : "---")
              << "\t|" << (dep ? department.empty() ? "nil" : department : "---")
              << "\t|" << placeHolder << std::endl;
}

void RowTable::print(std::vector<RowTable *> &tableRows) {
    if (tableRows.empty())
        return;
    auto prev = tableRows[0];
    prev->print(true, true);
    for (int i = 1; i < tableRows.size(); i++) {
        auto next = tableRows[i];
        bool noEnt = next->enterprise == prev->enterprise;
        bool noDep = noEnt && next->department == prev->department;
        next->print(!noEnt, !noDep);
        prev = next;
    }
}
