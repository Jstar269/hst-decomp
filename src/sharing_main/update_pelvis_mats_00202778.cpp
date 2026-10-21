/* HSTMATCH module=hstp_trans_main.prx start=0x00202778 end=0x00202a7c symbol=FUN_00202778 lang=c++ */
/* Clone of src/eboot/update_pelvis_mats_001f41e8.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the else-call of FUN_00066bb0 passes a literal 1 that Ghidra drops (retail shares the compare constant in a2), Vec4 and the temp matrix copied field by field while the stored matrix is a struct assignment (row batches), the loop body indexes self->obj[i] / self->mat[i] (self-based induction pointers); names and types await human review. */
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
extern Vec4 DAT_002cc280;
extern Vec4 DAT_002cc290;
extern unsigned char DAT_003eaaf0;
extern char DAT_00396454[];
extern char DAT_003968d0[];
extern "C" {
float FUN_00066bb0(void *, char *, ...);
void FUN_0004d64c(float, Mat4 *, Mat4 *);
Mat4 *FUN_0009573c(Obj *);
void FUN_00095358(Obj *, Mat4 *);
void FUN_00201ca4(Self *, Obj *, int, int, int, int);
void FUN_00056008(Mat4 *, Node *, char *);
void FUN_001fbc44(Tgt *, Vec4 *, Vec4 *);
}

extern "C" void FUN_00202778(Self *self)
{
    Vec4 q;
    q.x = DAT_002cc290.x;
    q.y = DAT_002cc290.y;
    q.z = DAT_002cc290.z;
    q.w = DAT_002cc290.w;
    Vec4 p;
    p.x = DAT_002cc280.x;
    p.y = DAT_002cc280.y;
    p.z = DAT_002cc280.z;
    p.w = DAT_002cc280.w;
    float ang;
    if (DAT_003eaaf0 == 1) {
        ang = FUN_00066bb0(self->tgt->f90, DAT_00396454, 2);
    } else {
        ang = FUN_00066bb0(self->tgt->f90, DAT_00396454, 1);
    }
    int i = 0;
    do {
        Node *n = self->obj[i] ? self->obj[i]->f58 : 0;
        if (n != 0) {
            Mat4 *src = FUN_0009573c(self->obj[i]);
            Mat4 t;
            t.r0.x = src->r0.x; t.r0.y = src->r0.y; t.r0.z = src->r0.z; t.r0.w = src->r0.w;
            t.r1.x = src->r1.x; t.r1.y = src->r1.y; t.r1.z = src->r1.z; t.r1.w = src->r1.w;
            t.r2.x = src->r2.x; t.r2.y = src->r2.y; t.r2.z = src->r2.z; t.r2.w = src->r2.w;
            t.r3.x = src->r3.x; t.r3.y = src->r3.y; t.r3.z = src->r3.z; t.r3.w = src->r3.w;
            FUN_0004d64c(-ang * 0.017453292f, &t, &t);
            FUN_00095358(self->obj[i], &t);
            self->obj[i]->m1();
            self->mat[i] = *FUN_0009573c(self->obj[i]);
            FUN_00201ca4(self, self->obj[i], self->prm[i], i, 5, 0);
            if (self->sel == i) {
                Mat4 pel;
                FUN_00056008(&pel, n, DAT_003968d0);
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
    FUN_001fbc44(self->tgt, &q, &p);
}
