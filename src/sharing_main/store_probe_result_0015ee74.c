/* HSTMATCH module=hstp_trans_main.prx start=0x0015ee74 end=0x0015eef8 symbol=FUN_0015ee74 lang=c99 data=0x00383bd8 */
/* Clone of src/eboot/store_probe_result_00152cec.c (hstclone.py tag c060607): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383bd8-0x00383be7) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print argument (&DAT_00383bd8, f8), typed Ctx/Obj/Arg views, the callee's bool result kept in an int, and matching idiom: the argument pointer param_2[3] is read through a volatile Arg before *param_2 (that fixes the load order so param_2 and the id share one saved register; plain locals, const, comma sequences and statement permutations all gave a third saved register); exact match verified; names and types await human review. */
typedef struct { char pad[0x1b4]; int f1b4; } Inner;
typedef struct { char pad[0x50]; Inner *f50; } Ctx;
typedef struct { char pad[8]; int f8; } Obj;
typedef struct { int f0; int f4; int f8; int *fc; } Arg;
typedef unsigned char bool;
extern unsigned char DAT_003e9630;
extern Ctx *DAT_003f3450;
extern unsigned int *FUN_00157e10(int a, int b);
extern void FUN_00158b2c(Arg *p);
extern void FUN_0015bb68(const char *fmt, int a);
extern bool FUN_0029a384(int *a, int b);

int FUN_0015ee74(Obj *param_1, Arg *param_2)
{
  int result;
  int id;
  int *fc;

  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68("IsMyBoss [%d]\n", param_1->f8);
  }
  fc = ((volatile Arg *)param_2)->fc;
  id = param_2->f0;
  result = FUN_0029a384(fc, DAT_003f3450->f50->f1b4);
  *FUN_00157e10(id, param_1->f8) = result;
  return 0;
}
