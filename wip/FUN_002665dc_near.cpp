/* HSTMATCH module=EBOOT.BIN start=0x002665dc end=0x0026665c symbol=FUN_002665dc lang=c99 */
int FUN_002665dc(int param_1)
{
  int *s = *(int **)(param_1 + 0x70);
  int i;
  for (i = *(int *)((char *)s + 0x158); i <= *(int *)((char *)s + 0x15c); i++) {
    char *e = (char *)s + i * 52;
    float t = 0.0f;
    int *p = *(int **)(e + 0xf4);
    if (p) t = *(float *)(*p + 8);
    if (*(float *)(e + 0x104) < t) return 0;
  }
  return 1;
}
// near miss: 32 words, 8 differ, all colouring: retail keeps the struct base in v1 and addresses the loop
// bound as 348(v1); ours keeps it in a0 and materialises &bound in v1 (addiu v1,a0,348 in the guard's block),
// which also costs the two likely-branch conversions (bnezl/beqzl) and the reload displacement.
// near miss from lane ds4 (unreviewed)
