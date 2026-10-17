/* HSTMATCH module=EBOOT.BIN start=0x000478d4 end=0x00047920 symbol=FUN_000478d4 lang=c99 */
/* Clone of src/sharing_main/FUN_00047d58.c (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: the byte flag and int store typed, `if (param_2 != 0)` call arm first, the store of param_1 shared after the if/else; exact match verified; names and types await human review. */
extern unsigned char DAT_002d0224;
extern int DAT_00310fd8;
extern void FUN_00048258(void);

void FUN_000478d4(int param_1,int param_2)
{
  if (param_1 >= 0) {
    if (param_2 != 0) {
      FUN_00048258();
    }
    else {
      DAT_002d0224 = 0;
    }
    DAT_00310fd8 = param_1;
  }
}
