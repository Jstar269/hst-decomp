/* HSTMATCH module=EBOOT.BIN start=0x001fea10 end=0x001feac4 symbol=FUN_001fea10 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: materialized both range predicates and formed the indexed row address through an offset-first comma expression; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ResRow {
  u8 **items;     /* 0x00 */
  int count;      /* 0x04 */
  int unk8;       /* 0x08 */
} ResRow;

typedef struct ResHeader {
  char pad0[8];
  int row_count;  /* 0x08 */
} ResHeader;

typedef struct ResEntry {
  char pad0[4];
  int ready;          /* 0x04 */
  ResHeader *header;  /* 0x08 */
  ResRow *rows;       /* 0x0c */
} ResEntry;

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 * FUN_0018c9f4();

/* Looks up item [col] of row [row] in resource entry [kind]; a placeholder is returned when
   the entry is not ready or an index is out of range. */
u8 * FUN_001fea10(u32 kind,int row,int col)
{
  ResEntry *entry;
  u8 *result;
  ResRow *row_ptr;
  int row_ok;
  int col_ok;
  int row_offset;
  
  entry = (ResEntry *)(FUN_0018c9f4(kind));
  if (entry->ready == 0) {
    result = &DAT_002c0e20;
  }
  else if ((row < 0) || ((row_ok = row < entry->header->row_count) == 0)) {
    result = &DAT_002c0e1c;
  }
  else if ((col < 0) ||
          (row_ptr = (ResRow *)(row_offset = row * 0xc, row_offset + (int)entry->rows),
           (col_ok = col < row_ptr->count) == 0)) {
    result = &DAT_002c0e18;
  }
  else {
    result = row_ptr->items[col];
  }
  return result;
}
