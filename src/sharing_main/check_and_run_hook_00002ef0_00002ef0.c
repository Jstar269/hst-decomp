/* HSTMATCH module=hstp_trans_main.prx start=0x00002ef0 end=0x00002f30 symbol=FUN_00002ef0 lang=c99 */
/* Clone of src/eboot/check_and_run_hook_00002ef0.c (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Asks the global at +0x2c8fdc whether the argument is acceptable and, if so, runs the hook at +0xc of
   the object; the result of that hook is the return value, otherwise 0.
   Matching idioms: the "return 0" of the other arm is copied into the branch-likely delay slot, so the
   hook's own result stays in v0. Names provisional. */
extern int FUN_00002f38(void *, void *);
extern void *FUN_00002f30(void *);
extern char DAT_002c8fdc[];

void *FUN_00002ef0(void *self, void *arg)
{
  if (FUN_00002f38(arg, DAT_002c8fdc) != 0) {
    return FUN_00002f30((char *)self + 12);
  }
  return 0;
}
