/* HSTMATCH module=EBOOT.BIN start=0x000d4758 end=0x000d4918 symbol=FUN_000d4758 lang=c99 */
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

extern undefined4 DAT_002d5ab0;
extern undefined4 DAT_003386b0;
extern int FUN_00000bcc();
extern void FUN_0001f21c();
extern void FUN_00051398();
extern void FUN_000513a0();
extern void FUN_00055240();
extern undefined4 FUN_000b3490();
extern undefined4 FUN_000b34d0();
extern undefined4 * FUN_000ea41c();

void FUN_000d4758(int param_1,int param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 auStack_10 [4];
  undefined4 auStack_40 [12];
  undefined4 auStack_50 [4];
  undefined4 auStack_80 [12];
  undefined4 auStack_90 [4];
  undefined4 auStack_c0 [12];
  undefined4 auStack_d0 [4];
  undefined4 auStack_100 [12];
  undefined4 auStack_110 [4];
  undefined4 auStack_140 [12];
  undefined4 auStack_150 [4];
  undefined4 auStack_180 [12];
  undefined4 auStack_190 [4];
  undefined4 auStack_1c0 [12];
  
  FUN_000513a0(**(int **)(param_1 + 0x3c),1);
  FUN_00051398(0x4541d000,**(int **)(param_1 + 0x3c));
  piVar3 = (int *)(*(int *)(param_1 + 0x48) + param_2 * 0x20);
  piVar2 = (int *)piVar3[7];
  if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
    if (piVar2 == (int *)0x0) {
      piVar3[7] = 0;
    }
    else {
      (**(code **)(*piVar2 + 8))(piVar2,1);
      piVar3[7] = 0;
    }
  }
  iVar6 = *(int *)(param_2 * 4 + DAT_003386b0 + 0x70);
  iVar4 = *(int *)(iVar6 + 0x5bc);
  if (((DAT_002d5ab0 & 0x1000) != 0) &&
     ((iVar6 = FUN_000b3490(iVar6), iVar6 != 0 || (iVar6 = FUN_000b34d0(), iVar6 != 0)))) {
    puVar1 = (undefined4 *)FUN_00000bcc(0x11e0);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      piVar2 = *(int **)(iVar4 + 0x58);
      puVar5 = *(undefined4 **)(param_1 + 0x3c);
      FUN_00055240(auStack_1c0,piVar2,*piVar3);
      FUN_00055240(auStack_180,piVar2,piVar3[1]);
      FUN_00055240(auStack_140,piVar2,piVar3[2]);
      FUN_00055240(auStack_100,piVar2,piVar3[3]);
      FUN_00055240(auStack_c0,piVar2,piVar3[4]);
      FUN_00055240(auStack_80,piVar2,piVar3[5]);
      FUN_00055240(auStack_40,piVar2,piVar3[6]);
      puVar1 = FUN_000ea41c(puVar1,*puVar5,auStack_190,auStack_150,auStack_110,auStack_d0,auStack_90
                            ,auStack_50,auStack_10);
    }
    piVar3[7] = (int)puVar1;
    FUN_0001f21c(param_1,(int)puVar1);
  }
  return;
}
// near miss from lane km4 (unreviewed)
