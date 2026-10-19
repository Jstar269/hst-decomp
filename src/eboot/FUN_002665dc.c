/* HSTMATCH module=EBOOT.BIN start=0x002665dc end=0x0026665c symbol=FUN_002665dc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the loop-bound member is declared `volatile int` (a non-volatile member or an untyped base makes MWCC hoist the bound address into v1 and re-read it through that pointer); names and types await human review. */
typedef struct { char pad0[0x158]; int first; volatile int last; char pad1[0x8c]; int *p94; char pad2[0xc]; float f104; } S;

int FUN_002665dc(int param_1)
{
  S *s = *(S **)(param_1 + 0x70);
  int i;
  for (i = s->first; i <= s->last; i++) {
    char *e = (char *)s + i * 52;
    int *p = *(int **)(e + 0xf4);
    float t;
    if (p) { t = *(float *)(*p + 8); } else { t = 0.0f; }
    if (*(float *)(e + 0x104) < t) return 0;
  }
  return 1;
}
