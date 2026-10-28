/* HSTMATCH module=hstp_trans_main.prx start=0x001a8688 end=0x001a86fc symbol=FUN_001a8688 lang=c99 */
/* Clone of src/eboot/FUN_002a22d8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

void FUN_001a8688(float param_1,float param_2,int param_3)
{
  *(short *)(param_3 + 4) = (short)(int)((float)(int)*(short *)(param_3 + 4) * param_1);
  *(short *)(param_3 + 8) = (short)(int)((float)(int)*(short *)(param_3 + 8) * param_1);
  *(short *)(param_3 + 6) = (short)(int)((float)(int)*(short *)(param_3 + 6) * param_2);
  *(short *)(param_3 + 10) = (short)(int)((float)(int)*(short *)(param_3 + 10) * param_2);
}
