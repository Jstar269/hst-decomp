/* HSTMATCH module=hstp_trans_main.prx start=0x00161b58 end=0x00161c3c symbol=FUN_00161b58 lang=c++ */
/* Clone of src/eboot/command_factory_with_settings_00155688.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Ctx_00161b58;
struct Mgr_00161b58;
struct Settings_00161b58 { int pad[2]; int id; };
extern "C" {
extern unsigned char DAT_003e9630;
extern char DAT_00383fe8[];
extern Mgr_00161b58 *DAT_003f344c;
void FUN_00158b2c(Ctx_00161b58 *ctx);
void FUN_0015bb68(char *fmt, ...);
void FUN_001dac44(Mgr_00161b58 *mgr);
}

class C_0014c8cc {
public:
  virtual ~C_0014c8cc();
  virtual int Init(float amount, Ctx_00161b58 *ctx) = 0;
};

class C_00161b58 : public C_0014c8cc {
public:
  Settings_00161b58 *settings;
  C_00161b58(Settings_00161b58 *settings) : settings(settings) {}
  virtual ~C_00161b58();
  virtual int Init(float amount, Ctx_00161b58 *ctx);
};

extern "C" C_0014c8cc *FUN_00161b58(Settings_00161b58 *settings, float amount, Ctx_00161b58 *ctx)
{
  if (DAT_003e9630) {
    FUN_00158b2c(ctx);
    FUN_0015bb68(DAT_00383fe8, settings->id);
  }
  FUN_001dac44(DAT_003f344c);
  C_0014c8cc *action = new C_00161b58(settings);
  if (action->Init(amount, ctx)) {
    if (action)
      delete action;
    return 0;
  }
  return action;
}
