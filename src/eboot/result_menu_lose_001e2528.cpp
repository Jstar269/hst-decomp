/* HSTMATCH module=EBOOT.BIN start=0x001e2528 end=0x001e25c0 symbol=FUN_001e2528 lang=c++ data=0x002ec020 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ec020-0x002ec04b) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" void FUN_00104118(int a, const char *b, int c);
extern "C" void FUN_00103540(int a, float x);
extern "C" void FUN_001037c8(int a, int b);
extern "C" void FUN_00216e90(int *a, int b, const void *c, int d);
extern "C" void FUN_00216f14(int *a, int *b, const void *c, int d);
extern "C" void FUN_00103628(int a, int b);
extern "C" void FUN_00217704(int *a, int b);
extern char DAT_002ebc84[];
extern char DAT_002c87bc[];

extern "C" void FUN_001e2528(int param_1)
{
  FUN_00104118(*(int *)(param_1 + 0x250c), "data/menu/result/result_rank/losebglay.lay", 0);
  FUN_00103540(*(int *)(param_1 + 0x250c), 2800.0f);
  FUN_001037c8(*(int *)(param_1 + 0x250c), -266);
  FUN_00216e90((int *)(param_1 + 0x2510), *(int *)(param_1 + 0x250c), DAT_002ebc84, 1);
  FUN_00216f14((int *)(param_1 + 0x2514), (int *)(param_1 + 0x2510), DAT_002c87bc, 1);
  FUN_00103628(*(int *)(param_1 + 0x250c), 1);
  FUN_00217704((int *)(param_1 + 0x252c), *(int *)(param_1 + 0x2510));
}
