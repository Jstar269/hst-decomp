/* HSTMATCH module=EBOOT.BIN start=0x0004ef98 end=0x0004f010 symbol=FUN_0004ef98 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Sharing twin's near-miss wip (lane u1r2-0, Ghidra pseudocode) retargeted to EBOOT and corrected by hand: object typed as a char pointer so the 0x1a0a8 sub-object offset is pointer arithmetic (lui/ori at); exact match verified; names and types await human review. */
extern unsigned char DAT_0032b230;
extern void FUN_00000a00(void *);
extern void FUN_00050370(void);
extern void FUN_00050ed4(void *, int);

/* Deleting destructor: clears a global byte, calls FUN_00050370, destroys the sub-object at +0x1a0a8 and frees self when delete_flag is positive. */
void *FUN_0004ef98(char *self, short delete_flag)
{
  char *sub;

  if (self != 0) {
    DAT_0032b230 = 0;
    FUN_00050370();
    sub = self + 0x1a0a8;
    if (sub != 0 && sub != 0) {
      FUN_00050ed4(sub, 0);
    }
    if (delete_flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
