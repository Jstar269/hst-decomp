/* HSTMATCH module=hstp_trans_main.prx start=0x001f077c end=0x001f0814 symbol=FUN_001f077c lang=c++ data=0x00393f38 */
/* Clone of src/eboot/result_menu_lose_001e2528.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00393f38-0x00393f63) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00109a44(int a, const char *b, int c);
extern "C" void FUN_00108e6c(int a, float x);
extern "C" void FUN_001090f4(int a, int b);
extern "C" void FUN_00225e94(int *a, int b, const void *c, int d);
extern "C" void FUN_00225f18(int *a, int *b, const void *c, int d);
extern "C" void FUN_00108f54(int a, int b);
extern "C" void FUN_002267ac(int *a, int b);
extern char DAT_00393b90[];
extern char DAT_002d8bfc[];

extern "C" void FUN_001f077c(int param_1)
{
  FUN_00109a44(*(int *)(param_1 + 0x250c), "data/menu/result/result_rank/losebglay.lay", 0);
  FUN_00108e6c(*(int *)(param_1 + 0x250c), 2800.0f);
  FUN_001090f4(*(int *)(param_1 + 0x250c), -266);
  FUN_00225e94((int *)(param_1 + 0x2510), *(int *)(param_1 + 0x250c), DAT_00393b90, 1);
  FUN_00225f18((int *)(param_1 + 0x2514), (int *)(param_1 + 0x2510), DAT_002d8bfc, 1);
  FUN_00108f54(*(int *)(param_1 + 0x250c), 1);
  FUN_002267ac((int *)(param_1 + 0x252c), *(int *)(param_1 + 0x2510));
}
