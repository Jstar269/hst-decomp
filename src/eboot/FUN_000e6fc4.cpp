/* HSTMATCH module=EBOOT.BIN start=0x000e6fc4 end=0x000e7010 symbol=FUN_000e1984 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; };

struct Obj {
  char pad[0xc0];
  Vec4 pos;
  void SetPos(Vec4 p) { pos = p; }
};

extern "C" void FUN_000e1984(Obj *o, const Vec4 *src)
{
  o->SetPos(*src);
}
