/* HSTMATCH module=EBOOT.BIN start=0x00051580 end=0x00051714 symbol=FUN_00051580 lang=c99 */
typedef struct {
    char pad[0x1c];
    int f1c;
    unsigned char f20;
    unsigned char f21;
    unsigned char f22;
    char pad2;
    int f24;
    unsigned *p;
    unsigned f2c;
    unsigned f30;
    unsigned f34;
    unsigned f38;
} Ctx;

extern int FUN_00036c28(int, int);
extern int FUN_00036eb8(int, int);

void FUN_00051580(Ctx *c, int a)
{
    int n = a;
    if (n >= 0) {
        c->p = (unsigned *)FUN_00036c28((int)c->p, c->f24);
    }
    *c->p = (c->f30 << 10) | 0xd4000000u | c->f2c;
    c->p[1] = (c->f38 << 10) | 0xd5000000u | c->f34;
    c->p += 2;
    *c->p = 0xdbff0006;
    c->p[1] = 0x22000001;
    c->p += 2;
    *c->p = 0x1d000000;
    c->p += 1;
    *c->p = (unsigned)c->f22 << 8 | 0xc9010000u;
    c->p += 1;
    *c->p = 0xe8000000;
    c->p += 1;
    *c->p = 0x24000000;
    c->p += 1;
    if (c->f20 == 0) {
        *c->p = 0xe7000000;
        c->p += 1;
    } else {
        *c->p = 0xe7000001;
        c->p += 1;
    }
    if (c->f21 == 0) {
        *c->p = 0x21000000;
        c->p += 1;
    } else {
        *c->p = 0x21000001;
        c->p += 1;
        c->p = (unsigned *)FUN_00036eb8((int)c->p, c->f1c);
    }
}
// near miss from lane fm11 (unreviewed)
