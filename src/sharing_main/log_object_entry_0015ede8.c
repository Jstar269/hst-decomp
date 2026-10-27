/* HSTMATCH module=hstp_trans_main.prx start=0x0015ede8 end=0x0015ee74 symbol=FUN_0015ede8 lang=c99 */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin src/eboot/log_object_entry_00152c60.c, Sharing addresses substituted: DAT_003e9630 log flag, FUN_00158b2c, FUN_0015bb68 print, FUN_00157ec0); exact match verified; names and types await human review. */
extern unsigned char DAT_003e9630;
extern char DAT_00383a64;
extern char DAT_00383a68;
extern char DAT_00383bc0[]; /* "SetActiveArea[%d:%s]\n" */
extern void FUN_00157ec0(int, int, unsigned char);
extern void FUN_00158b2c(void *);
extern void FUN_0015bb68(char *, int, char *);

int FUN_0015ede8(char *param_1, int *param_2)
{
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383bc0, *(int *)(param_1 + 8),
                 *(unsigned char *)(param_1 + 0xc) != 0 ? &DAT_00383a64 : &DAT_00383a68);
  }
  FUN_00157ec0(*param_2, *(int *)(param_1 + 8), (*(unsigned char *)(param_1 + 0xc) != 0) ^ 1);
  return 0;
}
