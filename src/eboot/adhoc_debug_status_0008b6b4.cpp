/* HSTMATCH module=EBOOT.BIN start=0x0008b6b4 end=0x0008be64 symbol=FUN_0008b6b4 lang=c++ rodata=0x002be914 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Console;

/* Values of Adhoc::state shown by the debug overlay (named after the text each prints). */
enum {
    NET_STATE_CONNECTING = 1,
    NET_STATE_CHOOSE = 2,        /* prints the Create / Join entries */
    NET_STATE_JOIN_REQUESTS = 4, /* lists join requests and the member slots */
    NET_STATE_GAME_LIST = 5,
    NET_STATE_REQUESTING = 6,
    NET_STATE_MEMBERS = 8        /* lists the member slots */
};

#define MAC_SIZE 6        /* bytes of a MAC address */
#define MEMBER_SLOTS 4    /* member slots shown */
#define CHOOSE_ENTRIES 2  /* entries of the Create / Join list */
#define LINE_SIZE 64      /* scratch line buffer */

struct Member {                 /* 7 bytes */
    unsigned char mac[MAC_SIZE];
    unsigned char valid;
};

struct GameInfo { char pad0[0xc]; unsigned char *mac; int players; };

template <class T> struct Iter {
    T **p;
    Iter(T **q) : p(q) {}
    T *operator*() const { return *p; }
    Iter &operator++() { ++p; return *this; }
    bool operator==(const Iter &o) const { return p == o.p; }
    bool operator!=(const Iter &o) const { return !(*this == o); }
};

template <class T> struct PtrVec {
    T **data;
    int size;
    Iter<T> begin() const { return Iter<T>(data); }
    Iter<T> end() { return Iter<T>(data + size); }
    int Size() const { return size; }
};

struct Adhoc {
    char pad0[0x28];
    int state;                  /* 0x28 */
    char pad2c[0x38 - 0x2c];
    unsigned char mac1[MAC_SIZE];      /* 0x38 */
    unsigned char mac2[MAC_SIZE];      /* 0x3e */
    char pad44[0x50 - 0x44];
    PtrVec<GameInfo> *games;    /* 0x50 */
    PtrVec<unsigned char> *requests; /* 0x54 */
    Member members[MEMBER_SLOTS];          /* 0x58 */
    char pad74[0x198 - 0x74];
    int ready;                  /* 0x198 */
};

struct Menu {
    char pad0[0x48];
    int frame;                  /* 0x48 */
    char pad4c[0x50 - 0x4c];
    int error;                  /* 0x50 */
};

extern Adhoc *DAT_00338ac4;
extern Console DAT_0030fc10;

extern const char *DAT_002d2458[];  /* { "Create", ... } */
extern const char DAT_002d2464[];   /* "connection error!" */
extern const char DAT_002d2478[];   /* "back to initial screen" */
extern const char DAT_002d2490[];   /* "Connecting" */
extern const char DAT_002d249c[];   /* "." */
extern const char DAT_002d24a0[];   /* ">" */
extern const char DAT_002d24a4[];   /* "Join Request" */
extern const char DAT_002d24b4[];   /* "%02X%02X%02X%02X%02X%02X" */
extern const char DAT_002d24d0[];   /* "NONE" */
extern const char DAT_002d24d8[];   /* "Member" */
extern const char DAT_002d24e0[];   /* "+" */
extern const char DAT_002d24e4[];   /* "*" */
extern const char DAT_002d24e8[];   /* "O" */
extern const char DAT_002d24ec[];   /* "%d:%02X%02X%02X%02X%02X%02X" */
extern const char DAT_002d2508[];   /* "%d:NONE" */
extern const char DAT_002d2510[];   /* "waiting for other player" */
extern const char DAT_002d252c[];   /* "press start to ready" */
extern const char DAT_002d2544[];   /* "Game List" */
extern const char DAT_002d2550[];   /* "Searching" */
extern const char DAT_002d255c[];   /* "Requesting" */

extern "C" {
void FUN_00047d58(Console *, const char *, ...);
int FUN_000143b0(char *, const char *, ...);
int FUN_0001100c(const void *, const void *, unsigned int);
int FUN_000bd92c(Adhoc *, int);
}

inline void *operator new[](unsigned int, void *p) { return p; }

