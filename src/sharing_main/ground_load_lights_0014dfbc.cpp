/* HSTMATCH module=hstp_trans_main.prx start=0x0014dfbc end=0x0014e738 symbol=FUN_0014dfbc lang=c++ data=0x00382e34 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00382e34-0x00382e46) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ground (ClassGround.cpp, per the Sharing twin's assert strings) light setup: set default ambient and two
   directional lights on the light manager, read them back into three light sets, override them from the
   row-indexed CSV files (each open asserted in the debug build), then load <base><dir>/pointlight.dat and
   push its records into the point-light vector. The interleaved element copy needs Vec4's memberwise copy
   constructor. Names provisional. */

inline void *operator new(unsigned, void *p) { return p; }

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
} __attribute__((aligned(16)));

struct PointLight {
    Vec4 pos;
    Vec4 color;
};

struct Tag {};

struct LightMgr;
struct CsvFile { int pad[4]; };

extern "C" {
void FUN_0005d3f4(LightMgr *, float, float, float, float);
void FUN_0005d580(LightMgr *, int, const Vec4 *, const Vec4 *);
void FUN_0005d980(LightMgr *, Vec4 *);
void FUN_0005d9a4(LightMgr *, int, Vec4 *, Vec4 *);
void FUN_00065884(CsvFile *);
bool FUN_00065ab8(CsvFile *, const char *, int, const char *);
void FUN_0006594c(CsvFile *);
float FUN_000660f0(CsvFile *, int, int);
void FUN_000658cc(CsvFile *, int);
void FUN_000149a8(char *, const char *);
void FUN_000143b0(char *, const char *, ...);
void *FUN_0004cd8c(const char *, int *, int, int);
void FUN_000104e0(void *);
}

struct PointLightVec {
    PointLight *data;
    unsigned size;
    unsigned cap;
    void push_back(const PointLight &x);
};

extern "C" void FUN_00152e20(PointLightVec *, const PointLight *, Tag);

inline void PointLightVec::push_back(const PointLight &x)
{
    if (size < cap) {
        new (data + size) PointLight(x);
        ++size;
    } else {
        FUN_00152e20(this, &x, Tag());
    }
}

struct LightSet {
    Vec4 ambient;
    Vec4 dir0;
    Vec4 color0;
    Vec4 dir1;
    Vec4 color1;
};

struct Ground {
    char pad0[0xd10];
    PointLightVec points;       /* 0xd10 */
    char padd1c[0xd24 - 0xd1c];
    int row;                    /* 0xd24 */
    char dir[0x40];             /* 0xd28 */
    char base[0x88];            /* 0xd68 */
    LightSet sets[3];           /* 0xdf0 */
    char name0[0x100];          /* 0xee0 */
    char name1[0x100];          /* 0xfe0 */
    char name2[0x100];          /* 0x10e0 */
    char name3[0x100];          /* 0x11e0 */
    float extra[7];             /* 0x12e0 */
};

extern LightMgr *DAT_003da704;
extern const char DAT_00382d94[];   /* "," */
extern const char DAT_002d1cf0[];   /* "%s%s" */

/* Debug build: assertions print through the (empty) variadic debug printf and hang. */
extern const char DAT_00382db8[];   /* "assertion \"%s\" failed: file \"%s\", line %d
" */
extern const char DAT_00382de4[];   /* "readflag" */
extern const char DAT_00382df0[];   /* "ClassGround.cpp" */
extern "C" void FUN_0014db60(...);
#define HST_ASSERT(cond, text, line)     do { if (!(cond)) { FUN_0014db60(DAT_00382db8, text, DAT_00382df0, line); for (;;) {} } } while (0)

