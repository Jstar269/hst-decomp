/* HSTMATCH module=hstp_trans_main.prx start=0x00060adc end=0x00060bc0 symbol=FUN_00060adc lang=c99 */
typedef unsigned int undefined4;
extern char DAT_00376e18[];
extern char DAT_00376e50[];
extern void FUN_00012ad0();

undefined4 FUN_00060adc(unsigned char *p)
{
  undefined4 r;

  if (p[0] == 'T' || p[1] == 'I' || p[2] == 'M' || p[3] == '2') {
    r = 1;
  } else if (p[0] == 'C' || p[1] == 'L' || p[2] == 'T' || p[3] == '2') {
    r = 2;
  } else {
    FUN_00012ad0(DAT_00376e18);
    return 0;
  }
  if (p[4] != 3 && (p[4] != 4 || (p[5] != 0 && p[5] != 1))) {
    FUN_00012ad0(DAT_00376e50);
    r = 0;
  }
  return r;
}

// NEAR MISS (agent snS5-00): 13 words differ, ALL of them register numbers of the four tag bytes (layout, branch likelies, delay slots,
// constants and both print calls match). Retail keeps p[0..3] in a1,a2,a3,t0 (ascending, 'T' constant in t1); ours allocates
// t1,a3,a2,a1 (descending, 'T' in t0). Ruled out: unsigned char locals assigned lazily inside the condition, eager locals (hoists the loads),
// struct-typed header with accessor methods, const, int/uchar return, swapped compare operands, locals for p[4]/p[5], C vs C++.
// The two chains are single `||` chains (a `if (p[0]=='T') ... else if (...)` ladder lays out differently).
