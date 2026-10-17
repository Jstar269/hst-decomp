/* HSTMATCH module=hstp_trans_main.prx start=0x001108a4 end=0x001109a8 symbol=FUN_001108a4 lang=c99 */
/* Clone of src/eboot/init_0010aae4.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. */
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

extern char DAT_0037fe88[];
extern uint * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_00110268(const char *, ...);
extern void FUN_001a5d44();
extern int FUN_002c79b0();

int FUN_001108a4(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,0x590);
  *param_1 = 0x590;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_001a5d44(param_1);
  param_1[0xc] = 1;
  FUN_00014b74(param_1 + 0xd,*param_2,0xc);
  *(undefined1 *)(param_1 + 0x10) = 0;
  FUN_00014b74(param_1 + 0x11,param_2[1],0x13);
  *(undefined1 *)((int)param_1 + 0x57) = 0;
  FUN_00014b74(param_1 + 0x16,param_2[2],0x7f);
  *(undefined1 *)((int)param_1 + 0xd7) = 0;
  FUN_00014b74(param_1 + 0x36,param_2[3],0x7f);
  *(undefined1 *)((int)param_1 + 0x157) = 0;
  FUN_00014b74(param_1 + 0x56,param_2[4],0x3ff);
  *(undefined1 *)((int)param_1 + 0x557) = 0;
  *(undefined1 *)(param_1 + 0x156) = *(undefined1 *)(param_2 + 5);
  iVar1 = FUN_002c79b0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00110268(DAT_0037fe88,iVar1);
  }
  return iVar1;
}
