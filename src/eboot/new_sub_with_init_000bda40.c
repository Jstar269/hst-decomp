/* HSTMATCH module=EBOOT.BIN start=0x000bda40 end=0x000bdac4 symbol=FUN_000bda40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: new+ctor kept in one pointer (merged likely-branch store), caller takes an int and the callee a ushort so the argument is masked, last argument d != 0; exact match verified; names and types await human review. */
typedef struct Sub { int x; } Sub;
typedef struct Obj { char pad[0x26c]; Sub *f26c; } Obj;
extern void *FUN_00000bcc(unsigned);
extern Sub *FUN_00126524(void *);
extern void FUN_001265f8(Sub *, int, unsigned short, int, int);

void FUN_000bda40(Obj *o, int a, int b, int c, int d)
{
  Sub *mem = (Sub *)FUN_00000bcc(0x20);
  Sub *s;
  if (mem)
    mem = FUN_00126524(mem);
  s = mem;
  o->f26c = s;
  FUN_001265f8(s, a, b, c, d != 0);
}
