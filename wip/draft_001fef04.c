/* HSTMATCH module=EBOOT.BIN start=0x001fef04 end=0x001ff3dc symbol=FUN_001fef04 lang=c99 */
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

extern undefined * DAT_003386c8;
extern undefined * DAT_00338ac4;
extern undefined * DAT_00341ccc;
extern undefined4 DAT_00341cec;
extern undefined4 DAT_00341cf0;
extern undefined4 DAT_00341cf4;
extern undefined4 DAT_00341cf8;
extern undefined4 DAT_00341cfc;
extern undefined4 DAT_00341d00;
extern undefined4 DAT_00341d04;
extern undefined4 DAT_00341d08;
extern undefined DAT_00341d10;
extern undefined4 DAT_00341d20;
extern undefined DAT_00341d22;
extern undefined4 DAT_00341d32;
extern undefined4 DAT_00341d34;
extern undefined4 DAT_00341d36;
extern undefined4 DAT_00341d37;
extern undefined4 DAT_00341d38;
extern undefined4 DAT_00341d39;
extern undefined4 DAT_00341d3a;
extern undefined4 DAT_00341d3b;
extern undefined4 DAT_00341d3c;
extern undefined4 DAT_00341d3d;
extern undefined4 DAT_00341d3e;
extern undefined4 DAT_00341d3f;
extern undefined4 DAT_00341d40;
extern undefined4 DAT_00341d41;
extern undefined4 DAT_00341d42;
extern undefined4 DAT_00341d43;
extern undefined4 DAT_00341d44;
extern undefined4 DAT_00341d46;
extern undefined4 DAT_00341d48;
extern undefined4 DAT_00341d4a;
extern undefined4 DAT_00341d4c;
extern undefined DAT_00341d4e;
extern undefined DAT_00341d5e;
extern undefined4 DAT_00341d6e;
extern undefined1 DAT_00341d6f;
extern undefined1 DAT_00341d70;
extern undefined4 DAT_00341d72;
extern undefined2 DAT_00341d74;
extern undefined2 DAT_00341d76;
extern undefined4 DAT_00341d78;
extern undefined4 DAT_00341d7a;
extern undefined4 DAT_0034a678;
extern undefined4 FUN_000be7b4();
extern int FUN_0016b534();
extern bool FUN_0016b540();
extern undefined1 FUN_0016b550();
extern void FUN_001bb6b0();
extern undefined4 FUN_0022c1c4();
extern code * FUN_0022cd60();

void FUN_001fef04(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  
  if (DAT_003386c8 == 0) {
    return;
  }
  if (DAT_00338ac4 == 0) {
    return;
  }
  iVar12 = *(int *)(DAT_003386c8 + 0x40);
  iVar7 = FUN_000be7b4();
  if (iVar7 == 0) {
    return;
  }
  iVar7 = 0;
  if (DAT_003386c8 != 0) {
    if (DAT_00338ac4 == 0) {
      cVar1 = '$';
      goto LAB_001fef94;
    }
    if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
      iVar7 = *(int *)(DAT_003386c8 + 0x40) + 0x1aa0;
    }
    else {
      iVar7 = *(int *)(DAT_003386c8 + 0x40) + 0x1ef8;
    }
  }
  cVar1 = *(char *)(iVar7 + 0x3a8);
