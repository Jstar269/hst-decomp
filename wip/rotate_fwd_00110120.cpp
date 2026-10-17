/* HSTMATCH module=hstp_trans_main.prx start=0x00110120 end=0x0011016c symbol=FUN_00110120 lang=c++ */
extern "C" void FUN_00110120(int *first, int *middle, int *last)
{
  int *i = middle;
  for (;;) {
    int t = *first;
    *first = *i;
    ++first;
    *i = t;
    if (first == middle) {
      ++i;
      if (i == last) return;
      middle = i;
    } else {
      ++i;
      if (i == last) i = middle;
    }
  }
}
// Near miss, 12 words: control flow and instruction schedule are exact (forward-iterator rotate loop, single loop,
// i = middle reset in the slot, likely-branch copy of the first load); only the register colours of the three
// temporaries differ: ours i=t0 / first-load=a3 / second-load=v1, retail i=v1 / first-load=t0 / second-load=a3.
// Ruled out (all gave the identical colouring): declaration order of t/x/i, C vs C++, inline swap/iter_swap helpers
// with pointer params, post-increment forms, locals declared outside the loop, copies of first/middle, an extra
// unused fourth parameter (int or empty tag), `*first++ = *i` forms (these also change the schedule).
