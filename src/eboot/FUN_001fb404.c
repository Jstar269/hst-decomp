/* HSTMATCH module=EBOOT.BIN start=0x001fb404 end=0x001fb44c symbol=FUN_001fb404 lang=c99 */
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

void FUN_001fb404(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x12d0) == -1) {
    iVar1 = FUN_001b1c44((int *)&DAT_0034179c,0x10);
    *(int *)(param_1 + 0x12d0) = iVar1;
    *(undefined4 *)(param_1 + 0x12d4) = 0;
  }
  return;
}
