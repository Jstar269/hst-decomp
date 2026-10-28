/* HSTMATCH module=hstp_trans_main.prx start=0x0015dc74 end=0x0015dd60 symbol=FUN_0015dc74 lang=c++ data=0x00383a90 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383a90-0x00383aa6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
extern unsigned char DAT_003e9630;
extern unsigned char DAT_003b1698;
extern unsigned char DAT_003b1f90;
extern unsigned char DAT_003f3610;
struct Target {
  virtual ~Target();
  virtual int initialize(float value, int flags);
};
struct Context {
  char padding[8];
  void *context;
};
extern "C" void FUN_00158b2c(int value);
extern "C" void FUN_0015bb68(const char *name, void *object);
extern "C" void FUN_0023b950(void *object, int value);
extern "C" void FUN_002352b4(u32 value, void *object, int flag);
extern "C" void *FUN_00000bcc(u32 size);
extern "C" Target *FUN_0015dc74(Context *param_1, float param_3, int param_2)
{
  Target *object;
  int status;
  float value = param_3;

  if (DAT_003e9630 != 0) {
    FUN_00158b2c(param_2);
    FUN_0015bb68("GetEventItem [%d:on]\n", param_1->context);
  }
  FUN_0023b950(param_1->context, 1);
  FUN_002352b4(*(u32 *)&DAT_003f3610, param_1->context, 1);
  if ((object = (Target *)FUN_00000bcc(4)) == 0) goto invoke;
  *(void **)object = &DAT_003b1698;
  *(void **)object = &DAT_003b1f90;
invoke:
  status = object->initialize(value, param_2);
  if (status != 0) {
    if (object != 0) delete object;
    return 0;
  }
  return object;
}
