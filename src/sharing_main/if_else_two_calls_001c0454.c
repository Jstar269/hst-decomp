/* HSTMATCH module=hstp_trans_main.prx start=0x001c0454 end=0x001c04c4 symbol=FUN_001c0454 lang=c99 */
/* Clone of src/eboot/if_else_two_calls_001b23c0.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: swapped if/else order (param_2 != 0 first); exact match verified; names and types await human review. */
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

extern void FUN_00063190();

void FUN_001c0454(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00063190(3,0x40,0x40,0xf);
    FUN_00063190(2,0,0,3);
  }
  else {
    FUN_00063190(3,0x80,0x80,0xf);
    FUN_00063190(2,0x80,0x80,3);
  }
  return;
}
