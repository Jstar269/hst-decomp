/* HSTMATCH module=EBOOT.BIN start=0x0017168c end=0x00171714 symbol=FUN_0017168c lang=c99 */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); matching idiom: reuse total for total < 5 so MWCC branches on the comparison result register; exact match verified; names and types await human review. */
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

extern void FUN_001b1f84(void *, int *);
extern undefined4 FUN_001b2bb8();
extern undefined DAT_0034179c;

struct Self {
  char pad0[0x588];
  int x588;
  int x58c;
  int x590;
  int x594;
  int x598;
  char pad1[0x98];
  int handle;
};

void FUN_0017168c(struct Self *param_1)
{
  undefined4 uVar1;

  int total = 0;
  total += param_1->x588;
  total += param_1->x58c;
  total += param_1->x590;
  total += param_1->x594;
  total += param_1->x598;
  if ((total = (total < 5))) {
  }
  else {
    if (param_1->handle >= 0) {
      FUN_001b1f84(&DAT_0034179c,&param_1->handle);
    }
    uVar1 = FUN_001b2bb8(&DAT_0034179c,0x58);
    param_1->handle = uVar1;
  }
  return;
}
