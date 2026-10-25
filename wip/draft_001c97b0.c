/* HSTMATCH module=EBOOT.BIN start=0x001c97b0 end=0x001c9d7c symbol=FUN_001c97b0 lang=c99 */
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

extern undefined * DAT_0033b574;
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
extern undefined4 DAT_00341d6f;
extern undefined4 DAT_00341d70;
extern undefined4 DAT_00341d72;
extern undefined4 DAT_00341d74;
extern undefined4 DAT_00341d76;
extern undefined4 DAT_00341d78;
extern undefined4 DAT_00341d7a;
extern undefined4 DAT_00341d88;
extern undefined4 DAT_00341d89;
extern undefined4 DAT_00341d8c;
extern char DAT_002eaa38[];
extern void FUN_000143b0();
extern int FUN_0014c384();
extern void FUN_0014c3ac();
extern int FUN_00193118();
extern void FUN_00194f44();
extern void FUN_001b2430();
extern void FUN_001b47d8();
extern void FUN_001c9e1c();
extern int FUN_0022a930();
extern undefined1 FUN_0022abdc();
extern bool FUN_0022af6c();
extern void FUN_0022c834();

void FUN_001c97b0(int param_1,int param_2,int param_3)
{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  int *piVar14;
  int local_8 [2];
  undefined1 auStack_18 [16];
  
  *(undefined1 *)(param_1 + 0xf9) = 0;
  FUN_001c9e1c();
  puVar7 = (undefined1 *)FUN_00193118(param_1 + 0x104);
  puVar11 = &DAT_00341d10;
  iVar10 = 8;
  puVar12 = puVar7;
  do {
    uVar1 = puVar12[1];
    iVar10 = iVar10 + -1;
    *puVar11 = *puVar12;
    puVar11[1] = uVar1;
    puVar12 = puVar12 + 2;
    puVar11 = puVar11 + 2;
  } while (0 < iVar10);
  DAT_00341d20 = *(undefined2 *)(puVar7 + 0x10);
  puVar11 = puVar7 + 0x12;
  puVar12 = &DAT_00341d22;
  iVar10 = 8;
  do {
    uVar1 = puVar11[1];
    iVar10 = iVar10 + -1;
    *puVar12 = *puVar11;
    puVar12[1] = uVar1;
    puVar11 = puVar11 + 2;
    puVar12 = puVar12 + 2;
  } while (0 < iVar10);
  DAT_00341d32 = *(undefined2 *)(puVar7 + 0x22);
  DAT_00341d34 = *(undefined2 *)(puVar7 + 0x24);
  DAT_00341d36 = puVar7[0x26];
  DAT_00341d37 = puVar7[0x27];
  DAT_00341d38 = puVar7[0x28];
  DAT_00341d39 = puVar7[0x29];
  DAT_00341d3a = puVar7[0x2a];
  DAT_00341d3b = puVar7[0x2b];
  DAT_00341d3c = puVar7[0x2c];
  DAT_00341d3d = puVar7[0x2d];
  DAT_00341d3e = puVar7[0x2e];
  puVar11 = puVar7 + 0x3e;
  DAT_00341d3f = puVar7[0x2f];
  puVar12 = &DAT_00341d4e;
  DAT_00341d40 = puVar7[0x30];
  iVar10 = 8;
  DAT_00341d41 = puVar7[0x31];
  DAT_00341d42 = puVar7[0x32];
  DAT_00341d43 = puVar7[0x33];
  DAT_00341d44 = puVar7[0x34];
  DAT_00341d46 = *(undefined2 *)(puVar7 + 0x36);
  DAT_00341d48 = *(undefined2 *)(puVar7 + 0x38);
  DAT_00341d4a = *(undefined2 *)(puVar7 + 0x3a);
  DAT_00341d4c = *(undefined2 *)(puVar7 + 0x3c);
  do {
    uVar1 = puVar11[1];
    iVar10 = iVar10 + -1;
    *puVar12 = *puVar11;
    puVar12[1] = uVar1;
    puVar11 = puVar11 + 2;
    puVar12 = puVar12 + 2;
  } while (0 < iVar10);
  puVar11 = puVar7 + 0x4e;
  puVar12 = &DAT_00341d5e;
  iVar10 = 8;
  do {
    uVar1 = puVar11[1];
    iVar10 = iVar10 + -1;
    *puVar12 = *puVar11;
    puVar12[1] = uVar1;
    puVar11 = puVar11 + 2;
    puVar12 = puVar12 + 2;
  } while (0 < iVar10);
  DAT_00341d6e = puVar7[0x5e];
  DAT_00341d6f = puVar7[0x5f];
  DAT_00341d70 = puVar7[0x60];
  DAT_00341d72 = *(undefined2 *)(puVar7 + 0x62);
  DAT_00341d74 = *(undefined2 *)(puVar7 + 100);
  DAT_00341d76 = *(undefined2 *)(puVar7 + 0x66);
  DAT_00341d78 = *(undefined2 *)(puVar7 + 0x68);
  DAT_00341d7a = *(undefined2 *)(puVar7 + 0x6a);
  if (*(char *)(param_1 + 0xfd) != '\0') {
    DAT_00341d3c = 0x10;
    *(undefined1 *)(param_1 + 0xfd) = 0;
  }
  FUN_0022c834(param_1 + 0x104);
  iVar10 = FUN_0022a930();
  if (*(int *)(iVar10 + 0xab2c) < 0) {
    iVar10 = FUN_0022a930();
    *(int *)(iVar10 + 0xab30) = (int)*(short *)(puVar7 + 0x36);
    iVar10 = FUN_0022a930();
    *(int *)(iVar10 + 0xab34) = (int)*(short *)(puVar7 + 0x38);
    piVar14 = *(int **)(param_1 + 0x4c);
    if (piVar14 != piVar14 + *(int *)(param_1 + 0x50)) {
      iVar10 = *piVar14;
      do {
        if (iVar10 == 0) {
          iVar10 = *(int *)(param_1 + 0x50);
        }
        else {
          iVar8 = FUN_0022a930();
          if (*(int *)(iVar10 + 0x34) == *(int *)(iVar8 + 0xab30)) {
            uVar13 = *(undefined4 *)(iVar10 + 0x30);
            iVar10 = FUN_0022a930();
            *(undefined4 *)(iVar10 + 0xab2c) = uVar13;
            break;
          }
          iVar10 = *(int *)(param_1 + 0x50);
        }
        piVar14 = piVar14 + 1;
        if (piVar14 == (int *)(*(int *)(param_1 + 0x4c) + iVar10 * 4)) break;
        iVar10 = *piVar14;
      } while( true );
    }
    sVar3 = *(short *)(puVar7 + 0x3a);
  }
  else {
    sVar3 = *(short *)(puVar7 + 0x3a);
  }
  if (sVar3 == -1) {
    iVar10 = FUN_0022a930();
    *(undefined4 *)(iVar10 + 0xab38) = 0xffffffff;
  }
  else {
    sVar4 = *(short *)(puVar7 + 0x38);
    sVar5 = *(short *)(puVar7 + 0x3c);
    sVar6 = *(short *)(puVar7 + 0x36);
    iVar10 = FUN_0022a930();
    if ((int)sVar6 == *(int *)(iVar10 + 0xab30)) {
      iVar10 = FUN_0022a930();
      *(int *)(iVar10 + 0xab38) = (int)sVar3;
      iVar10 = FUN_0022a930();
      *(int *)(iVar10 + 0xab3c) = (int)sVar5;
    }
    else {
      iVar10 = FUN_0022a930();
      *(int *)(iVar10 + 0xab38) = (int)sVar6;
      iVar10 = FUN_0022a930();
      *(int *)(iVar10 + 0xab3c) = (int)sVar4;
    }
  }
  iVar10 = FUN_0022a930();
  *(bool *)(iVar10 + 0xab4f) = puVar7[0x26] == '\x02';
  iVar10 = FUN_0022a930();
  *(bool *)(iVar10 + 0xab50) = puVar7[0x26] == '\x01';
  local_8[0] = 0;
  iVar10 = FUN_0022a930();
  iVar8 = FUN_0022a930();
  DAT_00341d88 = FUN_0022af6c(*(undefined4 *)(iVar8 + 0xab30),*(undefined4 *)(iVar10 + 0xab34));
  iVar10 = FUN_0022a930();
  iVar8 = FUN_0022a930();
  DAT_00341d8c =
       FUN_0022abdc(*(undefined4 *)(iVar8 + 0xab30),*(undefined4 *)(iVar10 + 0xab34),local_8);
  DAT_00341d89 = local_8[0] != 0;
  uVar13 = *(undefined4 *)(DAT_0033b574 + 0x1324);
  puVar9 = (undefined4 *)FUN_0014c384(uVar13,8);
  FUN_0014c3ac(uVar13,0xf,*puVar9);
  uVar13 = 0x25;
  if (param_2 == 0) {
    cVar2 = puVar7[0x28];
    if (cVar2 == '\x05') {
      uVar13 = 0x26;
    }
    else if ((cVar2 == '\x02') || (cVar2 == '\x01')) {
      uVar13 = 0x26;
    }
  }
  else {
    if (param_3 < 0) {
      FUN_00194f44(puVar7,0);
    }
    else {
      FUN_000143b0(auStack_18,DAT_002eaa38,param_3,0);
      FUN_00194f44(puVar7,auStack_18);
    }
    uVar13 = 0x2a;
  }
  FUN_001b47d8(0x34179c);
  FUN_001b2430(0x34179c);
  *(undefined4 *)(param_1 + 0xe4) = uVar13;
  *(undefined4 *)(param_1 + 0xc4) = 4;
  *(undefined4 *)(param_1 + 200) = 0;
  iVar10 = *(int *)(param_1 + 0x15c);
  *(undefined1 *)(iVar10 + 0x90) = 0;
  *(undefined1 *)(iVar10 + 0x91) = 0;
  return;
}
// near miss from lane fm11 (unreviewed)
