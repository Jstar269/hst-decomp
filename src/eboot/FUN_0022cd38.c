/* HSTMATCH module=EBOOT.BIN start=0x0022cd38 end=0x0022cd60 symbol=FUN_0022cd38 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;
typedef struct Self {
    char pad0[273];
    u8 f111;                     /* 273 */
    u8 f112;                     /* 274 */
    u8 f113;                     /* 275 */
} Self;
void FUN_0022cd38(Self *self, int a1)
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
