/* HSTMATCH module=hstp_trans_main.prx start=0x000f3ab0 end=0x000f3b14 symbol=FUN_000f3ab0 lang=c99 */
/* Clone of src/eboot/float_table_lookup_000ee3e8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the six float constants as one float[6] local (retail frame, lw of the int-typed return); exact match verified; names and types await human review. */
typedef unsigned char byte;
typedef unsigned int undefined4;

extern float DAT_0037da7c;
extern float DAT_0037da80;
extern float DAT_0037da84;
extern float DAT_0037da88;
extern float DAT_0037da8c;
extern float DAT_0037da90;

undefined4 FUN_000f3ab0(int param_1)
{
  float local[6];
  local[0] = DAT_0037da7c;
  local[1] = DAT_0037da80;
  local[2] = DAT_0037da84;
  local[3] = DAT_0037da88;
  local[4] = DAT_0037da8c;
  local[5] = DAT_0037da90;
  return *(undefined4 *)&local[*(byte *)(param_1 + 0x65)];
}
