/* HSTMATCH module=EBOOT.BIN start=0x00228be4 end=0x00228c7c symbol=FUN_00228be4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
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

extern void FUN_0005f1e8();

void FUN_00228be4(int param_1)
{
  int iVar1;
  
  if ((*(uchar *)(param_1 + 0x435) != '\0') && (*(uchar *)(param_1 + 0x436) != '\0')) {
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 == 1) {
      FUN_0005f1e8(param_1 + 0xb0,0);
    }
    else if ((iVar1 == 2) || (iVar1 == 4)) {
      FUN_0005f1e8(param_1 + 0xb0,0);
    }
    else if ((iVar1 == 3) || (iVar1 == 5)) {
      FUN_0005f1e8(param_1 + 0x260,0);
    }
  }
  return;
}
