/* HSTMATCH module=hstp_trans_main.prx start=0x00200228 end=0x00200290 symbol=FUN_00200228 lang=c99 */
/* Clone of src/eboot/helper_001f1e24.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: materialized the zero-float guard result with a default-true flag; exact match verified; names and types await human review. */
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

extern undefined * DAT_003daec4;
extern void FUN_00202d34();
extern void FUN_002031c4();
extern void FUN_00207bd0();

void FUN_00200228(undefined4 param_1)
{
  int should_call = 1;
  if (*(float *)(DAT_003daec4 + 0xc) != 0.0f) {
    should_call = 0;
  }
  if (should_call != 0) {
    FUN_00207bd0(param_1);
  }
  FUN_002031c4(param_1);
  FUN_00202d34(param_1);
  return;
}
