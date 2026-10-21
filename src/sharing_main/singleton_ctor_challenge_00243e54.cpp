/* HSTMATCH module=hstp_trans_main.prx start=0x00243e54 end=0x0024403c symbol=FUN_00243e54 lang=c++ */
/* Clone of src/eboot/singleton_ctor_challenge_00233d54.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
extern char DAT_003b2b28[];
extern void *DAT_003f3998;
extern Holder *DAT_003f3994;
extern int DAT_003f3458;
extern char DAT_003b7ebc[];
extern char DAT_0039c73c[];
extern char DAT_0039c758[];
extern char DAT_0039c6e8[];
extern char DAT_0039c774[];

extern void FUN_0001ec44(void *);
extern void *FUN_00000bcc(unsigned);
extern void FUN_0001c684(void *, int, char *);
extern void FUN_0001c73c(void *);
extern void FUN_0001c5f4(void *, char *);
extern void *FUN_0024177c(void *);
extern void *FUN_0022f648(void *);
extern void *FUN_00230474(void *);
extern int FUN_000143b0(char *, char *, ...);
extern void *FUN_000518d4(void *);
extern void FUN_00051ad8(void *, char *, int);
extern void FUN_00051d38(void *, float);
extern void FUN_002bf5d0(int, int);
extern void FUN_002bf730(int);
extern void FUN_0024312c(Holder *, int);
extern void FUN_00242fc4(Holder *);
}

extern "C" char *FUN_00243e54(char *self)
{
    char buf[256];
    FUN_0001ec44(self);
    *(void **)self = DAT_003b2b28;
    DAT_003f3998 = self;
    Holder *h;
    if (DAT_003f3994 == 0 && (h = (Holder *)::operator new(0x14)) != 0) {
        h->a = 0;
        h->b = 0;
        DAT_003f3994 = h;
        h->f10 = 0;
        h->f11 = 0;
        h->f12 = 0;
        FUN_0001c684(DAT_003b7ebc, 1, DAT_0039c73c);
        void *m = ::operator new(0x2f0);
        if (m != 0)
            h->a = FUN_0024177c(m);
        else
            h->a = m;
        m = ::operator new(0x78);
        if (m != 0)
            h->b = FUN_0022f648(m);
        else
            h->b = m;
        m = ::operator new(0xa0);
        if (m != 0)
            m = FUN_00230474(m);
        h->c = m;
        FUN_0001c73c(DAT_003b7ebc);
        FUN_0001c5f4(DAT_003b7ebc, DAT_0039c758);
        int i;
        char *p;
        p = (char *)h->a;
        i = 0;
        do {
            FUN_000143b0(buf, DAT_0039c6e8, i + 1);
            void *w = ::operator new(0x48);
            if (w != 0)
                w = FUN_000518d4(w);
            *(void **)(p + 0x1a8) = w;
            FUN_00051ad8(w, buf, 0);
            FUN_00051d38(*(void **)(p + 0x1a8), 1100.0f);
            i++;
            p += 4;
        } while (i < 10);
        FUN_0001c73c(DAT_003b7ebc);
        FUN_0001c684(DAT_003b7ebc, 1, DAT_0039c774);
        FUN_002bf5d0(DAT_003f3458, 0);
        FUN_002bf730(1);
        FUN_0001c73c(DAT_003b7ebc);
        FUN_0024312c(h, 9);
    }
    FUN_00242fc4(DAT_003f3994);
    return self;
}
