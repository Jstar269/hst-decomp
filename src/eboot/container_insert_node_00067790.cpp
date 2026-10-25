/* HSTMATCH module=EBOOT.BIN start=0x00067790 end=0x00067828 symbol=FUN_00067790 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma exceptions off

struct Base1 {
    virtual void v0();
    virtual void * v1(void *arg);
};

struct Base2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(void *arg);
};

extern "C" void FUN_00067a3c(void *a, void *b, void *c, void *d);

extern "C" void * FUN_00067798(char *self, Base1 *obj);

extern "C" void * FUN_00067790(char *self, Base1 *obj)
{
    return FUN_00067798(self, obj);
}

extern "C" void * FUN_00067798(char *self, Base1 *obj)
{
    if (obj == 0) {
        return 0;
    }

    void *node = obj->v1(self);
    if (node == 0) {
        return 0;
    }

    void *local_24;
    void *local_20 = self + 64;
    FUN_00067a3c(&local_24, self + 60, &local_20, &node);

    ((Base2 *)node)->v6(obj);
    return node;
}
