/* HSTMATCH module=EBOOT.BIN start=0x001b97a4 end=0x001b982c symbol=FUN_001b97a4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual deleting-destructor call (struct with a 4-byte non-polymorphic base so the vptr is at +4), delete of the member; exact match verified; names and types await human review. */
extern char DAT_003092f8;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001f0f0(void *, int);
struct VB_0 { int x; };
struct VC_0 : VB_0 { virtual ~VC_0(); };

extern "C" unsigned *FUN_001b97a4(unsigned *param_1, short param_2)
{
  if (param_1 != 0) {
    *param_1 = (unsigned)&DAT_003092f8;
    VC_0 *m = (VC_0 *)param_1[0xf];
    if (m != 0) {
      delete m;
      param_1[0xf] = 0;
    }
    FUN_0001f0f0(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
