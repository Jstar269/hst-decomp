/* HSTMATCH module=EBOOT.BIN start=0x00150ab4 end=0x00150b6c symbol=FUN_00150ab4 lang=c99 */
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

extern undefined * volatile DAT_0034a114;
extern int FUN_0014c384();
extern void FUN_001cc784();
extern int FUN_001cd13c();
extern int FUN_001cd284();

undefined4 FUN_00150ab4(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_001cd13c(DAT_0034a114);
  if (iVar1 == 0) {
    uVar2 = *param_2;
    uVar3 = (uchar)FUN_001cd284(DAT_0034a114);
    puVar4 = (uint *)FUN_0014c384(uVar2,*(undefined4 *)(*(int *)(param_1 + 4) + 0x10));
    *puVar4 = uVar3;
    FUN_001cc784(DAT_0034a114,*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
    iVar1 = FUN_001cd284(DAT_0034a114);
    if (iVar1 == 0) {
      puVar5 = (undefined4 *)FUN_0014c384(uVar2,0xb);
      *puVar5 = 0;
    }
    uVar2 = 1;
  undefined1 *global = DAT_0034a114;
  global[0xfd] = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
// Near miss: 2 words remain at the final global flag load; retail uses v0 as the global address base and v1 for the pointer result, while this build reuses v1. Local-pointer, volatile-pointee, and volatile-global forms left the same register choice.
// near miss from lane u3r1-0 (unreviewed)
