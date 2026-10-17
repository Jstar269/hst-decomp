/* HSTMATCH module=EBOOT.BIN start=0x0005743c end=0x000574c4 symbol=FUN_0005743c lang=c99 */
/* Clone of src/sharing_main/alloc_construct_dispatch_00058090.c (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2, variant v0c) corrected by hand: branch polarity inverted (param_3 != 0 first), inline new/ctor allocation; exact match verified; names and types await human review. */
extern void *FUN_00000bcc(int);
extern void *FUN_00056198(void *, int);
extern void FUN_000574c4(int, int, void *, int);

void FUN_0005743c(int param_1, int param_2, int param_3, int param_4)
{
  if (param_3 != 0) {
    void *p = FUN_00000bcc(16);
    if (p != 0) {
      p = FUN_00056198(p, param_3);
    }
    FUN_000574c4(param_1, param_2, p, param_4);
  } else {
    FUN_000574c4(param_1, param_2, 0, param_4);
  }
}
