/* HSTMATCH module=hstp_trans_main.prx start=0x000d5bd0 end=0x000d5c34 symbol=FUN_000d5bd0 lang=c99 */
/* Clone of src/eboot/vec4_triple_swap_000d1fa0.c (hstclone.py tag ds1018ar4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float x, y, z, w; } Vec4;
typedef struct {
    unsigned char pad0[0x50];
    Vec4 v50;      /* 0x50 */
    Vec4 v60;      /* 0x60 */
    Vec4 v70;      /* 0x70 */
} Self;

void FUN_000d5bd0(Self *s, const Vec4 *a, const Vec4 *b)
{
    s->v60.x = s->v50.x;
    s->v60.y = s->v50.y;
    s->v60.z = s->v50.z;
    s->v60.w = s->v50.w;
    s->v50.x = a->x;
    s->v50.y = a->y;
    s->v50.z = a->z;
    s->v50.w = a->w;
    s->v70.x = b->x;
    s->v70.y = b->y;
    s->v70.z = b->z;
    s->v70.w = b->w;
}
