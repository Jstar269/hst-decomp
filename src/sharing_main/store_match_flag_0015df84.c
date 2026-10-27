/* HSTMATCH module=hstp_trans_main.prx start=0x0015df84 end=0x0015e004 symbol=FUN_0015df84 lang=c99 data=0x00383af0 */
/* Clone of src/eboot/store_match_flag_00151ea4.c (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383af0-0x00383b09) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print arguments (&DAT_00383af0, f12, f8), typed Ctx/Obj views, and the global's field is read into a local before the single-statement store of the comparison (that is what keeps the compare before the call and in the retail load order); exact match verified; names and types await human review. */
typedef struct { char pad[0xec]; int fec; } Ctx;
typedef struct { char pad[8]; int f8; int fc; } Obj;
extern unsigned char DAT_003e9630;
extern Ctx *DAT_003f344c;
extern unsigned int *FUN_00157e10(int a, int b);
extern void FUN_00158b2c(int *p);
extern void FUN_0015bb68(const char *fmt, int a, int b);

int FUN_0015df84(Obj *param_1, int *param_2)
{
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68("AreaInside [%d, reg:%d]\n", param_1->fc, param_1->f8);
  }
  int g = DAT_003f344c->fec;
  *FUN_00157e10(*param_2, param_1->f8) = (param_1->fc == g);
  return 0;
}
