/* HSTMATCH module=EBOOT.BIN start=0x002a805c end=0x002a8668 symbol=FUN_002a805c lang=c99 */
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

extern undefined DAT_00300a90;
extern char DAT_00301ca2[];
extern char DAT_00301cbc[];
extern char DAT_00301cc8[];
extern char DAT_00301cec[];
extern char DAT_00301d08[];
extern char DAT_00301d28[];
extern char DAT_00301d48[];
extern char DAT_00301d70[];
extern char DAT_00301d90[];
extern char DAT_00301db0[];
extern char DAT_00301dcc[];
extern char DAT_00301dec[];
extern char DAT_00301e08[];
extern char DAT_00301e30[];
extern int FUN_00000bcc();
extern undefined4 * FUN_00011090();
extern void FUN_000143b0();
extern void FUN_0001ca58();
extern void FUN_0001cb88();
extern undefined4 FUN_00055dd0();
extern undefined4 FUN_00055eac();
extern void FUN_0005743c();
extern void FUN_000575fc();
extern void FUN_00092630();
extern undefined4 FUN_00092720();
extern undefined1 FUN_00092790();
extern void FUN_00092c38();
extern void FUN_00092d10();
extern void FUN_00092e50();
extern void FUN_000931ec();
extern void FUN_000b42b4();
extern int FUN_00193024();
extern int FUN_00193474();
extern undefined1 FUN_001fe0dc();
extern undefined4 FUN_002041e8();
extern undefined * FUN_00204220();
extern undefined * FUN_00204258();
extern void FUN_0020443c();
extern void FUN_002044b4();
extern void FUN_002a8668();

