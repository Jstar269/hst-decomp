/* HSTMATCH module=hstp_trans_main.prx start=0x00196c40 end=0x00196cec symbol=FUN_00196c40 lang=c99 */
/* Clone of src/eboot/FUN_0018a4f4_0018a4f4.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00226564(void *);

void FUN_00196c40(int param_1, int *param_2)
{
  int count;
  int i;

  FUN_00226564((char *)param_1 + 0xd0);
  i = 0;
  if (0 < *(int *)(param_1 + 0x104)) {
    do {
      if (*param_2 != 0) {
        int x = *(int *)(param_1 + 0xe4) + param_2[2];
        int y = *(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xec) + param_2[3];
        *(short *)(*param_2 + 4) = x;
        *(short *)(*param_2 + 8) = x + *(int *)(param_1 + 0xdc);
        *(short *)(*param_2 + 6) = y;
        *(short *)(*param_2 + 10) = y + *(int *)(param_1 + 0xe0);
      }
      count = *(int *)(param_1 + 0x104);
      ++i;
      param_2 += 5;
    } while (i < count);
  }
}
