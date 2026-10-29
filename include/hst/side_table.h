/* Table of 20-byte rows reached through a global pointer: each row has two sides of two five-byte arrays. */
#ifndef HST_SIDE_TABLE_H
#define HST_SIDE_TABLE_H

#define SIDE_TABLE_ROW_OFFSET 0x3d00 /* rows start this many bytes into the table */
#define SIDE_COUNT 2                 /* sides per row */
#define SIDE_SECOND 1                /* side argument that selects the second side */
#define SIDE_COLS 5                  /* entries per array */

/* Byte offsets of the four arrays inside a row (first side a, first side b, second side a, second side b). */
enum { SIDE0_A_OFFSET = 0, SIDE0_B_OFFSET = 5, SIDE1_A_OFFSET = 10, SIDE1_B_OFFSET = 15 };

typedef struct SideEntry {
  unsigned char a[SIDE_COLS];        /* 0x00 */
  unsigned char b[SIDE_COLS];        /* 0x05 */
} SideEntry;

typedef struct SideRow {
  SideEntry side[SIDE_COUNT];        /* 0x00 */
} SideRow;                           /* size 0x14 */

typedef struct SideTable {
  char pad[SIDE_TABLE_ROW_OFFSET];
  SideRow rows[1];                   /* 0x3d00, row count is not fixed here */
} SideTable;

#endif
