/* HSTMATCH module=EBOOT.BIN start=0x00212098 end=0x00212198 symbol=FUN_00212098 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002c97e4[2][4];
struct V4_00212098 { float x, y, z, w; };
int FUN_00212098(float x, int unused, const struct V4_00212098 *a, const struct V4_00212098 *b)
{
    struct V4_00212098 va = *a;
    struct V4_00212098 vb = *b;
    if (va.x * vb.x > 0.0f && x > 0.0f)
        return -1;
    int key = 0;
    key |= (va.z > x) ? 1 : 0;
    key |= (vb.z > x) ? 2 : 0;
    unsigned char row = (x < 0.0f) ^ 1;
    return DAT_002c97e4[row][key];
}
