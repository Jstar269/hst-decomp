/* HSTMATCH module=EBOOT.BIN start=0x001e521c end=0x001e532c symbol=FUN_001e521c lang=c99 */
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

typedef struct Sub_001e521c {
  char pad[0x20];
  int color;
  char pad2[0x8c - 0x24];
} Sub_001e521c;

typedef struct Obj_001e521c {
  char pad0[0x270];
  int f270;
  char pad1[0x438 - 0x274];
  unsigned char f438;
  char pad2[0x4c8 - 0x439];
  Sub_001e521c sub[4];
} Obj_001e521c;

extern char DAT_002ec180[];
extern float FUN_000657e4(int, char *, int);
extern void FUN_000ffb3c(int, int);
extern int FUN_001ee224();
extern void FUN_0021780c(void *, int, float, float);
extern void FUN_00217834(void *, int, int, int);

void FUN_001e521c(Obj_001e521c *o)
{
  int c;
  float f;

  o->f438 = 1;
  c = o->sub[0].color;
  f = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&o->sub[0], c, -1, (int)f);
  c = o->sub[2].color;
  f = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&o->sub[2], c, -1, (int)f);
  c = o->sub[1].color;
  f = FUN_000657e4(FUN_001ee224(), DAT_002ec180, 1);
  FUN_00217834(&o->sub[1], c, -1, (int)f);
  FUN_000ffb3c(o->f270, 0);
  FUN_0021780c(&o->sub[3], 0x19, 1.0f, 2.0f);
  FUN_00217834(&o->sub[3], -1, o->sub[3].color & 0xffffff, 0x19);
}
