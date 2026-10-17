/* HSTMATCH module=hstp_trans_main.prx start=0x001cb794 end=0x001cb80c symbol=FUN_001cb794 lang=c++ */
/* Clone of src/eboot/clamp_sum_to_limit_call_001bd9ac.cpp (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned long long u64;

extern u64 DAT_003919e0;
extern "C" void FUN_001c9f24(void *, int);

struct Obj { char pad0[8]; unsigned a; unsigned b; char pad1[0xc0 - 0x10]; char sub[1]; };

static inline const u64 &Min(const u64 &a, const u64 &b) { return b < a ? b : a; }

extern "C" void FUN_001cb794(Obj *o)
{
  u64 sum = o->a + o->b;
  FUN_001c9f24(o->sub, (int)Min(sum, DAT_003919e0));
}
