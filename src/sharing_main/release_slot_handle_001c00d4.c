/* HSTMATCH module=hstp_trans_main.prx start=0x001c00d4 end=0x001c01a0 symbol=FUN_001c00d4 lang=c99 */
/* Clone of src/eboot/release_slot_handle_001b2040.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: float first parameter, dropped call arguments restored (pointer pair to the first callee, handle to the second, item/handle to the release call), typed object, flag with else arm and the index re-read through an identical struct type (see 0x1b3e2c, 0x1b1f84); exact match verified; names and types await human review. */
typedef struct O2 { int tab[0x1eb]; int f7ac; int f7b0; } O2;
typedef struct O {
  int tab[0x1eb];
  int f7ac;
  int f7b0;
} O;
extern void FUN_00063810(float, int, int);
extern void FUN_000638c8(float, int);
extern int FUN_001c04cc(O **, int *);

int FUN_001c00d4(float f, O **pp, int *pv)
{
  O *o;
  int ok;
  if (FUN_001c04cc(pp, pv) == 0) return 0;
  o = *pp;
  if (*pv == o->f7ac) {
    ok = o->f7b0 < 0x1da;
    if (ok) ok = o->tab[o->f7b0] != 0; else ok = o->f7b0 < 0x1da;
    if (ok) {
      if (o->f7ac >= 0) {
        FUN_00063810(f, o->tab[((O2 *)o)->f7b0], o->f7ac);
        o->f7ac = -1;
      }
      o->f7b0 = 0x1da;
    }
  } else {
    FUN_000638c8(f, *pv);
  }
  *pv = -1;
  return 1;
}
