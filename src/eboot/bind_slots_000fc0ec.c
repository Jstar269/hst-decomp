/* HSTMATCH module=EBOOT.BIN start=0x000fc0ec end=0x000fc140 symbol=FUN_000fc0ec lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0x100]; } Self;

extern char *FUN_0010192c(Self *, int, int, int, int, int, int, int, int, int, int, int);

void FUN_000fc0ec(Self *self, int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k)
{
    char *t = FUN_0010192c(self, a, b, c, d, e, f, g, h, i, j, k);

    *(char **)(t + 0x14) = (char *)self + 0x80;
    *(char **)(t + 0x18) = (char *)self + 0x7c;
}
