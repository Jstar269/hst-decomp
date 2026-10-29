/* Global set of row tables: each table owns an array of fixed-size rows that the lookup helpers index. */
#ifndef HST_ROW_TABLES_H
#define HST_ROW_TABLES_H

typedef struct RowEntry {     /* size 0x22c */
    char data[0x22c];
} RowEntry;

typedef struct RowTable {     /* size 0x18 */
    RowEntry *rows;           /* 0x00 */
    char pad04[0x14];
} RowTable;

typedef struct RowTables {
    RowTable tables[2];
} RowTables;

#endif
