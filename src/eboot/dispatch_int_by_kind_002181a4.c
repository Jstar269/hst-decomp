/* HSTMATCH module=EBOOT.BIN start=0x002181a4 end=0x002182a0 symbol=FUN_002181a4 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x002181a4.c, no hstgen tag) corrected by hand: the if-chain rewritten as a switch with cases in source order and the result initialised after the pointer computation; readability pass; exact match verified; names and types await human review. */
#include "hst/row_tables.h"

extern RowTables *DAT_00341508;
extern int FUN_00165004(void *, int);
extern int FUN_00164c60(RowEntry *, int);
extern int FUN_00164d00(RowEntry *, int);
extern int FUN_00164e24(RowEntry *, int);
extern int FUN_00164f64(RowEntry *, int);
extern int FUN_00164ec4(RowEntry *, int);

int FUN_002181a4(int unused, int table_index, int row_key, int kind, int arg)
{
  int row_index;
  RowEntry *row;
  int result;

  row_index = FUN_00165004(&DAT_00341508->tables[table_index], row_key);
  row = (RowEntry *)((char *)DAT_00341508->tables[table_index].rows + row_index * sizeof(RowEntry));
  result = 0;
  switch (kind) {
  case 0:
    result = FUN_00164c60(row, arg);
    break;
  case 1:
    result = FUN_00164d00(row, arg);
    break;
  case 2:
    result = FUN_00164e24(row, arg);
    break;
  case 3:
    result = FUN_00164f64(row, arg);
    break;
  case 4:
    result = FUN_00164ec4(row, arg);
    break;
  }
  return result;
}
