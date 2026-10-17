/* HSTMATCH module=hstp_trans_main.prx start=0x000492ac end=0x00049380 symbol=FUN_000492ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
    extern char DAT_00375ee8;
    extern char DAT_00375ef0;
    extern char *FUN_000149a8(char *dest, const char *src);
    extern char *FUN_00014d64(const char *s1, const char *s2);
    extern char *FUN_00014cfc(const char *s, int c);
    extern void FUN_00057ff4(void *obj, int a1, const char *a2, int a3, int a4);
}

struct Callee {
    virtual void dummy0();
    virtual void dummy1();
    virtual void vfunc(const char *p1, const char *p2, int a3, int a4, int a5, int a6);
};

struct Obj {
    char pad[0x8c];
    int f_8c;
};

struct Wrapper {
    Obj *obj;
};

extern "C" void FUN_000492ac(Wrapper *param_1, int param_2, const char *param_3) {
    char path1[256];
    char path2[256];

    if (param_3 != 0) {
        if (param_1->obj->f_8c == 0) {
            FUN_000149a8(path1, param_3);
            char *sub = FUN_00014d64(path1, &DAT_00375ee8);
            FUN_000149a8(sub, &DAT_00375ef0);
            FUN_000149a8(path2, path1);
            char *slash = FUN_00014cfc(path2, 0x2f);
            slash[1] = 0;
            ((Callee *)param_1->obj)->vfunc(path1, path2, 0, 0, 0, 0);
        }
    }
    FUN_00057ff4(param_1->obj, param_2, param_3, 0, 0);
}
