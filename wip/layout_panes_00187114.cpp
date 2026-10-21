/* HSTMATCH module=EBOOT.BIN start=0x00187114 end=0x0018726c symbol=FUN_00187114 lang=c++ */
typedef unsigned char u8;

struct Elem {
    int a;
    int b;
    short x;
    short y;
};

struct Elem5 {
    int a[5];
    short x;
    short y;
};

extern "C" void *FUN_0016bc7c();
extern "C" void *FUN_0016bc70();
extern "C" void FUN_002177d4(Elem *e, int x, int y, int x2, int y2, int t);

extern "C" void FUN_00187114(u8 *self) {
    int t = ((int *)FUN_0016bc7c())[25];
    u8 *cfg = (u8 *)FUN_0016bc70();
    if (cfg[0x3d] != 0) {
        Elem *e = (Elem *)(self + 0x1254);
        FUN_002177d4(e, e->x, e->y, e->x - 480, e->y, t);
    } else {
        Elem5 *e = (Elem5 *)(self + 0x12e0);
        FUN_002177d4((Elem *)e, e->x, e->y, e->x - 480, e->y, t);
    }
    int f = (int)*(float *)(*(u8 **)(self + 0x20) + 100);
    Elem *e3 = (Elem *)(self + 0x136c);
    FUN_002177d4(e3, e3->x, f, e3->x - 480, f, t);
    Elem *e4 = (Elem *)(self + 0x1510);
    FUN_002177d4(e4, e4->x, e4->y, e4->x - 480, e4->y, t);
    Elem *e5 = (Elem *)(self + 0x13f8);
    FUN_002177d4(e5, e5->x, e5->y, e5->x - 480, e5->y, t);
    int g = (int)*(float *)(*(u8 **)(self + 0x28) + 0x60);
    Elem *e6 = (Elem *)(self + 0x1484);
    FUN_002177d4(e6, g, e6->y, g - 480, e6->y, t);
    Elem *e7 = (Elem *)(self + 0x159c);
    FUN_002177d4(e7, e7->x, e7->y, e7->x + 480, e7->y, t);
    Elem *e8 = (Elem *)(self + 0x1628);
    FUN_002177d4(e8, e8->x, e8->y, e8->x + 480, e8->y, t);
    Elem *e9 = (Elem *)(self + 0x16b4);
    FUN_002177d4(e9, e9->x, e9->y, e9->x + 480, e9->y, t);
}
// NEAR MISS (22 differing words, same 86-word size). All ten placement calls agree; only the order of
// three argument-setup instructions differs: retail emits `move t0,a2`, `addiu a3,a1,-480`, then puts
// `move t1,s0` (the shared handle) in the jal delay slot, while our build materialises t1 first and the
// addiu last. Ruled out: hoisting x/y into locals per call (worse), passing the handle as a pointer.
// near miss from lane ds10 (unreviewed)
