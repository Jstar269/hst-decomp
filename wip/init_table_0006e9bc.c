/* HSTMATCH module=EBOOT.BIN start=0x0006e9bc end=0x0006ea5c symbol=FUN_0006e9bc lang=c99 */
/* NEAR MISS: 40/40 words, 7 differ.
   The whole body matches except the placement of the incoming-parameter copy:
   retail keeps `n` in a1 for its first uses and copies it to s1 just before the
   first call (`sw a1,0(a0)` / `move s0,a0` / `sll v0,v0,0x4` / `move s1,a1`),
   while ours copies a1 -> s1 in the prologue and reuses s1 for the multiply and
   the store (`move s1,a1` / `sll v0,s1,0x3` / `sw s1,0(a0)`); the s0 save also
   moves with it (retail keeps `sw s0,4(sp)` in the prologue).
   Everything else (the two calls, the argument setup order, the zero-fill loop
   with its reloaded bound and buffer pointer) is byte-exact. */
extern void *FUN_00000a90(unsigned int n);
extern void *FUN_000008d8(void *mem, void (*ctor)(void *), void (*dtor)(void *), int size, int count);
extern void FUN_0005a8ec(void *);
extern void FUN_0005aeac(void *);

struct Rec {
  unsigned int count;
  void *items;
  unsigned char *buf;
};

void FUN_0006e9bc(struct Rec *p, unsigned int n)
{
  p->count = n;
  p->items = FUN_000008d8(FUN_00000a90(n * 0x70 + 0x10), FUN_0005a8ec, FUN_0005aeac, 0x70, n);
  p->buf = (unsigned char *)FUN_00000a90(p->count);
  for (unsigned int i = 0; i < p->count; i++) {
    p->buf[i] = 0;
  }
}
// Ruled out for the late parameter copy:
//  - plain `unsigned *p` + `((unsigned char *)p[2])[i] = 0`: the loop address becomes
//    `addu v1,a0,v1` (index first) instead of retail's `addu v1,v1,a0` (base first);
//    the struct member form fixes that but not the copy.
//  - the count stored after the array creation (17 words off), the count read back
//    from memory as the 5th argument (`lw t0,0(s0)` instead of `move t0,s1`).
//  - a local copy of n used for the multiply/store/t0 argument, `n` as `int`,
//    `p->count` as the multiply operand (no store-to-load forwarding), the
//    declaration order of the local, a separate `unsigned size = n * 0x70`,
//    `0x70 * n` / `n * 112` / `(n << 4) * 7` spellings, a C++ member function,
//    `#pragma opt_propagation off` / `#pragma opt_peephole off`, and an unused
//    third parameter: all keep the copy in the prologue.
//  - MWCC splits the parameter live range only when the parameter is NOT used
//    after the first call (then no copy is emitted at all), so the 5th argument
//    has to be a register copy of n that survives the call to FUN_00000a90.
// near miss from lane om1 (unreviewed)
