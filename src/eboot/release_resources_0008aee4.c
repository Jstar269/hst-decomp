/* HSTMATCH module=EBOOT.BIN start=0x0008aee4 end=0x0008af7c symbol=FUN_0008aee4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the two tail calls take the tested member as their argument (Ghidra dropped it); exact match verified; names and types await human review. */
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

extern undefined4 DAT_003313c4;
extern undefined4 DAT_003386cc;
extern undefined4 DAT_00338714;
extern undefined * DAT_003402a0;
extern int FUN_0005ba78();
extern void FUN_000c7894(int);
extern void FUN_00140acc();
extern void FUN_001f4c04(int);

void FUN_0008aee4(int param_1)
{
  int iVar1;
  
  if (DAT_00338714 != 0) {
    FUN_0005ba78(DAT_00338714,DAT_003313c4);
  }
  if (DAT_003386cc != 0) {
    FUN_0005ba78(DAT_003386cc,DAT_003313c4);
  }
  if (DAT_003402a0 != 0) {
    FUN_00140acc(DAT_003402a0 + 0x40);
  }
  iVar1 = *(int *)(param_1 + 0x90);
  if (iVar1 != 0) {
    FUN_000c7894(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0xa0);
  if (iVar1 != 0) {
    FUN_001f4c04(iVar1);
  }
  return;
}
