/* HSTMATCH module=hstp_trans_main.prx start=0x002a4ca4 end=0x002a4d64 symbol=FUN_002a4ca4 lang=c99 */
/* Clone of src/eboot/mat4_row_replace_store_00293698.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float m[16]; } Mat4;

typedef struct {
    char pad0[0x30];
    Mat4 mat;
} Obj;

struct Self {
    char pad0[0x78];
    Obj *obj;
};

extern Mat4 *mat4_store_0055044(void *obj, const Mat4 *src);

void FUN_002a4ca4(struct Self *s, const float *v)
{
    Mat4 m;
    Obj *o = *(Obj **)((char *)s + 0x78);
    int i;
    m.m[0] = o->mat.m[0];
    m.m[1] = o->mat.m[1];
    m.m[2] = o->mat.m[2];
    m.m[3] = o->mat.m[3];
    m.m[4] = o->mat.m[4];
    m.m[5] = o->mat.m[5];
    m.m[6] = o->mat.m[6];
    m.m[7] = o->mat.m[7];
    m.m[8] = o->mat.m[8];
    m.m[9] = o->mat.m[9];
    m.m[10] = o->mat.m[10];
    m.m[11] = o->mat.m[11];
    m.m[12] = o->mat.m[12];
    m.m[13] = o->mat.m[13];
    m.m[14] = o->mat.m[14];
    m.m[15] = o->mat.m[15];
    m.m[12] = v[0];
    m.m[13] = v[1];
    m.m[14] = v[2];
    m.m[15] = v[3];
    mat4_store_0055044(o, &m);
}
