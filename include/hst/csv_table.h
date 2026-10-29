/* CSV table reader object (C view): vtable, row vector, and two trees (row index by key, column index by header name). */
#ifndef HST_CSV_TABLE_H
#define HST_CSV_TABLE_H

#include "hst/tree_map.h"

typedef struct CsvTable {
  const void *vtable;  /* 0x00 */
  char rows[0xc];      /* 0x04 vector of rows */
  TreeMap by_key;      /* 0x10 row index by key */
  TreeMap by_column;   /* 0x20 column index by header name */
} CsvTable;

#endif
