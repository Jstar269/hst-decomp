/* HSTMATCH module=EBOOT.BIN start=0x001fb824 end=0x001fb8a0 symbol=FUN_001fb824 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: recovered the 20-entry key/value/count record layout and index-first table access; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct QueueView {
  char pad[0x3c];
  int keys[20];
  int values[20];
  int count;
};

void FUN_001fb824(int param_1,int param_2,undefined4 param_3)
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
  return;
}
