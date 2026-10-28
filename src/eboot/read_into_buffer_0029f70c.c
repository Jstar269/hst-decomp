/* HSTMATCH module=EBOOT.BIN start=0x0029f70c end=0x0029f818 symbol=FUN_0029f70c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct view, the early-return guard written as `if (f10 >= f14) { if (call < 1) { flag = 1; return; } }`, typed prototypes (the two print calls take a format string and a value); exact match verified; names and types await human review. */

typedef struct Obj_0029f70c {
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
} Obj_0029f70c;

extern char DAT_002cba34[];
extern char DAT_002cba4c[];
extern int FUN_000c06dc(int);
extern int FUN_000ff3cc(char *, int);
extern int FUN_000ff3f0(char *, int);
extern int FUN_000ff678(int, char *, int, int);
extern void FUN_0029e3cc(char *, int);

void FUN_0029f70c(Obj_0029f70c *o, int target)
{
  int n;
  int r;

  if (o->f10 >= o->f14) {
    if (FUN_000c06dc(o->f4) < 1) {
      o->f25 = 1;
      return;
    }
  }
  if (o->f10 < target && (n = o->fc) < 0x40000) {
    r = FUN_000ff678(o->f1b4, o->f8 + n, 0x40000 - n, 0);
    o->fc = o->fc + r;
    o->f10 = o->f10 + r;
    if (o->f14 == 0x7fffffff && (r = FUN_000ff3cc(o->f8, o->fc)) >= 0) {
      o->f14 = r;
      o->f18 = FUN_000ff3f0(o->f8, o->fc);
      FUN_0029e3cc(DAT_002cba4c, o->f14);
      FUN_0029e3cc(DAT_002cba34, o->f18);
    }
  }
}
