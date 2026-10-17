/* HSTMATCH module=hstp_trans_main.prx start=0x000eea54 end=0x000eeaa8 symbol=FUN_000eea54 lang=c99 */
/* Clone of src/eboot/alloc_child_object_000e9980.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the two stores to +0x540 merged into one, `p = ctor(p, ...)` kept in the null-check arm so the constructor result is stored (0xc82c8 recipe); exact match verified; names and types await human review. */
extern void *FUN_00000bcc(int);
extern void *FUN_0005b814(void *, int, int, int, int, int);

typedef struct Obj_000eea54 {
  char pad000[0x540];
  void *f540;
} Obj_000eea54;

void FUN_000eea54(Obj_000eea54 *o)
{
  void *p = FUN_00000bcc(0x70);
  if (p != 0) {
    p = FUN_0005b814(p, 1, 0x520, 1, 1, 0);
  }
  o->f540 = p;
}
