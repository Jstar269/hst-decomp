/* HSTMATCH module=hstp_trans_main.prx start=0x0022d7d0 end=0x0022d848 symbol=FUN_0022d7d0 lang=c99 */
/* Clone of src/eboot/FUN_0021e25c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00108dac();

void FUN_0022d7d0(float param_1,float param_2,char *param_3)
{
  if (*(float *)(param_3 + 0x1dc) == param_1) {
    if (*(float *)(param_3 + 0x1e0) == param_2) {
      return;
    }
    *(float *)(param_3 + 0x1dc) = param_1;
  }
  else {
    *(float *)(param_3 + 0x1dc) = param_1;
  }
  *(float *)(param_3 + 0x1e0) = param_2;
  *(float *)(*(int *)(param_3 + 0x54) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x54) + 100) = param_2;
  *(float *)(*(int *)(param_3 + 0x58) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x58) + 100) = param_2;
  *(float *)(*(int *)(param_3 + 0x5c) + 0x60) = param_1;
  *(float *)(*(int *)(param_3 + 0x5c) + 100) = param_2;
  FUN_00108dac(param_3);
}
