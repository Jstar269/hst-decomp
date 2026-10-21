/* HSTMATCH module=hstp_trans_main.prx start=0x001dc818 end=0x001dc95c symbol=FUN_001dc818 lang=c++ */
/* Clone of src/eboot/item_check_001ce13c.cpp (hstclone.py tag c21sn2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

struct Obj {
    char pad0[0x30];
    char f30[16];
    int f40;
};

extern "C" {
int FUN_001dc504(Item *p);
int FUN_001dca04(Item *p);
int FUN_001dc9fc(Item *p);
int FUN_001dc9f4(int x);
int FUN_001dc95c(Obj *self, Item *p);
int FUN_001dc38c(Item *p);
int FUN_0029d550(int a, Item *p);
void FUN_00054e34(Vec4 *out, int a, void *b);
void FUN_000c77a0(Vec4 *out, Vec4 *in);
int FUN_001dc384(Item *p);
int FUN_001dc378(int x);
float FUN_001dc484(int a, Vec4 *v);
}

extern "C" unsigned char FUN_001dc818(Obj *self, Item **pp)
{
    Item *p = *pp;
    bool r = false;
    if (p != 0) {
        if (FUN_001dc504(p) != 0) {
            if (FUN_001dca04(p) != 0) {
                r = !FUN_001dc9f4(FUN_001dc9fc(p)) && FUN_001dc95c(self, p) != 0;
            } else if (FUN_001dc38c(p) != 0) {
                r = FUN_001dc95c(self, p) != 0 && FUN_0029d550(self->f40, p) != 0;
                if (r) {
                    Vec4 b;
                    Vec4 a;
                    FUN_00054e34(&a, p->v6(), self->f30);
                    FUN_000c77a0(&b, &a);
                    float f = FUN_001dc484(FUN_001dc378(FUN_001dc384(p)) + 0x20, &b);
                    if (f >= 0.0f)
                        r = false;
                    else
                        r = true;
                }
            }
        }
    }
    return !r;
}
