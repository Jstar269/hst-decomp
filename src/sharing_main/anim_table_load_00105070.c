/* HSTMATCH module=hstp_trans_main.prx start=0x00105070 end=0x00105224 symbol=FUN_00105070 lang=c99 */
/* Clone of src/eboot/anim_table_load_000ff7d8.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: DAT_003e3a1c is an unsigned char (lbu), and iVar6 declared before iVar5 so the loop index gets s1 and the byte offset s0; exact match verified; names and types await human review. */
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

extern unsigned char DAT_003e3a1c;
extern int FUN_00000a90();
extern uint * FUN_000149a8();
extern int * FUN_00065884();
extern int * FUN_000658cc();
extern undefined4 FUN_00065ab8();
extern undefined4 FUN_00065fa4();
extern int FUN_00066038();
extern int FUN_000661a8();

undefined4 FUN_00105070(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  uchar cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar6;
  int iVar5;
  undefined1 auStack_10 [16];
  
  FUN_00065884(auStack_10);
  cVar1 = FUN_00065ab8(auStack_10,param_2,param_3,param_4);
  if (cVar1 == '\0') {
    *param_1 = 0;
    FUN_000658cc(auStack_10,0xffffffff);
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_00065fa4(auStack_10);
    *param_1 = iVar3;
    iVar3 = FUN_00000a90((iVar3 + -1) * 8);
    param_1[1] = iVar3;
    iVar3 = *param_1 + -1;
    iVar6 = 0;
    if (0 < iVar3) {
      iVar5 = 0;
      do {
        uVar2 = FUN_00066038(auStack_10,iVar6 + 1,1);
        *(undefined2 *)(param_1[1] + iVar5) = uVar2;
        uVar2 = FUN_00066038(auStack_10,iVar6 + 1,2);
        *(undefined2 *)(param_1[1] + iVar5 + 2) = uVar2;
        uVar2 = FUN_00066038(auStack_10,iVar6 + 1,3);
        *(undefined2 *)(param_1[1] + iVar5 + 4) = uVar2;
        uVar2 = FUN_00066038(auStack_10,iVar6 + 1,4);
        iVar6 = iVar6 + 1;
        *(undefined2 *)(param_1[1] + iVar5 + 6) = uVar2;
        iVar3 = *param_1 + -1;
        iVar5 = iVar5 + 8;
      } while (iVar6 < iVar3);
    }
    if (DAT_003e3a1c != '\0') {
      iVar3 = FUN_00000a90(iVar3 << 7);
      param_1[2] = iVar3;
      iVar3 = 0;
      if (0 < *param_1 + -1) {
        iVar6 = 0;
        do {
          uVar4 = FUN_000661a8(auStack_10,iVar3 + 1,0);
          FUN_000149a8(param_1[2] + iVar6,uVar4);
          iVar3 = iVar3 + 1;
          iVar6 = iVar6 + 0x80;
        } while (iVar3 < *param_1 + -1);
      }
    }
    FUN_000658cc(auStack_10,0xffffffff);
    uVar4 = 1;
  }
  return uVar4;
}
