/* HSTMATCH module=hstp_trans_main.prx start=0x0001cbf0 end=0x0001cd04 symbol=FUN_0001cbf0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Twin of EBOOT 0x1cfa4. Recursive quicksort of (key, index) pairs by signed key (middle element as pivot,
   Hoare partition, recurse into both halves). The pair needs a user constructor: as a non-POD class its
   implicit copies are memberwise lw/sw (a POD copy goes through an FPU stack temporary), and the swap
   reloads a[i].key instead of reusing the scan's load. Names provisional. */
struct Pair {
  int key;
  int idx;
  Pair() {}
};

extern "C" void FUN_0001cbf0(Pair *a, int lo, int hi)
{
  int pivot = a[(lo + hi) / 2].key;
  int i = lo;
  int j = hi;
  for (;;) {
    while (a[i].key < pivot) i++;
    while (pivot < a[j].key) j--;
    if (i >= j) break;
    Pair t = a[i];
    a[i] = a[j];
    a[j] = t;
    i++;
    j--;
  }
  if (lo < i - 1) FUN_0001cbf0(a, lo, i - 1);
  if (j + 1 < hi) FUN_0001cbf0(a, j + 1, hi);
}
