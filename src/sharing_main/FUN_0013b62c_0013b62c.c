/* HSTMATCH module=hstp_trans_main.prx start=0x0013b62c end=0x0013b72c symbol=FUN_0013b62c lang=c99 */
/* Clone of src/eboot/FUN_00130074_00130074.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: ordered result tests; exact match verified; names and types await human review. */
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

extern char DAT_00382190[];
extern char DAT_0038219c[];
extern char DAT_00382228[];
extern char DAT_00382274[];
extern char DAT_0038227c[];
extern char DAT_00382288[];
extern char DAT_00382294[];
extern char * FUN_00014d64();

undefined4 FUN_0013b62c(undefined4 param_1,int param_2)
{
  int result = 0;
  if (param_2 == 0) result = 0;
  else if (FUN_00014d64(param_2,DAT_00382274) != 0) result = 1;
  else if (FUN_00014d64(param_2,DAT_0038227c) != 0) result = 2;
  else if (FUN_00014d64(param_2,DAT_00382190) != 0) result = 3;
  else if (FUN_00014d64(param_2,DAT_00382288) != 0) result = 4;
  else if (FUN_00014d64(param_2,DAT_0038219c) != 0) result = 5;
  else if (FUN_00014d64(param_2,DAT_00382294) != 0) result = 6;
  else if (FUN_00014d64(param_2,DAT_00382228) != 0) result = 7;
  return result;
}
