/* HSTMATCH module=hstp_trans_main.prx start=0x0009378c end=0x00093860 symbol=FUN_0009378c lang=c99 data=0x00378af0 */
/* Clone of src/eboot/initialize_state_00091af4.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00378af0-0x00378b06) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e1a30;
extern char DAT_00378a5c[];
extern char DAT_00378a68[];
extern void FUN_000963e0();

void FUN_0009378c(int param_1)
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
  global_cursor = (int *)&DAT_003e1a30;
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
  FUN_000963e0(param_1 + 0x80,"Bip01Spine",DAT_00378a68);
  FUN_000963e0(param_1 + 0xb0,DAT_00378a5c,"Bip01Neck");
}
