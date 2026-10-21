/* HSTMATCH module=hstp_trans_main.prx start=0x00199098 end=0x001991d4 symbol=FUN_00199098 lang=c99 */
/* Clone of src/eboot/menu_setup_0018c8b8.c (hstclone.py tag c21sn1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Menu {
    char pad0[0x54];
    int f54;
    int *f58;
    int f5c;
    int f60;
    int **f64;
} Menu;

extern char DAT_00388518[];
extern int DAT_0038832c;
extern char DAT_002d28cc[];
extern char DAT_002d2938[];
extern char DAT_002d2974[];
extern char DAT_002d29bc[];
extern void FUN_00106984(int, char *, int *, int);
extern void FUN_001070cc(int, char *, int);
extern void FUN_00108290(int);
extern void FUN_001066f0(int, int);
extern void FUN_001098a0(Menu *);

void FUN_00199098(Menu *self)
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
    FUN_00106984(a, DAT_00388518, &DAT_0038832c, 4);
    FUN_001070cc(a, DAT_002d28cc, 9);
    FUN_00108290(a);
    FUN_001066f0(*b, a);
    FUN_001070cc(*b, DAT_002d2938, 5);
    *(char *)(*b + 0x12d) = 0;
    FUN_001066f0(c, a);
    FUN_001070cc(c, DAT_002d2974, 6);
    FUN_001066f0(**d, a);
    FUN_001070cc(**d, DAT_002d29bc, 10);
    FUN_00106984(e, DAT_00388518, &DAT_0038832c, 4);
    FUN_001070cc(e, DAT_002d28cc, 9);
    FUN_001098a0(self);
}
