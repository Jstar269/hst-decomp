/* HSTMATCH module=hstp_trans_main.prx start=0x00209f3c end=0x00209fb8 symbol=FUN_00209f3c lang=c99 */
/* Clone of src/eboot/append_unique_entry_001fb824.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: recovered the 20-entry key/value/count record layout and index-first table access; exact match verified; names and types await human review. */
#include "hst/types.h"

struct QueueView {
  char pad[0x3c];
  int keys[20];
  int values[20];
  int count;
};

void FUN_00209f3c(int param_1,int param_2,u32 param_3)
{
  int bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = false;
  iVar2 = 0;
  iVar3 = param_1;
  do {
    if (*(int *)(iVar3 + 0x3c) == param_2) {
      bVar1 = true;
      break;
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 0x14);
  if (!bVar1) {
    struct QueueView *queue = (struct QueueView *)param_1;
    iVar2 = queue->count;
    if (iVar2 < 0) return;
    if (iVar2 < 0x14) {
      queue->keys[iVar2] = param_2;
      queue->values[queue->count] = param_3;
      queue->count = queue->count + 1;
    }
  }
}
