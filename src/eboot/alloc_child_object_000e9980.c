/* HSTMATCH module=EBOOT.BIN start=0x000e9980 end=0x000e99d4 symbol=FUN_000e9980 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the two stores to +0x540 merged into one, `p = ctor(p, ...)` kept in the null-check arm so the constructor result is stored (0xc82c8 recipe); exact match verified; names and types await human review. */
extern void *FUN_00000bcc(int);
extern void *FUN_0005aa44(void *, int, int, int, int, int);

typedef struct Obj_000e9980 {
  char pad000[0x540];
  void *f540;
} Obj_000e9980;

void FUN_000e9980(Obj_000e9980 *o)
{
  void *p = FUN_00000bcc(0x70);
  if (p != 0) {
    p = FUN_0005aa44(p, 1, 0x520, 1, 1, 0);
  }
  o->f540 = p;
}
