/* HSTMATCH module=hstp_trans_main.prx start=0x001606a4 end=0x00160718 symbol=FUN_001606a4 lang=c99 */
/* Clone of src/eboot/bump_counter_store_0015435c.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: flag global is unsigned char (lbu), global base typed as a struct pointer, counter+1 computed into a local before the lookup call; exact match verified; names and types await human review. */
typedef struct G { char pad[0xd0]; int cnt; } G;
extern unsigned char DAT_003e9630;
extern G *DAT_003f344c;
extern char DAT_00383d9c[];
extern int *FUN_00157e10(int, int);
extern void FUN_00158b2c(int *);
extern void FUN_0015bb68(char *, int);

int FUN_001606a4(char *param_1, int *param_2)
{
  int n;
  int *p;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68(DAT_00383d9c, *(int *)(param_1 + 8));
  }
  n = DAT_003f344c->cnt + 1;
  p = FUN_00157e10(*param_2, *(int *)(param_1 + 8));
  *p = n;
  return 0;
}
