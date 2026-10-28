/* HSTMATCH module=EBOOT.BIN start=0x00102824 end=0x00102958 symbol=FUN_00102824 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_00102824.c) corrected by hand: C++ with trailing unused empty False parameter; loop-continue flag as int; exact match verified; names and types await human review. */
// matching idioms: trailing unused empty `False` by-value parameter (retail frame is 16 bytes larger); `more = (p == end) ^ 1` flag instead of `!(p == end)` (C++ bool would add andi); declare `i` before `src` for the s-register order.
#include "hst/types.h"

extern "C" u8 DAT_0033b394;
extern "C" u8 DAT_0033a6e0;
extern "C" int DAT_0033b45c;
extern "C" u8 DAT_002d8a28;
extern "C" void FUN_000114c0(void *, int, int);
extern "C" void FUN_000149a8(void *, void *);
extern "C" void FUN_00014788(void *, u8 *);

struct False {};
extern "C" void FUN_00102824(int *param_1, False)
{
  unsigned int i;
  unsigned char *src;
  int *p;
  int *e;
  int v;
  unsigned char *dst;
  int more;

  p = (int *)param_1[1];
  more = (p == (int *)param_1[1] + param_1[2]) ^ 1;
  while (more) {
    e = (int *)*p;
    v = *(int *)((int)e + 0x54);
    src = (unsigned char *)e + 0x59;
    if (DAT_0033b45c == 0) {
      FUN_000114c0(&DAT_0033b394,0,200);
    }
    for (i = 0; i < 50; i++) {
      if (((int *)&DAT_0033b394)[i] == 0) {
        dst = (unsigned char *)&DAT_0033a6e0 + i * 65;
        FUN_000149a8(dst,src);
        FUN_00014788(dst,&DAT_002d8a28);
        ((int *)&DAT_0033b394)[i] = v;
        DAT_0033b45c = DAT_0033b45c + 1;
        break;
      }
    }
    p = p + 1;
    more = (p == (int *)param_1[1] + param_1[2]) ^ 1;
  }
}
