#include <iostream>
#include "sqlite3.h"

int main() {
    sqlite3 *db;

    int r = sqlite3_open("./cities.db", &db);

    if (r) {
        std::cout << "can't open database cities.db, error " << r << std::endl;
        sqlite3_close(db);
        return 1;
    }

    // const char query[] =  "select * from cities;";
    std::string query=  "select * from cities;";
    sqlite3_stmt *rows;
    // int q = sqlite3_prepare(db, query, sizeof(query), &rows, NULL);
    int q = sqlite3_prepare(db, query.c_str(), query.size(), &rows, NULL);

    if (q != SQLITE_OK) {
        std::cout << "query error " << q << std::endl;
    }

    r = sqlite3_step(rows);

    while (r == SQLITE_ROW) {
        double latitude = sqlite3_column_double(rows, 2);
        double longitude = sqlite3_column_double(rows, 3);
        std::cout << latitude << " " << longitude << std::endl;
        r = sqlite3_step(rows);
    }

    sqlite3_finalize(rows);

    sqlite3_close(db);

    return 0;
}
