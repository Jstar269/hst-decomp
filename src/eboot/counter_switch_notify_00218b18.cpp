/* HSTMATCH module=EBOOT.BIN start=0x00218b18 end=0x00218bf4 symbol=FUN_00218b18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_000ffb3c(void *p, int v);
struct Obj {
    char pad[0x24];
    int a24;
    int a28;
};
struct Holder {
    Obj *o;
};
extern "C" void FUN_00218b18(Holder *h, int n)
{
    int q = n / 10;
    if (q == 0 || q == 50) {
        FUN_000ffb3c(h->o, 1);
    } else {
        switch (n % 10) {
        case 0:
            FUN_000ffb3c(h->o, 0);
            h->o->a24 = h->o->a28 + 2;
            break;
        case 1:
            FUN_000ffb3c(h->o, 0);
            h->o->a24 = h->o->a28 + 1;
            break;
        case 2:
            FUN_000ffb3c(h->o, 0);
            h->o->a24 = h->o->a28;
            break;
        }
    }
}
