/* HSTMATCH module=EBOOT.BIN start=0x002a3f58 end=0x002a41ac symbol=FUN_002a3f58 lang=c99 */
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

extern undefined * DAT_002cfc8c;
extern undefined * DAT_003415a8;
extern undefined DAT_0034179c;
extern undefined4 * FUN_00011090();
extern int FUN_001b1c44();

void FUN_002a3f58(int *param_1)
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  float fVar6;
  
  if (*param_1 != 0) {
    iVar3 = *(int *)(DAT_003415a8 + 0x86bd0);
    if (iVar3 == 2) {
      fVar6 = 3.0f;
    }
    else if ((iVar3 == 1) || (iVar3 != 0)) {
      fVar6 = 2.0f;
    }
    else {
      fVar6 = 1.0f;
    }
    if (param_1[0x42] < 4) {
      uVar5 = 0;
joined_r0x002a3ff8:
      if (0.0f < fVar6) {
        fVar6 = fVar6 - 1.0f;
        puVar4 = (undefined4 *)(*param_1 + param_1[0x41]);
        for (uVar5 = 0; bVar1 = *(byte *)((int)puVar4 + uVar5), bVar1 != 0; uVar5 = uVar5 + iVar3) {
          bVar2 = false;
          if ((bVar1 != 0) && (bVar1 < 0x10)) {
            bVar2 = true;
          }
          if (!bVar2) break;
          if (bVar1 == 0 || 0xf < bVar1) {
            iVar3 = 0;
          }
          else if (bVar1 == 8) {
            iVar3 = 3;
          }
          else {
            iVar3 = 2;
          }
        }
        do {
          if (bVar1 == 0) goto LAB_002a40e8;
          uVar5 = uVar5 + 1;
          bVar2 = true;
          if ((((int)*(char *)((int)puVar4 + uVar5) & 0x80U) != 0) &&
             (((int)*(char *)((int)puVar4 + uVar5) & 0xc0U) != 0xc0)) {
            bVar2 = false;
          }
          if (bVar2) goto LAB_002a40e8;
          bVar1 = *(byte *)((int)puVar4 + uVar5);
        } while( true );
      }
      if ((int)uVar5 < 1) {
        param_1[0x42] = param_1[0x42] + 1;
      }
      else {
        FUN_001b1c44((int *)&DAT_0034179c,0x14);
      }
      iVar3 = param_1[0x42];
      goto LAB_002a414c;
    }
    iVar3 = param_1[0x42];
LAB_002a414c:
    if ((3 < iVar3) && (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0)) {
      FUN_001b1c44((int *)&DAT_0034179c,0x13);
      *(undefined1 *)(param_1 + 0x43) = 1;
    }
  }
  return;
LAB_002a40e8:
  FUN_00011090((undefined4 *)((int)param_1 + param_1[0x41] + 4),puVar4,uVar5);
  iVar3 = param_1[0x41];
  param_1[0x41] = iVar3 + uVar5;
  *(undefined1 *)((int)param_1 + iVar3 + uVar5 + 4) = 0;
  goto joined_r0x002a3ff8;
}
// near miss from lane fm9 (unreviewed)
