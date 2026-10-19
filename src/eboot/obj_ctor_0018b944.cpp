/* HSTMATCH module=EBOOT.BIN start=0x0018b944 end=0x0018b9e0 symbol=FUN_0018b944 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_0001f06c(void *p);
extern "C" void FUN_0018c4dc(void *p);
extern "C" void FUN_0018b850();
extern "C" void FUN_0018b810();
extern "C" void FUN_0018b82c();
extern char DAT_0030915c[];
extern void *DAT_0034152c;

extern "C" int *FUN_0018b944(int *param_1, int param_2, int param_3)
{
  FUN_0001f06c(param_1);
  *param_1 = (int)DAT_0030915c;
  DAT_0034152c = param_1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  *(char *)((char *)param_1 + 0x44) = 0;
  *(char *)((char *)param_1 + 0x45) = 0;
  param_1[0xf] = 0;
  param_1[0x12] = param_2;
  param_1[0x13] = param_3;
  FUN_0018c4dc(param_1);
  param_1[0x1f] = (int)FUN_0018b850;
  param_1[0x20] = (int)FUN_0018b810;
  param_1[0x21] = (int)FUN_0018b82c;
  return param_1;
}
