/* HSTMATCH module=EBOOT.BIN start=0x001a5a1c end=0x001a5b14 symbol=FUN_001a5a1c lang=c99 */
void FUN_001a5a1c(int *pos, int *slot, int dir, int n, int wrap, int *tbl, int thr)
{
  int base, i, idx;
  if (dir < 0) {
    i = 1;
    if (n < 2) return;
    base = *pos;
    do {
      idx = base - i;
      if (idx < 0) {
        if (wrap == 0) return;
        idx += n;
      }
      if (thr < *(int *)(*(int *)(*tbl + *slot * 12) + idx * 4)) {
        *pos = idx;
        return;
      }
      i++;
    } while (i < n);
  } else {
    i = 1;
    if (n < 2) return;
    idx = *pos + 1;
    do {
      if (idx >= n) {
        if (wrap == 0) return;
        idx -= n;
      }
      if (thr < *(int *)(*(int *)(*tbl + *slot * 12) + idx * 4)) {
        *pos = idx;
        return;
      }
      i++;
      idx++;
    } while (i < n);
  }
}
// near miss from lane dsn3 (unreviewed)
