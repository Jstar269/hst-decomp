/* HSTMATCH module=hstp_trans_main.prx start=0x00101828 end=0x0010187c symbol=FUN_00101828 lang=c99 */
/* Clone of src/eboot/bind_slots_000fc0ec.c (hstclone.py tag s10200333g2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x100]; } Self;

extern char *FUN_00107364(Self *, int, int, int, int, int, int, int, int, int, int, int);

void FUN_00101828(Self *self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    char *t = FUN_00107364(self, a, b, c, d, e, f, g, h, i, j, k);

    *(char **)(t + 0x14) = (char *)self + 0x80;
    *(char **)(t + 0x18) = (char *)self + 0x7c;
}
