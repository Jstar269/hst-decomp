/* HSTMATCH module=hstp_trans_main.prx start=0x00222dc4 end=0x00222e98 symbol=FUN_00222dc4 lang=c++ */
/* Hand-written reconstruction from the disassembly (the out-of-line form of the spread-scale block inlined in src/sharing_main/fill_random_vec4_00223970.cpp; the lower bound goes through an inline `Max(const float &, const float &)` returning by value, which gives retail's double load of the global; each arm returns its own product, a shared `return r * 0.01f;` is 33 words off; the player argument reaches all three lookups in a0); exact match verified; names and types await human review. */
struct Player;
struct Rules { char pad0[0x45]; unsigned char doubles; };
struct A30 { char pad0[0x30]; float f30; };
struct A124 { char pad0[0x124]; float f124; char pad128[0x218 - 0x128]; float f218; };

extern "C" {
extern Rules *DAT_003e1e84;
extern float DAT_00397d50;
extern float DAT_00397d54;
A124 *FUN_002248ac(Player *);
A124 *FUN_0022492c(Player *);
A30 *FUN_00224a48(Player *);
}

static inline float Max(const float &a, const float &b) { return a > b ? a : b; }

extern "C" float FUN_00222dc4(Player *self)
{
  if (DAT_003e1e84->doubles != 0) {
    float s = FUN_0022492c(self)->f124 + FUN_002248ac(self)->f124;
    return Max(DAT_00397d50, s) * 0.01f;
  } else {
    float s = FUN_00224a48(self)->f30 + FUN_002248ac(self)->f218;
    return Max(DAT_00397d54, s) * 0.01f;
  }
}
