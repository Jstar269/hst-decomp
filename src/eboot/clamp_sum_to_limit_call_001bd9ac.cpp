/* HSTMATCH module=EBOOT.BIN start=0x001bd9ac end=0x001bda24 symbol=FUN_001bd9ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned long long u64;

extern u64 DAT_002e9da8;
extern "C" void FUN_001bc13c(void *, int);

struct Obj { char pad0[8]; unsigned a; unsigned b; char pad1[0xc0 - 0x10]; char sub[1]; };

static inline const u64 &Min(const u64 &a, const u64 &b) { return b < a ? b : a; }

extern "C" void FUN_001bd9ac(Obj *o)
{
  u64 sum = o->a + o->b;
  FUN_001bc13c(o->sub, (int)Min(sum, DAT_002e9da8));
}
