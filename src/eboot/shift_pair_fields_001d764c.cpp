/* HSTMATCH module=EBOOT.BIN start=0x001d764c end=0x001d7690 symbol=FUN_001d764c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[4];
    short s4;
    short s6;
    short s8;
    short s10;
};

extern "C" void FUN_001d764c(Obj *o, short x, short y)
{
    short dx = x - o->s4;
    o->s4 = x;
    o->s8 += dx;
    short dy = y - o->s6;
    o->s6 = y;
    o->s10 += dy;
}
