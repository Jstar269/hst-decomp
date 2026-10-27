/* HSTMATCH module=EBOOT.BIN start=0x000493fc end=0x000494d0 symbol=FUN_000493fc lang=c++ data=0x002d0758 */
/* Clone of src/sharing_main/remap_resource_path_000492ac.cpp (hstclone.py tag u6fr2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d0758-0x002d0765) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
    extern char *FUN_000149a8(char *dest, const char *src);
    extern char *FUN_00014d64(const char *s1, const char *s2);
    extern char *FUN_00014cfc(const char *s, int c);
    extern void FUN_000573a0(void *obj, int a1, const char *a2, int a3, int a4);
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

extern "C" void FUN_000493fc(Wrapper *param_1, int param_2, const char *param_3) {
    char path1[256];
    char path2[256];

    if (param_3 != 0) {
        if (param_1->obj->f_8c == 0) {
            FUN_000149a8(path1, param_3);
            char *sub = FUN_00014d64(path1, ".i3m");
            FUN_000149a8(sub, ".i3r");
            FUN_000149a8(path2, path1);
            char *slash = FUN_00014cfc(path2, 0x2f);
            slash[1] = 0;
            ((Callee *)param_1->obj)->vfunc(path1, path2, 0, 0, 0, 0);
        }
    }
    FUN_000573a0(param_1->obj, param_2, param_3, 0, 0);
}
