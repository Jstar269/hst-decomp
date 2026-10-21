/* HSTMATCH module=EBOOT.BIN start=0x0026d224 end=0x0026d5fc symbol=FUN_0026d224 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 { float x, y, z, w; };
struct Reader { int a, b, c, d; };

class Model {
public:
    virtual void m0();
    virtual void m1();
    virtual void Load(const char *, int, int, int, int, int);
};

extern "C" char DAT_0030ab9c;
extern "C" char DAT_0030ebf4;
extern "C" char DAT_002fe138[];
extern "C" char DAT_002fe148[];
extern "C" char DAT_002fe168[];
extern "C" char DAT_002fe190[];
extern "C" char DAT_002fe1bc[];
extern "C" char DAT_002fe1dc[];
extern "C" char DAT_002fe208[];
extern "C" char DAT_0034179c;
extern "C" int DAT_003313c4;
extern "C" int DAT_003386c8;

extern "C" {
void *FUN_00010184(int, int);
void FUN_0001bfb4(void *, void *, int);
void FUN_0001cad0(void *, int, void *);
void FUN_00104118(void *, void *, int);
void *FUN_00000bcc(int);
void *FUN_00102e38(void *);
void *FUN_00056b98(void *);
void FUN_001b2e78(void *);
void FUN_001037c8(void *, int);
void FUN_00103540(void *, float);
void *FUN_002226b4(void *, int);
void FUN_002230dc(void *, float, float);
void *FUN_0021d7c4(void *);
void FUN_000649c0(Reader *);
void FUN_00064bf4(Reader *, void *, int, void *);
int FUN_00065104(Reader *, int, int);
void FUN_0001cb88(void *);
int FUN_0001cbfc();
int FUN_0001cc54();
void FUN_000104e0(void *);
void FUN_00293c6c(void *);
void FUN_001b3ce8(void *, int);
void FUN_0005ba78(void *, int);
float FUN_0000c000(float);
void FUN_0005bbd4(void *, float, float, float, float, float, float);
void FUN_0005c76c(void *, float, float, float, float);
void FUN_0005c854(void *, int, Vec4 *, Vec4 *);
void FUN_0005bc58(void *);
void *FUN_0008d994(int);
void FUN_00064a08(Reader *, int);

int FUN_0026d224(char *o)
{
    void *buf = FUN_00010184(0x40, 0x280000);
    FUN_0001bfb4(&DAT_0030ab9c, buf, 0x280000);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002fe138);
    FUN_00104118(o + 0x3c, DAT_002fe148, 0);
    void *p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_00102e38(p);
    }
    *(void **)(o + 0xfc) = p;
    FUN_00104118(p, DAT_002fe168, 0);
    void *q = FUN_00000bcc(0x1b0);
    void *m;
    if (q != 0) {
        m = FUN_00056b98(q);
        *(void **)(o + 0xf4) = m;
    } else {
        *(void **)(o + 0xf4) = q;
        m = q;
    }
    ((Model *)m)->Load(DAT_002fe190, 0, 0, 0, 0, 0);
    FUN_001b2e78(&DAT_0034179c);
    p = FUN_00000bcc(0x54);
    if (p != 0) {
        p = FUN_00102e38(p);
    }
    *(void **)(o + 0x100) = p;
    FUN_00104118(p, DAT_002fe1bc, 0);
    FUN_001037c8(*(void **)(o + 0x100), -2);
    FUN_00103540(*(void **)(o + 0x100), 2000.0f);
    void *r = FUN_00000bcc(0xcc);
    void *rm;
    if (r != 0) {
        rm = FUN_002226b4(r, 1);
        *(void **)(o + 0xa0c) = rm;
    } else {
        *(void **)(o + 0xa0c) = r;
        rm = r;
    }
    FUN_001037c8(rm, -1);
    FUN_002230dc(*(void **)(o + 0xa0c), 110.0f, 50.0f);
    void *s = FUN_00000bcc(0x210);
    void *sm;
    if (s != 0) {
        sm = FUN_0021d7c4(s);
        *(void **)(o + 0xa3c) = sm;
    } else {
        *(void **)(o + 0xa3c) = s;
        sm = s;
    }
    FUN_001037c8(sm, -1);
    Reader rd;
    FUN_000649c0(&rd);
    FUN_00064bf4(&rd, DAT_002fe1dc, 0, DAT_002fe208);
    *(int *)(o + 0x98c) = FUN_00065104(&rd, 0, 1);
    *(int *)(o + 0x990) = FUN_00065104(&rd, 1, 1);
    *(int *)(o + 0x994) = FUN_00065104(&rd, 2, 1);
    FUN_0001cb88(&DAT_0030ebf4);
    int a = FUN_0001cbfc();
    int b = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c, (void *)a, b);
    if (buf != 0) {
        FUN_000104e0(buf);
    }
    FUN_00293c6c(o + 0x920);
    FUN_001b3ce8(&DAT_0034179c, 8);
    FUN_00103540(o + 0x3c, 2000.0f);
    FUN_001037c8(o + 0x3c, 4);
    FUN_0005ba78(o + 0x190, DAT_003313c4);
    *(float *)(o + 0x360) = 0.0f;
    *(float *)(o + 0x364) = -1.0f;
    *(float *)(o + 0x368) = 5.0f;
    *(float *)(o + 0x36c) = 1.0f;
    *(float *)(o + 0x370) = 0.0f;
    *(float *)(o + 0x374) = 0.2f;
    *(float *)(o + 0x378) = -1.0f;
    *(float *)(o + 0x37c) = 1.0f;
    *(float *)(o + 0x390) = 45.0f;
    *(float *)(o + 0x3a4) = FUN_0000c000(*(float *)(o + 0x390) * 0.008726646f);
    *(float *)(o + 0x394) = 0.1f;
    *(float *)(o + 0x398) = 1000.0f;
    FUN_0005bbd4(o + 0x190, 0.0f, 0.0f, 480.0f, 272.0f, 240.0f, 136.0f);
    FUN_0005c76c(o + 0x190, 1.0f, 1.0f, 1.0f, 1.0f);
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
    FUN_0005c854(o + 0x190, 0, &w, &v);
    FUN_0005bc58(o + 0x190);
    void *x = FUN_0008d994(DAT_003386c8);
    if (x != 0) {
        FUN_00103540(x, 2100.0f);
    }
    FUN_00064a08(&rd, -1);
    return 1;
}
}
