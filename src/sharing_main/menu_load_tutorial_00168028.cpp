/* HSTMATCH module=hstp_trans_main.prx start=0x00168028 end=0x00168204 symbol=FUN_00168028 lang=c++ data=0x00385858 */
/* Clone of src/eboot/menu_load_tutorial_0015ba80.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x00385858-0x003858b1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj_00051ad8 {
    virtual ~Obj_00051ad8();
};

struct Obj {
    char pad0[0x34];
    Obj_00051ad8 *obj34;
    Obj_00051ad8 *obj38;
    char pad3c[0x40 - 0x3c];
    float f40;
    float f44;
    float f48;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    char pad60[0x70 - 0x60];
    char sub70[0x170 - 0x70];
    char sub170[0x370 - 0x170];
    char buf370[1];
};

extern "C" {
extern char DAT_003b7ebc[];

extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, const char *, ...);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001c684(char *, int, char *);
extern void FUN_0001c73c(char *);
extern Obj_00051ad8 *FUN_000518d4(void *);
extern void FUN_00051ad8(Obj_00051ad8 *, char *, int);
extern void FUN_00051d38(float, Obj_00051ad8 *);
}

extern "C" void FUN_00168028(Obj *self, int param_2) {
    FUN_000143b0(self->buf370, "menu/020_tutorial.xb");
    FUN_0001c684(DAT_003b7ebc, 1, self->buf370);
    FUN_000143b0(self->buf370, "data/menu/tutorial/tutorial_bg");

    if (self->obj34 == 0 || FUN_00014934(self->sub70, self->buf370) != 0) {
        if (self->obj34 != 0) {
            delete self->obj34;
            self->obj34 = 0;
        }
        Obj_00051ad8 *p = (Obj_00051ad8 *)FUN_00000bcc(0x48);
        if (p != 0) {
            p = FUN_000518d4(p);
        }
        self->obj34 = p;
        FUN_00051ad8(p, self->buf370, 0);
        FUN_00051d38(3000.0f, self->obj34);
        FUN_000149a8(self->sub70, self->buf370);
        self->f40 = 0.0f;
        self->f44 = 0.0f;
        self->f48 = 0.0f;
        self->f4c = 1.0f;
    }

    FUN_000143b0(self->buf370, "data/menu/tutorial/tutorial_%03d", param_2 + 1);

    if (self->obj38 == 0 || FUN_00014934(self->sub170, self->buf370) != 0) {
        if (self->obj38 != 0) {
            delete self->obj38;
            self->obj38 = 0;
        }
        Obj_00051ad8 *q = (Obj_00051ad8 *)FUN_00000bcc(0x48);
        if (q != 0) {
            q = FUN_000518d4(q);
        }
        self->obj38 = q;
        FUN_00051ad8(q, self->buf370, 0);
        FUN_00051d38(3000.0f, self->obj38);
        FUN_000149a8(self->sub170, self->buf370);
        self->f50 = 0.0f;
        self->f54 = 15.0f;
        self->f58 = 0.0f;
        self->f5c = 1.0f;
    }

    FUN_0001c73c(DAT_003b7ebc);
}
