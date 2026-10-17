/* HSTMATCH module=EBOOT.BIN start=0x001fecb4 end=0x001fed58 symbol=FUN_001fecb4 lang=c99 */
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

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined1 * FUN_0018c9f4();

undefined * FUN_001fecb4(int param_1)
{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == 0x14) {
    param_1 = 0x10;
  }
  iVar1 = (int)FUN_0018c9f4(9);
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = &DAT_002c0e20;
  }
  else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 2) {
    puVar2 = &DAT_002c0e1c;
  }
  else if ((param_1 < 0) || (*(int *)(*(int *)(iVar1 + 0xc) + 0x10) <= param_1)) {
    puVar2 = &DAT_002c0e18;
  }
  else {
    puVar2 = *(undefined **)(*(int *)(*(int *)(iVar1 + 0xc) + 0xc) + param_1 * 4);
  }
  return puVar2;
}
// Near miss: two words differ at +0x70; slt/bnezl use at while retail uses v0. The positive nested range form changed the branch layout and was reverted.
// near miss from lane u4r4-0 (unreviewed)
