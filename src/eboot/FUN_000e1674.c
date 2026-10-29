/* HSTMATCH module=EBOOT.BIN start=0x000e1674 end=0x000e1724 symbol=FUN_000e1674 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void *FUN_00000a90(int);
extern void *FUN_000008d8(void *, void *, int, int, int);
extern void *FUN_00000bcc(int);
extern void *FUN_0005aa44(void *, int, int, int, int, int);
extern void FUN_000e1724();

#define POINT_SIZE 0x10     /* bytes per stored point */
#define ARRAY_COOKIE 0x10   /* bookkeeping header in front of the array */
#define MESH_SIZE 0x70

typedef struct TrailCfg {
    char pad0[2];
    short points;           /* 0x02 base number of points */
} TrailCfg;

typedef struct TrailObj {
    char pad0[0x3c];
    TrailCfg *cfg;          /* 0x3c */
    void *mesh;             /* 0x40 */
    char pad44[4];
    int vertsPerPoint;      /* 0x48 */
    int pointsBase;         /* 0x4c */
    int pointsPadded;       /* 0x50 */
    void *pointBuf;         /* 0x54 */
} TrailObj;

/* Sizes the point buffer (base count plus 6 spare) and creates the strip mesh with two vertices per point. */
void FUN_000e1674(TrailObj *self)
{
    int n;
    int m;
    int count;
    void *buf;
    void *p;

    self->vertsPerPoint = 2;
    n = self->cfg->points;
    self->pointsBase = n;
    m = n + 3;
    self->pointsPadded = m;
    count = m + 3;
    buf = FUN_00000a90(count * POINT_SIZE + ARRAY_COOKIE);
    self->pointBuf = FUN_000008d8(buf, (void *)&FUN_000e1724, 0, POINT_SIZE, count);
    p = FUN_00000bcc(MESH_SIZE);
    if (p != 0)
        p = FUN_0005aa44(p, 1, self->vertsPerPoint * count, 1, 1, 0);
    self->mesh = p;
}
