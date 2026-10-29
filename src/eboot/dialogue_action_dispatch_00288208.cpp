/* HSTMATCH module=EBOOT.BIN start=0x00288208 end=0x00288350 symbol=FUN_00288208 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot 11 gates on mode 4; the count<1 arm calls slots 8 and 9 and releases two sound/handle objects, the other arm queues a 0x34 record through 0x289544 (insert into the circular list whose sentinel node sits at +0x68). The Key tail word is copied by the callee but never written here. */

enum { MODE_ACTIVE = 4, RECORD_TAG_QUEUED = 0x34 };

extern "C" void FUN_00058f38(void *o, float f, int n);
extern "C" void FUN_0005f110(void *o, float f);
extern "C" void FUN_00289544(void *out, void *vec, void *list, void *key);

struct Node {
    Node *next;
    Node *prev;
};

/* Queued record; `extra` is never written here. */
struct Key {
    int type;
    int count;
    int target;
    int index;
    int flag;
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
    virtual void m8(void *target, int b);
    virtual void m9(int n);
    virtual void m10();
    virtual int mode();
    char pad04[0x60];
    int size;       /* 0x64 list header: count, then the sentinel */
    Node sentinel;  /* 0x68 */
    char *obj_a;    /* 0x70 */
    char *obj_b;    /* 0x74 */
};

extern "C" void FUN_00288208(Obj *self, void *target, int index, unsigned flag, int count)
{
    if (self->mode() != MODE_ACTIVE)
        return;
    if (count < 1) {
        self->m8(target, index == 0);
        self->m9(index - 1);
        char *a = self->obj_a;
        if (flag != 0) {
            char *b = self->obj_b;
            float z;
            if (*(char **)(a + 0xf4) != 0)
                z = *(float *)(**(char ***)(a + 0xf4) + 8);
            else
                z = 0.0f;
            FUN_00058f38(a, z, -1);
            FUN_0005f110(a, z);
            if (b != 0) {
                FUN_00058f38(b, z, -1);
                FUN_0005f110(b, z);
            }
        }
    } else {
        Key key;
        Node *out;
        key.flag = flag & 0xff;
        key.type = RECORD_TAG_QUEUED;
        Node *sent = &self->sentinel;
        key.count = count;
        key.target = (int)target;
        key.index = index;
        FUN_00289544(&out, &self->size, &sent, &key);
    }
}
