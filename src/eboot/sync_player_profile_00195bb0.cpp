/* HSTMATCH module=EBOOT.BIN start=0x00195bb0 end=0x0019644c symbol=FUN_00195bb0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Copy the active player's profile (+0x464) into the global profile (0x341d10) and, on the host side, push the
   player's two character records (+0x27c, +0x370) into the record table entries found by name (map<const char*,
   int> find 0x196478; the second only for types 1/3/5), renaming each entry after the copy (0x149a8); on the
   remote side create the NPC from the profile (0x1931b8) and set its geta value (clg_database.cpp per the
   Sharing twin's assert `pNpc1`). All copies are implicit memberwise operator= of non-POD structs (char arrays
   -> count-down two-per-iteration loops, 3-field sub-structs -> all loads before the stores). The 1/3/5 test is
   a switch (labels tested in reverse order). Names provisional. */
struct B3 { unsigned char a, b, c; };
struct S3 { short a, b, c; };

struct Profile {
    char name[16];
    unsigned short u10;
    char name2[16];
    short s22, s24;
    unsigned char c26, c27, type, c29, c2a, c2b;
    char c2c, c2d;
    unsigned char c2e;
    char c2f;
    unsigned char c30, c31;
    char c32;
    unsigned char c33, c34;
    short s36, s38, s3a, s3c;
    char key2[16];
    char key3[16];
    B3 b5e;
    S3 s62;
    short s68, s6a;
    Profile();
};

struct Rec {
    short a[6];
    unsigned char c0c, c0d, c0e;
    char name[16];
    unsigned short u20, u22;
    unsigned char c24;
    char s25[6];
    unsigned char c2b, c2c;
    char s2d[16];
    short s3e, s40;
    unsigned char c42, c43;
    float f44, f48, f4c;
    short s50, s52;
    char s54[16];
    unsigned char c64, c65, c66, c67;
    char s68[16];
    short s78, s7a;
    unsigned char c7c;
    char s7d[12];
    S3 s8a;
    short s90[5];
    Rec();
};

struct Player {
    char pad0[4];
    int remote;
    char pad8[0x27c - 8];
    Rec rec1;
    char pad318[0x370 - 0x318];
    Rec rec2;
    char pad40c[0x464 - 0x40c];
    Profile prof;
    char pad4d0[0x2c00 - 0x4d0];
    bool ready;
};
struct Game { char pad0[0x40]; Player *player; };

struct RecTable { int count; Rec *recs; };
struct NameNode { NameNode *left, *right, *parent; const char *key; int value; };
struct NameIt { NameNode *n; NameIt() {} };
struct NameMap { int size; NameNode *header[4]; };
struct RecOwner { char pad0[0x40]; NameMap map; };

struct Npc { char pad0[0x88]; char geta; };

extern Game *DAT_003386c8;
extern int DAT_00338ac4;
extern RecTable *DAT_0034173c;
extern RecOwner *DAT_00341748;
extern Profile DAT_00341d10;
extern char DAT_00341ab0;
extern char DAT_00341990;
extern char DAT_002e15d8[];   /* "geta=%d\n" */

extern "C" {
NameIt FUN_00196478(NameMap *m, const char *const &key);
void FUN_000149a8(char *dst, const char *src);
void FUN_001931b8(Npc **out, int a, Profile *p);
void FUN_0019644c(const char *fmt, ...);
}

static inline Rec *FindRec(const char *name)
{
    if (DAT_0034173c != 0) {
        NameIt it = FUN_00196478(&DAT_00341748->map, name);
        if (it.n != (NameNode *)DAT_00341748->map.header)
            return &DAT_0034173c->recs[it.n->value];
    }
    return 0;
}

extern "C" void FUN_00195bb0()
{
    if (DAT_003386c8 != 0 && DAT_00338ac4 != 0) {
        Player *pl = DAT_003386c8->player;
        if (pl->ready) {
            DAT_00341d10 = pl->prof;
            bool host = pl->remote == 0;
            if (host) {
                const char *key = DAT_00341d10.key2;
                Rec *r = FindRec(key);
                if (r) {
                    *r = pl->rec1;
                    FUN_000149a8(r->name, key);
                }
                switch (DAT_00341d10.type) {
                case 1:
                case 3:
                case 5: {
                    const char *key2 = DAT_00341d10.key3;
                    Rec *r2 = FindRec(key2);
                    if (r2) {
                        *r2 = pl->rec2;
                        FUN_000149a8(r2->name, key2);
                    }
                    break;
                }
                }
            }
            if (!host) {
                Npc *pNpc1 = 0;
                FUN_001931b8(&pNpc1, 0, &DAT_00341d10);
                FUN_0019644c(DAT_002e15d8, DAT_00341ab0);
                FUN_0019644c(DAT_002e15d8, DAT_00341990);
                pNpc1->geta = DAT_00341ab0;
            }
        }
    }
}
