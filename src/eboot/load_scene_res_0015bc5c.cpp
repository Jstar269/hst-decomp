/* HSTMATCH module=EBOOT.BIN start=0x0015bc5c end=0x0015be74 symbol=FUN_0015bc5c lang=c++ data=0x002de2f8 */
/* Clone of src/sharing_main/load_scene_res_00168204.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002de2f8-0x002de34c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v0c) corrected by hand: C++ struct layout, virtual deleting destructors, and null-checked allocations; exact match verified; names and types await human review. */
struct Obj_00102e38 {
    virtual ~Obj_00102e38();
};

struct Obj_000511c4 {
    virtual ~Obj_000511c4();
};

struct Item_001026b8 {
    char pad[0x24];
    int f24;
    int f28;
};

struct Self_0015bc5c {
    char pad00[0x28];
    Obj_00102e38 *obj28;
    char pad2c[0x34 - 0x2c];
    Obj_000511c4 *obj34;
    char pad38[0x40 - 0x38];
    float f40;
    float f44;
    float f48;
    float f4c;
    char pad50[0x70 - 0x50];
    char sub70[0x300];
    char buf370[1];
};

extern "C" {
extern char DAT_002de050[];
extern char DAT_002de074[];
extern char DAT_0030ebf4[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, ...);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001cad0(char *, int, char *);
extern void FUN_0001cb88(char *);
extern Obj_000511c4 *FUN_00050fc0(void *);
extern void FUN_000511c4(Obj_000511c4 *, char *, int);
extern void FUN_00051398(float, Obj_000511c4 *);
extern void FUN_000ffb3c(Item_001026b8 *, int);
extern Item_001026b8 *FUN_001026b8(void *, char *);
extern Obj_00102e38 *FUN_00102e38(void *);
extern void FUN_00103628(Obj_00102e38 *, int);
extern void *FUN_001039d8(Obj_00102e38 *, char *, int);
extern void FUN_00104118(Obj_00102e38 *, char *, int);
}

extern "C" void FUN_0015bc5c(Self_0015bc5c *self, int name)
{
    FUN_000143b0(self->buf370, DAT_002de050, name);
    FUN_0001cad0(DAT_0030ebf4, 1, self->buf370);
    FUN_000143b0(self->buf370, DAT_002de074, name);
    if (self->obj34 == 0 || FUN_00014934(self->sub70, self->buf370) != 0) {
        if (self->obj34 != 0) {
            delete self->obj34;
            self->obj34 = 0;
        }
        Obj_000511c4 *p = (Obj_000511c4 *)FUN_00000bcc(0x48);
        if (p != 0) {
            p = FUN_00050fc0(p);
        }
        self->obj34 = p;
        FUN_000511c4(p, self->buf370, 0);
        FUN_00051398(3000.0f, self->obj34);
        FUN_000149a8(self->sub70, self->buf370);
        self->f40 = 0.0f;
        self->f44 = 0.0f;
        self->f48 = 0.0f;
        self->f4c = 1.0f;
    }
    FUN_0001cb88(DAT_0030ebf4);
    FUN_000143b0(self->buf370, "menu/loadmes/court/loadmes_courtname.xb");
    FUN_0001cad0(DAT_0030ebf4, 1, self->buf370);
    if (self->obj28 != 0) {
        if (self->obj28 != 0) {
            delete self->obj28;
            self->obj28 = 0;
        }
    }
    Obj_00102e38 *q = (Obj_00102e38 *)FUN_00000bcc(0x54);
    if (q != 0) {
        q = FUN_00102e38(q);
    }
    Obj_00102e38 *o28 = q;
    self->obj28 = o28;
    FUN_00104118(o28, "data/menu/loadmes/ac00lay.lay", 0);
    FUN_00103628(self->obj28, 0);
    void *grp = FUN_001039d8(self->obj28, "ac", 0);
    if (grp != 0) {
        Item_001026b8 *item = FUN_001026b8(grp, "c_text0");
        if (item != 0) {
            FUN_000ffb3c(item, 0);
            int v = name + item->f24 - 1;
            item->f24 = v;
            item->f28 = v;
        }
    }
    FUN_0001cb88(DAT_0030ebf4);
}