/* Prints the ad-hoc connection status to the debug console, according to the network state (animated dots while waiting). */
extern "C" void FUN_0008b6b4(Menu *self)
{
    if (DAT_00338ac4) {
        if (self->error > 0) {
            FUN_00047d58(&DAT_0030fc10, DAT_002d2464);
            FUN_00047d58(&DAT_0030fc10, DAT_002d2478);
            return;
        }
        switch (DAT_00338ac4->state) {
        case NET_STATE_CONNECTING: {
            FUN_00047d58(&DAT_0030fc10, DAT_002d2490);
            int dots = self->frame % 40 / 10 + 1;
            for (int i = 0; i < dots; i++)
                FUN_00047d58(&DAT_0030fc10, DAT_002d249c);
            break;
        }
        case NET_STATE_CHOOSE:
            for (int i = 0; i < CHOOSE_ENTRIES; i++)
                FUN_00047d58(&DAT_0030fc10, DAT_002d2458[i]);
            FUN_00047d58(&DAT_0030fc10, DAT_002d24a0);
            break;
        case NET_STATE_JOIN_REQUESTS: {
            FUN_00047d58(&DAT_0030fc10, DAT_002d24a4);
            PtrVec<unsigned char> *v = DAT_00338ac4->requests;
            if (v && v->Size()) {
                for (Iter<unsigned char> it = v->begin(); it != v->end(); ++it) {
                    char line[LINE_SIZE];
                    new (line) char[LINE_SIZE]();
                    unsigned char *mac = *it;
                    FUN_000143b0(line, DAT_002d24b4, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                    FUN_00047d58(&DAT_0030fc10, line);
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24a0);
                }
            } else
                FUN_00047d58(&DAT_0030fc10, DAT_002d24d0);
            FUN_00047d58(&DAT_0030fc10, DAT_002d24d8);
            for (int i = 0; i < MEMBER_SLOTS; i++) {
                Member *m = &DAT_00338ac4->members[i];
                char line[LINE_SIZE];
                new (line) char[LINE_SIZE]();
                if (FUN_0001100c(m, DAT_00338ac4->mac1, MAC_SIZE) == 0)
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e0);
                if (FUN_0001100c(m, DAT_00338ac4->mac2, MAC_SIZE) == 0)
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e4);
                if (FUN_000bd92c(DAT_00338ac4, i))
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e8);
                if (m->valid) {
                    FUN_000143b0(line, DAT_002d24ec, i, m->mac[0], m->mac[1], m->mac[2], m->mac[3], m->mac[4], m->mac[5]);
                    FUN_00047d58(&DAT_0030fc10, line);
                } else
                    FUN_00047d58(&DAT_0030fc10, DAT_002d2508, i);
            }
            if (DAT_00338ac4->ready > -1) {
                if (FUN_000bd92c(DAT_00338ac4, DAT_00338ac4->ready))
                    FUN_00047d58(&DAT_0030fc10, DAT_002d2510);
                else
                    FUN_00047d58(&DAT_0030fc10, DAT_002d252c);
            }
            break;
        }
        case NET_STATE_GAME_LIST: {
            PtrVec<GameInfo> *v = DAT_00338ac4->games;
            FUN_00047d58(&DAT_0030fc10, DAT_002d2544);
            if (v && v->Size()) {
                for (Iter<GameInfo> it = v->begin(); it != v->end(); ++it) {
                    if ((*it)->players > 0) {
                        char line[LINE_SIZE];
                        new (line) char[LINE_SIZE]();
                        unsigned char *mac = (*it)->mac;
                        FUN_000143b0(line, DAT_002d24b4, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                        FUN_00047d58(&DAT_0030fc10, line);
                        FUN_00047d58(&DAT_0030fc10, DAT_002d24a0);
                    }
                }
            } else {
                FUN_00047d58(&DAT_0030fc10, DAT_002d2550);
                int dots = self->frame % 40 / 10 + 1;
                for (int i = 0; i < dots; i++)
                    FUN_00047d58(&DAT_0030fc10, DAT_002d249c);
            }
            break;
        }
        case NET_STATE_REQUESTING: {
            FUN_00047d58(&DAT_0030fc10, DAT_002d255c);
            int dots = self->frame % 40 / 10 + 1;
            for (int i = 0; i < dots; i++)
                FUN_00047d58(&DAT_0030fc10, DAT_002d249c);
            break;
        }
        case NET_STATE_MEMBERS:
            FUN_00047d58(&DAT_0030fc10, DAT_002d24d8);
            for (int i = 0; i < MEMBER_SLOTS; i++) {
                Member *m = &DAT_00338ac4->members[i];
                char line[LINE_SIZE];
                new (line) char[LINE_SIZE]();
                if (FUN_0001100c(m, DAT_00338ac4->mac1, MAC_SIZE) == 0)
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e0);
                if (FUN_0001100c(m, DAT_00338ac4->mac2, MAC_SIZE) == 0)
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e4);
                if (FUN_000bd92c(DAT_00338ac4, i))
                    FUN_00047d58(&DAT_0030fc10, DAT_002d24e8);
                if (m->valid) {
                    FUN_000143b0(line, DAT_002d24ec, i, m->mac[0], m->mac[1], m->mac[2], m->mac[3], m->mac[4], m->mac[5]);
                    FUN_00047d58(&DAT_0030fc10, line);
                } else
                    FUN_00047d58(&DAT_0030fc10, DAT_002d2508, i);
            }
            if (DAT_00338ac4->ready > -1) {
                if (FUN_000bd92c(DAT_00338ac4, DAT_00338ac4->ready))
                    FUN_00047d58(&DAT_0030fc10, DAT_002d2510);
                else
                    FUN_00047d58(&DAT_0030fc10, DAT_002d252c);
            }
            break;
        case 0:
        case 3:
        case 7:
        case 9:
        case 10:
        case 11:
            break;
        }
    }
}
