/* HSTMATCH module=hstp_trans_main.prx start=0x000dfc24 end=0x000dfc74 symbol=FUN_000dfc24 lang=c99 */
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

typedef struct Target { char pad[0x144]; int f144; } Target;
typedef struct Table { char pad[0x70]; Target *items[1]; } Table;
typedef struct Obj { char pad[0x61]; uchar f61; char pad2[0x36]; int idx; int f9c; } Obj;
extern Table *DAT_003e19f0;

int FUN_000dfc24(Obj *o)
{
  int r;
  if (o->f61 != 0 && o->idx >= 0 && o->f9c != DAT_003e19f0->items[o->idx]->f144) {
    r = 1;
  } else {
    r = 0;
  }
  return r;
}
