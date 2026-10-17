/* HSTMATCH module=hstp_trans_main.prx start=0x00057fa0 end=0x00057ff4 symbol=FUN_00057fa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: typed the two members, nested the duplicated null test around delete[] (matching idiom: if (p) { if (p) delete[] p; p = 0; }); exact match verified; names and types await human review. */
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

extern void FUN_000009e4();
extern undefined4 * FUN_00056de8();

typedef struct Obj {
  char pad[0x168];
  void *sub;
  char *buf;
} Obj;

void FUN_00057fa0(Obj *o)
{
  char *p;

  p = o->buf;
  if (p != 0) {
    if (p != 0) {
      FUN_000009e4(p - 0x10);
    }
    o->buf = 0;
  }
  if (o->sub != 0) {
    FUN_00056de8(o->sub,1);
    o->sub = 0;
  }
  return;
}
