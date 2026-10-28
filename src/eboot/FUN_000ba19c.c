/* HSTMATCH module=EBOOT.BIN start=0x000ba19c end=0x000ba1d0 symbol=FUN_000ba19c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;
extern float DAT_002bc440;
extern float DAT_002bc444;
extern float DAT_002bc448;
extern float DAT_002bc44c;
void FUN_000ba19c(Vec4 *out)
{
    out->x = DAT_002bc440;
    out->y = DAT_002bc444;
    out->z = DAT_002bc448;
    out->w = DAT_002bc44c;
}