LAB_001fef94:
  if (cVar1 != '\0') {
    *(undefined4 *)(iVar12 + 0x89c) = *(undefined4 *)(iVar7 + 0x3b0);
    *(undefined4 *)(iVar12 + 0x8ac) = *(undefined4 *)(iVar7 + 0x3c0);
    if (*(char *)(DAT_00338ac4 + 0x178) == '\0') {
      puVar11 = (undefined1 *)(iVar7 + 0x3e0);
      puVar9 = &DAT_00341d10;
      iVar10 = 8;
      do {
        uVar4 = puVar11[1];
        iVar10 = iVar10 + -1;
        *puVar9 = *puVar11;
        puVar9[1] = uVar4;
        puVar11 = puVar11 + 2;
        puVar9 = puVar9 + 2;
      } while (0 < iVar10);
      DAT_00341d20 = *(undefined2 *)(iVar7 + 0x3f0);
      puVar11 = (undefined1 *)(iVar7 + 0x3f2);
      puVar9 = &DAT_00341d22;
      iVar10 = 8;
      do {
        uVar4 = puVar11[1];
        iVar10 = iVar10 + -1;
        *puVar9 = *puVar11;
        puVar9[1] = uVar4;
        puVar11 = puVar11 + 2;
        puVar9 = puVar9 + 2;
      } while (0 < iVar10);
      DAT_00341d32 = *(undefined2 *)(iVar7 + 0x402);
      puVar11 = (undefined1 *)(iVar7 + 0x41e);
      puVar9 = &DAT_00341d4e;
      DAT_00341d34 = *(undefined2 *)(iVar7 + 0x404);
      iVar10 = 8;
      DAT_00341d36 = *(undefined1 *)(iVar7 + 0x406);
      DAT_00341d37 = *(undefined1 *)(iVar7 + 0x407);
      DAT_00341d38 = *(undefined1 *)(iVar7 + 0x408);
      DAT_00341d39 = *(undefined1 *)(iVar7 + 0x409);
      DAT_00341d3a = *(undefined1 *)(iVar7 + 0x40a);
      DAT_00341d3b = *(undefined1 *)(iVar7 + 0x40b);
      DAT_00341d3c = *(undefined1 *)(iVar7 + 0x40c);
      DAT_00341d3d = *(undefined1 *)(iVar7 + 0x40d);
      DAT_00341d3e = *(undefined1 *)(iVar7 + 0x40e);
      DAT_00341d3f = *(undefined1 *)(iVar7 + 0x40f);
      DAT_00341d40 = *(undefined1 *)(iVar7 + 0x410);
      DAT_00341d41 = *(undefined1 *)(iVar7 + 0x411);
      DAT_00341d42 = *(undefined1 *)(iVar7 + 0x412);
      DAT_00341d43 = *(undefined1 *)(iVar7 + 0x413);
      DAT_00341d44 = *(undefined1 *)(iVar7 + 0x414);
      DAT_00341d46 = *(undefined2 *)(iVar7 + 0x416);
      DAT_00341d48 = *(undefined2 *)(iVar7 + 0x418);
      DAT_00341d4a = *(undefined2 *)(iVar7 + 0x41a);
      DAT_00341d4c = *(undefined2 *)(iVar7 + 0x41c);
      do {
        uVar4 = puVar11[1];
        iVar10 = iVar10 + -1;
        *puVar9 = *puVar11;
        puVar9[1] = uVar4;
        puVar11 = puVar11 + 2;
        puVar9 = puVar9 + 2;
      } while (0 < iVar10);
      puVar11 = (undefined1 *)(iVar7 + 0x42e);
      puVar9 = &DAT_00341d5e;
      iVar10 = 8;
      do {
        uVar4 = puVar11[1];
        iVar10 = iVar10 + -1;
        *puVar9 = *puVar11;
        puVar9[1] = uVar4;
        puVar11 = puVar11 + 2;
        puVar9 = puVar9 + 2;
      } while (0 < iVar10);
      DAT_00341d6e = *(undefined1 *)(iVar7 + 0x43e);
      DAT_00341d6f = *(undefined1 *)(iVar7 + 0x43f);
      DAT_00341d70 = *(undefined1 *)(iVar7 + 0x440);
      DAT_00341d72 = *(undefined2 *)(iVar7 + 0x442);
      DAT_00341d74 = *(undefined2 *)(iVar7 + 0x444);
      DAT_00341d76 = *(undefined2 *)(iVar7 + 0x446);
      DAT_00341d78 = *(undefined2 *)(iVar7 + 0x448);
      DAT_00341d7a = *(undefined2 *)(iVar7 + 0x44a);
    }
  }
  *(undefined1 *)(iVar12 + 0x890) = 1;
  *(undefined4 *)(iVar12 + 0x894) = DAT_0034a678;
  *(undefined4 *)(iVar12 + 0x898) = param_2;
  *(undefined4 *)(iVar12 + 0x8a0) = param_1;
  *(undefined4 *)(iVar12 + 0x8a8) = *(undefined4 *)(DAT_00338ac4 + 0x28);
  *(undefined4 *)(iVar12 + 0x8a4) = param_3;
  if (*(char *)(DAT_00338ac4 + 0x178) != '\0') {
    *(char *)(iVar12 + 0x8c4) = (char)*(undefined2 *)(DAT_00341ccc + 0x1038);
    uVar4 = FUN_0016b540();
    uVar5 = FUN_0016b550();
    uVar6 = FUN_0016b534();
    *(undefined1 *)(iVar12 + 0x8c5) = uVar6;
    *(undefined1 *)(iVar12 + 0x8c6) = uVar5;
    *(undefined1 *)(iVar12 + 0x8c7) = uVar4;
    FUN_001bb6b0(iVar12 + 0x8b0,DAT_00341cec,DAT_00341cfc,DAT_00341d00,DAT_00341cf8,
                 DAT_00341cf0,DAT_00341cf4,DAT_00341d04,DAT_00341d08,1);
    puVar11 = &DAT_00341d10;
    puVar9 = (undefined1 *)(iVar12 + 0x8c8);
    iVar7 = 8;
    do {
      uVar4 = puVar11[1];
      iVar7 = iVar7 + -1;
      *puVar9 = *puVar11;
      puVar9[1] = uVar4;
      puVar11 = puVar11 + 2;
      puVar9 = puVar9 + 2;
    } while (0 < iVar7);
    puVar11 = &DAT_00341d22;
    puVar9 = (undefined1 *)(iVar12 + 0x8da);
    *(undefined2 *)(iVar12 + 0x8d8) = DAT_00341d20;
    iVar7 = 8;
    do {
      uVar4 = puVar11[1];
      iVar7 = iVar7 + -1;
      *puVar9 = *puVar11;
      puVar9[1] = uVar4;
      puVar11 = puVar11 + 2;
      puVar9 = puVar9 + 2;
    } while (0 < iVar7);
    puVar11 = &DAT_00341d4e;
    puVar9 = (undefined1 *)(iVar12 + 0x906);
    *(undefined2 *)(iVar12 + 0x8ea) = DAT_00341d32;
    iVar7 = 8;
    *(undefined2 *)(iVar12 + 0x8ec) = DAT_00341d34;
    *(undefined1 *)(iVar12 + 0x8ee) = DAT_00341d36;
    *(undefined1 *)(iVar12 + 0x8ef) = DAT_00341d37;
    *(undefined1 *)(iVar12 + 0x8f0) = DAT_00341d38;
    *(undefined1 *)(iVar12 + 0x8f1) = DAT_00341d39;
    *(undefined1 *)(iVar12 + 0x8f2) = DAT_00341d3a;
    *(undefined1 *)(iVar12 + 0x8f3) = DAT_00341d3b;
    *(undefined1 *)(iVar12 + 0x8f4) = DAT_00341d3c;
    *(undefined1 *)(iVar12 + 0x8f5) = DAT_00341d3d;
    *(undefined1 *)(iVar12 + 0x8f6) = DAT_00341d3e;
    *(undefined1 *)(iVar12 + 0x8f7) = DAT_00341d3f;
    *(undefined1 *)(iVar12 + 0x8f8) = DAT_00341d40;
    *(undefined1 *)(iVar12 + 0x8f9) = DAT_00341d41;
    *(undefined1 *)(iVar12 + 0x8fa) = DAT_00341d42;
    *(undefined1 *)(iVar12 + 0x8fb) = DAT_00341d43;
    *(undefined1 *)(iVar12 + 0x8fc) = DAT_00341d44;
    *(undefined2 *)(iVar12 + 0x8fe) = DAT_00341d46;
    *(undefined2 *)(iVar12 + 0x900) = DAT_00341d48;
    *(undefined2 *)(iVar12 + 0x902) = DAT_00341d4a;
    *(undefined2 *)(iVar12 + 0x904) = DAT_00341d4c;
    do {
      uVar4 = puVar11[1];
      iVar7 = iVar7 + -1;
      *puVar9 = *puVar11;
      puVar9[1] = uVar4;
      puVar11 = puVar11 + 2;
      puVar9 = puVar9 + 2;
    } while (0 < iVar7);
    puVar11 = &DAT_00341d5e;
    puVar9 = (undefined1 *)(iVar12 + 0x916);
    iVar7 = 8;
    do {
      uVar4 = puVar11[1];
      iVar7 = iVar7 + -1;
      *puVar9 = *puVar11;
      puVar9[1] = uVar4;
      uVar5 = DAT_00341d70;
      uVar4 = DAT_00341d6f;
      puVar11 = puVar11 + 2;
      puVar9 = puVar9 + 2;
    } while (0 < iVar7);
    *(undefined1 *)(iVar12 + 0x926) = DAT_00341d6e;
    *(undefined1 *)(iVar12 + 0x927) = uVar4;
    *(undefined1 *)(iVar12 + 0x928) = uVar5;
    uVar3 = DAT_00341d76;
    uVar2 = DAT_00341d74;
    *(undefined2 *)(iVar12 + 0x92a) = DAT_00341d72;
    *(undefined2 *)(iVar12 + 0x92c) = uVar2;
    *(undefined2 *)(iVar12 + 0x92e) = uVar3;
    *(undefined2 *)(iVar12 + 0x930) = DAT_00341d78;
    *(undefined2 *)(iVar12 + 0x932) = DAT_00341d7a;
    uVar8 = FUN_0022c1c4();
    *(undefined4 *)(iVar12 + 0x934) = uVar8;
    iVar7 = (int)(FUN_0022cd60());
    *(undefined4 *)(iVar12 + 0x938) = *(undefined4 *)(iVar7 + 0x138);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
