/* HSTMATCH module=EBOOT.BIN start=0x00253630 end=0x002536f0 symbol=FUN_00253630 lang=c99 */
/* IromonoRuleList ctor: data/common/rule/Rule_Iromono.txt; see docs/DATA-TABLES.md */
/* Ghidra pseudocode (hstgen.py tag t0) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define RULE_COLUMN_FLAG 3      /* column whose nonzero value selects a row */

/* List of the row numbers of the rule file whose flag column is set. */
typedef struct IromonoRuleList {
  int unk0;                     /* 0x00 */
  char pad4[0x14];
  int count;                    /* 0x18 number of selected rows */
  int rows[1];                  /* 0x1c selected row numbers, in file order */
} IromonoRuleList;

extern u8 DAT_002fcc70;
extern char DAT_002fcc4c[];
extern int * FUN_000649c0();
extern int * FUN_00064a08();
extern u32 FUN_00064bf4();
extern u32 FUN_000650e0();
extern int FUN_00065104();

IromonoRuleList * FUN_00253630(IromonoRuleList *list)
{
  int n;                        /* reused: row count, flag value, list count */
  int row;
  u8 parser[16];

  list->unk0 = 0;
  FUN_000649c0(parser);
  FUN_00064bf4(parser,DAT_002fcc4c,0,&DAT_002fcc70);
  list->count = 0;
  row = 0;
  n = FUN_000650e0(parser);
  if (0 < n) {
    do {
      n = FUN_00065104(parser,row,RULE_COLUMN_FLAG);
      if (n != 0) {
        n = list->count;
        list->count = n + 1;
        list->rows[n] = row;
      }
      row = 1 + row;
      n = FUN_000650e0(parser);
    } while (row < n);
  }
  FUN_00064a08(parser,0xffffffff);
  return list;
}
