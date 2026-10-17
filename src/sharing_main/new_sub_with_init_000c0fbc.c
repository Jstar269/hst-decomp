/* HSTMATCH module=hstp_trans_main.prx start=0x000c0fbc end=0x000c1040 symbol=FUN_000c0fbc lang=c99 */
/* Clone of src/eboot/new_sub_with_init_000bda40.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: new+ctor kept in one pointer (merged likely-branch store), caller takes an int and the callee a ushort so the argument is masked, last argument d != 0; exact match verified; names and types await human review. */
typedef struct Sub { int x; } Sub;
typedef struct Obj { char pad[0x26c]; Sub *f26c; } Obj;
extern void *FUN_00000bcc(unsigned);
extern Sub *FUN_00131794(void *);
extern void FUN_00131868(Sub *, int, unsigned short, int, int);

void FUN_000c0fbc(Obj *o, int a, int b, int c, int d)
{
  Sub *mem = (Sub *)FUN_00000bcc(0x20);
  Sub *s;
  if (mem)
    mem = FUN_00131794(mem);
  s = mem;
  o->f26c = s;
  FUN_00131868(s, a, b, c, d != 0);
}
