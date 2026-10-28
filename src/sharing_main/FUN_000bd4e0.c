/* HSTMATCH module=hstp_trans_main.prx start=0x000bd4e0 end=0x000bd514 symbol=FUN_000bd4e0 lang=c99 */
/* Clone of src/eboot/FUN_000ba19c.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Vec4 {
    float x, y, z, w;
} Vec4;
extern float DAT_002cc290;
extern float DAT_002cc294;
extern float DAT_002cc298;
extern float DAT_002cc29c;
void FUN_000bd4e0(Vec4 *out)
{
    out->x = DAT_002cc290;
    out->y = DAT_002cc294;
    out->z = DAT_002cc298;
    out->w = DAT_002cc29c;
}
