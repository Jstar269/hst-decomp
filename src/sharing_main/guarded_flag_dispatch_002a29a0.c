/* HSTMATCH module=hstp_trans_main.prx start=0x002a29a0 end=0x002a2a40 symbol=FUN_002a29a0 lang=c99 */
/* Clone of src/eboot/guarded_flag_dispatch_00291298.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed object struct with the two flag bytes and two pointers, the first `if` kept as a nested test with a re-read flag, and the dropped argument of FUN_00051df0 (the +0x30 member, loaded into a0) restored; exact match verified; names and types await human review. */
extern void FUN_002a1338(void *);
extern void *FUN_00051df0(void *);
extern void FUN_00022a70(void *, void *, int);
extern void FUN_002c7790(int);
extern unsigned char DAT_003f3b3c;

typedef struct Obj {
  char pad0[0x28];
  unsigned char f28;
  unsigned char f29;
  char pad1[2];
  void *f2c;
  void *f30;
} Obj;

void FUN_002a29a0(Obj **pp)
{
  Obj *o = *pp;
  if (o->f28 != 0) {
    if (DAT_003f3b3c != 0) {
      FUN_002a1338(o);
    }
  }
  if (o->f28 != 0 && o->f30 != 0 && o->f2c != 0 && o->f29 != 0) {
    FUN_00022a70(FUN_00051df0(o->f30), o->f2c, 0x88000);
    FUN_002c7790(6);
  }
}
