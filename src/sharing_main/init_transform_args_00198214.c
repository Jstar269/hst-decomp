/* HSTMATCH module=hstp_trans_main.prx start=0x00198214 end=0x0019825c symbol=FUN_00198214 lang=c99 */
/* Clone of src/eboot/init_transform_args_0018ba64.c (hstclone.py tag fm2od3): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_00198514(int);
extern int DAT_003ea86c;

void FUN_00198214(float p1, float p2, float p3, char *self, int p5, int p6, int p7, int p8, float *p9)
{
  *(int *)(self + 0x40) = p5;
  *(int *)(self + 0x50) = p6;
  *(int *)(self + 0x54) = p7;
  *(int *)(self + 0x58) = p8;
  *(float *)(self + 0x70) = p1;
  *(float *)(self + 0x74) = p2;
  *(float *)(self + 0x78) = p3;
  *(float *)(self + 0x60) = p9[0];
  *(float *)(self + 0x64) = p9[1];
  *(float *)(self + 0x68) = p9[2];
  *(float *)(self + 0x6c) = p9[3];
  FUN_00198514(DAT_003ea86c);
}
