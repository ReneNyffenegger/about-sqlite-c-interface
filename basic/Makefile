all: 00_create-table 01_insert 02-insert-bind 03-select

00_create-table: 00_create-table.c
	gcc $< -o $@ -lsqlite3

01_insert: 01_insert.c
	gcc $< -o $@ -lsqlite3

02-insert-bind: 02-insert-bind.c
	gcc $< -o $@ -lsqlite3

03-select: 03-select.c
	gcc $< -o $@ -lsqlite3
