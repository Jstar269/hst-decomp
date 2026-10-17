/* HSTMATCH module=EBOOT.BIN start=0x002a23d8 end=0x002a2434 symbol=FUN_002a23d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
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

extern undefined DAT_0034179c;
extern int FUN_001b1c44();
extern void FUN_002a1f60();

void FUN_002a23d8(int param_1)
{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x1b0) == 5) && (piVar1 = *(int **)(param_1 + 0x1d0), *piVar1 == 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,0xf);
    FUN_002a1f60(piVar1,2);
  }
  return;
}
