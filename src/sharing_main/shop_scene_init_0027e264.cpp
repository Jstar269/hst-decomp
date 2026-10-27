/* HSTMATCH module=hstp_trans_main.prx start=0x0027e264 end=0x0027e63c symbol=FUN_0027e264 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/shop_scene_init_0026d224.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Shop scene init: reads chrsel_param_scroll.csv by row position, loads face_dummy.i3r; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Reader { int a, b, c, d; };

class Model {
public:
    virtual void m0();
    virtual void m1();
    virtual void Load(const char *, int, int, int, int, int);
};

extern "C" char DAT_003b3e6c;
extern "C" char DAT_003b7ebc;
extern "C" char DAT_003a6e1c[];
extern "C" char DAT_003a6e2c[];
extern "C" char DAT_003a6e4c[];
extern "C" char DAT_003a6e74[];
extern "C" char DAT_003a6ea0[];
extern "C" char DAT_003a6ec0[];
extern "C" char DAT_003a6eec[];
extern "C" char DAT_003eaad8;
extern "C" int DAT_003da704;
extern "C" int DAT_003e1a08;

extern "C" {
void *FUN_00010184(int, int);
void FUN_0001bb2c(void *, void *, int);
void FUN_0001c684(void *, int, void *);
void FUN_00109a44(void *, void *, int);
void *FUN_00000bcc(int);
void *FUN_0010873c(void *);
void *FUN_000577ec(void *);
void FUN_001c0fa8(void *);
void FUN_001090f4(void *, int);
void FUN_00108e6c(void *, float);
void *FUN_00231c28(void *, int);
void FUN_00232650(void *, float, float);
void *FUN_0022cd38(void *);
void FUN_00065884(Reader *);
void FUN_00065ab8(Reader *, void *, int, void *);
int FUN_00066038(Reader *, int, int);
void FUN_0001c73c(void *);
int FUN_0001c848();
int FUN_0001c8a0();
void FUN_000104e0(void *);
void FUN_002a5278(void *);
void FUN_001c1f44(void *, int);
void FUN_0005c700(void *, int);
float FUN_0000c018(float);
void FUN_0005c85c(void *, float, float, float, float, float, float);
void FUN_0005d3f4(void *, float, float, float, float);
void FUN_0005d580(void *, int, Vec4 *, Vec4 *);
void FUN_0005c8e0(void *);
void *FUN_0008f170(int);
void FUN_000658cc(Reader *, int);

int FUN_0027e264(char *o)
{
    void *buf = FUN_00010184(0x40, 0x280000);
    FUN_0001bb2c(&DAT_003b3e6c, buf, 0x280000);
    FUN_0001c684(&DAT_003b7ebc, 1, DAT_003a6e1c);
    FUN_00109a44(o + 0x3c, DAT_003a6e2c, 0);
    void *p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_0010873c(p);
    }
    *(void **)(o + 0xfc) = p;
    FUN_00109a44(p, DAT_003a6e4c, 0);
    void *q = FUN_00000bcc(0x1b0);
    void *m;
    if (q != 0) {
        m = FUN_000577ec(q);
        *(void **)(o + 0xf4) = m;
    } else {
        *(void **)(o + 0xf4) = q;
        m = q;
    }
    ((Model *)m)->Load(DAT_003a6e74, 0, 0, 0, 0, 0);
    FUN_001c0fa8(&DAT_003eaad8);
    p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_0010873c(p);
    }
    *(void **)(o + 0x100) = p;
    FUN_00109a44(p, DAT_003a6ea0, 0);
    FUN_001090f4(*(void **)(o + 0x100), -2);
    FUN_00108e6c(*(void **)(o + 0x100), 2000.0f);
    void *r = FUN_00000bcc(0xcc);
    void *rm;
    if (r != 0) {
        rm = FUN_00231c28(r, 1);
        *(void **)(o + 0xa0c) = rm;
    } else {
        *(void **)(o + 0xa0c) = r;
        rm = r;
    }
    FUN_001090f4(rm, -1);
    FUN_00232650(*(void **)(o + 0xa0c), 110.0f, 50.0f);
    void *s = FUN_00000bcc(0x210);
    void *sm;
    if (s != 0) {
        sm = FUN_0022cd38(s);
        *(void **)(o + 0xa3c) = sm;
    } else {
        *(void **)(o + 0xa3c) = s;
        sm = s;
    }
    FUN_001090f4(sm, -1);
    Reader rd;
    FUN_00065884(&rd);
    FUN_00065ab8(&rd, DAT_003a6ec0, 0, DAT_003a6eec);
    *(int *)(o + 0x98c) = FUN_00066038(&rd, 0, 1);
    *(int *)(o + 0x990) = FUN_00066038(&rd, 1, 1);
    *(int *)(o + 0x994) = FUN_00066038(&rd, 2, 1);
    FUN_0001c73c(&DAT_003b7ebc);
    int a = FUN_0001c848();
    int b = FUN_0001c8a0();
    FUN_0001bb2c(&DAT_003b3e6c, (void *)a, b);
    if (buf != 0) {
        FUN_000104e0(buf);
    }
    FUN_002a5278(o + 0x920);
    FUN_001c1f44(&DAT_003eaad8, 8);
    FUN_00108e6c(o + 0x3c, 2000.0f);
    FUN_001090f4(o + 0x3c, 4);
    FUN_0005c700(o + 0x190, DAT_003da704);
    *(float *)(o + 0x360) = 0.0f;
    *(float *)(o + 0x364) = -1.0f;
    *(float *)(o + 0x368) = 5.0f;
    *(float *)(o + 0x36c) = 1.0f;
    *(float *)(o + 0x370) = 0.0f;
    *(float *)(o + 0x374) = 0.2f;
    *(float *)(o + 0x378) = -1.0f;
    *(float *)(o + 0x37c) = 1.0f;
    *(float *)(o + 0x390) = 45.0f;
    *(float *)(o + 0x3a4) = FUN_0000c018(*(float *)(o + 0x390) * 0.008726646f);
    *(float *)(o + 0x394) = 0.1f;
    *(float *)(o + 0x398) = 1000.0f;
    FUN_0005c85c(o + 0x190, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
    FUN_0005d3f4(o + 0x190, 1.0f, 1.0f, 1.0f, 1.0f);
    Vec4 w;
    Vec4 v;
    w.z = -1.0f;
    w.w = 1.0f;
    v.x = 1.0f;
    v.y = 1.0f;
    v.z = 1.0f;
    v.w = 1.0f;
    w.x = 0.0f;
    w.y = 0.0f;
    FUN_0005d580(o + 0x190, 0, &w, &v);
    FUN_0005c8e0(o + 0x190);
    void *x = FUN_0008f170(DAT_003e1a08);
    if (x != 0) {
        FUN_00108e6c(x, 2100.0f);
    }
    FUN_000658cc(&rd, -1);
    return 1;
}
}
