/* HSTMATCH module=EBOOT.BIN start=0x00291298 end=0x00291338 symbol=FUN_00291298 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed object struct with the two flag bytes and two pointers, the first `if` kept as a nested test with a re-read flag, and the dropped argument of FUN_00051450 (the +0x30 member, loaded into a0) restored; exact match verified; names and types await human review. */
extern void FUN_0028fb70(void *);
extern void *FUN_00051450(void *);
extern void FUN_00022a48(void *, void *, int);
extern void FUN_002b79f0(int);
extern unsigned char DAT_0034a80c;

typedef struct Obj {
  char pad0[0x28];
  unsigned char f28;
  unsigned char f29;
  char pad1[2];
  void *f2c;
  void *f30;
} Obj;

void FUN_00291298(Obj **pp)
{
  Obj *o = *pp;
  if (o->f28 != 0) {
    if (DAT_0034a80c != 0) {
      FUN_0028fb70(o);
    }
  }
  if (o->f28 != 0 && o->f30 != 0 && o->f2c != 0 && o->f29 != 0) {
    FUN_00022a48(FUN_00051450(o->f30), o->f2c, 0x88000);
    FUN_002b79f0(6);
  }
}
