/* HSTMATCH module=EBOOT.BIN start=0x00198df0 end=0x00198eb4 symbol=FUN_00198df0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } V4;

struct S {
    V4 a;
    V4 b;
    V4 c;
    int i[4];
};

extern V4 DAT_002e185c;
extern V4 DAT_002e186c;
extern V4 DAT_002e187c;
extern int DAT_002e188c;
extern int DAT_002e1890;
extern int DAT_002e1894;
extern int DAT_002e1898;

void FUN_00198df0(struct S *p)
{
    p->a = DAT_002e185c;
    p->b = DAT_002e186c;
    p->c = DAT_002e187c;
    p->i[0] = DAT_002e188c;
    p->i[1] = DAT_002e1890;
    p->i[2] = DAT_002e1894;
    p->i[3] = DAT_002e1898;
}
