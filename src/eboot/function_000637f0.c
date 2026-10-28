/* HSTMATCH module=EBOOT.BIN start=0x000637f0 end=0x00063830 symbol=FUN_000637f0 lang=c99 */
/* Clone of src/sharing_main/function_000646b4.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used unsigned-u8 fields, an int flag accumulator, and a float helper parameter to preserve the retail loads and call; exact match verified; names and types await human review. */

extern void FUN_00063088(float);

void FUN_000637f0(int param_1)
{
  unsigned char *p = (unsigned char *)param_1;
  int bVar1 = p[0x52] != 0;
  if (bVar1)
    bVar1 = (p[0x51] != 0) ^ 1;
  if (bVar1)
    FUN_00063088(*(float *)(p + 0x54));
}
