/* HSTMATCH module=hstp_trans_main.prx start=0x000d8d50 end=0x000d8dcc symbol=FUN_000d8d50 lang=c99 */
/* Clone of src/eboot/FUN_000d5060_000d5060.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v3) corrected by hand: made the early gate explicit and reordered the loop locals for retail register allocation; exact match verified; names and types await human review. */
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

extern undefined * DAT_003e19f0;
extern void FUN_0005ffd8();

void FUN_000d8d50(int param_1)
{
  int iVar2;
  int iVar1;
  int self;
  
  if (*(uchar *)(param_1 + 0x710) != '\0') return;
  iVar2 = 0;
  iVar1 = 0;
  self = param_1;
  do {
    if (*(int *)(DAT_003e19f0 + iVar1 + 0x70) != 0) {
      FUN_0005ffd8(self + 0x50,0);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 4;
    self = self + 0x1b0;
  } while (iVar2 < 4);
  return;
}
