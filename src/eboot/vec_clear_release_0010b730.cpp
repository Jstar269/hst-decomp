/* HSTMATCH module=EBOOT.BIN start=0x0010b730 end=0x0010b76c symbol=FUN_0010b730 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Tag {};
/* The third argument is an empty class temporary: it reserves retail's 32-byte frame (16 bytes above
   ra at 12(sp)) and materialises as `move v0,zero; seb a2,v0` (an empty class is 1 byte, sign-extended).
   The counter is hoisted into a local so the `addiu a0` lands in the jal delay slot. */
extern "C" int FUN_001087d0(void *a, int b, Tag c);
struct S {
    char pad[208];
    int fd0;
    char pad2[8];
    int fdc;
    char pad3[12];
    short fec, fee;
    char pad4[32];
    int f110;
    char pad5[12];
    int f120, f124;
};

extern "C" int FUN_0010b730(S *s)
{
    int n;
    s->f110 = 0;
    s->fdc = 0;
    s->fec = 0;
    s->fee = 0;
    s->fd0 = 0;
    n = s->f124;
    return FUN_001087d0(&s->f120, n, Tag());
}
