/* HSTMATCH module=hstp_trans_main.prx start=0x001a57f4 end=0x001a58b8 symbol=FUN_001a57f4 lang=c99 */
/* Clone of src/eboot/globals_into_vec4_block_00198df0.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } V4;

struct S {
    V4 a;
    V4 b;
    V4 c;
    int i[4];
};

extern V4 DAT_0038900c;
extern V4 DAT_0038901c;
extern V4 DAT_0038902c;
extern int DAT_0038903c;
extern int DAT_00389040;
extern int DAT_00389044;
extern int DAT_00389048;

void FUN_001a57f4(struct S *p)
{
    p->a = DAT_0038900c;
    p->b = DAT_0038901c;
    p->c = DAT_0038902c;
    p->i[0] = DAT_0038903c;
    p->i[1] = DAT_00389040;
    p->i[2] = DAT_00389044;
    p->i[3] = DAT_00389048;
}
