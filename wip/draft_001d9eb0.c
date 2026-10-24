/* HSTMATCH module=EBOOT.BIN start=0x001d9eb0 end=0x001da0a8 symbol=FUN_001d9eb0 lang=c99 */
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
typedef signed char undefined1;
typedef short undefined2;
typedef int undefined4;

extern undefined4 DAT_003415a8;
extern char DAT_002c6a54[];
extern char DAT_002c6a78[];
extern int FUN_0000d518(void);
extern void FUN_0000f3e8();
extern undefined * FUN_0000fe3c(void);
extern uint FUN_0019d368(undefined4 param_1,uint param_2);
extern int FUN_001d9cfc(int *param_1,int param_2);
extern undefined4 FUN_001da1c8(undefined4 *param_1);

uint FUN_001d9eb0(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 local_58 [4];
  uint local_54;
  undefined4 local_50;
  
  iVar1 = FUN_001d9cfc((int *)(&local_50),(int)(1));
  local_54 = *(uint *)(DAT_003415a8 + 0x86d20);
  uVar8 = 0xffffffff;
  if (local_54 == 0) {
    uVar8 = 1;
  }
  else {
    iVar7 = 0;
    if (0 < iVar1) {
      puVar6 = (unsigned int *)(&local_50);
      do {
        uVar5 = *puVar6;
        if (0x1f < uVar5) {
          iVar2 = (int)(FUN_0000fe3c());
          FUN_0000f3e8(*(undefined4 *)(iVar2 + 0xc),DAT_002c6a78);
          FUN_0000d518();
        }
        if ((local_54 & 1 << (uVar5 & 0x1f)) == 0) {
          uVar8 = (&local_50)[iVar7];
          break;
        }
        iVar7 = iVar7 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar7 < iVar1);
    }
    if ((int)uVar8 < 0) {
      puVar6 = (unsigned int *)(&local_50);
      iVar7 = (int)&local_50 + (iVar1 * 4 - (int)puVar6);
      if (iVar7 < 0) {
        iVar7 = iVar7 + 3;
      }
      iVar7 = iVar7 >> 2;
      uVar8 = local_50;
      if ((1 < iVar7) && (puVar6 < &local_54 + iVar1)) {
        do {
          local_58[0] = 0;
          iVar2 = FUN_0019d368((undefined4)(local_58),(uint)(iVar7));
          puVar4 = puVar6 + iVar2;
          uVar8 = *puVar6;
          iVar7 = iVar7 + -1;
          *puVar6 = *puVar4;
          puVar6 = puVar6 + 1;
          *puVar4 = uVar8;
          uVar8 = local_50;
        } while (puVar6 < &local_54 + iVar1);
      }
    }
  }
  if ((int)uVar8 < 0) {
    uVar8 = 1;
  }
  if (param_1 != 0) {
    if (0x1f < uVar8) {
      iVar1 = (int)(FUN_0000fe3c());
      FUN_0000f3e8(*(undefined4 *)(iVar1 + 0xc),DAT_002c6a54);
      FUN_0000d518();
    }
    local_54 = local_54 | 1 << (uVar8 & 0x1f);
    uVar3 = FUN_001da1c8((undefined4 *)(&local_54));
    *(undefined4 *)(DAT_003415a8 + 0x86d20) = uVar3;
  }
  return uVar8;
}
// near miss from lane fm9 (unreviewed)
