/* HSTMATCH module=EBOOT.BIN start=0x001ca60c end=0x001ca8e8 symbol=FUN_001ca60c lang=c++ data=0x002eaa50 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: Vec4 copies written field by field (a struct copy batches the loads), the scratch Vec4 w2 declared before w (frame slots 64/48), the matrix copied by initialisation, FUN_00022498 declared (out, in, float) so the float move lands in the jal slot, the outer loop as do/while (i < RING_COUNT) with the epilogue after it; names and types await human review. Data: its string literals (1 strings, 0x002eaa50-0x002eaa61) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};
struct Cam {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual Vec4 *Pos();
};
enum { RING_COUNT = 2, STEP_COUNT = 24 }; /* candidate rings, candidate angles per ring */

extern Cam *DAT_0034a118;
extern Mat4 DAT_002bc410;
extern char DAT_002eaa64[];
extern char DAT_002eaa68[];
extern char DAT_002eaa6c[];
extern "C" {
void FUN_001c5018(char *, ...);
void FUN_0004d2d4(float, Mat4 *, Mat4 *);
void FUN_00022548(Vec4 *, Mat4 *, Vec4 *);
void FUN_00022498(Vec4 *, Vec4 *, float);
void FUN_00022418(Vec4 *, Vec4 *, Vec4 *);
int FUN_001293b4(float, Vec4 *, Vec4 *, int *);
int FUN_00128f60(float, int, Vec4 *);
}

/* Try candidate positions around the start position (24 rotations of dir, two lengths); store the first free one in out and return 1, else restore the start position and return 0. */
extern "C" int FUN_001ca60c(int unused, Vec4 *dir, Vec4 *out)
{
    Vec4 *start = DAT_0034a118->Pos();
    Vec4 pos;
    pos.x = start->x;
    pos.y = start->y;
    pos.z = start->z;
    pos.w = start->w;
    int hit = 0;
    FUN_001c5018("search Apl Pos: ");
    int i = 0;
    do {
        int j = 0;
        int label = 0;
        do {
            out->x = pos.x;
            out->y = pos.y;
            out->z = pos.z;
            out->w = pos.w;
            Vec4 v;
            v.x = dir->x;
            v.y = dir->y;
            v.z = dir->z;
            v.w = dir->w;
            Mat4 m = DAT_002bc410;
            FUN_0004d2d4((float)(j + 6) * 0.17453294f, &m, &m);
            FUN_00022548(&v, &m, &v);
            Vec4 w2;
            Vec4 w;
            FUN_00022498(&w, &v, 1.5f - (float)i * 0.5f);
            w2 = w;
            FUN_00022418(out, out, &w2);
            FUN_001c5018(DAT_002eaa64, label);
            if (FUN_001293b4(0.0f, out, &pos, &hit) == 0 && FUN_00128f60(0.0f, 0, out) == 0) {
                FUN_001c5018(DAT_002eaa68);
                return 1;
            }
            j++;
            label += 10;
        } while (j < STEP_COUNT);
        i++;
    } while (i < RING_COUNT);
    FUN_001c5018(DAT_002eaa6c);
    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
    out->w = pos.w;
    return 0;
}
