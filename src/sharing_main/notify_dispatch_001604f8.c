/* HSTMATCH module=hstp_trans_main.prx start=0x001604f8 end=0x00160550 symbol=FUN_001604f8 lang=c99 */
/* Clone of src/eboot/notify_dispatch_001541b0.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003e9630 is an unsigned char flag (lbu); exact match verified; names and types await human review. */
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
extern char DAT_00383d58[];
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001d6284();

undefined4 FUN_001604f8(int param_1,undefined4 param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383d58,*(undefined4 *)(param_1 + 8));
  }
  FUN_001d6284(DAT_003f344c,*(undefined4 *)(param_1 + 8));
  return 0;
}
