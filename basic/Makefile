all: 00_create-table 01_insert 02_insert-bind 03_select

00_create-table: 00_create-table.c
	gcc $< -o $@ -lsqlite3

01_insert: 01_insert.c
	gcc $< -o $@ -lsqlite3

02_insert-bind: 02_insert-bind.c
	gcc $< -o $@ -lsqlite3

03_select: 03_select.c
	gcc $< -o $@ -lsqlite3
