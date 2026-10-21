/* HSTMATCH module=hstp_trans_main.prx start=0x0004f7ec end=0x0004f864 symbol=FUN_0004f7ec lang=c99 */
/* Clone of src/eboot/deleting_dtor_0004ef98.c (hstclone.py tag c21rt1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Sharing twin's near-miss wip (lane u1r2-0, Ghidra pseudocode) retargeted to EBOOT and corrected by hand: object typed as a char pointer so the 0x1a0a8 sub-object offset is pointer arithmetic (lui/ori at); exact match verified; names and types await human review. */
extern unsigned char DAT_003d4570;
extern void FUN_00000a00(void *);
extern void FUN_00050c4c(void);
extern void FUN_000517e8(void *, int);

void *FUN_0004f7ec(char *self, short flag)
{
  char *p;

  if (self != 0) {
    DAT_003d4570 = 0;
    FUN_00050c4c();
    p = self + 0x1a0a8;
    if (p != 0 && p != 0) {
      FUN_000517e8(p, 0);
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
