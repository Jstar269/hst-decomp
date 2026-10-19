/* HSTMATCH module=hstp_trans_main.prx start=0x000e5f4c end=0x000e5f98 symbol=FUN_000e5f4c lang=c++ */
/* Clone of src/eboot/FUN_000e1984.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; };

struct Obj {
  char pad[0x80];
  Vec4 pos;
  void SetPos(Vec4 p) { pos = p; }
};

extern "C" void FUN_000e5f4c(Obj *o, const Vec4 *src)
{
  o->SetPos(*src);
}
