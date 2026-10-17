/* HSTMATCH module=hstp_trans_main.prx start=0x0008db80 end=0x0008e25c symbol=FUN_0008db80 lang=c++ rodata=0x002ce87c */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Debug-build twin of src/eboot/scene_change_seq_0008c434.cpp: same source plus the Menu.cpp ASSERT(0) (line 1232)
   after the error print; the three FUN_001cf798 call sites are two distinct constructors here (one object is
   0x50 bytes instead of 0x40). */

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

extern SceneMgr *DAT_003e1a08;
extern int DAT_003e19fc;
extern Game *DAT_003e1e04;
extern unsigned char DAT_003e19f8;
extern void *DAT_003f398c;
extern int DAT_00378500;
extern char DAT_003b04dc[];
extern const char DAT_00378784[];   /* "Match_000" */
extern const char DAT_00378790[];   /* "ERROR:ChangeSeq(%s)\n" */
extern const char DAT_0037872c[];   /* "assertion \"%s\" failed: file \"%s\", line %d\n" */
extern const char DAT_00378758[];   /* "0" */
extern const char DAT_0037875c[];   /* "Menu.cpp" */

void *operator new(unsigned int);

extern "C" {
void FUN_00113ee4();
void FUN_0001f054(SceneMgr *);
void FUN_0001ef34(SceneMgr *, Scene *);
Scene *FUN_001a63f8(void *);
Scene *FUN_001a95d8(void *);
Scene *FUN_001a9620(void *);
Scene *FUN_0026e494(void *);
Scene *FUN_001dde74(void *);
Scene *FUN_002414c8(void *, int);
void FUN_00241340(void *, int);
Scene *FUN_00243e54(void *);
Scene *FUN_00262fd8(void *);
Scene *FUN_0027dc40(void *);
void FUN_00248eac(int);
void FUN_00177ec4();
void FUN_001aa948(int);
Scene *FUN_00274644(void *);
void FUN_0001ec44(void *);
Game *FUN_000bd5ec(void *);
void FUN_000bd7d0(Game *);
void FUN_000bd8c0(Game *, int);
void FUN_0020b804(SceneMgr *, const char *);
Scene *FUN_00169a1c(void *, int);
Scene *FUN_0027302c(void *);
Scene *FUN_0029f3c0(void *);
Scene *FUN_002ad3ec(void *);
Scene *FUN_002bad68(void *);
void FUN_002bf5d0(SceneMgr *, int);
const char *FUN_00244178(int);
void FUN_0008d950(...);
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
        FUN_0001ec44(this);
        vt = DAT_003b04dc;
        m3c = 0;
        m3d = 0;
        m3e = 0;
        m3f = 0;
        m40 = 0;
        m41 = 0;
        Game *g = (Game *)operator new(0x288);
        if (g)
            g = FUN_000bd5ec(g);
        DAT_003e1e04 = g;
        FUN_000bd7d0(g);
        FUN_000bd8c0(DAT_003e1e04, 0);
        m44 = 0;
        m48 = 0;
        m4c = DAT_003e1e04->m28;
        m50 = 0;
        DAT_003e19f8 = 1;
    }
};

#define HST_ASSERT(cond, text, line) do { if (!(cond)) { FUN_0008d950(DAT_0037872c, text, DAT_0037875c, line); for (;;) {} } } while (0)

#define PUSH(size, ctor)                              \
    {                                                 \
        Scene *s = (Scene *)operator new(size);       \
        if (s)                                        \
            s = ctor(s);                              \
        FUN_0001ef34(DAT_003e1a08, s);                \
    }

