/* HSTMATCH module=hstp_trans_main.prx start=0x00132318 end=0x00132344 symbol=FUN_00132318 lang=c99 */
/* Clone of src/eboot/set_origin4_001270a8.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[464]; float f1d0, f1d4, f1d8, f1dc; unsigned char f1e0; };

void FUN_00132318(struct S *s, float *src)
{
    s->f1d0 = src[0];
    s->f1d4 = src[1];
    s->f1d8 = src[2];
    s->f1dc = src[3];
    s->f1e0 = 1;
}
