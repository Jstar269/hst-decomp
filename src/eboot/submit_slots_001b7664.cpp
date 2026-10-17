/* HSTMATCH module=EBOOT.BIN start=0x001b7664 end=0x001b76ec symbol=FUN_001b7664 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed globals, count as a ternary on the flag byte, plain indexed for loop over the slot array (strength-reduced by the compiler); exact match verified; names and types await human review. */
struct G1 { char pad[0x45]; unsigned char flag; };
struct G2 { char pad[0x70]; int items[8]; };
extern G2 *DAT_003386b0;
extern G1 *DAT_00338b44;
extern "C" void FUN_001b76ec(int, int);

extern "C" void FUN_001b7664(int p)
{
  int n = DAT_00338b44->flag ? 2 : 4;
  for (int i = 0; i < n; i++)
    FUN_001b76ec(p, DAT_003386b0->items[i]);
}
