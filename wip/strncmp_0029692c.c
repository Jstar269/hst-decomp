/* HSTMATCH module=EBOOT.BIN start=0x0029692c end=0x002969e0 symbol=FUN_0029692c lang=c99 */
int FUN_0029692c(char *a, char *b, unsigned n)
{
  int nz = n != 0;
  unsigned la = 0;
  if (nz && *a != '\0')
  {
    la = 1;
    char *p = a;
    while (la < n && *++p != '\0')
      la++;
  }
  unsigned lb = 0;
  if (nz && *b != '\0')
  {
    lb = 1;
    char *p = b;
    while (lb < n && *++p != '\0')
      lb++;
  }
  if (la != lb)
    return 1;
  if (la == 0)
    return 0;
  char ca = *a;
  for (;;)
  {
    char cb = *b;
    la--;
    a++;
    b++;
    if (ca != cb)
      return 1;
    if (la == 0)
      return 0;
    ca = *a;
  }
}
// near miss from lane od3 (unreviewed)
