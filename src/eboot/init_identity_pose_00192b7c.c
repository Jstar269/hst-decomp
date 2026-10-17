/* HSTMATCH module=EBOOT.BIN start=0x00192b7c end=0x00192c98 symbol=FUN_00192b7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the 16-word copy from DAT_002bc410.. is four Vec4 struct assignments in plain C (batched lwc1 then swc1; in C++ MWCC interleaves or reorders them), the tail words stay integer constants; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
    Vec4 r0, r1, r2, r3;
    unsigned int t[0x12];
    unsigned char flag;
} Obj;
extern Vec4 DAT_002bc410;
extern Vec4 DAT_002bc420;
extern Vec4 DAT_002bc430;
extern Vec4 DAT_002bc440;

Obj *FUN_00192b7c(Obj *p)
{
    p->r0 = DAT_002bc410;
    p->r1 = DAT_002bc420;
    p->r2 = DAT_002bc430;
    p->r3 = DAT_002bc440;
    p->t[0] = 0x3f800000;
    p->t[1] = 0x3f800000;
    p->t[2] = 0x3f800000;
    p->t[3] = 0x3f800000;
    p->t[4] = 0x3f800000;
    p->t[5] = 0;
    p->t[6] = 0;
    p->t[7] = 0x3f800000;
    p->t[8] = 0;
    p->t[9] = 0x3f800000;
    p->t[10] = 0;
    p->t[11] = 0x3f800000;
    p->t[12] = 0;
    p->t[13] = 0;
    p->t[14] = 0x3f800000;
    p->t[15] = 0x3f800000;
    p->t[16] = 0x3f800000;
    p->t[17] = 0x3f800000;
    p->flag = 1;
    return p;
}
