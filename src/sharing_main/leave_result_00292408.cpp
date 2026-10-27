/* HSTMATCH module=hstp_trans_main.prx start=0x00292408 end=0x002924a0 symbol=FUN_00292408 lang=c++ */
/* Hand-written reconstruction from the disassembly (same source as the EBOOT twin src/eboot/leave_result_00281090.cpp, addresses substituted); exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };
extern "C" void FUN_000bdad0(GObj *p);
extern "C" void FUN_000bd848(GObj *p);
extern "C" void FUN_00108f54(void *a, int b);
struct Tag {};
extern "C" void FUN_00121330(void *a, int b, Tag c);
extern GObj *DAT_003e1e04;
extern char *DAT_003ea8ec;

extern "C" void FUN_00292408(int param_1)
{
  *(char *)(param_1 + 0x2c00) = 0;
  if (DAT_003e1e04 != 0) {
    FUN_000bdad0(DAT_003e1e04);
    FUN_000bd848(DAT_003e1e04);
    if (DAT_003e1e04 != 0) {
      delete DAT_003e1e04;
      DAT_003e1e04 = 0;
    }
  }
  FUN_00108f54(DAT_003ea8ec, 1);
  FUN_00121330(DAT_003ea8ec + 0x8c, *(int *)(DAT_003ea8ec + 0x90), Tag());
}
