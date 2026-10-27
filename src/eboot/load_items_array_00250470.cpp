/* HSTMATCH module=EBOOT.BIN start=0x00250470 end=0x002505a0 symbol=FUN_00250470 lang=c++ data=0x002fcb58 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: `p = alloc(0x48); if (p) p = ctor(p); self->field = p;` merged-store idiom and `FUN_00051398(2000.0f, ...)` float first argument; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002fcb58-0x002fcbbe) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Obj_000511c4 {
    virtual ~Obj_000511c4();
};

struct Self_00250470 {
    char pad[0x1dc];
    Obj_000511c4 *items[15];
    Obj_000511c4 *extra0;
    Obj_000511c4 *extra1;
};

extern "C" {
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, const char *, ...);
extern Obj_000511c4 *FUN_00050fc0(void *);
extern void FUN_000511c4(Obj_000511c4 *, char *, int);
extern void FUN_00051398(float, Obj_000511c4 *);
}

extern "C" void FUN_00250470(Self_00250470 *self)
{
    char buf[256];

    for (int i = 0; i < 15; i++) {
        FUN_000143b0(buf, "data/menu/exhibition/exhi_chara%02d", i);
        Obj_000511c4 *p = (Obj_000511c4 *)FUN_00000bcc(0x48);
        if (p != 0) {
            p = FUN_00050fc0(p);
        }
        self->items[i] = p;
        FUN_000511c4(p, buf, 0);
        FUN_00051398(2000.0f, self->items[i]);
    }

    FUN_000143b0(buf, "data/menu/exhibition/exhi_random");
    Obj_000511c4 *p0 = (Obj_000511c4 *)FUN_00000bcc(0x48);
    if (p0 != 0) {
        p0 = FUN_00050fc0(p0);
    }
    self->extra0 = p0;
    FUN_000511c4(p0, buf, 0);
    FUN_00051398(2000.0f, self->extra0);

    FUN_000143b0(buf, "data/menu/exhibition/exv_bg00");
    Obj_000511c4 *p1 = (Obj_000511c4 *)FUN_00000bcc(0x48);
    if (p1 != 0) {
        p1 = FUN_00050fc0(p1);
    }
    self->extra1 = p1;
    FUN_000511c4(p1, buf, 0);
    FUN_00051398(2000.0f, self->extra1);
}