void FUN_002a805c(int *param_1,undefined1 *param_2,undefined4 *param_3,undefined4 param_4, char param_5,undefined4 *param_6,undefined1 param_7,undefined1 param_8, undefined1 uStackX_0,undefined1 uStackX_4,int iStackX_8)
{
  undefined1 uVar1;
  short sVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int *piVar17;
  int local_18 [6];
  undefined1 auStack_28 [16];
  undefined1 local_2c [4];
  undefined1 auStack_6c [64];
  undefined1 auStack_16c [256];
  undefined4 local_170;
  undefined1 auStack_1b0 [64];
  undefined1 auStack_2b0 [256];
  undefined1 auStack_3b0 [256];
  char local_3c8;
  
  iVar16 = *param_1;
  FUN_00011090(local_18,param_6,0x18);
  *param_2 = 0;
  local_3c8 = '\0';
  iVar5 = FUN_001fe0dc();
  if (iVar5 == 0) {
    if (iStackX_8 < 1000) {
      psVar6 = (short *)FUN_00193474(iStackX_8);
      sVar2 = *psVar6;
      *param_3 = 0;
    }
    else {
      FUN_000143b0(auStack_28,DAT_00301cbc,iStackX_8 + -1000);
      psVar6 = (short *)FUN_00193024(auStack_28);
      sVar2 = *psVar6;
      if ((char)psVar6[0x12] == '\x01') {
        uVar11 = 2;
      }
      else {
        uVar11 = 4;
      }
      *param_3 = uVar11;
    }
    local_18[0] = (int)sVar2;
    uVar1 = *(undefined1 *)((int)psVar6 + 0xd);
    uVar14 = (uint)*(byte *)(psVar6 + 6);
    iVar5 = 0;
    piVar17 = local_18;
    do {
      iVar7 = FUN_002041e8(iVar5);
      iVar13 = *piVar17;
      if (iVar13 != 0x7fffffff) {
        if (iVar13 < 0) {
          FUN_00092c38(iVar16,iVar7);
        }
        else {
          if (iVar7 == 5) {
            iVar13 = iVar13 / 10;
          }
          if ((iVar7 - 3U < 2) && (iVar13 == 0)) {
            FUN_00092c38(iVar16,iVar7);
          }
          iVar8 = FUN_00092720(iVar16,iVar7,iVar13,uVar1,0);
          if (iVar8 == 0) {
            iVar8 = FUN_001fe0dc();
            if (iVar8 != 0) {
              FUN_002a8668(DAT_00301cc8,iVar5);
              *param_2 = 1;
              return;
            }
            uVar11 = (unsigned int)(FUN_00204220(iVar5));
            FUN_0001ca58(0x30ebf4,DAT_00301cec,uVar11,uVar11,iVar13,
                         &DAT_00300a90);
            iVar8 = FUN_001fe0dc();
            if (iVar8 != 0) {
              FUN_0001cb88(0x30ebf4);
              FUN_002a8668(DAT_00301d08,iVar5);
              *param_2 = 1;
              return;
            }
            cVar4 = FUN_00092790(iVar16,iVar7,iVar13,uVar1,0);
            if ((iVar7 != 2) && (iVar7 == 0)) {
              local_3c8 = cVar4;
            }
            FUN_0001cb88(0x30ebf4);
          }
        }
        iVar13 = FUN_001fe0dc();
        if (iVar13 != 0) {
          FUN_002a8668(DAT_00301d28,iVar5);
          *param_2 = 1;
          return;
        }
        if ((iVar7 == 2) && (uVar14 != *(uint *)(iVar16 + 0x68))) {
          FUN_0001ca58(0x30ebf4,DAT_00301d48,uVar14);
          FUN_00092d10(iVar16,uVar14);
          FUN_0001cb88(0x30ebf4);
        }
      }
      iVar5 = iVar5 + 1;
      piVar17 = piVar17 + 1;
    } while (iVar5 < 6);
    FUN_00092630(iVar16,uStackX_4);
    iVar5 = FUN_001fe0dc();
    if (iVar5 == 0) {
      puVar9 = (undefined1 *)0x2;
      puVar12 = local_2c;
      puVar3 = puVar12;
      while (puVar3 != (undefined1 *)0x0) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
        puVar9 = puVar9 + -1;
        puVar3 = puVar9;
      }
      local_2c[0] = param_7;
      local_2c[1] = param_8;
      FUN_000931ec(iVar16,1,local_2c,uStackX_0);
      iVar5 = FUN_001fe0dc();
      if (iVar5 == 0) {
        if (local_3c8 != '\0') {
          uVar15 = *param_6;
          uVar11 = uVar15;
          if (0xe < iStackX_8) {
            uVar11 = 99;
          }
          FUN_0001ca58(0x30ebf4,DAT_00301db0,uVar11);
          iVar5 = *(int *)(iVar16 + 100);
          if (param_5 != '\0') {
            iVar13 = 0;
            do {
              uVar10 = (unsigned int)(FUN_00204258(iVar13));
              FUN_000143b0(auStack_6c,uVar10,uVar11);
              FUN_0020443c(auStack_16c,uVar11,auStack_6c,iVar13);
              iVar7 = FUN_00000bcc(0x10);
              if (iVar7 == 0) {
                local_170 = 0;
              }
              else {
                local_170 = FUN_00055dd0(iVar7);
              }
              FUN_00055eac(local_170,auStack_16c,0);
              FUN_0005743c(*(undefined4 *)(iVar16 + 0x58),iVar13,local_170,0);
              if (iVar5 == 0) {
                uVar14 = param_1[2];
              }
              else {
                FUN_0005743c(iVar5,iVar13,local_170,0);
                uVar14 = param_1[2];
              }
              if (uVar14 < (uint)param_1[3]) {
                param_1[2] = uVar14 + 1;
                *(undefined4 *)(param_1[1] + (uVar14 + 1) * 4 + -4) = local_170;
              }
              else {
                FUN_000b42b4(param_1 + 1,&local_170,0);
              }
              iVar13 = iVar13 + 1;
            } while (iVar13 < 6);
          }
          iVar5 = *(int *)(iVar16 + 0x58);
          if (iVar5 != 0) {
            iVar13 = 0;
            do {
              FUN_000575fc(iVar5,iVar13,uStackX_0);
              iVar13 = iVar13 + 1;
            } while (iVar13 < 6);
          }
          iVar5 = FUN_001fe0dc();
          if (iVar5 != 0) {
            FUN_002a8668(DAT_00301dcc);
            FUN_0001cb88(0x30ebf4);
            *param_2 = 1;
            return;
          }
          if (*(int *)(iVar16 + 0x50) != 0) {
            iVar5 = 0;
            do {
              uVar11 = (unsigned int)(FUN_00204258(iVar5));
              FUN_000143b0(auStack_1b0,uVar11,uVar15);
              FUN_002044b4(auStack_2b0,uVar15,auStack_1b0,iVar5);
              FUN_000143b0(auStack_3b0,DAT_00301dec,uVar15);
              FUN_00092e50(iVar16,iVar5,auStack_2b0,auStack_3b0,0,0);
              iVar5 = iVar5 + 1;
            } while (iVar5 < 6);
          }
          FUN_0001cb88(0x30ebf4);
        }
        iVar5 = FUN_001fe0dc();
        if (iVar5 == 0) {
          FUN_002a8668(DAT_00301e30);
          *param_2 = 1;
        }
        else {
          FUN_002a8668(DAT_00301e08);
          *param_2 = 1;
        }
      }
      else {
        FUN_002a8668(DAT_00301d90);
        *param_2 = 1;
      }
    }
    else {
      FUN_002a8668(DAT_00301d70);
      *param_2 = 1;
    }
  }
  else {
    FUN_002a8668(DAT_00301ca2 + 2);
    *param_2 = 1;
  }
  return;
}
// near miss from lane fm11 (unreviewed)
