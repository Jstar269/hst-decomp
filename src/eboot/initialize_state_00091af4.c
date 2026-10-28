/* HSTMATCH module=EBOOT.BIN start=0x00091af4 end=0x00091bc8 symbol=FUN_00091af4 lang=c99 data=0x002d28d4 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d28d4-0x002d28ea) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003386f0;
extern char DAT_002d2840[];
extern char DAT_002d284c[];
extern void FUN_000944bc();

void FUN_00091af4(int param_1)
{
  unsigned int count;
  unsigned int global_count;
  unsigned int sentinel_count;
  int *cursor;
  int *global_cursor;
  int *sentinel_cursor;

  count = 0;
  cursor = (int *)param_1;
  do {
    ++count;
    cursor[0x14] = 0;
    ++cursor;
  } while (count < 6);
  *(int *)(param_1 + 0x68) = -1;
  *(int *)(param_1 + 0x6c) = 0;
  *(int *)(param_1 + 0x70) = 0;
  *(unsigned char *)(param_1 + 0x74) = 0;
  *(unsigned char *)(param_1 + 0x75) = 0;
  global_count = 0;
  global_cursor = (int *)&DAT_003386f0;
  do {
    global_cursor[0] = 0;
    global_cursor[1] = 0;
    ++global_count;
    global_cursor[2] = 0;
    global_cursor += 4;
  } while (global_count < 2);
  sentinel_count = 0;
  sentinel_cursor = (int *)param_1;
  do {
    ++sentinel_count;
    sentinel_cursor[1] = -1;
    ++sentinel_cursor;
  } while (sentinel_count < 7);
  *(int *)(param_1 + 0x20) = -1;
  *(int *)(param_1 + 0x24) = 0;
  FUN_000944bc(param_1 + 0x80,"Bip01Spine",DAT_002d284c);
  FUN_000944bc(param_1 + 0xb0,DAT_002d2840,"Bip01Neck");
}
