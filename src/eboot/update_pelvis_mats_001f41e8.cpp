/* HSTMATCH module=EBOOT.BIN start=0x001f41e8 end=0x001f44ec symbol=FUN_001f41e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the else-call of FUN_000657e4 passes a literal 1 that Ghidra drops (retail shares the compare constant in a2), Vec4 and the temp matrix copied field by field while the stored matrix is a struct assignment (row batches), the loop body indexes self->obj[i] / self->mat[i] (self-based induction pointers); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};
struct Node {
    char pad[0x50];
    Vec4 v;
};
struct Obj {
    virtual void m0();
    virtual void m1();
    char pad[0x58 - 4];
    Node *f58;
};
struct Tgt {
    char pad[0x90];
    void *f90;
};
struct Self {
    char pad[0x3a0];
    Obj *obj[4];
    int prm[4];
    char pad1[0x3cc - 0x3c0];
    int sel;
    char pad2[0x410 - 0x3d0];
    Mat4 mat[4];
    char pad3[0x584 - 0x510];
    Tgt *tgt;
};
extern Vec4 DAT_002bc430;
extern Vec4 DAT_002bc440;
extern unsigned char DAT_003417b8;
extern char DAT_002ee4c8[];
extern char DAT_002ee8d0[];
extern "C" {
float FUN_000657e4(void *, char *, ...);
void FUN_0004d2d4(float, Mat4 *, Mat4 *);
Mat4 *FUN_00093818(Obj *);
void FUN_00093434(Obj *, Mat4 *);
void FUN_001f37e4(Self *, Obj *, int, int, int, int);
void FUN_0005548c(Mat4 *, Node *, char *);
void FUN_001ed87c(Tgt *, Vec4 *, Vec4 *);
}

extern "C" void FUN_001f41e8(Self *self)
{
    Vec4 q;
    q.x = DAT_002bc440.x;
    q.y = DAT_002bc440.y;
    q.z = DAT_002bc440.z;
    q.w = DAT_002bc440.w;
    Vec4 p;
    p.x = DAT_002bc430.x;
    p.y = DAT_002bc430.y;
    p.z = DAT_002bc430.z;
    p.w = DAT_002bc430.w;
    float ang;
    if (DAT_003417b8 == 1) {
        ang = FUN_000657e4(self->tgt->f90, DAT_002ee4c8, 2);
    } else {
        ang = FUN_000657e4(self->tgt->f90, DAT_002ee4c8, 1);
    }
    int i = 0;
    do {
        Node *n = self->obj[i] ? self->obj[i]->f58 : 0;
        if (n != 0) {
            Mat4 *src = FUN_00093818(self->obj[i]);
            Mat4 t;
            t.r0.x = src->r0.x; t.r0.y = src->r0.y; t.r0.z = src->r0.z; t.r0.w = src->r0.w;
            t.r1.x = src->r1.x; t.r1.y = src->r1.y; t.r1.z = src->r1.z; t.r1.w = src->r1.w;
            t.r2.x = src->r2.x; t.r2.y = src->r2.y; t.r2.z = src->r2.z; t.r2.w = src->r2.w;
            t.r3.x = src->r3.x; t.r3.y = src->r3.y; t.r3.z = src->r3.z; t.r3.w = src->r3.w;
            FUN_0004d2d4(-ang * 0.017453292f, &t, &t);
            FUN_00093434(self->obj[i], &t);
            self->obj[i]->m1();
            self->mat[i] = *FUN_00093818(self->obj[i]);
            FUN_001f37e4(self, self->obj[i], self->prm[i], i, 5, 0);
            if (self->sel == i) {
                Mat4 pel;
                FUN_0005548c(&pel, n, DAT_002ee8d0);
                q.x = pel.r3.x;
                q.y = pel.r3.y;
                q.z = pel.r3.z;
                q.w = pel.r3.w;
                p.x = n->v.x;
                p.y = n->v.y;
                p.z = n->v.z;
                p.w = n->v.w;
            }
        }
        i++;
    } while (i < 4);
    FUN_001ed87c(self->tgt, &q, &p);
}
