/* HSTMATCH module=EBOOT.BIN start=0x00280ff0 end=0x00281064 symbol=FUN_00280ff0 lang=c99 */
typedef unsigned int undefined4;
extern undefined4 DAT_00338ac4;
extern char DAT_002fe91c[];
extern void FUN_000bd924(undefined4, void (*)(void));
extern void FUN_002803d8(char *);
extern void FUN_00280830(void *, int, int);
extern void FUN_002b7898(void *);
extern void FUN_002807d0(void);
void FUN_00280ff0(unsigned char *param_1, int param_2)
{
  if (param_1[0x2c00] != 0) {
    FUN_002803d8(DAT_002fe91c);
    return;
  }
  FUN_00280830(param_1, 3, 0);
  FUN_002b7898(param_1 + 0x10);
  *(int *)(param_1 + 4) = param_2;
  FUN_000bd924(DAT_00338ac4, FUN_002807d0);
}
// Best candidate is six words from retail: lbu/branch use v0 instead of v1; the 0x10 receiver addiu is in the jal delay slot; final global/callback argument setup order differs.
// Ruled out: free C and C++ member-method forms produced the same six-word mismatch.
// near miss from lane u6cr4-1 (unreviewed)
