/* HSTMATCH module=hstp_trans_main.prx start=0x00132fcc end=0x00133034 symbol=FUN_00132fcc lang=c99 */
/* Clone of src/eboot/set_flag_release_00127d5c.c (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag and parameter as unsigned char (lbu/andi), float first argument 0.0f (mtc1 zero) with the pointer in a0 (prototype void(float, void *)); exact match verified; names and types await human review. */
extern void FUN_0005ff00(float, void *);

void FUN_00132fcc(char *param_1, unsigned char param_2)
{
  if (param_2 != *(unsigned char *)(param_1 + 0x339)) {
    *(unsigned char *)(param_1 + 0x339) = param_2;
    *(int *)(param_1 + 0x33c) = 0;
    if (((*(unsigned char *)(param_1 + 0x339) == 0) && (*(int *)(param_1 + 0x198) == 0)) &&
       (*(int *)(param_1 + 0x50) != 0)) {
      FUN_0005ff00(0.0f, *(void **)(param_1 + 0x50));
      *(int *)(param_1 + 0x198) = 0;
    }
  }
}
