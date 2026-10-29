/* HSTMATCH module=EBOOT.BIN start=0x001c3ae8 end=0x001c3b64 symbol=FUN_001c3ae8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: preserved the nested null check and field reset form that matches the cleanup tail; readability pass; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_000104e0();
extern void FUN_002293d4();
extern void FUN_00229774();

/* Heap block whose resource (at 0x04) is released first when the flag byte is set. */
typedef struct Child {
  unsigned char owned;  /* 0x00 */
  char pad01[3];
  int resource;         /* 0x04 */
} Child;

typedef struct Owner {
  char pad00[0x24];
  Child *child;         /* 0x24 */
  char pad28[0xc];
  char sub34[1];        /* 0x34 sub-object torn down first */
} Owner;

/* Tear down the sub-object, then free the child block (and its resource) and clear the pointer. */
void FUN_001c3ae8(Owner *self)
{
  Child *child;
  
  FUN_00229774(self->sub34);
  FUN_002293d4(self->sub34);
  child = self->child;
  if (child == (Child *)0x0)
    return;
  if (child != (Child *)0x0) {
    if ((child->owned != 0) && (child->resource != 0)) {
      FUN_000104e0(child->resource);
    }
    FUN_00000a00(child);
    self->child = 0;
  }
  else
    self->child = 0;
}
