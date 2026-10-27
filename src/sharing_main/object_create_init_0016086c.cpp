/* HSTMATCH module=hstp_trans_main.prx start=0x0016086c end=0x001609a0 symbol=FUN_0016086c lang=c++ data=0x00383dc8 */
/* Hand-written reconstruction from the disassembly (modelled on the matched factory siblings device_create_init_0015c510 and FUN_00161ec8); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00383dc8-0x00383de6) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Debug trace when enabled, reset the existing target for context->id through its slot-8 virtual, then (only when
   context->enable is set) build an 8-byte object (base vtable 0x3b1698, then 0x3b1b70; id copied), run its
   slot-1 initializer and delete it again on failure. The enabled test must enclose the build: an early
   `if (!enable) return 0;` gives bnezl + b instead of retail's beqzl to the epilogue. */
extern "C" {
extern unsigned char DAT_003e9630;
extern int DAT_003f344c;
extern char DAT_00383de8[];
extern char DAT_00383dec[];
extern char DAT_003b1698;
extern char DAT_003b1b70;
void *FUN_00000bcc(int);
void FUN_00158b2c(void *);
void FUN_0015bb68(char *, int, char *);
}
struct Context {
  char padding[8];
  int id;
  unsigned char enable;
};
struct Resource {};
struct Target {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void Reset(int, int);
};
extern "C" Target *FUN_001d54e8(int, int);
struct Command {
  virtual ~Command();
  virtual int initialize(float, Resource *);
  int id;
};

extern "C" Command *FUN_0016086c(Context *context, float progress, Resource *resource)
{
  Command *command;
  Target *target;
  int result;
  if (DAT_003e9630 != 0) {
    FUN_00158b2c(resource);
    FUN_0015bb68("ActionKomono [%d (%wait:%s)]\n", context->id, context->enable ? DAT_00383de8 : DAT_00383dec);
  }
  target = FUN_001d54e8(DAT_003f344c, context->id);
  if (target != 0) {
    target->Reset(0, 0);
  }
  if (context->enable) {
    if ((command = (Command *)FUN_00000bcc(8)) != 0) {
      int id = context->id;
      *(char **)command = &DAT_003b1698;
      *(char **)command = &DAT_003b1b70;
      command->id = id;
    }
    result = command->initialize(progress, resource);
    if (result != 0) {
      if (command != 0) delete command;
      return 0;
    }
    return command;
  }
  return 0;
}
