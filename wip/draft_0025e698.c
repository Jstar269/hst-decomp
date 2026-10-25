/* HSTMATCH module=EBOOT.BIN start=0x0025e698 end=0x0025eca0 symbol=FUN_0025e698 lang=c99 */
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

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined4 DAT_002cfc8c;
extern undefined4 DAT_00331b88;
extern undefined4 DAT_003415ac;
extern undefined DAT_003417be;
extern undefined4 DAT_0034a120;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();
extern void FUN_00063d08(undefined4 param_1,float param_2,int param_3,int param_4);
extern void FUN_00103480();
extern void FUN_0010b6d4();
extern void FUN_0010b8cc();
extern void FUN_0010d4a8();
extern void FUN_00114168();
extern undefined1 * FUN_0018c9f4();
extern int FUN_001d9cc4();
extern void FUN_00261884();
extern void FUN_00261a18();
extern void FUN_00261bbc();
extern void FUN_00261d70();
extern void FUN_002a1a64();

void FUN_0025e698(int *param_1,int param_2)
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  undefined *puVar6;
  
  param_1[0x18] = param_2;
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  FUN_0001dfe8(DAT_002cfc8c,0x4000);
  FUN_0001e23c(DAT_002cfc8c,0x4000,1);
  iVar3 = param_1[0x18];
  if (iVar3 == 4) {
    FUN_00063d08(0x477fff00,0x48435000,DAT_00331b88,0xf);
  }
  else if (iVar3 == 3) {
    param_1[0x1a] = 0;
    if ((char)param_1[0x19] == '\0') {
      param_1[0x94] = 0;
    }
    piVar4 = (int *)param_1[0x1d];
    (**(code **)(*piVar4 + 0xc))(piVar4,1);
    (**(code **)(*(int *)param_1[0x1e] + 0xc))((int *)param_1[0x1e],0);
    (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
    iVar3 = param_1[0x16];
    *(undefined4 *)(iVar3 + 0xd8) = 2;
    *(undefined1 *)(iVar3 + 0x114) = 1;
    (**(code **)(*(int *)param_1[0x16] + 0x30))();
    if ((char)param_1[0x19] == '\0') {
      if (param_1[0x38] == 1) {
        FUN_0010b6d4(param_1[0x16],4,9);
      }
      else {
        FUN_0010b6d4(param_1[0x16],3,9);
      }
LAB_0025eacc:
      iVar3 = param_1[0x38];
    }
    else {
      if (*(char *)((int)param_1 + 0x65) == '\0') {
        FUN_0010b6d4(param_1[0x16],8,8);
        goto LAB_0025eacc;
      }
      FUN_0010b6d4(param_1[0x16],4,9);
      iVar3 = param_1[0x38];
    }
    if (iVar3 == 2) {
      DAT_003417be = '\x01';
      if ((char)param_1[0x19] == '\0') {
        iVar3 = param_1[0x16];
        *(undefined4 *)(iVar3 + 0xd8) = 0;
        *(undefined1 *)(iVar3 + 0x114) = 1;
      }
      else {
        iVar3 = param_1[0x16];
        *(undefined4 *)(iVar3 + 0xd8) = 2;
        *(undefined1 *)(iVar3 + 0x114) = 1;
      }
      (**(code **)(*(int *)param_1[0x1c] + 0xc))((int *)param_1[0x1c],1);
      cVar1 = (char)param_1[0x19];
    }
    else {
      DAT_003417be = '\0';
      iVar3 = param_1[0x16];
      *(undefined4 *)(iVar3 + 0xd8) = 2;
      *(undefined1 *)(iVar3 + 0x114) = 1;
      (**(code **)(*(int *)param_1[0x1c] + 0xc))((int *)param_1[0x1c],0);
      cVar1 = (char)param_1[0x19];
    }
    if (cVar1 != '\0') {
      if (*(char *)((int)param_1 + 0x65) != '\0') {
        if (DAT_003417be == '\0') goto LAB_0025ebac;
      }
      iVar3 = param_1[0x16];
      FUN_0010b6d4(iVar3,3,8);
      FUN_0010b8cc(param_1[0x16],0,0);
      (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
    }
LAB_0025ebac:
    bVar5 = DAT_003417be != '\0';
    if (!(bVar5)) {
      bVar5 = (char)param_1[0x19] != '\0';
    }
    piVar4 = (int *)param_1[0x1c];
    (**(code **)(*piVar4 + 0xc))(piVar4,bVar5);
    FUN_00261bbc(param_1 + 0xbc,0);
    FUN_00261bbc(param_1 + 0xbc,1);
    FUN_00261bbc(param_1 + 0xbc,2);
    FUN_00261a18(param_1 + 0xbc,param_1[0x38]);
    if ((char)param_1[0x19] != '\0') {
      iVar3 = 0;
      do {
        FUN_00261d70(param_1 + 0xbc);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0xf);
    }
    FUN_00103480(param_1);
  }
  else if (iVar3 == 1) {
    param_1[0x1a] = 0;
    uVar2 = FUN_001d9cc4(DAT_0034a120);
    FUN_002a1a64(uVar2,0x18);
    iVar3 = param_1[0x16];
    *(undefined4 *)(iVar3 + 0xd8) = 0;
    *(undefined1 *)(iVar3 + 0x114) = 1;
  }
  else if (iVar3 == 2) {
    iVar3 = (int)(FUN_0018c9f4(0x11));
    if (*(int *)(iVar3 + 4) == 0) {
      puVar6 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar3 + 8) + 8) < 0x11) {
      puVar6 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar3 + 0xc) + 0xc4) < 0x14) {
      puVar6 = &DAT_002c0e18;
    }
    else {
      puVar6 = *(undefined **)(*(int *)(*(int *)(iVar3 + 0xc) + 0xc0) + 0x4c);
    }
    FUN_00114168(DAT_003415ac,6,puVar6,0,0);
  }
  else {
    if (iVar3 != 0) {
      iVar3 = param_1[0x18];
      goto LAB_0025ec70;
    }
    (**(code **)(*(int *)param_1[0x1d] + 0xc))((int *)param_1[0x1d],0);
    (**(code **)(*(int *)param_1[0x1e] + 0xc))((int *)param_1[0x1e],1);
    (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
    iVar3 = param_1[0x16];
    *(undefined4 *)(iVar3 + 0xd8) = 2;
    *(undefined1 *)(iVar3 + 0x114) = 1;
    (**(code **)(*(int *)param_1[0x16] + 0x30))();
    FUN_0010b6d4(param_1[0x16],0,2);
    iVar3 = param_1[0x16];
    *(undefined4 *)(iVar3 + 0xd8) = 2;
    *(undefined1 *)(iVar3 + 0x114) = 1;
    FUN_0010b8cc(param_1[0x16],param_1[0x174],0);
    (**(code **)(*(int *)param_1[0x1c] + 0xc))((int *)param_1[0x1c],1);
    iVar3 = (int)(FUN_0018c9f4(0x13));
    if (*(int *)(iVar3 + 4) == 0) {
      puVar6 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar3 + 8) + 8) < 8) {
      puVar6 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar3 + 0xc) + 0x58) < 1) {
      puVar6 = &DAT_002c0e18;
    }
    else {
      puVar6 = (undefined *)**(undefined4 **)(*(int *)(iVar3 + 0xc) + 0x54);
    }
    iVar3 = param_1[0x2b];
    *(undefined **)(iVar3 + 0xf8) = puVar6;
    *(undefined4 *)(iVar3 + 0x138) = 0;
    FUN_0010d4a8();
    iVar3 = (int)(FUN_0018c9f4(0x13));
    if (*(int *)(iVar3 + 4) == 0) {
      puVar6 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar3 + 8) + 8) < 8) {
      puVar6 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar3 + 0xc) + 0x58) < 2) {
      puVar6 = &DAT_002c0e18;
    }
    else {
      puVar6 = *(undefined **)(*(int *)(*(int *)(iVar3 + 0xc) + 0x54) + 4);
    }
    iVar3 = param_1[0x2d];
    *(undefined **)(iVar3 + 0xf8) = puVar6;
    *(undefined4 *)(iVar3 + 0x138) = 0;
    FUN_0010d4a8();
    iVar3 = (int)(FUN_0018c9f4(0x13));
    if (*(int *)(iVar3 + 4) == 0) {
      puVar6 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar3 + 8) + 8) < 8) {
      puVar6 = &DAT_002c0e1c;
    }
    else if (*(int *)(*(int *)(iVar3 + 0xc) + 0x58) < 3) {
      puVar6 = &DAT_002c0e18;
    }
    else {
      puVar6 = *(undefined **)(*(int *)(*(int *)(iVar3 + 0xc) + 0x54) + 8);
    }
    iVar3 = param_1[0x2f];
    *(undefined **)(iVar3 + 0xf8) = puVar6;
    *(undefined4 *)(iVar3 + 0x138) = 0;
    FUN_0010d4a8();
    FUN_00261884(param_1 + 0xbc);
    FUN_00103480(param_1);
  }
  iVar3 = param_1[0x18];
LAB_0025ec70:
  if (iVar3 != 4) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return;
}
// near miss from lane fm11 (unreviewed)
