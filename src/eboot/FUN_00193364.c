/* HSTMATCH module=EBOOT.BIN start=0x00193364 end=0x001933e8 symbol=FUN_00193364 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: store the argument into the outgoing stack slot before the null guard (fills the beqz delay slot) and share a `goto ret0` for the two early returns. */
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

extern undefined * DAT_0034173c;
extern undefined4 DAT_00341748;
extern void FUN_00196478();

int FUN_00193364(undefined4 param_1)
{
  int iVar1;
  int local_4;
  undefined4 local_8;

  local_8 = param_1;
  if (DAT_0034173c == 0) {
    goto ret0;
  }
  FUN_00196478(&local_4,DAT_00341748 + 0x40,&local_8);
  if (local_4 == DAT_00341748 + 0x44) {
    goto ret0;
  }
  iVar1 = *(int *)(DAT_0034173c + 4) + *(int *)(local_4 + 0x10) * 0x9c;
  return iVar1;
ret0:
  return 0;
}
