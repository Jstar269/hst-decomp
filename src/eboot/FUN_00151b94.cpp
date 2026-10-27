/* HSTMATCH module=EBOOT.BIN start=0x00151b94 end=0x00151c80 symbol=FUN_00151b94 lang=c++ data=0x002dc5a8 */
/* Hand-written reconstruction (port of src/sharing_main/FUN_0015dc74_0015dc74.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dc5a8-0x002dc5be) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef unsigned int uint;
extern unsigned char DAT_003402f0;
extern unsigned char DAT_003083cc;
extern unsigned char DAT_00308cc4;
extern unsigned char DAT_0034a2e0;
struct Target {
  virtual ~Target();
  virtual int initialize(float value, int flags);
};
struct Context {
  char padding[8];
  void *context;
};
extern "C" void FUN_0014d044(int value);
extern "C" void FUN_0014fd94(const char *name, void *object);
extern "C" void FUN_0022bf24(void *object, int value);
extern "C" void FUN_00225d40(uint value, void *object, int flag);
extern "C" void *FUN_00000bcc(uint size);
extern "C" Target *FUN_00151b94(Context *param_1, float param_3, int param_2)
{
  Target *object;
  int status;
  float value = param_3;

  if (DAT_003402f0 != 0) {
    FUN_0014d044(param_2);
    FUN_0014fd94("GetEventItem [%d:on]\n", param_1->context);
  }
  FUN_0022bf24(param_1->context, 1);
  FUN_00225d40(*(uint *)&DAT_0034a2e0, param_1->context, 1);
  if ((object = (Target *)FUN_00000bcc(4)) == 0) goto invoke;
  *(void **)object = &DAT_003083cc;
  *(void **)object = &DAT_00308cc4;
invoke:
  status = object->initialize(value, param_2);
  if (status != 0) {
    if (object != 0) delete object;
    return 0;
  }
  return object;
}
