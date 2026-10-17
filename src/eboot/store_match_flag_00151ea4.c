/* HSTMATCH module=EBOOT.BIN start=0x00151ea4 end=0x00151f24 symbol=FUN_00151ea4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: restored the dropped print arguments (&DAT_002dc608, f12, f8), typed Ctx/Obj views, and the global's field is read into a local before the single-statement store of the comparison (that is what keeps the compare before the call and in the retail load order); exact match verified; names and types await human review. */
typedef struct { char pad[0xec]; int fec; } Ctx;
typedef struct { char pad[8]; int f8; int fc; } Obj;
extern unsigned char DAT_003402f0;
extern Ctx *DAT_0034a114;
extern char DAT_002dc608[];
extern unsigned int *FUN_0014c384(int a, int b);
extern void FUN_0014d044(int *p);
extern void FUN_0014fd94(const char *fmt, int a, int b);

int FUN_00151ea4(Obj *param_1, int *param_2)
{
  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94(DAT_002dc608, param_1->fc, param_1->f8);
  }
  int g = DAT_0034a114->fec;
  *FUN_0014c384(*param_2, param_1->f8) = (param_1->fc == g);
  return 0;
}
