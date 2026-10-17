/* HSTMATCH module=EBOOT.BIN start=0x00127d5c end=0x00127dc4 symbol=FUN_00127d5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag and parameter as unsigned char (lbu/andi), float first argument 0.0f (mtc1 zero) with the pointer in a0 (prototype void(float, void *)); exact match verified; names and types await human review. */
extern void FUN_0005f110(float, void *);

void FUN_00127d5c(char *param_1, unsigned char param_2)
{
  if (param_2 != *(unsigned char *)(param_1 + 0x339)) {
    *(unsigned char *)(param_1 + 0x339) = param_2;
    *(int *)(param_1 + 0x33c) = 0;
    if (((*(unsigned char *)(param_1 + 0x339) == 0) && (*(int *)(param_1 + 0x198) == 0)) &&
       (*(int *)(param_1 + 0x50) != 0)) {
      FUN_0005f110(0.0f, *(void **)(param_1 + 0x50));
      *(int *)(param_1 + 0x198) = 0;
    }
  }
}
