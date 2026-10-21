/* HSTMATCH module=hstp_trans_main.prx start=0x0024177c end=0x00241b18 symbol=FUN_0024177c lang=c++ */
/* Clone of src/eboot/menu_challenge_ctor_0023167c.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: each loop is a block with its own counter, table pointer and byte offset declared in that order (saved regs counter > pointer > offset), stores through (unsigned int)self + off + DISP and the reload through (unsigned long)self + off + DISP (the two casts stop MWCC folding them into one pointer), FUN_00051d38 declared (obj, float), the first widget slot re-read for the virtual call, FUN_0008f170 takes the tested global; names and types await human review. */
struct Widget {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5(int);
};
struct Rec3 {
    int idx;
    int key;
    int out;
};
extern unsigned DAT_003b2b44;
extern char DAT_0039c694[];
extern char DAT_0039c6bc[];
extern char *DAT_0039bf7c[];
extern Rec3 DAT_0039c2b4[];
extern int DAT_003e1a08;
extern "C" {
void FUN_0010873c(void *);
void FUN_00109a44(void *, char *, int);
void FUN_00108e6c(float, void *);
void FUN_001090f4(void *, int);
void FUN_000143b0(char *, char *, int);
void *FUN_00000bcc(int);
void *FUN_000518d4(void *);
void FUN_00051ad8(void *, char *, int);
void FUN_00051d38(void *, float);
Widget *FUN_00109304(void *, char *, int);
void *FUN_00108124(void *, int);
void FUN_00105570(void *, int);
void *FUN_0008f170(int);
}
extern "C" unsigned *FUN_0024177c(unsigned *self)
{
    char buf[256];
    FUN_0010873c(self);
    self[0] = (unsigned)&DAT_003b2b44;
    self[0x75] = 0;
    FUN_00109a44(self, DAT_0039c694, 0);
    FUN_00108e6c(1100.0f, self);
    FUN_001090f4(self, 17);
    {
    int i = 0;
    int off = 0;
    do {
        FUN_000143b0(buf, DAT_0039c6bc, i);
        void *mem = FUN_00000bcc(0x48);
        void *obj = mem;
        if (mem != 0) {
            obj = FUN_000518d4(mem);
        }
        *(void **)((unsigned int)self + off + 0x16c) = obj;
        FUN_00051ad8(obj, buf, 0);
        void *o2 = *(void **)((unsigned long)self + off + 0x16c);
        FUN_00051d38(o2, 1100.0f);
        i++;
        off += 4;
    } while (i < 15);
    }
    *(unsigned char *)(self + 0x76) = 1;
    *((unsigned char *)self + 0x1d9) = 1;
    *((unsigned char *)self + 0x1da) = 0;
    {
    int i = 0;
    char **names = DAT_0039bf7c;
    int off = 0;
    do {
        Widget *w = FUN_00109304(self, *names, 0);
        *(Widget **)((unsigned int)self + off + 0x54) = w;
        (*(Widget **)((unsigned int)self + off + 0x54))->m5(-2);
        i++;
        names++;
        off += 4;
    } while (i < 4);
    }
    {
    int i = 0;
    Rec3 *r = DAT_0039c2b4;
    int off = 0;
    do {
        void *h = FUN_00108124((void *)self[r->idx + 0x15], r->key);
        *(void **)((unsigned int)self + off + 100) = h;
        if (h != 0) {
            FUN_00105570(h, 17);
            r->out = *(int *)(*(char **)((unsigned long)self + off + 100) + 0x24);
        }
        i++;
        r++;
        off += 4;
    } while (i < 66);
    }
    FUN_00105570((void *)self[0x5a], 16);
    FUN_00105570((void *)self[0x30], 16);
    self[0x74] = 0;
    if (DAT_003e1a08 != 0) {
        void *v = FUN_0008f170(DAT_003e1a08);
        self[0x74] = (unsigned)v;
        FUN_00108e6c(2300.0f, v);
    }
    self[0x77] = 0;
    self[0x78] = 0;
    self[0x79] = 0;
    *(unsigned char *)(self + 0x7a) = 0;
    self[0x7b] = 0;
    self[0x7c] = 0;
    self[0x7d] = 0;
    self[0x7e] = 0;
    self[0x7f] = 0;
    int k = 0;
    unsigned *p = self;
    do {
        p[0x80] = 0; p[0x8a] = 0; p[0x94] = 0; p[0x9e] = 0; p[0xa8] = 0; p[0xb2] = 0;
        p[0x81] = 0; p[0x8b] = 0; p[0x95] = 0; p[0x9f] = 0; p[0xa9] = 0; p[0xb3] = 0;
        p[0x82] = 0; p[0x8c] = 0; p[0x96] = 0; p[0xa0] = 0; p[0xaa] = 0; p[0xb4] = 0;
        p[0x83] = 0; p[0x8d] = 0; p[0x97] = 0; p[0xa1] = 0; p[0xab] = 0; p[0xb5] = 0;
        p[0x84] = 0; p[0x8e] = 0; p[0x98] = 0; p[0xa2] = 0; p[0xac] = 0;
        k += 5;
        p[0xb6] = 0;
        p += 5;
    } while (k < 10);
    k = 0;
    p = self;
    do {
        k += 5;
        ((float *)p)[0xa8] = (float)(int)*(short *)(p[0x46] + 4);
        ((float *)p)[0xb2] = (float)(int)*(short *)(p[0x46] + 6);
        ((float *)p)[0xa9] = (float)(int)*(short *)(p[0x47] + 4);
        ((float *)p)[0xb3] = (float)(int)*(short *)(p[0x47] + 6);
        ((float *)p)[0xaa] = (float)(int)*(short *)(p[0x48] + 4);
        ((float *)p)[0xb4] = (float)(int)*(short *)(p[0x48] + 6);
        ((float *)p)[0xab] = (float)(int)*(short *)(p[0x49] + 4);
        ((float *)p)[0xb5] = (float)(int)*(short *)(p[0x49] + 6);
        ((float *)p)[0xac] = (float)(int)*(short *)(p[0x4a] + 4);
        ((float *)p)[0xb6] = (float)(int)*(short *)(p[0x4a] + 6);
        p += 5;
    } while (k < 10);
    return self;
}
