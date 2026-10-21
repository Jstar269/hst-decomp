/* HSTMATCH module=hstp_trans_main.prx start=0x0010cb80 end=0x0010cc9c symbol=FUN_0010cb80 lang=c99 */
/* Clone of src/eboot/track_points_00106dc0.c (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Pt { unsigned short x, y, z, w; } Pt;
typedef struct Track {
    char pad0[8];
    int width;
    int height;
    char pad1[0x50 - 0x10];
    Pt *pts;
} Track;
int FUN_0010cb80(Track *self, int idx, float *a, float *b, float *c, float *d)
{
    if (idx < 0 || self->pts == 0) {
        *a = 0;
        *b = 0;
        *c = (float)self->width;
        *d = (float)self->height;
    } else {
        *a = (float)self->pts[idx].x;
        *b = (float)self->pts[idx].y;
        *c = (float)self->pts[idx].z;
        *d = (float)self->pts[idx].w;
    }
    return 1;
}
