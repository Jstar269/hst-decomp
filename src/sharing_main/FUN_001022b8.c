/* HSTMATCH module=hstp_trans_main.prx start=0x001022b8 end=0x00102320 symbol=FUN_001022b8 lang=c99 */
/* Clone of src/eboot/FUN_000fcb7c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q3) corrected by hand: the object typed unsigned char * and the tested member passed to the free call (Ghidra dropped the argument); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_000104e0();

unsigned char * FUN_001022b8(unsigned char *param_1,short param_2)
{
  if (param_1 != (unsigned char *)0x0) {
    if ((*param_1 != '\0') && (*(int *)(param_1 + 4) != 0)) {
      FUN_000104e0(*(int *)(param_1 + 4));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
