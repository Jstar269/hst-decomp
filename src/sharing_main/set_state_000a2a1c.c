/* HSTMATCH module=hstp_trans_main.prx start=0x000a2a1c end=0x000a2b84 symbol=FUN_000a2a1c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct Player { char pad[0x462]; unsigned char f462; } Player;
typedef struct Glob { char pad0[0x70]; Player *players[4]; char pad1[0x10]; void *f90; } Glob;
typedef struct Obj {
    char pad0[0x148];
    int f148;
    char pad1[0x4dc - 0x14c];
    int f4dc;
    char pad2[0x5bc - 0x4e0];
    int f5bc;
} Obj;
extern Glob *DAT_003e19f0;
extern char DAT_003eaad8[];
extern char *FUN_0009575c(int);
extern void FUN_000d1d7c(void *, int);
extern void FUN_000d1d84(void *, int);
extern void FUN_000d1ff4(void *, int);
extern int FUN_001bfd3c(char *, int, char *, int);
void FUN_000a2a1c(Obj *self, int mode)
{
    switch (mode) {
    case 0:
        FUN_001bfd3c(DAT_003eaad8, 78, FUN_0009575c(self->f5bc), 0);
        break;
    case 1:
        FUN_001bfd3c(DAT_003eaad8, 80, FUN_0009575c(self->f5bc), 0);
        FUN_000d1d7c(DAT_003e19f0->f90, self->f148);
        DAT_003e19f0->players[(self->f148 + 2) % 4]->f462 = 1;
        break;
    case 2:
        FUN_001bfd3c(DAT_003eaad8, 79, FUN_0009575c(self->f5bc), 0);
        FUN_000d1ff4(DAT_003e19f0->f90, self->f148);
        break;
    case 3:
        FUN_001bfd3c(DAT_003eaad8, 82, FUN_0009575c(self->f5bc), 0);
        FUN_000d1d84(DAT_003e19f0->f90, self->f148);
        break;
    default:
        mode = -1;
        break;
    }
    self->f4dc = mode;
}
