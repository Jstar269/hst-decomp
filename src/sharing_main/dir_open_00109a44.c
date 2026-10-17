/* HSTMATCH module=hstp_trans_main.prx start=0x00109a44 end=0x00109b08 symbol=FUN_00109a44 lang=c99 */
/* Clone of src/eboot/dir_open_00104118.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: constructed object kept as a pointer and passed on (null stays null, no zero-extend through uint); exact match verified; names and types await human review. */
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

extern undefined DAT_0037f7fc;
extern char DAT_0037fa34[];
extern void * FUN_00000bcc();
extern uint * FUN_000149a8();
extern int FUN_00014cfc();
extern int * FUN_00065884();
extern undefined4 FUN_00065ab8();
extern undefined4 FUN_00065fa4();
extern void FUN_0010532c();
extern void FUN_00109b20();

void FUN_00109a44(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int *mem;
  undefined1 auStack_100 [256];
  
  mem = (int *)FUN_00000bcc(0x10);
  if (mem != 0) {
    mem = FUN_00065884(mem);
  }
  *(int **)(param_1 + 0x1c) = mem;
  FUN_00065ab8(mem,param_2,1,&DAT_0037f7fc);
  iVar1 = FUN_00065fa4(*(undefined4 *)(param_1 + 0x1c));
  if (iVar1 < 1) {
    FUN_0010532c(DAT_0037fa34,param_2);
  }
  else {
    FUN_000149a8(auStack_100,param_2);
    iVar1 = FUN_00014cfc(auStack_100,0x2f);
    *(undefined1 *)(iVar1 + 1) = 0;
    *(undefined1 **)(param_1 + 0x20) = auStack_100;
    FUN_00109b20(param_1,param_2,param_3);
  }
  return;
}
