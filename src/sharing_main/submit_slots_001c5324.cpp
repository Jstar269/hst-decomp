/* HSTMATCH module=hstp_trans_main.prx start=0x001c5324 end=0x001c53ac symbol=FUN_001c5324 lang=c++ */
/* Clone of src/eboot/submit_slots_001b7664.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed globals, count as a ternary on the flag byte, plain indexed for loop over the slot array (strength-reduced by the compiler); exact match verified; names and types await human review. */
struct G1 { char pad[0x45]; unsigned char flag; };
struct G2 { char pad[0x70]; int items[8]; };
extern G2 *DAT_003e19f0;
extern G1 *DAT_003e1e84;
extern "C" void FUN_001c53ac(int, int);

extern "C" void FUN_001c5324(int p)
{
  int n = DAT_003e1e84->flag ? 2 : 4;
  for (int i = 0; i < n; i++)
    FUN_001c53ac(p, DAT_003e19f0->items[i]);
}
