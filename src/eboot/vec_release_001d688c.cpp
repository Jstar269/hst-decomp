/* HSTMATCH module=EBOOT.BIN start=0x001d688c end=0x001d68b4 symbol=FUN_001d688c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
/* The third argument is an empty class temporary: it reserves retail's 32-byte frame (16 bytes above
   ra at 12(sp)) and materialises as `move v0,zero; seb a2,v0` (an empty class is 1 byte, sign-extended).
   The counter is hoisted into a local so the `addiu a0` lands in the jal delay slot. */
extern "C" int FUN_00116414(void *a, int b, Tag c);
struct S { char pad[140]; int f140; int f144; };

extern "C" int FUN_001d688c(S *s)
{
    int n = s->f144;
    return FUN_00116414(&s->f140, n, Tag());
}
