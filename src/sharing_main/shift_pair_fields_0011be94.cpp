/* HSTMATCH module=hstp_trans_main.prx start=0x0011be94 end=0x0011bed8 symbol=FUN_0011be94 lang=c++ */
/* Clone of src/eboot/shift_pair_fields_001d764c.cpp (hstclone.py tag x1237s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad[4];
    short s4;
    short s6;
    short s8;
    short s10;
};

extern "C" void FUN_0011be94(Obj *o, short x, short y)
{
    short dx = x - o->s4;
    o->s4 = x;
    o->s8 += dx;
    short dy = y - o->s6;
    o->s6 = y;
    o->s10 += dy;
}
