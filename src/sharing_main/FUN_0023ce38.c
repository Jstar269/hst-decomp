/* HSTMATCH module=hstp_trans_main.prx start=0x0023ce38 end=0x0023ce60 symbol=FUN_0023ce38 lang=c99 */
/* Clone of src/eboot/FUN_0022cd38.c (hstclone.py tag c170007): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef struct Self {
    char pad0[273];
    u8 f111;                     /* 273 */
    u8 f112;                     /* 274 */
    u8 f113;                     /* 275 */
} Self;
void FUN_0023ce38(Self *self, int a1)
{
    switch (a1) {
    case 0:
        self->f111 = 1;
        break;
    case 1:
        self->f113 = 1;
        self->f112 = 1;
        break;
    }
}
