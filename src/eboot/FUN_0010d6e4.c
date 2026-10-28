/* HSTMATCH module=EBOOT.BIN start=0x0010d6e4 end=0x0010d724 symbol=FUN_0010d6e4 lang=c99 */
/* Clone of src/sharing_main/FUN_00113c8c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00102230(float);

void FUN_0010d6e4(float param_1,int param_2)
{
  FUN_00102230((float)(param_1));
  *(float *)(param_2 + 0x148) = param_1 + 0.5f;
}