extern "C" void FUN_0008db80(Seq *self)
{
    if (self->change) {
        self->change = 0;
        FUN_00113ee4();
        switch (self->next) {
        case 9: case 0x1b: case 0x52:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_001a63f8);
            DAT_003e19fc++;
            break;
        case 0x1c: case 0x53:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x3c, FUN_001a95d8);
            return;
        case 8: case 0x1d: case 0x54:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x44, FUN_001a9620);
            break;
        case 0x13: case 0x1e:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x50, FUN_0026e494);
            break;
        case 0x21: case 0x4d: {
            FUN_0001f054(DAT_003e1a08);
            Scene *s = (Scene *)operator new(0x3c);
            if (s)
                s = FUN_002414c8(s, 0);
            FUN_0001ef34(DAT_003e1a08, s);
            FUN_00241340(DAT_003f398c, self->next == 0x21);
            break;
        }
        case 0xd:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x3c, FUN_00243e54);
            break;
        case 0x1f:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_001dde74);
            break;
        case 0xe: case 0x2b:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x3c, FUN_00262fd8);
            break;
        case 0x22: case 0x47: case 0x48:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0xa60, FUN_0027dc40);
            break;
        case 0x23: case 0x49:
            FUN_0001f054(DAT_003e1a08);
            FUN_00248eac(0);
            break;
        case 6:
            FUN_0001f054(DAT_003e1a08);
            FUN_00248eac(1);
            break;
        case 3: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x2c: case 0x2d: case 0x2e:
        case 0x2f: case 0x33: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3f: case 0x40: case 0x41:
        case 0x42: case 0x46: case 0x55:
            FUN_0001f054(DAT_003e1a08);
            FUN_00177ec4();
            break;
        case 4: case 0x29: case 0x30: case 0x34: case 0x56:
            FUN_0001f054(DAT_003e1a08);
            FUN_001aa948(DAT_00378500);
            break;
        case 0x43:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_00274644);
            break;
        case 0x3c:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_001dde74);
            break;
        case 1: {
            FUN_0001f054(DAT_003e1a08);
            Scene01 *p = new Scene01;
            FUN_0001ef34(DAT_003e1a08, (Scene *)p);
            break;
        }
        case 5:
            FUN_0001f054(DAT_003e1a08);
            FUN_0020b804(DAT_003e1a08, DAT_00378784);
            break;
        case 0xa: case 0x2a: case 0x31: case 0x35: case 0x44: case 0x57: {
            FUN_0001f054(DAT_003e1a08);
            Scene *s = (Scene *)operator new(0x4c);
            if (s)
                s = FUN_00169a1c(s, self->next);
            FUN_0001ef34(DAT_003e1a08, s);
            break;
        }
        case 0xb: case 0x4b: case 0x4c: case 0x58: {
            FUN_0001f054(DAT_003e1a08);
            Scene *s = (Scene *)operator new(0x4c);
            if (s)
                s = FUN_00169a1c(s, self->next);
            FUN_0001ef34(DAT_003e1a08, s);
            break;
        }
        case 0xc: {
            FUN_0001f054(DAT_003e1a08);
            Scene *s = (Scene *)operator new(0x3c);
            if (s)
                s = FUN_002414c8(s, 0);
            FUN_0001ef34(DAT_003e1a08, s);
            FUN_00241340(DAT_003f398c, 0);
            break;
        }
        case 0x3d:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_0027302c);
            break;
        case 0x12: case 0x3e:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_0029f3c0);
            break;
        case 0x45:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x40, FUN_002ad3ec);
            break;
        case 0x14:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0xa60, FUN_0027dc40);
            break;
        case 0x15: case 0x4e:
            FUN_0001f054(DAT_003e1a08);
            PUSH(0x128, FUN_002bad68);
            break;
        case 0x16: case 0x4f:
            FUN_0001f054(DAT_003e1a08);
            FUN_002bf5d0(DAT_003e1a08, 0);
            break;
        case 7: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x32: case 0x36: case 0x3b: case 0x4a:
        case 0x50: case 0x51:
            break;
        case 0: case 2: case 0xf: case 0x10: case 0x11: case 0x20:
        default:
            FUN_0008d950(DAT_00378790, FUN_00244178(((SeqB *)self)->next));
            HST_ASSERT(0, DAT_00378758, 1232);
            break;
        }
    }
}
