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

  if (sqlite3_exec(db,
        "insert into tab values(1, 'one', null);"
        "insert into tab values(2,  2.2 ,'two');",
        NULL, NULL, NULL)) {

     printf("Error executing sql statement\n");
  }
  else {
    printf("records inserted\n");
  }

  sqlite3_close(db);
}
