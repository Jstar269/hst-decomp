/* HSTMATCH module=EBOOT.BIN start=0x000ac04c end=0x000ac0f8 symbol=FUN_000ac04c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clears two float outputs, defaults idx to the object word at +0x140, calls 0xadb10 to fill them, then 0xad2f0 to build a Vec4 from them, copied field by field to the result. */
struct Vec4 { float x, y, z, w; };
struct Obj {
  char pad[0x140];
  int f140;
};
extern "C" void FUN_000adb10(Obj *, float *, float *, int);
extern "C" void FUN_000ad2f0(Vec4 *, Obj *, int, float, float);

extern "C" void FUN_000ac04c(Vec4 *out, Obj *o, int idx, int p4, float *a, float *b)
{
  *a = 0.0f;
  *b = 0.0f;
  if (idx == 0) idx = o->f140;
  FUN_000adb10(o, a, b, idx);
  Vec4 r;
  FUN_000ad2f0(&r, o, p4, *a, *b);
  *out = r;
}
