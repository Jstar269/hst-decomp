/* HSTMATCH module=EBOOT.BIN start=0x00213f70 end=0x00214044 symbol=FUN_00213f70 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/spread_scale_00222dc4.cpp, the out-of-line form of the block inlined in src/eboot/fill_random_vec4_00214ae4.cpp; the lower bound goes through an inline `Max(const float &, const float &)` returning by value, which gives retail's double load of the global; each arm returns its own product, a shared `return r * 0.01f;` is 33 words off; the player argument reaches all three lookups in a0); exact match verified; names and types await human review. */
struct Player;
struct Rules { char pad0[0x45]; unsigned char doubles; };
struct A30 { char pad0[0x30]; float f30; };
struct A124 { char pad0[0x124]; float f124; char pad128[0x218 - 0x128]; float f218; };

extern "C" {
extern Rules *DAT_00338b44;
extern float DAT_002efacc;
extern float DAT_002efad0;
A124 *FUN_00215a20(Player *);
A124 *FUN_00215a58(Player *);
A30 *FUN_00215ab8(Player *);
}

static inline float Max(const float &a, const float &b) { return a > b ? a : b; }

extern "C" float FUN_00213f70(Player *self)
{
  if (DAT_00338b44->doubles != 0) {
    float s = FUN_00215a58(self)->f124 + FUN_00215a20(self)->f124;
    return Max(DAT_002efacc, s) * 0.01f;
  } else {
    float s = FUN_00215ab8(self)->f30 + FUN_00215a20(self)->f218;
    return Max(DAT_002efad0, s) * 0.01f;
  }
}
