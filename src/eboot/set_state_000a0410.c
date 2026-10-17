/* HSTMATCH module=EBOOT.BIN start=0x000a0410 end=0x000a0578 symbol=FUN_000a0410 lang=c99 */
/* Clone of src/sharing_main/set_state_000a2a1c.c (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
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
extern Glob *DAT_003386b0;
extern char DAT_0034179c[];
extern char *FUN_00093838(int);
extern void FUN_000ce180(void *, int);
extern void FUN_000ce188(void *, int);
extern void FUN_000ce3f8(void *, int);
extern int FUN_001b1d10(char *, int, char *, int);
void FUN_000a0410(Obj *self, int mode)
{
    switch (mode) {
    case 0:
        FUN_001b1d10(DAT_0034179c, 78, FUN_00093838(self->f5bc), 0);
        break;
    case 1:
        FUN_001b1d10(DAT_0034179c, 80, FUN_00093838(self->f5bc), 0);
        FUN_000ce180(DAT_003386b0->f90, self->f148);
        DAT_003386b0->players[(self->f148 + 2) % 4]->f462 = 1;
        break;
    case 2:
        FUN_001b1d10(DAT_0034179c, 79, FUN_00093838(self->f5bc), 0);
        FUN_000ce3f8(DAT_003386b0->f90, self->f148);
        break;
    case 3:
        FUN_001b1d10(DAT_0034179c, 82, FUN_00093838(self->f5bc), 0);
        FUN_000ce188(DAT_003386b0->f90, self->f148);
        break;
    default:
        mode = -1;
        break;
    }
    self->f4dc = mode;
}
