/* HSTMATCH module=EBOOT.BIN start=0x002180a8 end=0x002181a4 symbol=FUN_002180a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/row_tables.h"

extern RowTables *DAT_00341508;
extern int FUN_00165004(void *, int);
extern float FUN_001646a0(RowEntry *, int);
extern float FUN_00164740(RowEntry *, int);
extern float FUN_001647ec(RowEntry *, int);
extern float FUN_00164ac4(RowEntry *, int);
extern float FUN_00164958(RowEntry *, int);

float FUN_002180a8(int unused, int table_index, int row_key, int kind, int arg)
{
  int row_index;
  RowEntry *row;
  float result;

  row_index = FUN_00165004(&DAT_00341508->tables[table_index], row_key);
  row = (RowEntry *)((char *)DAT_00341508->tables[table_index].rows + row_index * sizeof(RowEntry));
  result = 0.0f;
  switch (kind) {
  case 0:
    result = FUN_001646a0(row, arg);
    break;
  case 1:
    result = FUN_00164740(row, arg);
    break;
  case 2:
    result = FUN_001647ec(row, arg);
    break;
  case 3:
    result = FUN_00164ac4(row, arg);
    break;
  case 4:
    result = FUN_00164958(row, arg);
    break;
  }
  return result;
}
