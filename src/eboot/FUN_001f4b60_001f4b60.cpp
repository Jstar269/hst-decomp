/* HSTMATCH module=EBOOT.BIN start=0x001f4b60 end=0x001f4bbc symbol=FUN_001f4b60 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed the walking object cursor and the integer argument to its virtual method; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined4 DAT_00338714;
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void m(int); };

extern "C" void FUN_001f4b60(int param_1)
{
  int *piVar1;
  int iVar2;
  int *cursor;
  
  iVar2 = 0;
  cursor = (int *)param_1;
  do {
    piVar1 = *(int **)((int)cursor + 0x3a0);
    if (piVar1 != (int *)0x0) {
      ((VC_0 *)(piVar1))->m((int)(DAT_00338714));
    }
    iVar2 = iVar2 + 1;
    cursor = (int *)((int)cursor + 4);
  } while (iVar2 < 4);
  return;
}
