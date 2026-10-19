/* HSTMATCH module=hstp_trans_main.prx start=0x002607c4 end=0x002608f4 symbol=FUN_002607c4 lang=c++ */
/* Clone of src/eboot/load_items_array_00250470.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: `p = alloc(0x48); if (p) p = ctor(p); self->field = p;` merged-store idiom and `FUN_00051d38(2000.0f, ...)` float first argument; exact match verified; names and types await human review. */
struct Obj_00051ad8 {
    virtual ~Obj_00051ad8();
};

struct Self_002607c4 {
    char pad[0x1dc];
    Obj_00051ad8 *items[15];
    Obj_00051ad8 *extra0;
    Obj_00051ad8 *extra1;
};

extern "C" {
extern char DAT_003a564c[];
extern char DAT_003a5670[];
extern char DAT_003a5694[];
extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, const char *, ...);
extern Obj_00051ad8 *FUN_000518d4(void *);
extern void FUN_00051ad8(Obj_00051ad8 *, char *, int);
extern void FUN_00051d38(float, Obj_00051ad8 *);
}

extern "C" void FUN_002607c4(Self_002607c4 *self)
{
    char buf[256];

    for (int i = 0; i < 15; i++) {
        FUN_000143b0(buf, DAT_003a564c, i);
        Obj_00051ad8 *p = (Obj_00051ad8 *)FUN_00000bcc(0x48);
        if (p != 0) {
            p = FUN_000518d4(p);
        }
        self->items[i] = p;
        FUN_00051ad8(p, buf, 0);
        FUN_00051d38(2000.0f, self->items[i]);
    }

    FUN_000143b0(buf, DAT_003a5670);
    Obj_00051ad8 *p0 = (Obj_00051ad8 *)FUN_00000bcc(0x48);
    if (p0 != 0) {
        p0 = FUN_000518d4(p0);
    }
    self->extra0 = p0;
    FUN_00051ad8(p0, buf, 0);
    FUN_00051d38(2000.0f, self->extra0);

    FUN_000143b0(buf, DAT_003a5694);
    Obj_00051ad8 *p1 = (Obj_00051ad8 *)FUN_00000bcc(0x48);
    if (p1 != 0) {
        p1 = FUN_000518d4(p1);
    }
    self->extra1 = p1;
    FUN_00051ad8(p1, buf, 0);
    FUN_00051d38(2000.0f, self->extra1);
}
