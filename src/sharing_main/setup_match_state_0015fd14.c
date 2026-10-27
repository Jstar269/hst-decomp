/* HSTMATCH module=hstp_trans_main.prx start=0x0015fd14 end=0x0015fe00 symbol=FUN_0015fd14 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/setup_match_state_00153aac.c: global and callee addresses substituted); exact match verified; names and types await human review. */
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003eb0b8;
extern char DAT_00383cb0[];
extern char DAT_00383cd0[];
extern char DAT_00383918[];
extern char DAT_00383928[];
extern int DAT_003f344c;
extern void FUN_000143b0(char *, char *, int);
extern void FUN_00158b2c(void *);
extern void FUN_0015bb68(char *, int, char *);
extern void FUN_001daeb8(int, char *);
extern void FUN_001db0d0(int, int, int, int, int);

int FUN_0015fd14(char *param_1, char *param_2)
{
  char buf[32];
  int b;

  FUN_000143b0(buf, DAT_00383cb0, *(int *)(param_1 + 8));
  FUN_001daeb8(DAT_003f344c, buf);
  DAT_003eb0b8 = *(int *)(param_1 + 0xc) == 1;
  b = *(int *)(param_1 + 0x10) == 1;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383cd0, *(int *)(param_1 + 0xc), b ? DAT_00383918 : DAT_00383928);
  }
  FUN_001db0d0(DAT_003f344c, *(int *)(param_1 + 0xc) == 2, 1, *(int *)(param_1 + 0x14), b);
  *(char *)(*(int *)(param_2 + 0xc) + 0x59) = 1;
  *(char *)(param_2 + 0x10) = 1;
  return 0;
}
