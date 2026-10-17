/* HSTMATCH module=hstp_trans_main.prx start=0x000aea60 end=0x000aeb0c symbol=FUN_000aea60 lang=c++ */
/* Clone of src/eboot/vec4_via_two_calls_000ac04c.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clears two float outputs, defaults idx to the object word at +0x140, calls 0xadb10 to fill them, then 0xad2f0 to build a Vec4 from them, copied field by field to the result. */
struct Vec4 { float x, y, z, w; };
struct Obj {
  char pad[0x140];
  int f140;
};
extern "C" void FUN_000b07f0(Obj *, float *, float *, int);
extern "C" void FUN_000afdf8(Vec4 *, Obj *, int, float, float);

extern "C" void FUN_000aea60(Vec4 *out, Obj *o, int idx, int p4, float *a, float *b)
{
  *a = 0.0f;
  *b = 0.0f;
  if (idx == 0) idx = o->f140;
  FUN_000b07f0(o, a, b, idx);
  Vec4 r;
  FUN_000afdf8(&r, o, p4, *a, *b);
  *out = r;
}
