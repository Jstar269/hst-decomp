/* HSTMATCH module=EBOOT.BIN start=0x0005c318 end=0x0005c374 symbol=FUN_0005c318 lang=c99 */
/* Clone of src/sharing_main/FUN_0005cfa0.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern float FUN_0000b8a8(float param_1);
extern float FUN_0000c000(float param_1);

float FUN_0005c318(int param_1)
{
  float fVar1;
  
  fVar1 = (float)FUN_0000c000(*(float *)(param_1 + 0x200) * 0.008726646f);
  fVar1 = (float)FUN_0000b8a8(fVar1 * (*(float *)(param_1 + 0x224) / *(float *)(param_1 + 0x220)));
  return fVar1 * 114.59156f;
}
