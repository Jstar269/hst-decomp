/* HSTMATCH module=EBOOT.BIN start=0x00233d54 end=0x00233f3c symbol=FUN_00233d54 lang=c++ */
/* Hand-written reconstruction from the disassembly (structure taken from singleton_ctor_002313c8.cpp); exact match verified (matching idioms: the allocation is tested inside the condition 'DAT == 0 && (h = operator new(20)) != 0' so the pointer copy lands in the beqz slot, each of the first two owned objects is 'if (m != 0) h->x = Init(m); else h->x = m;', and the table loop walks a char pointer declared after the counter); names and types await human review. */
struct Holder {
    void *a;
    void *b;
    void *c;
    int pad;
    unsigned char f10;
    unsigned char f11;
    unsigned char f12;
};

extern "C" {
extern char DAT_0030985c[];
extern void *DAT_0034a668;
extern Holder *DAT_0034a664;
extern int DAT_0034a120;
extern char DAT_0030ebf4[];
extern char DAT_002f3e78[];
extern char DAT_002f3e94[];
extern char DAT_002f3e24[];
extern char DAT_002f3eb0[];

extern void FUN_0001f06c(void *);
extern void *FUN_00000bcc(unsigned);
extern void FUN_0001cad0(void *, int, char *);
extern void FUN_0001cb88(void *);
extern void FUN_0001ca58(void *, char *);
extern void *FUN_0023167c(void *);
extern void *FUN_002200d4(void *);
extern void *FUN_00220f00(void *);
extern int FUN_000143b0(char *, char *, ...);
extern void *FUN_00050fc0(void *);
extern void FUN_000511c4(void *, char *, int);
extern void FUN_00051398(void *, float);
extern void FUN_002afb80(int, int);
extern void FUN_002afce0(int);
extern void FUN_0023302c(Holder *, int);
extern void FUN_00232ec4(Holder *);
}

extern "C" char *FUN_00233d54(char *self)
{
    char buf[256];
    FUN_0001f06c(self);
    *(void **)self = DAT_0030985c;
    DAT_0034a668 = self;
    Holder *h;
    if (DAT_0034a664 == 0 && (h = (Holder *)::operator new(0x14)) != 0) {
        h->a = 0;
        h->b = 0;
        DAT_0034a664 = h;
        h->f10 = 0;
        h->f11 = 0;
        h->f12 = 0;
        FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f3e78);
        void *m = ::operator new(0x2f0);
        if (m != 0)
            h->a = FUN_0023167c(m);
        else
            h->a = m;
        m = ::operator new(0x78);
        if (m != 0)
            h->b = FUN_002200d4(m);
        else
            h->b = m;
        m = ::operator new(0xa0);
        if (m != 0)
            m = FUN_00220f00(m);
        h->c = m;
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0001ca58(DAT_0030ebf4, DAT_002f3e94);
        int i;
        char *p;
        p = (char *)h->a;
        i = 0;
        do {
            FUN_000143b0(buf, DAT_002f3e24, i + 1);
            void *w = ::operator new(0x48);
            if (w != 0)
                w = FUN_00050fc0(w);
            *(void **)(p + 0x1a8) = w;
            FUN_000511c4(w, buf, 0);
            FUN_00051398(*(void **)(p + 0x1a8), 1100.0f);
            i++;
            p += 4;
        } while (i < 10);
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f3eb0);
        FUN_002afb80(DAT_0034a120, 0);
        FUN_002afce0(1);
        FUN_0001cb88(DAT_0030ebf4);
        FUN_0023302c(h, 9);
    }
    FUN_00232ec4(DAT_0034a664);
    return self;
}
