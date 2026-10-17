/* HSTMATCH module=EBOOT.BIN start=0x000c47a0 end=0x000c482c symbol=FUN_000c47a0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: pass the global pointer to its setter and use the deleting virtual destructor; exact match verified; names and types await human review. */
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
extern int * DAT_00338ac4;
extern void FUN_00000a00(int);
extern undefined4 FUN_000ba504(int);
extern undefined4 FUN_000ba78c(int);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_000c47a0(int param_1)
{
  int iVar1;
  
  if (DAT_00338ac4 != (int *)0x0) {
    FUN_000ba78c((int)DAT_00338ac4);
    FUN_000ba504((int)DAT_00338ac4);
    if (DAT_00338ac4 != (int *)0x0) {
      delete ((VC_0 *)DAT_00338ac4);
      DAT_00338ac4 = (int *)0x0;
    }
  }
  if (*(int *)(param_1 + 0x784) != 0) {
    FUN_00000a00(*(int *)(param_1 + 0x784));
    *(undefined4 *)(param_1 + 0x784) = 0;
  }
  return;
}
