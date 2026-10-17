/* HSTMATCH module=hstp_trans_main.prx start=0x0019f38c end=0x0019f4a8 symbol=FUN_0019f38c lang=c99 */
/* Clone of src/eboot/init_identity_pose_00192b7c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: the 16-word copy from DAT_002cc260.. is four Vec4 struct assignments in plain C (batched lwc1 then swc1; in C++ MWCC interleaves or reorders them), the tail words stay integer constants; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
    Vec4 r0, r1, r2, r3;
    unsigned int t[0x12];
    unsigned char flag;
} Obj;
extern Vec4 DAT_002cc260;
extern Vec4 DAT_002cc270;
extern Vec4 DAT_002cc280;
extern Vec4 DAT_002cc290;

Obj *FUN_0019f38c(Obj *p)
{
    p->r0 = DAT_002cc260;
    p->r1 = DAT_002cc270;
    p->r2 = DAT_002cc280;
    p->r3 = DAT_002cc290;
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
