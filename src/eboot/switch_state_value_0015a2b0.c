/* HSTMATCH module=EBOOT.BIN start=0x0015a2b0 end=0x0015a304 symbol=FUN_0015a2b0 lang=c99 rodata=0x002c1cd8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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


struct S
{
  char pad[0x14];
  int f14;
  char pad2[0x20 - 0x18];
  int f20;
};

void FUN_0015a2b0(struct S *p, int v)
{
  p->f14 = v;
  switch(v) {
  case 0:
  case 1:
    p->f20 = 0;
    p->f14 = 2;
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    p->f14 = 8;
    break;
  case 6:
    break;
  case 7:
    p->f14 = 8;
    break;
  }
}
