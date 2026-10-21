/* HSTMATCH module=hstp_trans_main.prx start=0x0029993c end=0x00299a84 symbol=FUN_0029993c lang=c++ */
/* Clone of src/eboot/dialogue_action_dispatch_00288208.cpp (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot 11 gates on mode 4; the a4<1 arm calls slots 8 and 9 and releases two sound/handle objects, the other arm queues a 0x34 record through 0x289544 (insert into the circular list whose sentinel node sits at +0x68). The Key tail word is copied by the callee but never written here. */

extern "C" void FUN_00059c1c(void *o, float f, int n);
extern "C" void FUN_0005ff00(void *o, float f);
extern "C" void FUN_0029ace0(void *out, void *vec, void *list, void *key);

struct Node {
    Node *next;
    Node *prev;
};

struct Key {
    int type;
    int h;
    int a;
    int b;
    int d;
    int extra;
};

struct Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(void *a, int b);
    virtual void m9(int n);
    virtual void m10();
    virtual int m11();
    char pad[0x60];
    int count;
    Node sentinel;
    char *f70;
    char *f74;
};

extern "C" void FUN_0029993c(Obj *self, void *a1, int a2, unsigned a3, int a4)
{
    if (self->m11() != 4)
        return;
    if (a4 < 1) {
        self->m8(a1, a2 == 0);
        self->m9(a2 - 1);
        char *p = self->f70;
        if (a3 != 0) {
            char *q = self->f74;
            float z;
            if (*(char **)(p + 0xf4) != 0)
                z = *(float *)(**(char ***)(p + 0xf4) + 8);
            else
                z = 0.0f;
            FUN_00059c1c(p, z, -1);
            FUN_0005ff00(p, z);
            if (q != 0) {
                FUN_00059c1c(q, z, -1);
                FUN_0005ff00(q, z);
            }
        }
    } else {
        Key k;
        Node *out;
        k.d = a3 & 0xff;
        k.type = 0x34;
        Node *sent = &self->sentinel;
        k.h = a4;
        k.a = (int)a1;
        k.b = a2;
        FUN_0029ace0(&out, &self->count, &sent, &k);
    }
}
