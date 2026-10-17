/* HSTMATCH module=hstp_trans_main.prx start=0x00228030 end=0x0022810c symbol=FUN_00228030 lang=c++ */
/* Clone of src/eboot/counter_switch_notify_00218b18.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00105470(void *p, int v);
struct Obj {
    char pad[0x24];
    int a24;
    int a28;
};
struct Holder {
    Obj *o;
};
extern "C" void FUN_00228030(Holder *h, int n)
{
    int q = n / 10;
    if (q == 0 || q == 50) {
        FUN_00105470(h->o, 1);
    } else {
        switch (n % 10) {
        case 0:
            FUN_00105470(h->o, 0);
            h->o->a24 = h->o->a28 + 2;
            break;
        case 1:
            FUN_00105470(h->o, 0);
            h->o->a24 = h->o->a28 + 1;
            break;
        case 2:
            FUN_00105470(h->o, 0);
            h->o->a24 = h->o->a28;
            break;
        }
    }
}
