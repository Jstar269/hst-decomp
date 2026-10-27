/* HSTMATCH module=hstp_trans_main.prx start=0x000c7e48 end=0x000c7fa4 symbol=__ct__10C_000c7e48Fv lang=c++ */
/* Hand-written reconstruction from the disassembly (member wrapper types taken from src/sharing_main/player_ctor_00097520.cpp); exact match verified; names and types await human review. */
/* OnlineGame constructor (OnlineGame.cpp, per its assert `g_pOnlineGame == 0` at line 15): base ctor 0x1ec44, own
   vtable 0x3b06fc, then an array of four 0x1d0-byte OnlineGameObject members (named by the debug print
   "sizeof(OnlineGameObject) %d") whose members have out-of-line ctors (0x97e68..0x98094, the same sub-object layout
   as the Player's member at +0x1c0), written as inline wrappers so MWCC emits its own member-array construction
   loops. The body prints the object size through the debug print stub 0xc7fa4, asserts the singleton slot is
   free, registers itself and calls 0xc85a8. Names provisional. */
extern "C" {
void *FUN_00098094(void *);
void *FUN_00098064(void *);
void *FUN_00098034(void *);
void *FUN_00098004(void *);
void *FUN_00097fd4(void *);
void *FUN_00097fa4(void *);
void *FUN_00097f74(void *);
void *FUN_00097f44(void *);
void *FUN_00097f14(void *);
void *FUN_00097edc(void *);
void *FUN_00097eac(void *);
void *FUN_00097e98(void *);
void *FUN_00097e68(void *);
void FUN_000c7fa4(...);
}

struct M_98094 { char d[4]; M_98094() { FUN_00098094(this); } };
struct M_98064 { char d[12]; M_98064() { FUN_00098064(this); } };
struct M_98034 { char d[0x30]; M_98034() { FUN_00098034(this); } };
struct M_98004 { char d[12]; M_98004() { FUN_00098004(this); } };
struct M_97fd4 { char d[12]; M_97fd4() { FUN_00097fd4(this); } };
struct M_97fa4 { char d[12]; M_97fa4() { FUN_00097fa4(this); } };
struct M_97f74 { char d[0x30]; M_97f74() { FUN_00097f74(this); } };
struct M_97f44 { char d[0x30]; M_97f44() { FUN_00097f44(this); } };
struct M_97f14 { char d[0x10]; M_97f14() { FUN_00097f14(this); } };
struct M_97edc { char d[0x40]; M_97edc() { FUN_00097edc(this); } };
struct M_97eac { char d[8]; M_97eac() { FUN_00097eac(this); } };
struct M_97e98 { char d[8]; M_97e98() { FUN_00097e98(this); } };
struct M_97e68 { char d[0x90]; M_97e68() { FUN_00097e68(this); } };

struct OnlineGameObject {
    char c00, c01;
    short s02;
    int i04;
    int i08;
    M_98094 a0c[2];
    M_98064 m14;
    M_98034 m20;
    M_98004 a50[2];
    M_97fd4 m68;
    M_97fa4 m74;
    M_97f74 m80;
    M_97f44 mb0;
    M_97f14 me0;
    M_97edc mf0;
    M_97eac m130;
    M_97e98 m138;
    M_97e68 m140;
    OnlineGameObject()
    {
        c00 = 0;
        c01 = 0;
        s02 = 0;
        i04 = 0;
        i08 = 0;
    }
};

struct B_0001ec44 {
    B_0001ec44();
    virtual void v0();
    char pad4[0x3c - 4];
};

struct C_000c7e48;
extern C_000c7e48 *DAT_003e1e30;   /* g_pOnlineGame */
/* "sizeof(OnlineGameObject) %d\n", "assertion \"%s\" failed: file \"%s\", line %d\n", "g_pOnlineGame == 0", "OnlineGame.cpp" */
extern char DAT_0037c458[], DAT_0037c478[], DAT_0037c4a4[], DAT_0037c4b8[];
extern "C" void FUN_000c85a8(C_000c7e48 *);

struct C_000c7e48 : B_0001ec44 {
    int m3c;
    OnlineGameObject objs[4];
    C_000c7e48();
    virtual void v1();
};

C_000c7e48::C_000c7e48()
{
    FUN_000c7fa4(DAT_0037c458, sizeof(OnlineGameObject));
    if (!(DAT_003e1e30 == 0)) {
        FUN_000c7fa4(DAT_0037c478, DAT_0037c4a4, DAT_0037c4b8, 15);
        for (;;) {
        }
    }
    DAT_003e1e30 = this;
    FUN_000c85a8(this);
}
