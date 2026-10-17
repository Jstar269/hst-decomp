/* HSTMATCH module=hstp_trans_main.prx start=0x000962f4 end=0x00096348 symbol=FUN_000962f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: the flags byte is a typed `char` member (lb, not Ghidra's byte/lbu) of a struct with leading padding, and `kind` stays a `char` parameter (seb); exact match verified; names and types await human review. */
/* Sets one of three flag bits (0x20 / 0x08 / 0x10) in the byte at +0x74 for kind 5 / 3 / 4; any other kind does nothing. */
typedef struct Obj {
  char pad[0x74];
  char flags;
} Obj;

void FUN_000962f4(Obj *obj, char kind)
{
  if (kind == 5) {
    obj->flags |= 0x20;
  } else if (kind == 3) {
    obj->flags |= 0x08;
  } else if (kind == 4) {
    obj->flags |= 0x10;
  }
}
