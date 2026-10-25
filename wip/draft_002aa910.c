/* HSTMATCH module=EBOOT.BIN start=0x002aa910 end=0x002aae5c symbol=FUN_002aa910 lang=c99 */
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
extern undefined DAT_003024e4;
extern undefined4 DAT_00302bec;
extern undefined4 DAT_00302bf0;
extern undefined4 DAT_00302bf4;
extern undefined4 DAT_00302bf8;
extern undefined * DAT_003415a8;
extern uint * FUN_000149a8();
extern undefined4 * FUN_00022498();
extern int * FUN_00054554();
extern void FUN_0005bbd4(float, float, float, float, float, float, int);
extern void FUN_0005bc58();
extern void FUN_000ffb3c();
extern void FUN_0010d4a8();
extern void FUN_002aa3f0();
extern undefined8 FUN_002af314();
extern int FUN_002af32c();

undefined4 FUN_002aa910(int param_1,int param_2)
{
  bool bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  undefined4 *puVar18;
  undefined8 uVar19;
  int local_10 [4];
  int local_1c [3];
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  undefined4 local_44;
  undefined4 local_48;
  undefined4 local_4c;
  undefined4 local_50;
  undefined4 local_54;
  undefined4 local_58;
  undefined4 local_5c;
  undefined4 local_60;
  int local_64;
  
  if (*(char *)(param_1 + 0x30c5) == '\0') {
    iVar9 = 0;
  }
  else {
    iVar9 = *(int *)(param_1 + 0x30c8);
  }
  iVar6 = param_2 + iVar9 + *(int *)(param_1 + 0x30cc);
  if (iVar6 < 0) {
    uVar2 = 0;
  }
  else if (iVar6 < *(int *)((*(byte *)(param_1 + 0x30c4) != 0 ^ 1) * 0xc + param_1 + 0x30f0)) {
    FUN_002aa3f0(local_1c,param_1,(uint)*(byte *)(param_1 + 0x30c4));
    iVar9 = *(int *)(local_1c[0] + (param_2 + iVar9 + *(int *)(param_1 + 0x30cc)) * 4);
    FUN_00054554(local_1c,0);
    piVar3 = (int *)FUN_002af32c(DAT_003415a8 + 0x87128,iVar9);
    iVar6 = 0x6a;
    local_64 = 0x14;
    bVar1 = 2 < *piVar3;
    iVar9 = 0x6c;
    if (bVar1) {
      iVar6 = 0x74;
      local_64 = 0x16;
      iVar9 = 0x78;
    }
    iVar11 = 0x6a;
    iVar10 = param_1 + 0x1a8;
    do {
      FUN_000ffb3c(*(int *)(iVar10 + 0x78),1);
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 4;
    } while (iVar11 < 0x88);
    iVar10 = param_1 + param_2 * 0x680;
    iVar11 = 0x14;
    iVar12 = iVar10 + 0x500;
    do {
      FUN_000149a8((uint *)(iVar12 + 0x103d),(uint *)&DAT_00300a90);
      iVar11 = iVar11 + 1;
      iVar12 = iVar12 + 0x40;
    } while (iVar11 < 0x1a);
    if (bVar1) {
      uVar14 = 0x74;
      uVar13 = 0x87;
    }
    else {
      uVar14 = 0x6a;
      uVar13 = 0x73;
    }
    if (uVar14 <= uVar13) {
      iVar11 = param_1 + uVar14 * 4;
      do {
        FUN_000ffb3c(*(int *)(iVar11 + 0x78),0);
        uVar14 = uVar14 + 1;
        iVar11 = iVar11 + 4;
      } while ((int)uVar14 <= (int)uVar13);
    }
    iVar17 = param_1 + iVar6 * 4;
    iVar12 = 0;
    piVar16 = local_10;
    iVar11 = param_1 + param_2 * 0x68 + local_64 * 4;
    iVar6 = param_1 + iVar9 * 4;
    puVar18 = (unsigned int *)(&DAT_003024e4 + iVar9 * 3);
    iVar9 = param_1;
    while( true ) {
      if (bVar1) {
        iVar4 = 4;
      }
      else {
        iVar4 = 2;
      }
      if (iVar4 <= iVar12) break;
      local_10[0] = DAT_00302bec;
      local_10[1] = DAT_00302bf0;
      local_10[2] = DAT_00302bf4;
      local_10[3] = DAT_00302bf8;
      iVar4 = iVar12;
      if (bVar1) {
        iVar4 = *piVar16;
      }
      FUN_000ffb3c(*(int *)(iVar17 + 0x78),0);
      FUN_000149a8((uint *)(iVar10 + (local_64 + iVar12) * 0x40 + 0x103d),
                   (uint *)(piVar3 + iVar4 * 0xd + 2));
      if (piVar3[1] == iVar4) {
        iVar15 = *(int *)(iVar11 + 0xe18);
        *(undefined4 *)(iVar15 + 0x118) = 0x80090961;
        local_30 = 0x42c20000;
        local_2c = 0x41100000;
        local_28 = 0x41100000;
        local_24 = 0x43000000;
        FUN_00022498(0x3c03126f,&local_50,(undefined1 (*) [16])&local_30);
        *(undefined4 *)(iVar15 + 0x120) = local_50;
        *(undefined4 *)(iVar15 + 0x124) = local_4c;
        *(undefined4 *)(iVar15 + 0x128) = local_48;
        *(undefined4 *)(iVar15 + 300) = local_44;
      }
      else {
        iVar15 = *(int *)(iVar11 + 0xe18);
        *(undefined4 *)(iVar15 + 0x118) = 0x80141414;
        local_40 = 0x41a00000;
        local_3c = 0x41a00000;
        local_38 = 0x41a00000;
        local_34 = 0x43000000;
        FUN_00022498(0x3c03126f,&local_60,(undefined1 (*) [16])&local_40);
        *(undefined4 *)(iVar15 + 0x120) = local_60;
        *(undefined4 *)(iVar15 + 0x124) = local_5c;
        *(undefined4 *)(iVar15 + 0x128) = local_58;
        *(undefined4 *)(iVar15 + 300) = local_54;
      }
      uVar19 = FUN_002af314((int)(piVar3 + iVar4 * 0xd + 2));
      FUN_000ffb3c(*(int *)(iVar6 + 0x78),0);
      iVar4 = *(int *)(iVar6 + 0x78);
      iVar15 = (int)uVar19 + puVar18[2];
      *(int *)(iVar4 + 0x24) = iVar15;
      *(int *)(iVar4 + 0x28) = iVar15;
      if (bVar1) {
        iVar4 = 0x84;
      }
      else {
        iVar4 = 0x72;
      }
      iVar15 = *(int *)(param_1 + (iVar12 + iVar4) * 4 + 0x78);
      iVar7 = (int)*(short *)(iVar15 + 4);
      iVar8 = (int)*(short *)(iVar15 + 6);
      iVar4 = *(short *)(iVar15 + 8) + iVar7;
      iVar5 = *(short *)(iVar15 + 10) + iVar8;
      FUN_0005bbd4((float)((float)(iVar7 + 2)),(float)((float)(iVar8 + 2)),(float)((float)((*(short *)(iVar15 + 8) - iVar7) + -4)),(float)((float)((*(short *)(iVar15 + 10) - iVar8) + -4)),(float)((float)(iVar4 / 2)),(float)((float)(iVar5 / 2)),(int)(*(int *)(iVar9 + 0x3128)));
      FUN_0005bc58(*(int *)(iVar9 + 0x3128));
      piVar16 = piVar16 + 1;
      iVar17 = iVar17 + 4;
      iVar11 = iVar11 + 4;
      iVar6 = iVar6 + 4;
      puVar18 = puVar18 + 3;
      iVar9 = iVar9 + 4;
      iVar12 = iVar12 + 1;
    }
    iVar6 = 0;
    iVar9 = param_1;
    do {
      iVar12 = 0;
      iVar10 = param_1;
      iVar11 = iVar9;
      do {
        iVar17 = *(int *)(iVar11 + 0xe18);
        if (iVar17 != 0) {
          *(int *)(iVar17 + 0xf8) = iVar10 + 0x103d;
          *(undefined4 *)(iVar17 + 0x138) = 1;
          FUN_0010d4a8(iVar17);
        }
        iVar12 = iVar12 + 1;
        iVar11 = iVar11 + 4;
        iVar10 = iVar10 + 0x40;
      } while (iVar12 < 0x1a);
      iVar6 = iVar6 + 1;
      iVar9 = iVar9 + 0x68;
      param_1 = param_1 + 0x680;
    } while (iVar6 < 5);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
// near miss from lane fm11 (unreviewed)