extern "C" void FUN_0014dfbc(Ground *self, int row, const char *main, const char *f3, const char *f2, const char *f4)
{
    CsvFile file;
    int size;
    char buf[512];
    char path[512];
    Vec4 dir;
    PointLight pl;
    Vec4 col0;
    Vec4 col1;
    bool readflag;

    self->row = row;
    FUN_0005d3f4(DAT_003da704, 0.4f, 0.4f, 0.4f, 1.0f);
    dir.x = -1.0f;
    dir.y = 1.0f;
    dir.z = 1.0f;
    dir.w = 0.0f;
    col0.x = 0.9f;
    col0.y = 0.9f;
    col0.z = 0.7f;
    col0.w = 0.0f;
    FUN_0005d580(DAT_003da704, 0, &dir, &col0);
    dir.y *= -1.0f;
    col1.x = 0.2f;
    col1.y = 0.2f;
    col1.z = 0.2f;
    col1.w = 0.0f;
    FUN_0005d580(DAT_003da704, 1, &dir, &col1);
    FUN_0005d980(DAT_003da704, &self->sets[0].ambient);
    FUN_0005d9a4(DAT_003da704, 0, &self->sets[0].dir0, &self->sets[0].color0);
    FUN_0005d9a4(DAT_003da704, 1, &self->sets[0].dir1, &self->sets[0].color1);
    FUN_0005d980(DAT_003da704, &self->sets[1].ambient);
    FUN_0005d9a4(DAT_003da704, 0, &self->sets[1].dir0, &self->sets[1].color0);
    FUN_0005d9a4(DAT_003da704, 1, &self->sets[1].dir1, &self->sets[1].color1);
    FUN_0005d980(DAT_003da704, &self->sets[2].ambient);
    FUN_0005d9a4(DAT_003da704, 0, &self->sets[2].dir0, &self->sets[2].color0);
    FUN_0005d9a4(DAT_003da704, 1, &self->sets[2].dir1, &self->sets[2].color1);
    self->extra[0] = 0.0f;
    self->extra[1] = 0.0f;
    self->extra[2] = 0.0f;
    self->extra[3] = 1.0f;
    self->extra[4] = 1.0f;
    self->extra[5] = 1.0f;
    self->extra[6] = 1.0f;

    FUN_00065884(&file);
    readflag = FUN_00065ab8(&file, main, 1, DAT_00382d94);
    HST_ASSERT(readflag, DAT_00382de4, 600);
    FUN_000149a8(self->name0, main);
    self->sets[0].ambient.x = FUN_000660f0(&file, row, 0);
    self->sets[0].ambient.y = FUN_000660f0(&file, row, 1);
    self->sets[0].ambient.z = FUN_000660f0(&file, row, 2);
    self->sets[0].color0.x = FUN_000660f0(&file, row, 3);
    self->sets[0].color0.y = FUN_000660f0(&file, row, 4);
    self->sets[0].color0.z = FUN_000660f0(&file, row, 5);
    self->sets[0].dir0.x = FUN_000660f0(&file, row, 6);
    self->sets[0].dir0.y = FUN_000660f0(&file, row, 7);
    self->sets[0].dir0.z = FUN_000660f0(&file, row, 8);
    self->sets[0].color1.x = FUN_000660f0(&file, row, 9);
    self->sets[0].color1.y = FUN_000660f0(&file, row, 10);
    self->sets[0].color1.z = FUN_000660f0(&file, row, 11);
    self->sets[0].dir1.x = FUN_000660f0(&file, row, 12);
    self->sets[0].dir1.y = FUN_000660f0(&file, row, 13);
    self->sets[0].dir1.z = FUN_000660f0(&file, row, 14);
    FUN_0006594c(&file);

    if (f2) {
        readflag = FUN_00065ab8(&file, f2, 1, DAT_00382d94);
        FUN_000149a8(self->name1, f2);
        HST_ASSERT(readflag, DAT_00382de4, 627);
        self->sets[1].ambient.x = FUN_000660f0(&file, row, 0);
        self->sets[1].ambient.y = FUN_000660f0(&file, row, 1);
        self->sets[1].ambient.z = FUN_000660f0(&file, row, 2);
        self->sets[1].color0.x = FUN_000660f0(&file, row, 3);
        self->sets[1].color0.y = FUN_000660f0(&file, row, 4);
        self->sets[1].color0.z = FUN_000660f0(&file, row, 5);
    }
    FUN_0006594c(&file);

    if (f3) {
        readflag = FUN_00065ab8(&file, f3, 1, DAT_00382d94);
        FUN_000149a8(self->name2, f3);
        HST_ASSERT(readflag, DAT_00382de4, 642);
        self->sets[2].ambient.x = FUN_000660f0(&file, row, 0);
        self->sets[2].ambient.y = FUN_000660f0(&file, row, 1);
        self->sets[2].ambient.z = FUN_000660f0(&file, row, 2);
        self->sets[2].color0.x = FUN_000660f0(&file, row, 3);
        self->sets[2].color0.y = FUN_000660f0(&file, row, 4);
        self->sets[2].color0.z = FUN_000660f0(&file, row, 5);
    }
    FUN_0006594c(&file);

    if (f4) {
        readflag = FUN_00065ab8(&file, f4, 1, DAT_00382d94);
        FUN_000149a8(self->name3, f4);
        HST_ASSERT(readflag, DAT_00382de4, 657);
        self->extra[0] = FUN_000660f0(&file, row, 0);
        self->extra[1] = FUN_000660f0(&file, row, 1);
        self->extra[2] = FUN_000660f0(&file, row, 2);
        self->extra[3] = FUN_000660f0(&file, row, 3);
        self->extra[4] = FUN_000660f0(&file, row, 4);
        self->extra[5] = FUN_000660f0(&file, row, 5);
        self->extra[6] = FUN_000660f0(&file, row, 6);
    }

    size = 0;
    FUN_000143b0(buf, DAT_002d1cf0, self->base, self->dir);
    FUN_000143b0(path, "%s/pointlight.dat", buf);
    int *data = (int *)FUN_0004cd8c(path, &size, 16, 1);
    if (data) {
        int n = data[0];
        float *src = (float *)(data + 1);
        for (int i = 0; i < n; i++) {
            pl.pos.x = src[0];
            pl.pos.y = src[1];
            pl.pos.z = src[2];
            pl.pos.w = 1.0f;
            pl.color.x = src[3];
            pl.color.y = src[4];
            pl.color.z = src[5];
            pl.color.w = 1.0f;
            src += 6;
            self->points.push_back(pl);
        }
        FUN_000104e0(data);
    }
    FUN_000658cc(&file, -1);
}
