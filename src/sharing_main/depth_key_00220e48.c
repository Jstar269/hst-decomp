/* HSTMATCH module=hstp_trans_main.prx start=0x00220e48 end=0x00220f48 symbol=FUN_00220e48 lang=c99 */
/* Clone of src/eboot/depth_key_00212098.c (hstclone.py tag ds1011s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002d9c7c[2][4];
struct V4_00220e48 { float x, y, z, w; };
int FUN_00220e48(float x, int unused, const struct V4_00220e48 *a, const struct V4_00220e48 *b)
{
    struct V4_00220e48 va = *a;
    struct V4_00220e48 vb = *b;
    if (va.x * vb.x > 0.0f && x > 0.0f)
        return -1;
    int key = 0;
    key |= (va.z > x) ? 1 : 0;
    key |= (vb.z > x) ? 2 : 0;
    unsigned char row = (x < 0.0f) ^ 1;
    return DAT_002d9c7c[row][key];
}
