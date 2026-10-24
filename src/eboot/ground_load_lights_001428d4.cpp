/* HSTMATCH module=EBOOT.BIN start=0x001428d4 end=0x00142f90 symbol=FUN_001428d4 lang=c++ */
/* Stage_LoadLightingAndFog: courtlight/playerlight/balllight/fogsetting.csv; see docs/DATA-TABLES.md */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
void FUN_0005c76c(LightMgr *, float, float, float, float);
void FUN_0005c854(LightMgr *, int, const Vec4 *, const Vec4 *);
void FUN_0005cbf4(LightMgr *, Vec4 *);
void FUN_0005cc18(LightMgr *, int, Vec4 *, Vec4 *);
void FUN_000649c0(CsvFile *);
bool FUN_00064bf4(CsvFile *, const char *, int, const char *);
void FUN_00064a88(CsvFile *);
float FUN_00065140(CsvFile *, int, int);
void FUN_00064a08(CsvFile *, int);
void FUN_000149a8(char *, const char *);
void FUN_000143b0(char *, const char *, ...);
void *FUN_0004cad0(const char *, int *, int, int);
void FUN_000104e0(void *);
}

struct PointLightVec {
    PointLight *data;
    unsigned size;
    unsigned cap;
    void push_back(const PointLight &x);
};

extern "C" void FUN_00147538(PointLightVec *, const PointLight *, Tag);

inline void PointLightVec::push_back(const PointLight &x)
{
    if (size < cap) {
        new (data + size) PointLight(x);
        ++size;
    } else {
        FUN_00147538(this, &x, Tag());
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

extern LightMgr *DAT_003313c4;
extern const char DAT_002dbb34[];   /* "," */
extern const char DAT_002c1910[];   /* "%s%s" */
extern const char DAT_002dbb68[];   /* "%s/pointlight.dat" */

extern "C" void FUN_001428d4(Ground *self, int row, const char *main, const char *f3, const char *f2, const char *f4)
{
    CsvFile file;
    int size;
    char buf[512];
    char path[512];
    Vec4 dir;
    PointLight pl;
    Vec4 col0;
    Vec4 col1;

    self->row = row;
    FUN_0005c76c(DAT_003313c4, 0.4f, 0.4f, 0.4f, 1.0f);
    dir.x = -1.0f;
    dir.y = 1.0f;
    dir.z = 1.0f;
    dir.w = 0.0f;
    col0.x = 0.9f;
    col0.y = 0.9f;
    col0.z = 0.7f;
    col0.w = 0.0f;
    FUN_0005c854(DAT_003313c4, 0, &dir, &col0);
    dir.y *= -1.0f;
    col1.x = 0.2f;
    col1.y = 0.2f;
    col1.z = 0.2f;
    col1.w = 0.0f;
    FUN_0005c854(DAT_003313c4, 1, &dir, &col1);
    FUN_0005cbf4(DAT_003313c4, &self->sets[0].ambient);
    FUN_0005cc18(DAT_003313c4, 0, &self->sets[0].dir0, &self->sets[0].color0);
    FUN_0005cc18(DAT_003313c4, 1, &self->sets[0].dir1, &self->sets[0].color1);
    FUN_0005cbf4(DAT_003313c4, &self->sets[1].ambient);
    FUN_0005cc18(DAT_003313c4, 0, &self->sets[1].dir0, &self->sets[1].color0);
    FUN_0005cc18(DAT_003313c4, 1, &self->sets[1].dir1, &self->sets[1].color1);
    FUN_0005cbf4(DAT_003313c4, &self->sets[2].ambient);
    FUN_0005cc18(DAT_003313c4, 0, &self->sets[2].dir0, &self->sets[2].color0);
    FUN_0005cc18(DAT_003313c4, 1, &self->sets[2].dir1, &self->sets[2].color1);
    self->extra[0] = 0.0f;
    self->extra[1] = 0.0f;
    self->extra[2] = 0.0f;
    self->extra[3] = 1.0f;
    self->extra[4] = 1.0f;
    self->extra[5] = 1.0f;
    self->extra[6] = 1.0f;

    FUN_000649c0(&file);
    FUN_00064bf4(&file, main, 1, DAT_002dbb34);
    FUN_000149a8(self->name0, main);
    self->sets[0].ambient.x = FUN_00065140(&file, row, 0);
    self->sets[0].ambient.y = FUN_00065140(&file, row, 1);
    self->sets[0].ambient.z = FUN_00065140(&file, row, 2);
    self->sets[0].color0.x = FUN_00065140(&file, row, 3);
    self->sets[0].color0.y = FUN_00065140(&file, row, 4);
    self->sets[0].color0.z = FUN_00065140(&file, row, 5);
    self->sets[0].dir0.x = FUN_00065140(&file, row, 6);
    self->sets[0].dir0.y = FUN_00065140(&file, row, 7);
    self->sets[0].dir0.z = FUN_00065140(&file, row, 8);
    self->sets[0].color1.x = FUN_00065140(&file, row, 9);
    self->sets[0].color1.y = FUN_00065140(&file, row, 10);
    self->sets[0].color1.z = FUN_00065140(&file, row, 11);
    self->sets[0].dir1.x = FUN_00065140(&file, row, 12);
    self->sets[0].dir1.y = FUN_00065140(&file, row, 13);
    self->sets[0].dir1.z = FUN_00065140(&file, row, 14);
    FUN_00064a88(&file);

    if (f2) {
        FUN_00064bf4(&file, f2, 1, DAT_002dbb34);
        FUN_000149a8(self->name1, f2);
        self->sets[1].ambient.x = FUN_00065140(&file, row, 0);
        self->sets[1].ambient.y = FUN_00065140(&file, row, 1);
        self->sets[1].ambient.z = FUN_00065140(&file, row, 2);
        self->sets[1].color0.x = FUN_00065140(&file, row, 3);
        self->sets[1].color0.y = FUN_00065140(&file, row, 4);
        self->sets[1].color0.z = FUN_00065140(&file, row, 5);
    }
    FUN_00064a88(&file);

    if (f3) {
        FUN_00064bf4(&file, f3, 1, DAT_002dbb34);
        FUN_000149a8(self->name2, f3);
        self->sets[2].ambient.x = FUN_00065140(&file, row, 0);
        self->sets[2].ambient.y = FUN_00065140(&file, row, 1);
        self->sets[2].ambient.z = FUN_00065140(&file, row, 2);
        self->sets[2].color0.x = FUN_00065140(&file, row, 3);
        self->sets[2].color0.y = FUN_00065140(&file, row, 4);
        self->sets[2].color0.z = FUN_00065140(&file, row, 5);
    }
    FUN_00064a88(&file);

    if (f4) {
        FUN_00064bf4(&file, f4, 1, DAT_002dbb34);
        FUN_000149a8(self->name3, f4);
        self->extra[0] = FUN_00065140(&file, row, 0);
        self->extra[1] = FUN_00065140(&file, row, 1);
        self->extra[2] = FUN_00065140(&file, row, 2);
        self->extra[3] = FUN_00065140(&file, row, 3);
        self->extra[4] = FUN_00065140(&file, row, 4);
        self->extra[5] = FUN_00065140(&file, row, 5);
        self->extra[6] = FUN_00065140(&file, row, 6);
    }

    size = 0;
    FUN_000143b0(buf, DAT_002c1910, self->base, self->dir);
    FUN_000143b0(path, DAT_002dbb68, buf);
    int *data = (int *)FUN_0004cad0(path, &size, 16, 1);
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
    FUN_00064a08(&file, -1);
}
