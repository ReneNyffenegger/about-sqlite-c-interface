#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

void printColumnValue(sqlite3_stmt* stmt, int col) {

  int colType = sqlite3_column_type(stmt, col);

  switch(colType) {

    case SQLITE_INTEGER:
         printf("  %3d   ", sqlite3_column_int(stmt, col));
         break;

    case SQLITE_FLOAT:
         printf("  %5.2f", sqlite3_column_double(stmt, col));
         break;

    case SQLITE_TEXT:
         printf("  %-5s", sqlite3_column_text(stmt, col));
         break;

    case SQLITE_NULL:
         printf("  null");
         break;

    case SQLITE_BLOB:
         printf("  blob");
         break;
    }

}

int main() {

    sqlite3 *db;
    if (sqlite3_open("the.db", &db)) {
      printf("Could not open the.db\n");
      exit(-1);
    }

    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, "select * from tab where foo >= ? order by foo", -1, &stmt, NULL)) {
       printf("Error executing sql statement\n");
       sqlite3_close(db);
       exit(-1);
    }

 //
 // Bind the only bindable value in the select stament (foo >= ?)
 //
    sqlite3_bind_int (stmt, 1, 2);

    while (sqlite3_step(stmt) != SQLITE_DONE) {
     //
     // Print the column values for the current record.
     // Note: the column values are 0-indexed while the
     // bind values are 1-indexed.
     //
        for (int col=0; col<=2; col++) {
          printColumnValue(stmt, col);
        }
        printf("\n");
    }

    sqlite3_finalize(stmt);

    sqlite3_close(db);
}
