/* HSTMATCH module=hstp_trans_main.prx start=0x000ebfc0 end=0x000ec00c symbol=FUN_000ebfc0 lang=c++ */
/* Hand-written reconstruction from the disassembly (the same source as its EBOOT twin src/eboot/FUN_000e6fc4.cpp: a Vec4 passed by value to an inline setter); exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; };

struct Obj {
  char pad[0xc0];
  Vec4 pos;
  void SetPos(Vec4 p) { pos = p; }
};

extern "C" void FUN_000ebfc0(Obj *o, const Vec4 *src)
{
  o->SetPos(*src);
}
