/* HSTMATCH module=EBOOT.BIN start=0x00057bc0 end=0x00057c60 symbol=FUN_00057bc0 lang=c99 */
/* Clone of src/sharing_main/function_00058814.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the third float and separated the indexed row base from its +0xf0 state; exact match verified; names and types await human review. */

void FUN_00057bc0(float param_1,float param_2,float param_3,int param_4,int param_5,int param_6 )
{
  char *base;
  char *record;
  float *pfVar2;
  float local_4;
  float local_8;
  
  base = (char *)param_4 + param_5 * 0x34;
  record = base + 0xf0;
  local_8 = param_1;
  local_4 = param_2;
  if (*(int *)(base + 0x110) != param_6) {
    *(int *)(record + 0x20) = param_6;
    if (param_6 >= 0) {
      if (param_6 < *(int *)(param_4 + 0xe4)) {
        *(int *)(record + 0x24) = *(int *)(*(int *)(param_4 + 0xe0) + param_6 * 4);
      } else {
        *(int *)(record + 0x24) = 0;
      }
    }
    else {
      *(int *)(record + 0x24) = 0;
    }
    *(float *)(record + 0x28) = local_8;
    if (local_4 < local_8) {
      pfVar2 = &local_8;
    }
    else {
      pfVar2 = &local_4;
    }
    *(float *)(record + 0x2c) = *pfVar2;
    *(float *)(record + 0x30) = param_3;
  }
}
