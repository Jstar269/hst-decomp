/* HSTMATCH module=hstp_trans_main.prx start=0x0008eadc end=0x0008ebd0 symbol=FUN_0008eadc lang=c99 */
/* Clone of src/eboot/record_init_0008d388.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed 0xffff as unsigned short vs -1 signed short; exact match verified; names and types await human review. */

extern void *FUN_000114c0(void *p, int c, unsigned n);
extern void FUN_000dbb60(void *p);

short *FUN_0008eadc(short *param_1, short param_2, short param_3, short param_4, short param_5, short param_6, short param_7)
{
  FUN_000114c0(param_1, 0, 0x9c);
  ((unsigned short *)param_1)[0x11] = 0xffff;
  ((unsigned short *)param_1)[0x10] = 0xffff;
  param_1[0] = -1;
  param_1[1] = -1;
  param_1[2] = -1;
  param_1[3] = -1;
  param_1[4] = -1;
  param_1[5] = -1;
  param_1[0x3d] = -1;
  *(char *)(param_1 + 0x2a) = 0x2d;
  *(char *)((char *)param_1 + 0x55) = 0x31;
  *(char *)((char *)param_1 + 0x56) = 0;
  *(char *)(param_1 + 0x34) = 0x2d;
  *(char *)((char *)param_1 + 0x69) = 0x31;
  *(char *)((char *)param_1 + 0x6a) = 0;
  FUN_000114c0(param_1, 0, 200);
  param_1[0] = param_2;
  param_1[1] = param_3;
  param_1[2] = param_4;
  param_1[3] = param_5;
  param_1[4] = param_6;
  param_1[5] = param_7;
  FUN_000dbb60(param_1);
  return param_1;
}
