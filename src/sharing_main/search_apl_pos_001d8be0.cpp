/* HSTMATCH module=hstp_trans_main.prx start=0x001d8be0 end=0x001d8ebc symbol=FUN_001d8be0 lang=c++ data=0x00392820 */
/* Clone of src/eboot/search_apl_pos_001ca60c.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00392820-0x00392831) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: Vec4 copies written field by field (a struct copy batches the loads), the scratch Vec4 w2 declared before w (frame slots 64/48), the matrix copied by initialisation, FUN_000224c0 declared (out, in, float) so the float move lands in the jal slot, the outer loop as do/while (i < 2) with the epilogue after it; names and types await human review. */
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
extern Cam *DAT_003f3450;
extern Mat4 DAT_002cc260;
extern char DAT_00392834[];
extern char DAT_00392838[];
extern char DAT_0039283c[];
extern "C" {
void FUN_001d0468(char *, ...);
void FUN_0004d64c(float, Mat4 *, Mat4 *);
void FUN_00022570(Vec4 *, Mat4 *, Vec4 *);
void FUN_000224c0(Vec4 *, Vec4 *, float);
void FUN_00022440(Vec4 *, Vec4 *, Vec4 *);
int FUN_00134624(float, Vec4 *, Vec4 *, int *);
int FUN_001341d0(float, int, Vec4 *);
}

extern "C" int FUN_001d8be0(int unused, Vec4 *dir, Vec4 *out)
{
    Vec4 *p = DAT_003f3450->Pos();
    Vec4 pos;
    pos.x = p->x;
    pos.y = p->y;
    pos.z = p->z;
    pos.w = p->w;
    int local4 = 0;
    FUN_001d0468("search Apl Pos: ");
    int i = 0;
    do {
        int j = 0;
        int cnt = 0;
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
            Mat4 m = DAT_002cc260;
            FUN_0004d64c((float)(j + 6) * 0.17453294f, &m, &m);
            FUN_00022570(&v, &m, &v);
            Vec4 w2;
            Vec4 w;
            FUN_000224c0(&w, &v, 1.5f - (float)i * 0.5f);
            w2 = w;
            FUN_00022440(out, out, &w2);
            FUN_001d0468(DAT_00392834, cnt);
            if (FUN_00134624(0.0f, out, &pos, &local4) == 0 && FUN_001341d0(0.0f, 0, out) == 0) {
                FUN_001d0468(DAT_00392838);
                return 1;
            }
            j++;
            cnt += 10;
        } while (j < 24);
        i++;
    } while (i < 2);
    FUN_001d0468(DAT_0039283c);
    out->x = pos.x;
    out->y = pos.y;
    out->z = pos.z;
    out->w = pos.w;
    return 0;
}
