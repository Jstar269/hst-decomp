/* HSTMATCH module=EBOOT.BIN start=0x0008c434 end=0x0008cae8 symbol=FUN_0008c434 lang=c++ rodata=0x002be944 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Scene change on a pending sequence id: case bodies in retail layout order (jump table follows the values);
   twin: src/sharing_main/scene_change_seq_0008db80.cpp. */

struct Scene;
struct SceneMgr;

struct Seq {
    char pad0[0x9c0];
    int next;
    char pad9c4[4];
    unsigned char change;
};

/* Same layout as Seq: retail re-reads next for the error print instead of reusing the switch value, which
   MWCC only does when the two accesses go through different (identical) struct types. */
struct SeqB { char pad0[0x9c0]; int next; };
struct Game { char pad0[0x28]; int m28; };

extern SceneMgr *DAT_003386c8;
extern int DAT_003386bc;
extern Game *DAT_00338ac4;
extern unsigned char DAT_003386b8;
extern void *DAT_0034a65c;
extern int DAT_002d2444;
extern char DAT_00307210[];
extern const char DAT_002d268c[];   /* "Match_000" */
extern const char DAT_002d2698[];   /* "ERROR:ChangeSeq(%s)\n" */

void *operator new(unsigned int);

extern "C" {
void FUN_0010d93c();
void FUN_0001f294(SceneMgr *);
void FUN_0001f21c(SceneMgr *, Scene *);
Scene *FUN_00199904(void *);
Scene *FUN_0019c340(void *);
Scene *FUN_0019c3b8(void *);
Scene *FUN_001cf798(void *);
Scene *FUN_002313c8(void *, int);
void FUN_00231240(void *, int);
Scene *FUN_00233d54(void *);
Scene *FUN_00252c84(void *);
Scene *FUN_0026cc00(void *);
void FUN_00238d74(int);
void FUN_0016bc9c();
void FUN_0019d4a0(int);
Scene *FUN_002637c8(void *);
void FUN_0001f06c(void *);
Game *FUN_000ba2a8(void *);
void FUN_000ba48c(Game *);
void FUN_000ba57c(Game *, int);
void FUN_001fd060(SceneMgr *, const char *);
Scene *FUN_0015d4bc(void *, int);
Scene *FUN_00262204(void *);
Scene *FUN_0028dbf8(void *);
Scene *FUN_0029e160(void *);
Scene *FUN_002ab5ac(void *);
void FUN_002afb80(SceneMgr *, int);
const char *FUN_00234078(int);
void FUN_0008cae8(...);
}

struct Scene01 {
    void *vt;
    char pad4[0x3c - 4];
    unsigned char m3c, m3d, m3e, m3f, m40, m41;
    char pad42[2];
    int m44;
    int m48;
    int m4c;
    int m50;
    Scene01()
    {
        FUN_0001f06c(this);
        vt = DAT_00307210;
        m3c = 0;
        m3d = 0;
        m3e = 0;
        m3f = 0;
        m40 = 0;
        m41 = 0;
        Game *g = (Game *)operator new(0x288);
        if (g)
            g = FUN_000ba2a8(g);
        DAT_00338ac4 = g;
        FUN_000ba48c(g);
        FUN_000ba57c(DAT_00338ac4, 0);
        m44 = 0;
        m48 = 0;
        m4c = DAT_00338ac4->m28;
        m50 = 0;
        DAT_003386b8 = 1;
    }
};

/* Release build: assertions compile to nothing (the Sharing build keeps them, see the twin). */
#define HST_ASSERT(cond, text, line) ((void)0)

#define PUSH(size, ctor)                              \
    {                                                 \
        Scene *s = (Scene *)operator new(size);       \
        if (s)                                        \
            s = ctor(s);                              \
        FUN_0001f21c(DAT_003386c8, s);                \
    }

