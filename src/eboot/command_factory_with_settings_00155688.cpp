/* HSTMATCH module=EBOOT.BIN start=0x00155688 end=0x0015576c symbol=FUN_00155688 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ctx_00155688;
struct Mgr_00155688;
struct Settings_00155688 { int pad[2]; int id; };
extern "C" {
extern unsigned char DAT_003402f0;
extern char DAT_002dcb00[];
extern Mgr_00155688 *DAT_0034a114;
void FUN_0014d044(Ctx_00155688 *ctx);
void FUN_0014fd94(char *fmt, ...);
void FUN_001cc510(Mgr_00155688 *mgr);
}

class C_0014c8cc {
public:
  virtual ~C_0014c8cc();
  virtual int Init(float amount, Ctx_00155688 *ctx) = 0;
};

class C_00155688 : public C_0014c8cc {
public:
  Settings_00155688 *settings;
  C_00155688(Settings_00155688 *settings) : settings(settings) {}
  virtual ~C_00155688();
  virtual int Init(float amount, Ctx_00155688 *ctx);
};

extern "C" C_0014c8cc *FUN_00155688(Settings_00155688 *settings, float amount, Ctx_00155688 *ctx)
{
  if (DAT_003402f0) {
    FUN_0014d044(ctx);
    FUN_0014fd94(DAT_002dcb00, settings->id);
  }
  FUN_001cc510(DAT_0034a114);
  C_0014c8cc *action = new C_00155688(settings);
  if (action->Init(amount, ctx)) {
    if (action)
      delete action;
    return 0;
  }
  return action;
}
