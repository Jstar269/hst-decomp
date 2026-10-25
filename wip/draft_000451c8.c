/* HSTMATCH module=EBOOT.BIN start=0x000451c8 end=0x00045574 symbol=FUN_000451c8 lang=c99 */
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

extern undefined4 DAT_002d01b8;
extern void FUN_00045574();
extern void FUN_00045690();

void FUN_000451c8(ushort *param_1,ushort *param_2,char param_3)
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort uVar8;
  ushort *puVar9;
  ushort *puVar10;
  int iVar11;
  
LAB_000451f0:
  do {
    puVar10 = param_1;
    iVar3 = (int)param_2 - (int)puVar10;
    iVar7 = iVar3 / 4;
    if (iVar7 < 2) {
      return;
    }
    if (iVar7 < 0x15) {
      FUN_00045690(puVar10,param_2,(int)param_3);
      return;
    }
    iVar3 = iVar3 >> 4;
    if (iVar7 < 0) {
      iVar3 = iVar7 + 3 >> 2;
    }
    iVar11 = DAT_002d01b8 % 5;
    iVar4 = DAT_002d01b8 + 1;
    if (4 < iVar4) {
      iVar4 = -4;
    }
    iVar7 = iVar7 * 3;
    DAT_002d01b8 = iVar4 + 1;
    if (4 < DAT_002d01b8) {
      DAT_002d01b8 = -4;
    }
    puVar9 = param_2 + -2;
    FUN_00045574(puVar10 + (iVar3 + iVar11) * 2,puVar10 + ((iVar7 / 4) + iVar4 % 5) * 2,puVar9,
                 (int)param_3);
    uVar8 = *puVar9;
    uVar2 = *puVar10;
    param_1 = puVar10;
    while (puVar6 = puVar9, uVar2 < uVar8) {
      param_1 = param_1 + 2;
      uVar2 = *param_1;
    }
    do {
      puVar5 = puVar6;
      puVar6 = puVar5 + -2;
      if (param_1 == puVar6) break;
    } while (uVar8 <= *puVar6);
    if (param_1 < puVar6) {
      uVar8 = *param_1;
      uVar2 = param_1[1];
      *param_1 = *puVar6;
      param_1[1] = puVar5[-1];
      *puVar6 = uVar8;
      puVar5[-1] = uVar2;
      param_1 = param_1 + 2;
      while( true ) {
        for (; uVar8 = *puVar9, *param_1 < uVar8; param_1 = param_1 + 2) {
        }
        do {
          puVar5 = puVar6;
          puVar6 = puVar5 + -2;
        } while (uVar8 <= *puVar6);
        if (puVar6 <= param_1) break;
        uVar8 = *param_1;
        uVar2 = param_1[1];
        *param_1 = *puVar6;
        param_1[1] = puVar5[-1];
        *puVar6 = uVar8;
        puVar5[-1] = uVar2;
        param_1 = param_1 + 2;
      }
    }
    if (param_1 != puVar10) {
      iVar3 = (int)param_1 - (int)puVar10;
      iVar7 = (int)param_2 - (int)param_1;
      if (iVar3 / 4 < iVar7 / 4) {
        FUN_000451c8(puVar10,param_1,(int)param_3);
      }
      else {
        FUN_000451c8(param_1,param_2,(int)param_3);
        param_2 = param_1;
        param_1 = puVar10;
      }
      goto LAB_000451f0;
    }
    uVar2 = *param_1;
    uVar1 = param_1[1];
    puVar6 = param_2 + -2;
    *param_1 = uVar8;
    param_1[1] = param_2[-1];
    *puVar9 = uVar2;
    param_2[-1] = uVar1;
    param_1 = param_1 + 2;
    if (param_2[-2] <= *puVar10) {
      for (; (param_1 != param_2 && (*param_1 <= *puVar10)); param_1 = param_1 + 2) {
      }
      if (param_1 < puVar6) {
        uVar8 = *param_1;
        uVar2 = param_1[1];
        *param_1 = *puVar6;
        param_1[1] = param_2[-1];
        *puVar6 = uVar8;
        param_2[-1] = uVar2;
      }
    }
    if (param_1 < puVar6) {
      uVar8 = *puVar10;
      do {
        if (uVar8 < *param_1) {
          do {
            puVar9 = puVar6;
            puVar6 = puVar9 + -2;
          } while (uVar8 < *puVar6);
          if (puVar6 <= param_1) break;
          uVar8 = *param_1;
          uVar2 = param_1[1];
          *param_1 = *puVar6;
          param_1[1] = puVar9[-1];
          *puVar6 = uVar8;
          puVar9[-1] = uVar2;
        }
        param_1 = param_1 + 2;
        uVar8 = *puVar10;
      } while( true );
    }
  } while( true );
}
// near miss from lane fm11 (unreviewed)
