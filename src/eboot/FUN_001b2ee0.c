/* HSTMATCH module=EBOOT.BIN start=0x001b2ee0 end=0x001b2f60 symbol=FUN_001b2ee0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: three if (p != 0) { if (p != 0) { free(p,1); p-field = 0; } } blocks reproduce retail's duplicated null guard and beqzl+beqz chain. */
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

extern int FUN_00062418();

void FUN_001b2ee0(int *param_1)
{
  int iVar1;
  int iVar2;

  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0xfc);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      *(undefined4 *)(iVar2 + 0xfc) = 0;
    }
  }
  iVar1 = *(int *)(iVar2 + 0xf8);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      *(undefined4 *)(iVar2 + 0xf8) = 0;
    }
  }
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      *(undefined4 *)(iVar2 + 0x2b0) = 0;
    }
  }
  return;
}
