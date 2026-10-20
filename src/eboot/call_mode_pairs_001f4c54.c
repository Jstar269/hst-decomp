/* HSTMATCH module=EBOOT.BIN start=0x001f4c54 end=0x001f4d44 symbol=FUN_001f4c54 lang=c99 rodata=0x002c908c */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
typedef struct { unsigned char pad[0xa8]; char *obj; } Global;
typedef struct { unsigned char pad[0x524]; unsigned int mode; } Self;

extern Global *DAT_003386b0;
extern void FUN_001b4e14(void *, int, int, int, int);

void FUN_001f4c54(Self *self)
{
    char *o = DAT_003386b0->obj;

    switch (self->mode) {
    case 0:
    case 1:
        FUN_001b4e14(o + 0x3c, 180, 30, 0, 0);
        FUN_001b4e14(o + 0x3c, 185, 90, 0, 0);
        break;
    case 2:
        FUN_001b4e14(o + 0x3c, 180, 30, 0, 0);
        FUN_001b4e14(o + 0x3c, 186, 90, 0, 0);
        break;
    case 3:
    case 4:
    case 5:
        FUN_001b4e14(o + 0x3c, 179, 30, 0, 0);
        FUN_001b4e14(o + 0x3c, 184, 90, 0, 0);
        break;
    }
}
