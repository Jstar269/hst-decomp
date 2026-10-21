/* HSTMATCH module=EBOOT.BIN start=0x0018c8b8 end=0x0018c9f4 symbol=FUN_0018c8b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Menu {
    char pad0[0x54];
    int f54;
    int *f58;
    int f5c;
    int f60;
    int **f64;
} Menu;

extern char DAT_002e0e3c[];
extern int DAT_002e0c50;
extern char DAT_002c23cc[];
extern char DAT_002c2438[];
extern char DAT_002c2474[];
extern char DAT_002c24bc[];
extern void FUN_00101048(int, char *, int *, int);
extern void FUN_001016f4(int, char *, int);
extern void FUN_00102824(int);
extern void FUN_00100de8(int, int);
extern void FUN_00103f74(Menu *);

void FUN_0018c8b8(Menu *self)
{
    int a;
    int *b;
    int c;
    int **d;
    int e;
    a = self->f54;
    b = self->f58;
    c = self->f5c;
    d = self->f64;
    e = self->f60;
    FUN_00101048(a, DAT_002e0e3c, &DAT_002e0c50, 4);
    FUN_001016f4(a, DAT_002c23cc, 9);
    FUN_00102824(a);
    FUN_00100de8(*b, a);
    FUN_001016f4(*b, DAT_002c2438, 5);
    *(char *)(*b + 0x12d) = 0;
    FUN_00100de8(c, a);
    FUN_001016f4(c, DAT_002c2474, 6);
    FUN_00100de8(**d, a);
    FUN_001016f4(**d, DAT_002c24bc, 10);
    FUN_00101048(e, DAT_002e0e3c, &DAT_002e0c50, 4);
    FUN_001016f4(e, DAT_002c23cc, 9);
    FUN_00103f74(self);
}
