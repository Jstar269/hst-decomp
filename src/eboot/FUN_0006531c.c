/* HSTMATCH module=EBOOT.BIN start=0x0006531c end=0x00065364 symbol=FUN_0006531c lang=c99 */
/* CSV table reader: FindRowByKey; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/FUN_000663b8.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper arguments, used pointer arithmetic for the object subobject, and reversed the comparison arms; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/csv_table.h"

extern void FUN_00065c60(TreeNode **,TreeMap *,u32 *);

/* Looks key up in the table's key tree; returns the stored row index, or -1 when absent. */
u32 FUN_0006531c(CsvTable *table,u32 key)
{
  u32 row;
  TreeNode *iter [2];
  u32 key_copy;
  
  key_copy = key;
  FUN_00065c60(iter,&table->by_key,&key_copy);
  if ((char *)iter[0] != (char *)&table->by_key.root) {
    row = iter[0]->value;
  } else {
    row = 0xffffffff;
  }
  return row;
}
