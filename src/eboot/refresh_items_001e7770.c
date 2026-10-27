/* HSTMATCH module=EBOOT.BIN start=0x001e7770 end=0x001e77f0 symbol=FUN_001e7770 lang=c99 */
/* Clone of src/sharing_main/refresh_items_001f5988.c (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the two item pointers are taken after the getter call and before the mode test (item 11 first), which keeps retail's materialised `addiu aN,s0,off` addresses ahead of the branch; names and types await human review. */
/* Items are the 20-byte records from +0x2364 that FUN_001e77f0 walks; item 10 or 11 is passed to FUN_000ffb3c
   with 1 depending on the mode word at +0x8188 of the FUN_001ee200 block. */
typedef struct Info {
    char pad[0x8188];
    int mode;
} Info;

typedef struct Item {
    int handle;
    int pad[4];
} Item;

typedef struct Obj {
    char pad0[0x235c];
    int h235c;
    char pad1[0x2364 - 0x2360];
    Item items[13];
} Obj;

extern void FUN_001e2694(Obj *);
extern void FUN_00103628(int, int);
extern Info *FUN_001ee200(void);
extern void FUN_000ffb3c(int, int);
extern void FUN_001e77f0(Obj *);

void FUN_001e7770(Obj *self)
{
    FUN_001e2694(self);
    FUN_00103628(self->h235c, 0);
    Info *info = FUN_001ee200();
    Item *b = &self->items[11];
    Item *a = &self->items[10];
    if (info->mode == 3)
        FUN_000ffb3c(a->handle, 1);
    else
        FUN_000ffb3c(b->handle, 1);
    FUN_001e77f0(self);
}
