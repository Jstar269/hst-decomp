/* HSTMATCH module=EBOOT.BIN start=0x000ee3e8 end=0x000ee44c symbol=FUN_000ee3e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the six float constants as one float[6] local (retail frame, lw of the int-typed return); exact match verified; names and types await human review. */
typedef unsigned char byte;
typedef unsigned int undefined4;

extern float DAT_002d6ca4;
extern float DAT_002d6ca8;
extern float DAT_002d6cac;
extern float DAT_002d6cb0;
extern float DAT_002d6cb4;
extern float DAT_002d6cb8;

undefined4 FUN_000ee3e8(int param_1)
{
  float local[6];
  local[0] = DAT_002d6ca4;
  local[1] = DAT_002d6ca8;
  local[2] = DAT_002d6cac;
  local[3] = DAT_002d6cb0;
  local[4] = DAT_002d6cb4;
  local[5] = DAT_002d6cb8;
  return *(undefined4 *)&local[*(byte *)(param_1 + 0x65)];
}
