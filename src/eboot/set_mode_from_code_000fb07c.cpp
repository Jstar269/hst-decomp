/* HSTMATCH module=EBOOT.BIN start=0x000fb07c end=0x000fb0cc symbol=FUN_000fb07c lang=c++ */
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

extern "C" void FUN_000fb07c(A *a, int code)
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