extern "C" void FUN_0008c434(Seq *self)
{
    if (self->change) {
        self->change = 0;
        FUN_0010d93c();
        switch (self->next) {
        case 9: case 0x1b: case 0x52:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_00199904);
            DAT_003386bc++;
            break;
        case 0x1c: case 0x53:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x3c, FUN_0019c340);
            return;
        case 8: case 0x1d: case 0x54:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x44, FUN_0019c3b8);
            break;
        case 0x13: case 0x1e:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_001cf798);
            break;
        case 0x21: case 0x4d: {
            FUN_0001f294(DAT_003386c8);
            Scene *s = (Scene *)operator new(0x3c);
            if (s)
                s = FUN_002313c8(s, 0);
            FUN_0001f21c(DAT_003386c8, s);
            FUN_00231240(DAT_0034a65c, self->next == 0x21);
            break;
        }
        case 0xd:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x3c, FUN_00233d54);
            break;
        case 0x1f:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_001cf798);
            break;
        case 0xe: case 0x2b:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x3c, FUN_00252c84);
            break;
        case 0x22: case 0x47: case 0x48:
            FUN_0001f294(DAT_003386c8);
            PUSH(0xa60, FUN_0026cc00);
            break;
        case 0x23: case 0x49:
            FUN_0001f294(DAT_003386c8);
            FUN_00238d74(0);
            break;
        case 6:
            FUN_0001f294(DAT_003386c8);
            FUN_00238d74(1);
            break;
        case 3: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x2c: case 0x2d: case 0x2e:
        case 0x2f: case 0x33: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3f: case 0x40: case 0x41:
        case 0x42: case 0x46: case 0x55:
            FUN_0001f294(DAT_003386c8);
            FUN_0016bc9c();
            break;
        case 4: case 0x29: case 0x30: case 0x34: case 0x56:
            FUN_0001f294(DAT_003386c8);
            FUN_0019d4a0(DAT_002d2444);
            break;
        case 0x43:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_002637c8);
            break;
        case 0x3c:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_001cf798);
            break;
        case 1: {
            FUN_0001f294(DAT_003386c8);
            Scene01 *p = new Scene01;
            FUN_0001f21c(DAT_003386c8, (Scene *)p);
            break;
        }
        case 5:
            FUN_0001f294(DAT_003386c8);
            FUN_001fd060(DAT_003386c8, DAT_002d268c);
            break;
        case 0xa: case 0x2a: case 0x31: case 0x35: case 0x44: case 0x57: {
            FUN_0001f294(DAT_003386c8);
            Scene *s = (Scene *)operator new(0x4c);
            if (s)
                s = FUN_0015d4bc(s, self->next);
            FUN_0001f21c(DAT_003386c8, s);
            break;
        }
        case 0xb: case 0x4b: case 0x4c: case 0x58: {
            FUN_0001f294(DAT_003386c8);
            Scene *s = (Scene *)operator new(0x4c);
            if (s)
                s = FUN_0015d4bc(s, self->next);
            FUN_0001f21c(DAT_003386c8, s);
            break;
        }
        case 0xc: {
            FUN_0001f294(DAT_003386c8);
            Scene *s = (Scene *)operator new(0x3c);
            if (s)
                s = FUN_002313c8(s, 0);
            FUN_0001f21c(DAT_003386c8, s);
            FUN_00231240(DAT_0034a65c, 0);
            break;
        }
        case 0x3d:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_00262204);
            break;
        case 0x12: case 0x3e:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_0028dbf8);
            break;
        case 0x45:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x40, FUN_0029e160);
            break;
        case 0x14:
            FUN_0001f294(DAT_003386c8);
            PUSH(0xa60, FUN_0026cc00);
            break;
        case 0x15: case 0x4e:
            FUN_0001f294(DAT_003386c8);
            PUSH(0x128, FUN_002ab5ac);
            break;
        case 0x16: case 0x4f:
            FUN_0001f294(DAT_003386c8);
            FUN_002afb80(DAT_003386c8, 0);
            break;
        case 7: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x32: case 0x36: case 0x3b: case 0x4a:
        case 0x50: case 0x51:
            break;
        case 0: case 2: case 0xf: case 0x10: case 0x11: case 0x20:
        default:
            FUN_0008cae8(DAT_002d2698, FUN_00234078(((SeqB *)self)->next));
            HST_ASSERT(0, "0", 1232);
            break;
        }
    }
}
