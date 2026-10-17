/* HSTMATCH module=hstp_trans_main.prx start=0x0015f648 end=0x0015f730 symbol=FUN_0015f648 lang=c++ */
/* Clone of src/eboot/command_factory_00153418.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ctx_0015f648;
struct Mgr_0015f648;
struct Settings_0015f648 { int pad[2]; int id; };
extern "C" {
extern unsigned char DAT_003e9630;
extern char DAT_00383c34[];
extern Mgr_0015f648 *DAT_003f344c;
void FUN_00158b2c(Ctx_0015f648 *ctx);
void FUN_0015bb68(char *fmt, ...);
void FUN_0023c364(int id);
void FUN_001daeb0(Mgr_0015f648 *mgr, int id);
}

class C_0014c8cc {
public:
  virtual ~C_0014c8cc();
  virtual int Init(float amount, Ctx_0015f648 *ctx) = 0;
};

class C_0015f648 : public C_0014c8cc {
public:
  virtual ~C_0015f648();
  virtual int Init(float amount, Ctx_0015f648 *ctx);
};

extern "C" C_0014c8cc *FUN_0015f648(Settings_0015f648 *settings, float amount, Ctx_0015f648 *ctx)
{
  if (DAT_003e9630) {
    FUN_00158b2c(ctx);
    FUN_0015bb68(DAT_00383c34, settings->id);
  }
  FUN_0023c364(settings->id - 1);
  FUN_001daeb0(DAT_003f344c, settings->id);
  C_0014c8cc *action = new C_0015f648;
  if (action->Init(amount, ctx)) {
    if (action)
      delete action;
    return 0;
  }
  return action;
}
