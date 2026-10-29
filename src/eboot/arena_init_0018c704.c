/* HSTMATCH module=EBOOT.BIN start=0x0018c704 end=0x0018c808 symbol=FUN_0018c704 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern void FUN_002adb98(char *self);
extern void FUN_001be450(char *p);
extern void *FUN_000114c0(void *dst, int value, unsigned n);
extern void FUN_0022cc64(char *p);
extern void FUN_0024df94(char *p);

/* Object made of several regions; the table at 0x4c holds each region's offset from the object start and the table at 0x68 its capacity. */
typedef struct Arena {
    char pad0[0x4c];
    int off4c;                  /* 0x4c */
    int off50;                  /* 0x50 */
    int off54;                  /* 0x54 */
    int off58;                  /* 0x58 */
    int off5c;                  /* 0x5c */
    int off60;                  /* 0x60 */
    int off64;                  /* 0x64 */
    int cap68;                  /* 0x68 */
    int cap6c;                  /* 0x6c */
    int cap70;                  /* 0x70 */
    int cap74;                  /* 0x74 */
    int cap78;                  /* 0x78 */
    char pad7c[4];
    char region80[4];           /* 0x80 */
    char region84[0x3cc - 0x84];
    char region3cc[0x8cc - 0x3cc];
    char region8cc[0xb4c - 0x8cc];
    char regionb4c[0xdcc - 0xb4c];
    char regiondcc[0xea60 - 0xdcc];
    char regionea60[0x86a9c - 0xea60];
    char region86a9c[0x86c10 - 0x86a9c];
    char region86c10[0x86d10 - 0x86c10];
    char region86d10[0x87128 - 0x86d10];
    char region87128[0x10890];
} Arena;

#define CAP_SMALL 15
#define CAP_LARGE 640

Arena *FUN_0018c704(Arena *self)
{
    FUN_002adb98((char *)self);
    FUN_001be450(self->region80);
    FUN_000114c0(self->regionea60, 0, 0x7803c);
    FUN_0022cc64(self->region86a9c);
    FUN_0024df94(self->region86c10);
    FUN_000114c0(self->region86d10, 0, 0x414);
    FUN_000114c0(self->region87128, 0, 0x10890);
    self->off4c = (int)self->region80 - (int)self;
    self->off50 = (int)self->region84 - (int)self;
    self->cap68 = CAP_SMALL;
    self->off54 = (int)self->region3cc - (int)self;
    self->cap6c = CAP_LARGE;
    self->off58 = (int)self->region8cc - (int)self;
    self->cap70 = CAP_LARGE;
    self->off5c = (int)self->regionb4c - (int)self;
    self->cap74 = CAP_LARGE;
    self->off60 = (int)self->regiondcc - (int)self;
    self->cap78 = CAP_LARGE;
    self->off64 = (int)self->region80 - (int)self;
    return self;
}
