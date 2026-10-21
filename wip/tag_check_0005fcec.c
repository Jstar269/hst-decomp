/* HSTMATCH module=EBOOT.BIN start=0x0005fcec end=0x0005fdd0 symbol=FUN_0005fcec lang=c99 */
typedef unsigned int undefined4;
extern char DAT_002d0fc8[];
extern char DAT_002d1000[];
extern void FUN_00012ad0();

undefined4 FUN_0005fcec(unsigned char *p)
{
  undefined4 r;

  if (p[0] == 'T' || p[1] == 'I' || p[2] == 'M' || p[3] == '2') {
    r = 1;
  } else if (p[0] == 'C' || p[1] == 'L' || p[2] == 'T' || p[3] == '2') {
    r = 2;
  } else {
    FUN_00012ad0(DAT_002d0fc8);
    return 0;
  }
  if (p[4] != 3 && (p[4] != 4 || (p[5] != 0 && p[5] != 1))) {
    FUN_00012ad0(DAT_002d1000);
    r = 0;
  }
  return r;
}
// EBOOT copy of the Sharing twin wip (hstp_trans_main.prx 0x00060adc) with the header, the two print strings
// (DAT_002d0fc8 = 0x2d0fc8, DAT_002d1000 = 0x2d1000) and the symbol changed. NEAR MISS: 13 words, ALL of them
// register numbers of the four tag bytes; layout, branch likelies, delay slots, constants and both print calls match.
// Retail keeps p[0..3] in a1,a2,a3,t0 (ascending; 'T' constant in t1) and reuses them for the second chain;
// ours allocates them t1,a3,a2,a1 (descending; 'T' in t0), i.e. the exact mirror of retail's order.
// Ruled out here (~6 compiles): reversed `||` order in both chains (layout breaks, 48 words), eager
// `unsigned char c0..c3` locals (loads hoist, `andi` per compare), lazily assigned locals inside the condition
// ((c0 = p[0]) == 'T' || .., 61 words), plus the twin lane's list (struct accessors, const, swap operands,
// C vs C++, locals for p[4]/p[5]). Isolated hstcc probes always pick v0 for a single flag load, so the direction
// of the scratch pool is not reachable from the guard spelling alone.
// from lane snS5-00 (Sharing twin), re-addressed by lane rt1 (unreviewed)
// near miss from lane rt1 (unreviewed)
