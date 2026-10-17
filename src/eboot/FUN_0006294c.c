/* HSTMATCH module=EBOOT.BIN start=0x0006294c end=0x00062990 symbol=FUN_0006294c lang=c99 */
/* Clone of src/sharing_main/FUN_00063810.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used an early negative return and typed both helper prototypes; exact match verified; names and types await human review. */
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

extern void FUN_00062a44(undefined4, int);
extern void FUN_00076498(int);

void FUN_0006294c(undefined4 param_1,int param_2)
{
  if (param_2 < 0) return;
  FUN_00076498(param_2);
  FUN_00062a44(param_1,param_2);
}
