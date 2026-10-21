/* HSTMATCH module=hstp_trans_main.prx start=0x00126b40 end=0x00126c8c symbol=FUN_00126b40 lang=c++ */
/* Clone of src/eboot/action_scale_setup_0011b96c.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-flag gated update: after a global subsystem check, writes the pair of timer values at +0x24/+0x28 of the node payload, a scale in [0..1] derived from +0xcc, an intensity from +0xb8 and one more scale at +0x78, then flushes and advances the handler. */

extern unsigned DAT_0037c440;
extern void *DAT_003e1f60;
extern int DAT_003810ac[];
extern "C" int FUN_00100ef4(void *o);
extern "C" void FUN_00108dac(void *o);

struct VC_11b96c {
    virtual void s0();
    virtual void s1(int n);
    virtual void s2();
    virtual void s3();
    char pad0[0x60];
    float f64;
    char pad1[0x10];
    float f78;
};

struct Tgt_11b96c {
    char pad0[0x24];
    int a;
    int b;
};

struct Node_11b96c {
    void *f0;
    VC_11b96c *f4;
    Tgt_11b96c *f8;
};

struct Obj_11b96c {
    char pad0[0x3c];
    char *f3c;
    char pad1[0x70];
    int f_b0;
    char pad2[4];
    float f_b8;
    char pad3[0x0c];
    unsigned char f_c8;
    char pad4[3];
    int f_cc;
};

extern "C" void FUN_00126b40(Obj_11b96c *self)
{
    if ((DAT_0037c440 & 0x800) != 0) {
        if (DAT_003e1f60 != 0) {
            if (FUN_00100ef4(DAT_003e1f60) != 0)
                return;
        }
        if (self->f_c8 == 0) {
            Node_11b96c *n = *(Node_11b96c **)(self->f3c + 0x40);
            void *o = n->f0;
            int *tbl = DAT_003810ac;
            n->f4->s1(0);
            Tgt_11b96c *t = n->f8;
            int m = self->f_b0;
            int d;
            switch (m) {
            case 0:
            case 1:
                d = 0;
                break;
            }
            int v = d + tbl[2];
            t->a = v;
            t->b = v;
            int k = 0x80;
            if (self->f_cc < 6)
                k *= (float)self->f_cc / 5.0f;
            VC_11b96c *vc = n->f4;
            float f = self->f_b8;
            vc->f64 = f;
            vc->f78 = (float)k / 128.0f;
            FUN_00108dac(o);
            ((VC_11b96c *)o)->s3();
        }
    }
}
