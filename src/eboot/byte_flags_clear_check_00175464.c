/* HSTMATCH module=EBOOT.BIN start=0x00175464 end=0x0017551c symbol=FUN_00175464 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the three byte tests written as one || chain (if (b8 != 0 || b11 != 0 || b12 != 0) clear = false; else clear = true;) instead of Ghidra's nested if/else; exact match verified; readability pass; names and types await human review. */
#include "hst/types.h"
typedef int (*Fn)();

/* Record of status bytes. */
typedef struct FlagRec {
  char pad00[8];
  u8 unk08;         /* 0x08 */
  char pad09[2];
  u8 unk0b;         /* 0x0b */
  u8 unk0c;         /* 0x0c */
} FlagRec;

/* One row of the grid: pointer to the row's cells (12 bytes per row). */
typedef struct GridRow {
  FlagRec **cells;  /* 0x00 */
  int unk04;
  int unk08;
} GridRow;

/* Cursor over a grid of FlagRec pointers: current column and row. */
typedef struct GridCursor {
  char pad00[4];
  int col;          /* 0x04 */
  int row;          /* 0x08 */
  char pad0c[0xc];
  GridRow *rows;    /* 0x18 */
} GridCursor;

typedef struct FlagOwner {
  char pad000[0x538];
  GridCursor *grid; /* 0x538 */
  char pad53c[0x558 - 0x53c];
  int code_fn;      /* 0x558 function returning a status code */
} FlagOwner;

/* Returns 1 when the status code is not one of the two special values and the current cell has three flag bytes all clear. */
u32 FUN_00175464(FlagOwner *owner)
{
  bool clear;
  int code;
  GridCursor *grid;
  FlagRec *rec;
  
  code = ((Fn)owner->code_fn)();
  if ((code != 0x7fff) && (code = ((Fn)owner->code_fn)(), code != 0x7ffe)) {
    grid = owner->grid;
    rec = grid->rows[grid->row].cells[grid->col];
    if (rec->unk08 != 0 || rec->unk0b != 0 || rec->unk0c != 0) clear = false; else clear = true;
    if (clear) return 1;
  }
  return 0;
}
