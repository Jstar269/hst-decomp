/* HSTMATCH module=hstp_trans_main.prx start=0x00110120 end=0x0011016c symbol=FUN_00110120 lang=c++ */
/* Clone of src/eboot/rotate_fwd_0010a360.cpp (hstclone.py tag lnmc): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: one-pointer Cursor wrapper for the middle iterator; exact match verified; names and types await human review. */
struct Cursor {
  int *p;
  Cursor(int *value) : p(value) {}
};

extern "C" void FUN_00110120(int *first, int *middle, int *last)
{
  Cursor i(middle);
  for (;;) {
    int t = *first;
    *first = *i.p;
    ++first;
    *i.p = t;
    if (first == middle) {
      ++i.p;
      if (i.p == last) return;
      middle = i.p;
    } else {
      ++i.p;
      if (i.p == last) i.p = middle;
    }
  }
}
// Near miss, 12 words: control flow and instruction schedule are exact (forward-iterator rotate loop, single loop,
// i = middle reset in the slot, likely-branch copy of the first load); only the register colours of the three
// temporaries differ: ours i=t0 / first-load=a3 / second-load=v1, retail i=v1 / first-load=t0 / second-load=a3.
// Ruled out (all gave the identical colouring): declaration order of t/x/i, C vs C++, inline swap/iter_swap helpers
// with pointer params, post-increment forms, locals declared outside the loop, copies of first/middle, an extra
// unused fourth parameter (int or empty tag), `*first++ = *i` forms (these also change the schedule).
// EBOOT copy of the Sharing wip (header + symbol re-addressed). Same 12 words: 19/19 words, schedule exact,
// only the three scratch registers rotate: retail i=v1, t=t0, x=a3; ours i=t0, t=a3, x=v1.
// rt1 also tried `int *i; i = middle;` (declaration then assignment) — identical 12.
// near miss from lane rt1 (unreviewed)
