/* HSTMATCH module=EBOOT.BIN start=0x0017947c end=0x0017951c symbol=FUN_0017947c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
    char pad0[0x1e4];
    int **tab0;
    char pad1e8[0x1fc - 0x1e8];
    int **tab1;
    char pad200[0x208 - 0x200];
    int **tab2;
    char pad20c[0x5b8 - 0x20c];
    int state;
};
extern "C" int FUN_0017947c(Obj *o, int a, int n)
{
    int idx = a + n * 4;
    int r = 0;
    switch (o->state) {
    case 0:
        r = *o->tab0[idx];
        break;
    case 1:
        r = *o->tab1[idx];
        break;
    case 2:
        r = *o->tab2[idx];
        break;
    case 3:
        r = *o->tab2[idx];
        break;
    case 4:
        break;
    }
    return r;
}
