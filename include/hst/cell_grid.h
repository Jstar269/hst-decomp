/* Table of per-row cell pointers: rows of CELL_ROW_BYTES bytes, each holding a pointer per column. */
#ifndef HST_CELL_GRID_H
#define HST_CELL_GRID_H

enum { CELL_ROW_BYTES = 0xa4, CELL_COLUMNS = CELL_ROW_BYTES / 4 };

/* Cell object reached through the grid; two int fields are set by the helpers. */
typedef struct GridCell {
  char pad00[0x24];
  int unk24;          /* 0x24 */
  int unk28;          /* 0x28 */
} GridCell;

typedef struct CellRow {
  GridCell *cells[CELL_COLUMNS];
} CellRow;

typedef struct CellGrid {
  CellRow rows[1];    /* row count is not fixed here */
} CellGrid;

#endif
