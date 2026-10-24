/* HSTMATCH module=EBOOT.BIN start=0x001b50a4 end=0x001b523c symbol=FUN_001b50a4 lang=c99 */
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

extern undefined DAT_003092dc;
extern undefined DAT_0034179c;
extern void FUN_000009e4();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern void FUN_000622d4();
extern void FUN_001b23c0();
extern void FUN_001b3590();
extern void FUN_001b3640();
extern void FUN_001b871c();
extern void FUN_001b94f8();

undefined4 * FUN_001b50a4(undefined4 *param_1,short param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uStack_4;
  int local_8;
  undefined4 *local_c;
  undefined4 uStack_10;
  int local_14;
  undefined4 *local_18;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003092dc);
    FUN_001b3590((int *)&DAT_0034179c,0);
    FUN_001b871c((int)param_1);
    FUN_000622d4(3,0x80,0x80,0);
    iVar3 = 0x11;
    puVar2 = param_1 + 0x11;
    do {
      if (puVar2[0x28] != 0) {
        FUN_00000a00();
        puVar2[0x28] = 0;
      }
      iVar3 = iVar3 + -1;
      puVar2 = puVar2 + -1;
    } while (-1 < iVar3);
    if (param_1[0x18] == 0) {
      iVar3 = param_1[0x17];
    }
    else {
      FUN_000009e4();
      param_1[0x18] = 0;
      iVar3 = param_1[0x17];
    }
    if (iVar3 != 0) {
      FUN_000009e4();
      param_1[0x17] = 0;
    }
    FUN_001b3640((int *)&DAT_0034179c);
    piVar1 = (int *)(param_1 + 0x3c);
    if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) {
      local_c = param_1 + 0x3d;
      local_8 = param_1[0x3e];
      FUN_001b94f8(&uStack_4,piVar1,&local_8,&local_c);
    }
    if (param_1 != (undefined4 *)0xffffffc4) {
      FUN_001b23c0(0x34179c,0);
      piVar1 = (int *)(param_1 + 0xf);
      if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) {
        local_18 = param_1 + 0x10;
        local_14 = param_1[0x11];
        FUN_001b94f8(&uStack_10,piVar1,&local_14,&local_18);
      }
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00();
    }
  }
  return param_1;
}
// near miss from lane fm9 (unreviewed)
