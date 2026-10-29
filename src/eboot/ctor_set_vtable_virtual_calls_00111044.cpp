/* HSTMATCH module=EBOOT.BIN start=0x00111044 end=0x0011110c symbol=FUN_00111044 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the three indirect calls written as C++ virtual calls (slots 6 float 10.0f, 5 int -256, 1 int 0) on a polymorphic type; exact match verified; readability pass; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1174;
extern u8 DAT_00307b6c;
extern u8 DAT_00307d94;
extern "C" void FUN_00100eb8(...);
extern "C" void FUN_001014e8(...);

struct VC_0 {
  virtual void v0();
  virtual void v1(int);
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5(int);
  virtual void v6(float);
};

struct Obj {
  const void *vtable;   /* 0x00 */
  int unk04;
  int unk08;
  int unk0c;
  int unk10;
  int unk14;
  int unk18;
  u8 unk1c;             /* 0x1c */
  char pad1d[3];
  int unk20;            /* 0x20 bit pattern of the float 100000.0 */
  u8 unk24;             /* 0x24 */
  char pad25[3];
  int unk28;            /* 0x28 */
};

/* Constructs the object: base vtable first, then the derived vtable, then initial settings through virtual calls. */
extern "C" Obj * FUN_00111044(Obj *obj,u32 *arg1,u32 arg2)
{
  obj->vtable = &DAT_00307b6c;
  obj->unk04 = 0;
  obj->unk08 = 0;
  obj->unk0c = 0;
  obj->unk10 = 0;
  obj->unk14 = 0;
  obj->unk18 = 0;
  obj->unk1c = 0;
  obj->unk20 = 0x47c35000;
  obj->unk24 = 0;
  obj->vtable = &DAT_00307d94;
  obj->unk28 = 0;
  FUN_00100eb8(obj,arg1,arg2,(char *)0x0);
  FUN_001014e8(obj,&DAT_002c1174,0x2a);
  ((VC_0 *)obj)->v6(10.0f);
  ((VC_0 *)obj)->v5(-256);
  ((VC_0 *)obj)->v1(0);
  return obj;
}
