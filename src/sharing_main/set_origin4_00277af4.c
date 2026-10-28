/* HSTMATCH module=hstp_trans_main.prx start=0x00277af4 end=0x00277b20 symbol=FUN_00277af4 lang=c99 */
/* Clone of src/eboot/set_origin4_00266b78.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct S { char pad[336]; float f150, f154, f158, f15c; unsigned char f160; };

void FUN_00277af4(struct S *s, float *src)
{
    s->f150 = src[0];
    s->f154 = src[1];
    s->f158 = src[2];
    s->f15c = src[3];
    s->f160 = 1;
}
