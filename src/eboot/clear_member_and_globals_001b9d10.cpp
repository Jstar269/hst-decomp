/* HSTMATCH module=EBOOT.BIN start=0x001b9d10 end=0x001b9d78 symbol=FUN_001b9d10 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual deleting-destructor call on the member (vptr at +4 via a 4-byte non-polymorphic base), typed global pointers; exact match verified; names and types await human review. */
struct VB_0 { int x; };
struct VC_0 : VB_0 { virtual ~VC_0(); };
extern char *DAT_00331b84;
extern char *DAT_00331b88;

extern "C" void FUN_001b9d10(char *param_1)
{
  VC_0 *m = *(VC_0 **)(param_1 + 0x3c);
  if (m != 0) {
    delete m;
    *(int *)(param_1 + 0x3c) = 0;
  }
  char *a = DAT_00331b84;
  *(int *)(a + 0xc) = 0;
  a[0x52] = 0;
  char *b = DAT_00331b88;
  *(int *)(b + 0xc) = 0;
  b[0x52] = 0;
}
