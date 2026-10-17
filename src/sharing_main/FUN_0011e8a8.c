/* HSTMATCH module=hstp_trans_main.prx start=0x0011e8a8 end=0x0011e940 symbol=FUN_0011e8a8 lang=c99 */
/* Clone of src/eboot/FUN_001140d0.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the this argument Ghidra dropped from the base constructor call restored; exact match verified; names and types await human review. */
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

extern undefined DAT_002cc260;
extern undefined DAT_003b0a68;
extern undefined DAT_003b0cd4;
extern undefined4 FUN_00056cac();
extern undefined4 * FUN_001016c0();
extern undefined4 * FUN_00101748();
extern undefined4 * FUN_001017dc();

undefined4 * FUN_0011e8a8(undefined4 *param_1,undefined4 param_2)
{
  FUN_001017dc(param_1);
  FUN_00056cac(param_1 + 0xc);
  *param_1 = (unsigned int)(&DAT_003b0a68);
  param_1[0x1c] = 0;
  param_1[0x1d] = 0xffffffff;
  param_1[0x1e] = 0x3f800000;
  param_1[0x1f] = 0x3f800000;
  FUN_00056cac(param_1 + 0x20);
  param_1[0x30] = param_2;
  FUN_00101748(param_1,&DAT_002cc260);
  FUN_001016c0(param_1 + 0x20,&DAT_002cc260);
  *param_1 = (unsigned int)(&DAT_003b0cd4);
  return param_1;
}
