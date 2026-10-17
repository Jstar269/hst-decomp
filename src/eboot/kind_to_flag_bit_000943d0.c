/* HSTMATCH module=EBOOT.BIN start=0x000943d0 end=0x00094424 symbol=FUN_000943d0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets a bit in the signed-char flag byte at +0x74 depending on a small kind (3 -> 0x08, 4 -> 0x10, 5 -> 0x20). */
typedef struct Obj_000943d0 {
  char pad[0x74];
  signed char flags;
} Obj_000943d0;

void FUN_000943d0(Obj_000943d0 *o, char kind)
{
  if (kind == 5) {
    o->flags |= 0x20;
  } else if (kind == 3) {
    o->flags |= 0x08;
  } else if (kind == 4) {
    o->flags |= 0x10;
  }
}
