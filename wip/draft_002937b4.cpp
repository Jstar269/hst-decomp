/* HSTMATCH module=EBOOT.BIN start=0x002937b4 end=0x0029398c symbol=FUN_002937b4 lang=c++ */
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
extern void FUN_00055044(...);
extern void FUN_0005743c(...);
extern undefined4 FUN_0005787c(...);
extern undefined1 FUN_00057b58(...);
extern void FUN_00057f30(...);
extern void FUN_00058ec4(...);
extern void FUN_00058f38(...);
extern void FUN_00059084(...);
extern void FUN_0005f110(...);
extern undefined4 * FUN_00093818(...);
extern int * FUN_00288a84(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

extern "C" void FUN_002937b4(int param_1,undefined4 param_2)
{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_4;
  undefined4 local_8;
  undefined4 local_c;
  undefined4 local_10;
  undefined4 local_14;
  undefined4 local_18;
  undefined4 local_1c;
  undefined4 local_20;
  undefined4 local_24;
  undefined4 local_28;
  undefined4 local_2c;
  undefined4 local_30;
  undefined4 local_34;
  undefined4 local_38;
  undefined4 local_3c;
  undefined4 local_40;
  
  piVar5 = *(int **)(param_1 + 0x7c);
  if (piVar5 != (int *)0x0) {
    iVar2 = ((VC_0 *)(piVar5))->m();
    bVar1 = iVar2 == 2;
    if (!bVar1) {
      iVar2 = ((VC_1 *)(piVar5))->m();
      bVar1 = iVar2 == 3;
    }
    if (bVar1) {
      iVar2 = (int)(FUN_00288a84(*(undefined4 *)(param_1 + 0x7c)));
      iVar7 = *(int *)(iVar2 + 0x58);
      puVar3 = (undefined4 *)FUN_00093818(iVar2);
      local_40 = *puVar3;
      local_3c = puVar3[1];
      local_38 = puVar3[2];
      local_34 = puVar3[3];
      local_30 = puVar3[4];
      local_2c = puVar3[5];
      local_28 = puVar3[6];
      local_24 = puVar3[7];
      local_20 = puVar3[8];
      local_1c = puVar3[9];
      local_18 = puVar3[10];
      local_14 = puVar3[0xb];
      local_10 = puVar3[0xc];
      local_c = puVar3[0xd];
      local_8 = puVar3[0xe];
      local_4 = puVar3[0xf];
      if (*(undefined4 **)(iVar7 + 0xf4) == (undefined4 *)0x0) {
        uVar6 = 0;
      }
      else {
        uVar6 = **(undefined4 **)(iVar7 + 0xf4);
      }
      if (*(int *)(iVar7 + 0x110) < 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x78);
      }
      else {
        uVar6 = FUN_0005787c(iVar7);
        uVar4 = *(undefined4 *)(param_1 + 0x78);
      }
      FUN_00057f30(uVar4,0);
      FUN_00055044(*(undefined4 *)(param_1 + 0x78),&local_40);
      FUN_0005743c(*(undefined4 *)(param_1 + 0x78),param_2,uVar6,0);
      FUN_00057b58(0,*(undefined4 *)(param_1 + 0x78),0,param_2);
      uVar6 = *(undefined4 *)(param_1 + 0x78);
      FUN_00058f38(0,uVar6,0xffffffff);
      FUN_0005f110(0,uVar6);
      iVar2 = *(int *)(param_1 + 0x78);
      FUN_00058ec4(0x3f800000,iVar2,0xffffffff);
      *(undefined4 *)(iVar2 + 0xc4) = 0x3f800000;
      iVar2 = *(int *)(param_1 + 0x78);
      FUN_00059084(iVar2,0xffffffff);
      *(undefined4 *)(iVar2 + 0xd0) = *(undefined4 *)(iVar2 + 0xc4);
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
