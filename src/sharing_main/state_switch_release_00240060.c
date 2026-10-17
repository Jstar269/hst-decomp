/* HSTMATCH module=hstp_trans_main.prx start=0x00240060 end=0x002400e4 symbol=FUN_00240060 lang=c99 */
/* Clone of src/eboot/state_switch_release_0022ff60.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed object struct, if/else-if on the state field rewritten as a switch (cases written 3 then 4, MWCC tests them in reverse), dropped `this` argument of the case-3 callee restored; exact match verified; names and types await human review. */
extern int FUN_001c0018(void *, int *);
extern void FUN_0023d77c(void *);
extern void FUN_0023de04(void *);
extern char DAT_003eaad8;

typedef struct Obj {
  char pad0[0xac];
  int fac;
  int fb0;
  char pad1[0x414 - 0xb4];
  int state;
} Obj;

void FUN_00240060(Obj *self)
{
  switch (self->state) {
  case 3:
    FUN_0023de04(self);
    break;
  case 4:
    if (self->fb0 >= 0) {
      FUN_001c0018(&DAT_003eaad8, &self->fb0);
      self->fb0 = -1;
    }
    self->fac = -1;
    FUN_0023d77c(self);
    break;
  }
}
