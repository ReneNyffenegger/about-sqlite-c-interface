#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {

    sqlite3 *db;
    if (sqlite3_open("the.db", &db)) {
      printf("Could not open the.db\n");
      exit(-1);
    }

 //
 // Prepare a statement for multiple use:
 //
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, "insert into tab values(?, ?, ?)", -1, &stmt, NULL)) {
       printf("Error executing sql statement\n");
       sqlite3_close(db);
       exit(-1);
    }

 //
 // Bind the values for the first insert:
 //
    sqlite3_bind_int (stmt, 1, 3      );
    sqlite3_bind_text(stmt, 2, "three", -1, NULL);
    sqlite3_bind_int (stmt, 3,  333   );

 //
 // Do the first insert:
 //
    sqlite3_step(stmt);

 //
 // Reset the prepared statement to the initial state.
 // This seems to be necessary in order to
 // use the prepared statement again for another
 // insert:
 //
    sqlite3_reset(stmt);

 //
 // Bind the values for the second insert
 //
    sqlite3_bind_int (stmt, 1, 4      );
    sqlite3_bind_text(stmt, 2, "four" , -1, NULL);
    sqlite3_bind_null(stmt, 3);

 //
 // To the second insert
 //
    sqlite3_step(stmt);

 //
 // Get rid of the memory allocated for stmt:
 //
    sqlite3_finalize(stmt);

    sqlite3_close(db);
}
