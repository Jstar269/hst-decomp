/* HSTMATCH module=hstp_trans_main.prx start=0x00207b70 end=0x00207bd0 symbol=FUN_00207b70 lang=c99 */
/* Clone of src/eboot/FUN_001f94b8.c (hstclone.py tag s10171846c1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed float and pointer arguments and replaced the numeric address with DAT_003eaad8; exact match verified; names and types await human review. */
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

extern undefined4 DAT_003daec4;
extern undefined4 DAT_003eaad8;
extern void FUN_000647e0(float,undefined4,int);
extern void FUN_001c2130(float,undefined4 *);
extern void FUN_0020a040();

void FUN_00207b70(int param_1)
{
  FUN_000647e0(65535.0f,DAT_003daec4,0xf);
  FUN_001c2130(0.5f,&DAT_003eaad8);
  FUN_0020a040(param_1 + 0x3c,0x11,1);
  return;
}
