/* HSTMATCH module=EBOOT.BIN start=0x00153418 end=0x00153500 symbol=FUN_00153418 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ctx_00153418;
struct Mgr_00153418;
struct Settings_00153418 { int pad[2]; int id; };
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dc74c[];
extern Mgr_00153418 *DAT_0034a114;
void FUN_0014d044(Ctx_00153418 *ctx);
void FUN_0014fd94(char *fmt, ...);
void FUN_0022c890(int id);
void FUN_001cc77c(Mgr_00153418 *mgr, int id);
}

class C_0014c8cc {
public:
  virtual ~C_0014c8cc();
  virtual int Init(float amount, Ctx_00153418 *ctx) = 0;
};

class C_00153418 : public C_0014c8cc {
public:
  virtual ~C_00153418();
  virtual int Init(float amount, Ctx_00153418 *ctx);
};

extern "C" C_0014c8cc *FUN_00153418(Settings_00153418 *settings, float amount, Ctx_00153418 *ctx)
{
  if (DAT_003402f0) {
    FUN_0014d044(ctx);
    FUN_0014fd94(DAT_002dc74c, settings->id);
  }
  FUN_0022c890(settings->id - 1);
  FUN_001cc77c(DAT_0034a114, settings->id);
  C_0014c8cc *action = new C_00153418;
  if (action->Init(amount, ctx)) {
    if (action)
      delete action;
    return 0;
  }
  return action;
}
