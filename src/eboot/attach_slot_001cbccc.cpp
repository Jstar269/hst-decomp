/* HSTMATCH module=EBOOT.BIN start=0x001cbccc end=0x001cbedc symbol=FUN_001cbccc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The table lookup is one inline helper used by both branches (retail's per-branch return joins), and the slot pointer is read once after the if/else. */
#include "hst/types.h"
#include "hst/panel_data.h"

extern "C" {
extern void FUN_0018a950(...);
extern TextBank * FUN_0018c9f4(...);
extern void FUN_001cd88c(...);
extern u8 * FUN_002294f4(void *, TextBank *, u32, int);
extern u32 FUN_002297d8(...);
extern int * FUN_00288a84(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29(); virtual void d30(); virtual void m(int, int); };

/* Text for string index idx of group 0 in a bank (placeholder strings when unloaded or out of range). */
static inline u8 *Lookup(TextBank *bank, int idx)
{
  if (bank->loaded == 0)
    return (u8 *)DAT_002c0e20;
  if (bank->header->groupCount < 1)
    return (u8 *)DAT_002c0e1c;
  if ((idx < 0) || (idx >= bank->groups[0].count))
    return (u8 *)DAT_002c0e18;
  return (u8 *)bank->groups[0].strings[idx];
}

extern "C" void FUN_001cbccc(PanelOwner *owner, int *obj, u32 key, int bank_id)
{
  u8 *text;
  bool matched;
  PanelData *panel;
  int kind;
  u8 *found;
  int *handler;

  if (obj != (int *)0x0) {
    if (bank_id < 0) {
      kind = obj[0xd];
      text = Lookup(FUN_0018c9f4(7), kind);
    }
    else {
      text = Lookup(FUN_0018c9f4(0xc), bank_id);
    }
    panel = owner->panel;
    found = FUN_002294f4(panel->map34, panel->bank, key, 0);
    if (found != 0) {
      panel->unk63 = 0;
      panel->unk64 = 0;
      panel->text = found;
      panel->unk6c = 0;
      panel->unk70 = 0;
      FUN_0018a950(panel->unk20, text);
      FUN_001cd88c(panel, 2, 1);
    }
    panel->unk74 = -1;
    panel->unk78 = -1;
    FUN_002297d8(panel->map34, key, 0);
    kind = ((VC_0 *)(obj))->m();
    matched = kind == 2;
    if (!matched) {
      kind = ((VC_1 *)(obj))->m();
      matched = kind == 3;
    }
    if (matched) {
      handler = (int *)FUN_00288a84(obj);
      ((VC_2 *)(handler))->m((int)(0), (int)(1));
      owner->panel->unk5c = obj;
    }
  }
}
