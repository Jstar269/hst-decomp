/* HSTMATCH module=EBOOT.BIN start=0x001ec3b8 end=0x001ec418 symbol=FUN_001ec3b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reconstructed merged-store null-checked constructor calls for both allocated objects; exact match verified; names and types await human review. */
typedef unsigned int uint;

extern void *FUN_00000bcc(uint size);
extern void *FUN_001eb784(void *);
extern void *FUN_001eab84(void *);

void FUN_001ec3b8(void **param_1)
{
  void *p1 = FUN_00000bcc(316);
  if (p1 != 0) {
    p1 = FUN_001eb784(p1);
  }
  param_1[0] = p1;

  void *p2 = FUN_00000bcc(992);
  if (p2 != 0) {
    p2 = FUN_001eab84(p2);
  }
  param_1[1] = p2;
}
