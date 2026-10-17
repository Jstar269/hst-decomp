/* HSTMATCH module=EBOOT.BIN start=0x0022a4b8 end=0x0022a744 symbol=__ct__10C_0022a4b8Fv lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Constructor of a 0xb460-byte object: the embedded block at +0xa210 is constructed (FUN_0022a744), the whole object is zeroed, a few fields are set, then a fresh temporary block is assigned over it (memberwise copy; layout as in assign_001ca92c.cpp). Matching idioms: `#pragma opt_unroll_loops off` keeps the 15-element loop rolled; the block is aligned(16) (16-byte-aligned temporary at the bottom of the 4704-byte frame). */
#pragma opt_unroll_loops off
extern "C" void FUN_000114c0(void *, int, int);
extern "C" void FUN_0022a744(void *);

struct Sub {
  int arr1[576];
  char arr2[16];
  int s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10;
  unsigned char b0, b1, b2, b3, b4;
  int arr3[256];
  int arr4[256];
  int arr5[64];
  Sub() { FUN_0022a744(this); }
} __attribute__((aligned(16)));

struct C_0022a4b8 {
  char pad0[0x8d00];
  unsigned char flags;
  char pad1[0x9fd4 - 0x8d01];
  int f9fd4;
  char pad2[0x9fe6 - 0x9fd8];
  short vals[15];
  char pad3[0xa210 - 0x9fe6 - 30];
  Sub sub;
  char pad4[0xb460 - 0xa210 - sizeof(Sub)];
  C_0022a4b8();
};

C_0022a4b8::C_0022a4b8()
{
  FUN_000114c0(this, 0, 0xb460);
  f9fd4 = -1;
  for (unsigned i = 0; i < 15; i++)
    vals[i] = 200;
  Sub tmp;
  sub = tmp;
  flags |= 1;
}
