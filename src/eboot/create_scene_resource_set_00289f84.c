/* HSTMATCH module=EBOOT.BIN start=0x00289f84 end=0x0028a230 symbol=FUN_00289f84 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: allocation failure labels, cleanup returns, and final string selection were matched to retail; exact match verified; names and types await human review. */
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

extern char DAT_002fec24[];
extern char DAT_002fec48[];
extern char DAT_002fec60[];
extern char DAT_002fec6c[];
extern char DAT_002fec94[];
extern char DAT_002fecbc[];
extern char DAT_002fece8[];
extern char DAT_002fed14[];
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern void FUN_000143b0();
extern int FUN_00053670();
extern int FUN_00053718();
extern undefined4 FUN_00055df8();

int * FUN_00289f84(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  undefined1 auStack_100 [256];
  undefined1 auStack_200 [256];
  undefined1 auStack_300 [256];
  undefined1 auStack_400 [256];
  undefined1 auStack_500 [256];
  
  piVar1 = (int *)FUN_00000bcc(0x10);
  if (piVar1 != (int *)0x0) {
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
  }
  FUN_000143b0(auStack_100,DAT_002fec24,param_2,param_4,param_3,
               param_4);
  FUN_000143b0(auStack_400,DAT_002fec48,param_2);
  iVar2 = FUN_00000bcc(0x30);
  if (iVar2 == 0) goto first_allocation_failed;
  iVar2 = FUN_00053670(iVar2,auStack_100,auStack_400,0,0,0,3);
  *piVar1 = iVar2;
  goto first_allocation_done;
first_allocation_failed:
  *piVar1 = iVar2;
first_allocation_done:
  ;
  if (*(int *)(iVar2 + 8) == 0) {
    if (iVar2 != 0) {
      FUN_00053718(iVar2,1);
      *piVar1 = 0;
    }
    if (piVar1 == (int *)0x0) goto cleanup_done;
    FUN_00000a00(piVar1);
    piVar1 = (int *)0x0;
cleanup_done:
    return piVar1;
  }
  else {
    FUN_000143b0(auStack_500,DAT_002fec60,param_2);
    FUN_000143b0(auStack_100,DAT_002fec6c,param_2,param_4,param_3,
                 param_4);
    FUN_000143b0(auStack_200,DAT_002fec94,param_2,param_4,param_3,
                 param_4);
    iVar2 = FUN_00000bcc(0x30);
    if (iVar2 == 0) goto allocation_one_failed;
    iVar2 = FUN_00053670(iVar2,auStack_100,auStack_500,auStack_200,auStack_500,0,0);
    piVar1[1] = iVar2;
    goto allocation_one_done;
allocation_one_failed:
    piVar1[1] = iVar2;
allocation_one_done:
    ;
    if (*(int *)(iVar2 + 8) == 0) {
      if (iVar2 == 0) goto second_destroy_done;
      FUN_00053718(iVar2,1);
      piVar1[1] = 0;
    }
second_destroy_done:
    ;
    FUN_000143b0(auStack_100,DAT_002fecbc,param_2,param_4,param_3,
                 param_4);
    iVar2 = FUN_00000bcc(0x30);
    if (iVar2 == 0) goto allocation_two_failed;
    iVar2 = FUN_00053670(iVar2,auStack_100,auStack_400,0,0,0,0);
    piVar1[2] = iVar2;
    goto allocation_two_done;
allocation_two_failed:
    piVar1[2] = iVar2;
allocation_two_done:
    ;
    if (*(int *)(iVar2 + 8) == 0) {
      if (iVar2 != 0) {
        FUN_00053718(iVar2,1);
        piVar1[2] = 0;
      }
    }
    iVar2 = piVar1[2];
    if (iVar2 != 0) {
      FUN_000143b0(auStack_300,DAT_002fece8,param_2,param_4,param_3,
                   param_4);
    }
    else {
      FUN_000143b0(auStack_300,DAT_002fed14,param_2,param_4,param_3,
                   param_4);
    }
    iVar2 = FUN_00000bcc(0x10);
    if (iVar2 == 0) goto allocation_three_failed;
    iVar2 = FUN_00055df8(iVar2,auStack_300,0);
    piVar1[3] = iVar2;
    goto allocation_three_done;
allocation_three_failed:
    piVar1[3] = iVar2;
allocation_three_done:
    ;
  }
  return piVar1;
}
