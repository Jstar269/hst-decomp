/* HSTMATCH module=EBOOT.BIN start=0x00204394 end=0x00204400 symbol=FUN_00204394 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: used a typed C++ virtual method call; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined * DAT_0034a148;
extern int * DAT_0034a14c;
extern void FUN_000009e4(void *);
void FUN_00204394(void);
}

struct VC_0 { virtual void m(int); };

extern "C" void FUN_00204394(void)
{
  if (DAT_0034a148 != 0) {
    if (DAT_0034a148 != 0) {
      FUN_000009e4(DAT_0034a148 + -0x10);
    }
    DAT_0034a148 = 0;
  }
  if (DAT_0034a14c != (int *)0x0) {
    if (DAT_0034a14c != (int *)0x0) {
      ((VC_0 *)DAT_0034a14c)->m(1);
    }
    DAT_0034a14c = (int *)0x0;
  }
  return;
}
