/* HSTMATCH module=EBOOT.BIN start=0x002b0704 end=0x002b07c4 symbol=FUN_002b0704 lang=c99 */
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

extern void FUN_0010b6d4();
extern void FUN_0010b8cc();

void FUN_002b0704(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar4;
  int iVar2;
  undefined4 uVar3;
  int iVar5;
  int current;
  int expected;
  
  iVar1 = param_1 + *(int *)(param_1 + 0x94) * 4;
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = *(int *)(iVar1 + 0x3d0) << 1;
  do {
    if (iVar2 < *(int *)(iVar1 + 0x110)) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar4 < 6);
  current = *(int *)(param_1 + 0x3f8);
  expected = iVar5 - 1;
  if (current != expected) {
    FUN_0010b6d4(*(undefined4 *)(param_1 + 900),0);
    *(int *)(param_1 + 0x3f8) = iVar5 + -1;
  }
  uVar3 = *(undefined4 *)(param_1 + 900);
  FUN_0010b8cc(uVar3,param_2,0);
  ((undefined4 *)((char *)param_1 + 0x3a8))[*(int *)(param_1 + 0x94)] =
       *(undefined4 *)(*(int *)(param_1 + 900) + 0xdc);
  return;
}
// Near miss: three words remain in the field-versus-count comparison register colors.
// The loop and index-first final address match retail; current/expected still map to v1/v0 instead of v0/a2.
// near miss from lane u5cr1-2 (unreviewed)
