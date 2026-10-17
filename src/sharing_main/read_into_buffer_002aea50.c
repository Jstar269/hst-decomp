/* HSTMATCH module=hstp_trans_main.prx start=0x002aea50 end=0x002aeb5c symbol=FUN_002aea50 lang=c99 */
/* Clone of src/eboot/read_into_buffer_0029f70c.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct view, the early-return guard written as `if (f10 >= f14) { if (call < 1) { flag = 1; return; } }`, typed prototypes (the two print calls take a format string and a value); exact match verified; names and types await human review. */
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

typedef struct Obj_002aea50 {
  int f0;
  int f4;
  char *f8;
  int fc;
  int f10;
  int f14;
  int f18;
  char pad1c[9];
  unsigned char f25;
  char pad26[0x1b4 - 0x26];
  int f1b4;
} Obj_002aea50;

extern char DAT_002dbad4[];
extern char DAT_002dbaec[];
extern int FUN_000c3d7c(int);
extern int FUN_00104c64(char *, int);
extern int FUN_00104c88(char *, int);
extern int FUN_00104f10(int, char *, int, int);
extern void FUN_002ad710(char *, int);

void FUN_002aea50(Obj_002aea50 *o, int target)
{
  int n;
  int r;

  if (o->f10 >= o->f14) {
    if (FUN_000c3d7c(o->f4) < 1) {
      o->f25 = 1;
      return;
    }
  }
  if (o->f10 < target && (n = o->fc) < 0x40000) {
    r = FUN_00104f10(o->f1b4, o->f8 + n, 0x40000 - n, 0);
    o->fc = o->fc + r;
    o->f10 = o->f10 + r;
    if (o->f14 == 0x7fffffff && (r = FUN_00104c64(o->f8, o->fc)) >= 0) {
      o->f14 = r;
      o->f18 = FUN_00104c88(o->f8, o->fc);
      FUN_002ad710(DAT_002dbaec, o->f14);
      FUN_002ad710(DAT_002dbad4, o->f18);
    }
  }
}
