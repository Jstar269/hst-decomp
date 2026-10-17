/* HSTMATCH module=hstp_trans_main.prx start=0x001007b8 end=0x00100808 symbol=FUN_001007b8 lang=c++ */
/* Clone of src/eboot/set_mode_from_code_000fb07c.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct C {
    char pad[0x8c];
    int f8c;
};
struct B {
    char pad[0x78];
    C *f78;
};
struct A {
    char pad[0x3c];
    B *f3c;
};

extern "C" void FUN_001007b8(A *a, int code)
{
    switch (code) {
    case 0:
        a->f3c->f78->f8c = 1;
        break;
    case 1:
        a->f3c->f78->f8c = 2;
        break;
    case 2:
        a->f3c->f78->f8c = 0;
        break;
    }
}
