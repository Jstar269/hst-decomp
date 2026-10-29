/* HSTMATCH module=EBOOT.BIN start=0x0018c8b8 end=0x0018c9f4 symbol=FUN_0018c8b8 lang=c99 data=0x002e0e3c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e0e3c-0x002e0e53) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
typedef struct Menu {
    char pad0[0x54];
    int root;           /* 0x54 */
    int *slotB;         /* 0x58 */
    int panelC;         /* 0x5c */
    int root2;          /* 0x60 */
    int **slotD;        /* 0x64 */
} Menu;

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

/* Loads the common menu resources for both roots and parents the other widgets to the first. */
void FUN_0018c8b8(Menu *self)
{
    int root;
    int *slotB;
    int panelC;
    int **slotD;
    int root2;
    root = self->root;
    slotB = self->slotB;
    panelC = self->panelC;
    slotD = self->slotD;
    root2 = self->root2;
    FUN_00101048(root, "data/menu/menu_common/", &DAT_002e0c50, 4);
    FUN_001016f4(root, DAT_002c23cc, 9);
    FUN_00102824(root);
    FUN_00100de8(*slotB, root);
    FUN_001016f4(*slotB, DAT_002c2438, 5);
    *(char *)(*slotB + 0x12d) = 0;
    FUN_00100de8(panelC, root);
    FUN_001016f4(panelC, DAT_002c2474, 6);
    FUN_00100de8(**slotD, root);
    FUN_001016f4(**slotD, DAT_002c24bc, 10);
    FUN_00101048(root2, "data/menu/menu_common/", &DAT_002e0c50, 4);
    FUN_001016f4(root2, DAT_002c23cc, 9);
    FUN_00103f74(self);
}
