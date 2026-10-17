/* HSTMATCH module=hstp_trans_main.prx start=0x000bc794 end=0x000bc7fc symbol=FUN_000bc794 lang=c99 */
/* Clone of src/eboot/open_check_file_000b9450.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the sign test written as >= 0 (bltzl); exact match verified; names and types await human review. */
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

extern undefined DAT_0037b0cc;
extern char DAT_0037b308[];
extern void FUN_000143b0();
extern int FUN_0004cfac();
extern undefined4 FUN_0004d2c4();
extern void FUN_0004d31c();

void FUN_000bc794(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  undefined1 auStack_100 [256];
  
  FUN_000143b0(auStack_100,DAT_0037b308,param_2);
  iVar1 = FUN_0004cfac(auStack_100,1,1);
  if (iVar1 >= 0) {
    FUN_0004d31c(iVar1,&DAT_0037b0cc,0x120);
    FUN_0004d2c4(iVar1);
  }
  return;
}
