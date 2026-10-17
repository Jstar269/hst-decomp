/* HSTMATCH module=hstp_trans_main.prx start=0x00162070 end=0x001620b8 symbol=FUN_00162070 lang=c99 */
/* Clone of src/eboot/FUN_00155bb0.c (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a byte and the object address Ghidra dropped from the call restored; exact match verified; names and types await human review. */
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

extern undefined DAT_003e9630;
extern undefined DAT_00384054;
extern undefined DAT_003eaad8;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001c20b8();

undefined4 FUN_00162070(undefined4 param_1,int param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(&DAT_00384054);
  }
  FUN_001c20b8((int *)&DAT_003eaad8);
  return 0;
}
