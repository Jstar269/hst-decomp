/* HSTMATCH module=EBOOT.BIN start=0x00091c48 end=0x00091cbc symbol=FUN_00091c48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" int DAT_002d28ec;
extern "C" int DAT_002d28f0;
extern "C" void FUN_00091cbc(void);

struct Obj { char pad[0x28]; int f28; };

static inline int Clamp(const int &v, const int &lo, const int &hi)
{
  return v < lo ? lo : (hi < v ? hi : v);
}

extern "C" void FUN_00091c48(Obj *param_1,int param_2)
{
  int n = Clamp(param_2, DAT_002d28ec, DAT_002d28f0);

  if (param_1->f28 != n) {
    param_1->f28 = n;
    if (n >= 0) {
      FUN_00091cbc();
    }
  }
}
