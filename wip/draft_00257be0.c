/* HSTMATCH module=EBOOT.BIN start=0x00257be0 end=0x00258180 symbol=FUN_00257be0 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002fd6a8;
extern undefined DAT_002fd700;
extern undefined DAT_002fd708;
extern undefined DAT_002fd718;
extern undefined DAT_00309380;
extern undefined DAT_00309968;
extern undefined * DAT_003386c8;
extern undefined * DAT_00338ac4;
extern undefined4 DAT_003415a8;
extern undefined DAT_003417be;
extern undefined4 DAT_0034a678;
extern char DAT_002fd6a0[];
extern char DAT_002fd6ac[];
extern char DAT_002fd6b8[];
extern char DAT_002fd6c0[];
extern char DAT_002fd6c8[];
extern char DAT_002fd6d4[];
extern char DAT_002fd6dc[];
extern char DAT_002fd6e8[];
extern char DAT_002fd6f4[];
extern char DAT_002fd710[];
extern char DAT_002fd720[];
extern char DAT_002fd72c[];
extern char DAT_002fd738[];
extern char DAT_002fd744[];
extern char DAT_002fd750[];
extern char DAT_002fd75c[];
extern char DAT_002fd768[];
extern char DAT_002fd774[];
extern char DAT_002fd780[];
extern char DAT_002fd78c[];
extern char DAT_002fd798[];
extern char DAT_002fd7a4[];
extern char DAT_002fd7b0[];
extern char DAT_002fd7bc[];
extern char DAT_002fd7c8[];
extern char DAT_002fd7d4[];
extern char DAT_002fd7e0[];
extern char DAT_002fd7ec[];
extern char DAT_002fd7f4[];
extern char DAT_002fd7fc[];
extern char DAT_002fd804[];
extern char DAT_002fd810[];
extern void FUN_000007f4(...);
extern int FUN_001026b8(...);
extern undefined4 * FUN_00102e38(...);
extern void FUN_00103480(...);
extern int FUN_001039d8(...);
extern void FUN_00104118(...);
extern void FUN_0010d4a8(...);
extern void FUN_001b2fb8(...);
extern int FUN_00253afc(...);
extern void FUN_00255824(...);
extern void FUN_0008cea4(...);
extern void FUN_0008d72c(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };

extern "C" undefined4 * FUN_00257be0(undefined4 *param_1,undefined4 param_2)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_00102e38();
  *param_1 = (unsigned int)(&DAT_00309380);
  *(undefined1 *)(param_1 + 0x15) = 0;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  param_1[0x16] = 0;
  *param_1 = (unsigned int)(&DAT_00309968);
  FUN_00253afc(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x147) = 1;
  param_1[400] = *(undefined4 *)(DAT_003386c8 + 0x40);
  param_1[0x1ba] = 0;
  FUN_000007f4(param_1 + 0x1bc,FUN_0008cea4,FUN_0008d72c,0x458,4);
  FUN_001b2fb8(0x34179c);
  *(bool *)(param_1 + 0x191) = *(int *)(param_1[400] + 0x5c) == 0;
  if (*(char *)(param_1 + 0x191) == '\0') {
    iVar2 = 4;
  }
  else {
    iVar2 = 2;
  }
  param_1[0x192] = iVar2 + -1;
  FUN_00104118(param_1,param_2,0);
  uVar3 = FUN_001039d8(param_1,DAT_002fd6a0,0);
  param_1[0x194] = uVar3;
  iVar2 = FUN_001039d8(param_1,&DAT_002fd6a8,0);
  param_1[0x195] = iVar2;
  if (iVar2 == 0) {
    uVar3 = FUN_001039d8(param_1,DAT_002fd6ac,0);
    param_1[0x195] = uVar3;
  }
  uVar3 = FUN_001039d8(param_1,DAT_002fd6b8,0);
  param_1[0x196] = uVar3;
  uVar3 = FUN_001039d8(param_1,DAT_002fd6c0,0);
  param_1[0x19f] = uVar3;
  uVar3 = FUN_001039d8(param_1,DAT_002fd6c8,0);
  param_1[0x1a0] = uVar3;
  uVar3 = FUN_001039d8(param_1,DAT_002fd6d4,0);
  param_1[0x1a1] = uVar3;
  uVar3 = FUN_001039d8(param_1,DAT_002fd6dc,0);
  param_1[0x197] = uVar3;
  uVar3 = FUN_001039d8(param_1,DAT_002fd6e8,0);
  param_1[0x19b] = uVar3;
  if (*(char *)(param_1 + 0x191) == '\0') {
    uVar3 = FUN_001039d8(param_1,DAT_002fd6e8,1);
    param_1[0x19c] = uVar3;
    uVar3 = FUN_001039d8(param_1,DAT_002fd6e8,2);
    param_1[0x19d] = uVar3;
    uVar3 = FUN_001039d8(param_1,DAT_002fd6e8,3);
    param_1[0x19e] = uVar3;
    *(undefined4 *)(param_1[0x19c] + 0x60) = 0x42cc0000;
    if (DAT_0034a678 == 0x3e) {
      iVar2 = param_1[0x19d];
    }
    else {
      if (DAT_0034a678 != 0x12) {
        *(undefined4 *)(param_1[0x19d] + 0x60) = 0x43820000;
        *(undefined4 *)(param_1[0x19e] + 0x60) = 0x43b50000;
        goto LAB_00257e5c;
      }
      iVar2 = param_1[0x19d];
    }
    *(undefined4 *)(iVar2 + 0x60) = 0x43750000;
    *(undefined4 *)(param_1[0x19e] + 0x60) = 0x43ad8000;
  }
  else {
    iVar2 = FUN_001039d8(param_1,DAT_002fd6dc,1);
    param_1[0x198] = iVar2;
    *(undefined4 *)(iVar2 + 0x60) = 0x43810000;
  }
LAB_00257e5c:
  FUN_00103480(param_1);
  param_1[0x1a7] = 0;
  param_1[0x1a8] = 0;
  param_1[0x1a9] = 0;
  param_1[0x1aa] = 0;
  if (param_1[0x195] != 0) {
    iVar2 = FUN_001026b8(param_1[0x195],DAT_002fd6f4);
    param_1[0x16] = *(undefined4 *)(iVar2 + 0x20);
    uVar3 = FUN_001026b8(param_1[0x195],&DAT_002fd700);
    param_1[0x1a7] = uVar3;
    iVar2 = FUN_001026b8(param_1[0x195],&DAT_002fd708);
    param_1[0x1a8] = *(undefined4 *)(iVar2 + 0x20);
    uVar3 = FUN_001026b8(param_1[0x195],DAT_002fd710);
    param_1[0x1a9] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x195],&DAT_002fd718);
    param_1[0x1aa] = uVar3;
  }
  param_1[0x1a2] = 0;
  iVar2 = FUN_001026b8(param_1[0x194],DAT_002fd720);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x20);
    param_1[0x1a2] = iVar2;
    *(int *)(iVar2 + 0xf8) = DAT_003415a8 + 0x20;
    *(undefined4 *)(iVar2 + 0x138) = 1;
    FUN_0010d4a8();
    ((VC_0 *)((int *)param_1[0x1a2]))->m((int)(0x80000000));
  }
  uVar3 = param_1[0x194];
  uVar3 = FUN_001026b8(uVar3,DAT_002fd72c);
  param_1[0x1a3] = uVar3;
  uVar3 = FUN_001026b8(param_1[0x194],DAT_002fd738);
  param_1[0x1a4] = uVar3;
  uVar3 = FUN_001026b8(param_1[0x194],DAT_002fd744);
  param_1[0x1a5] = uVar3;
  uVar3 = FUN_001026b8(param_1[0x194],DAT_002fd750);
  param_1[0x1a6] = uVar3;
  FUN_00255824(param_1 + 0x9c,*(undefined1 *)(param_1 + 0x191),param_1 + 0x197,param_1 + 0x19b);
  if (param_1[0x196] == 0) {
    iVar2 = param_1[0x1a0];
  }
  else {
    uVar3 = FUN_001026b8(param_1[0x196],DAT_002fd75c);
    param_1[0x1ab] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x196],DAT_002fd768);
    param_1[0x1ac] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x196],DAT_002fd774);
    param_1[0x1ad] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x196],DAT_002fd780);
    param_1[0x1ae] = uVar3;
    iVar2 = 0;
    if (DAT_003417be == '\0') {
      bVar1 = true;
      if ((DAT_00338ac4 != 0) && (*(char *)(DAT_00338ac4 + 0x178) == '\0')) {
        bVar1 = false;
      }
      if (bVar1) {
        iVar2 = 1;
      }
      else {
        iVar2 = 0;
      }
    }
    iVar4 = FUN_001026b8(param_1[0x196],DAT_002fd78c);
    *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x28) + iVar2;
    uVar3 = FUN_001026b8(param_1[0x196],DAT_002fd798);
    param_1[0x1af] = uVar3;
    iVar2 = param_1[0x1a0];
  }
  if (iVar2 != 0) {
    uVar3 = FUN_001026b8(iVar2,DAT_002fd7a4);
    param_1[0x1b0] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7b0);
    param_1[0x1b1] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7bc);
    param_1[0x1b2] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7c8);
    param_1[0x1b3] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7d4);
    param_1[0x1b4] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7e0);
    param_1[0x1b5] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7ec);
    param_1[0x1b6] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7f4);
    param_1[0x1b7] = uVar3;
    uVar3 = FUN_001026b8(param_1[0x1a0],DAT_002fd7fc);
    param_1[0x1b8] = uVar3;
    param_1[0x1b9] = *(undefined4 *)(param_1[0x1b6] + 0x24);
    iVar2 = FUN_001026b8(param_1[0x1a0],DAT_002fd804);
    iVar4 = *(int *)(iVar2 + 0x24) + 1;
    iVar2 = FUN_001026b8(param_1[0x1a0],DAT_002fd810);
    *(int *)(iVar2 + 0x24) = iVar4;
    *(int *)(iVar2 + 0x28) = iVar4;
  }
  return param_1;
}
// near miss from lane fm11 (unreviewed)
