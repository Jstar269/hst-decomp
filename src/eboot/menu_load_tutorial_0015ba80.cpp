/* HSTMATCH module=EBOOT.BIN start=0x0015ba80 end=0x0015bc5c symbol=FUN_0015ba80 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj_000511c4 {
    virtual ~Obj_000511c4();
};

struct Obj {
    char pad0[0x34];
    Obj_000511c4 *obj34;
    Obj_000511c4 *obj38;
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
extern char DAT_002de29c[];
extern char DAT_002de2b4[];
extern char DAT_002de2d4[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned);
extern void FUN_000143b0(char *, const char *, ...);
extern int FUN_00014934(char *, char *);
extern void FUN_000149a8(char *, char *);
extern void FUN_0001cad0(char *, int, char *);
extern void FUN_0001cb88(char *);
extern Obj_000511c4 *FUN_00050fc0(void *);
extern void FUN_000511c4(Obj_000511c4 *, char *, int);
extern void FUN_00051398(float, Obj_000511c4 *);
}

extern "C" void FUN_0015ba80(Obj *self, int param_2) {
    FUN_000143b0(self->buf370, DAT_002de29c);
    FUN_0001cad0(DAT_0030ebf4, 1, self->buf370);
    FUN_000143b0(self->buf370, DAT_002de2b4);

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

    FUN_000143b0(self->buf370, DAT_002de2d4, param_2 + 1);

    if (self->obj38 == 0 || FUN_00014934(self->sub170, self->buf370) != 0) {
        if (self->obj38 != 0) {
            delete self->obj38;
            self->obj38 = 0;
        }
        Obj_000511c4 *q = (Obj_000511c4 *)FUN_00000bcc(0x48);
        if (q != 0) {
            q = FUN_00050fc0(q);
        }
        self->obj38 = q;
        FUN_000511c4(q, self->buf370, 0);
        FUN_00051398(3000.0f, self->obj38);
        FUN_000149a8(self->sub170, self->buf370);
        self->f50 = 0.0f;
        self->f54 = 15.0f;
        self->f58 = 0.0f;
        self->f5c = 1.0f;
    }

    FUN_0001cb88(DAT_0030ebf4);
}
