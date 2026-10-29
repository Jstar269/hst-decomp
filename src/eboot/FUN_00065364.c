/* HSTMATCH module=EBOOT.BIN start=0x00065364 end=0x000653ac symbol=FUN_00065364 lang=c99 */
/* CSV table reader: column index by header name; see docs/DATA-TABLES.md */
/* Clone of src/sharing_main/FUN_00066400.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper arguments, used pointer arithmetic for the object subobject, and reversed the comparison arms; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/csv_table.h"

extern void FUN_00065c60(TreeNode **,TreeMap *,u32 *);

/* Looks a header name up in the table's column tree; returns the column index, or -1 when absent. */
u32 FUN_00065364(CsvTable *table,u32 name)
{
  u32 column;
  TreeNode *iter [2];
  u32 name_copy;
  
  name_copy = name;
  FUN_00065c60(iter,&table->by_column,&name_copy);
  if ((char *)iter[0] != (char *)&table->by_column.root) {
    column = iter[0]->value;
  } else {
    column = 0xffffffff;
  }
  return column;
}
