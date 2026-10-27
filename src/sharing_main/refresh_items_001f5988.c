/* HSTMATCH module=hstp_trans_main.prx start=0x001f5988 end=0x001f5a08 symbol=FUN_001f5988 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the two item pointers are taken after the getter call and before the mode test (item 11 first), which keeps retail's materialised `addiu aN,s0,off` addresses ahead of the branch; names and types await human review. */
/* Items are the 20-byte records from +0x2364 that FUN_001f5a08 walks; item 10 or 11 is passed to FUN_00105470
   with 1 depending on the mode word at +0x8188 of the FUN_001fc5c8 block. */
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

extern void FUN_001f08e8(Obj *);
extern void FUN_00108f54(int, int);
extern Info *FUN_001fc5c8(void);
extern void FUN_00105470(int, int);
extern void FUN_001f5a08(Obj *);

void FUN_001f5988(Obj *self)
{
    FUN_001f08e8(self);
    FUN_00108f54(self->h235c, 0);
    Info *info = FUN_001fc5c8();
    Item *b = &self->items[11];
    Item *a = &self->items[10];
    if (info->mode == 3)
        FUN_00105470(a->handle, 1);
    else
        FUN_00105470(b->handle, 1);
    FUN_001f5a08(self);
}
