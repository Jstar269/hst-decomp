/* HSTMATCH module=hstp_trans_main.prx start=0x0015e86c end=0x0015e8f0 symbol=FUN_0015e86c lang=c99 */
/* Clone of src/eboot/dispatch_id_range_001526e4.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is unsigned char (lbu) and the if/else tests iVar1 >= 10000 first; exact match verified; names and types await human review. */
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

extern unsigned char DAT_003e9630;
extern undefined4 DAT_003f344c;
extern char DAT_00383b5c[];
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001dbb1c();
extern void FUN_001dbb6c();

undefined4 FUN_0015e86c(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383b5c,*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc));
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 >= 10000) {
    FUN_001dbb1c(DAT_003f344c,iVar1 + -10000,*(undefined4 *)(param_1 + 0xc));
  }
  else {
    FUN_001dbb6c(DAT_003f344c,iVar1,*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}
