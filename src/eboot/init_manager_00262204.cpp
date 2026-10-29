/* HSTMATCH module=EBOOT.BIN start=0x00262204 end=0x00262310 symbol=FUN_00262204 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual call, declaration order for saved registers, merged alloc/ctor pattern; exact match verified; readability pass; names and types await human review. */

extern "C" {
extern char DAT_002fdddc[];
extern char DAT_002fddf4[];
extern char DAT_00309a38[];
extern char DAT_0030ab9c[];
extern char DAT_0030ebf4[];

extern void *FUN_00000bcc(unsigned int size);
extern void *FUN_00010184(int a, int b);
extern void FUN_000104e0(void *p);
extern void FUN_0001bfb4(void *a, void *b, int c);
extern void FUN_0001cad0(void *a, int b, void *c);
extern void FUN_0001cb88(void *a);
extern void *FUN_0001cbfc(void);
extern int FUN_0001cc54(void);
extern void *FUN_0001f06c(void *self);
extern void FUN_00253da0(void);
extern void FUN_00258294(void *p);
extern void *FUN_00262310(void *p, void *name);
}

/* Object whose child (created here) sits at +0x3c. */
struct Obj_00262204 {
    void *vptr;           // +0
    char pad[56];         // +4 .. +59
    void *child;          // +60 (0x3c)
};

enum {
    ARENA_ALIGN = 64,
    ARENA_SIZE = 0x300000,   /* temporary arena swapped in while the child is built */
    CHILD_SIZE = 0x1870      /* allocation size of the child object */
};

struct Target_00262204 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

/* Initialises the manager: builds its child object inside a temporary arena, restores the previous arena, then runs the child's slot-6 method. */
extern "C" void *FUN_00262204(struct Obj_00262204 *self)
{
    void *arena;
    void *prev_base;
    void *p;
    int prev_size;

    FUN_0001f06c(self);
    self->vptr = &DAT_00309a38;
    arena = FUN_00010184(ARENA_ALIGN, ARENA_SIZE);
    FUN_0001bfb4(&DAT_0030ab9c, arena, ARENA_SIZE);
    FUN_0001cad0(&DAT_0030ebf4, 1, DAT_002fdddc);

    p = FUN_00000bcc(CHILD_SIZE);
    if (p != 0) {
        p = FUN_00262310(p, DAT_002fddf4);
    }
    self->child = p;

    FUN_00253da0();
    FUN_0001cb88(&DAT_0030ebf4);
    prev_base = FUN_0001cbfc();
    prev_size = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c, prev_base, prev_size);

    if (arena != 0) {
        FUN_000104e0(arena);
    }

    FUN_00258294(self->child);
    ((struct Target_00262204 *)self->child)->v6();

    return self;
}
