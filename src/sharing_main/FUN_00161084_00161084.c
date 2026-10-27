/* HSTMATCH module=hstp_trans_main.prx start=0x00161084 end=0x001610e8 symbol=FUN_00161084 lang=c99 data=0x00383eb8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383eb8-0x00383ed0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { char pad[8]; float value; } ValueObject;
extern u32 DAT_003e48b4;
extern u8 DAT_003e9630;
extern long long FUN_00020f84(float);
extern void FUN_00138d68(int, float);
extern void FUN_00158b2c(int);
extern void FUN_0015bb68(const char *, ...);
int FUN_00161084(ValueObject *param_1, int param_2)
{
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68("Ground Tex Anim [%.0f]\n", FUN_00020f84(param_1->value));
  }
  FUN_00138d68((int)DAT_003e48b4, param_1->value);
  return 0;
}
