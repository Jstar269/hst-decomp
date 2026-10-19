/* HSTMATCH module=EBOOT.BIN start=0x001793e8 end=0x0017947c symbol=FUN_001793e8 lang=c++ rodata=0x002c1fa8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Matching idiom: `#pragma opt_strength_reduction off` keeps the loop index multiply (retail recomputes i*0xc each pass). */
#pragma opt_strength_reduction off
extern "C" int FUN_001793e8(int param_1, int param_2)
{
  int v;
  switch (param_2) {
  case 0: {
    unsigned int count = *(unsigned int *)(param_1 + 0x50c);
    v = 0;
    int i = 0;
    if (count != 0) {
      const char *rows = *(const char **)(param_1 + 0x508);
      do {
        v += *(const int *)(rows + i * 0xc + 4);
        i++;
      } while (i < count);
    }
    break;
  }
  case 1: v = *(int *)(param_1 + 0x1dc); break;
  case 2: v = *(int *)(param_1 + 0x1f4); break;
  case 3:
  case 4: v = *(int *)(param_1 + 0x20c); break;
  case 5: v = *(int *)(param_1 + 0x1a8); break;
  default: v = 0; break;
  }
  return v;
}
