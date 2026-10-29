/* HSTMATCH module=hstp_trans_main.prx start=0x0008cda4 end=0x0008d554 symbol=FUN_0008cda4 lang=c++ rodata=0x002ce84c */
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

extern Adhoc *DAT_003e1e04;
extern Console DAT_003b8f08;

extern const char *DAT_00378514[];  /* { "Create", ... } */
extern const char DAT_00378520[];   /* "connection error!" */
extern const char DAT_00378534[];   /* "back to initial screen" */
extern const char DAT_0037854c[];   /* "Connecting" */
extern const char DAT_00378558[];   /* "." */
extern const char DAT_0037855c[];   /* ">" */
extern const char DAT_00378560[];   /* "Join Request" */
extern const char DAT_00378570[];   /* "%02X%02X%02X%02X%02X%02X" */
extern const char DAT_0037858c[];   /* "NONE" */
extern const char DAT_00378594[];   /* "Member" */
extern const char DAT_0037859c[];   /* "+" */
extern const char DAT_003785a0[];   /* "*" */
extern const char DAT_003785a4[];   /* "O" */
extern const char DAT_003785a8[];   /* "%d:%02X%02X%02X%02X%02X%02X" */
extern const char DAT_003785c4[];   /* "%d:NONE" */
extern const char DAT_003785cc[];   /* "waiting for other player" */
extern const char DAT_003785e8[];   /* "press start to ready" */
extern const char DAT_00378600[];   /* "Game List" */
extern const char DAT_0037860c[];   /* "Searching" */
extern const char DAT_00378618[];   /* "Requesting" */

extern "C" {
void FUN_000481dc(Console *, const char *, ...);
int FUN_000143b0(char *, const char *, ...);
int FUN_0001100c(const void *, const void *, unsigned int);
int FUN_000c0ea8(Adhoc *, int);
}

inline void *operator new[](unsigned int, void *p) { return p; }

/* Prints the ad-hoc connection status to the debug console, according to the network state (animated dots while waiting). */
extern "C" void FUN_0008cda4(Menu *self)
{
    if (DAT_003e1e04) {
        if (self->error > 0) {
            FUN_000481dc(&DAT_003b8f08, DAT_00378520);
            FUN_000481dc(&DAT_003b8f08, DAT_00378534);
            return;
        }
        switch (DAT_003e1e04->state) {
        case NET_STATE_CONNECTING: {
            FUN_000481dc(&DAT_003b8f08, DAT_0037854c);
            int dots = self->frame % 40 / 10 + 1;
            for (int i = 0; i < dots; i++)
                FUN_000481dc(&DAT_003b8f08, DAT_00378558);
            break;
        }
        case NET_STATE_CHOOSE:
            for (int i = 0; i < CHOOSE_ENTRIES; i++)
                FUN_000481dc(&DAT_003b8f08, DAT_00378514[i]);
            FUN_000481dc(&DAT_003b8f08, DAT_0037855c);
            break;
        case NET_STATE_JOIN_REQUESTS: {
            FUN_000481dc(&DAT_003b8f08, DAT_00378560);
            PtrVec<unsigned char> *v = DAT_003e1e04->requests;
            if (v && v->Size()) {
                for (Iter<unsigned char> it = v->begin(); it != v->end(); ++it) {
                    char line[LINE_SIZE];
                    new (line) char[LINE_SIZE]();
                    unsigned char *mac = *it;
                    FUN_000143b0(line, DAT_00378570, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                    FUN_000481dc(&DAT_003b8f08, line);
                    FUN_000481dc(&DAT_003b8f08, DAT_0037855c);
                }
            } else
                FUN_000481dc(&DAT_003b8f08, DAT_0037858c);
            FUN_000481dc(&DAT_003b8f08, DAT_00378594);
            for (int i = 0; i < MEMBER_SLOTS; i++) {
                Member *m = &DAT_003e1e04->members[i];
                char line[LINE_SIZE];
                new (line) char[LINE_SIZE]();
                if (FUN_0001100c(m, DAT_003e1e04->mac1, MAC_SIZE) == 0)
                    FUN_000481dc(&DAT_003b8f08, DAT_0037859c);
                if (FUN_0001100c(m, DAT_003e1e04->mac2, MAC_SIZE) == 0)
                    FUN_000481dc(&DAT_003b8f08, DAT_003785a0);
                if (FUN_000c0ea8(DAT_003e1e04, i))
                    FUN_000481dc(&DAT_003b8f08, DAT_003785a4);
                if (m->valid) {
                    FUN_000143b0(line, DAT_003785a8, i, m->mac[0], m->mac[1], m->mac[2], m->mac[3], m->mac[4], m->mac[5]);
                    FUN_000481dc(&DAT_003b8f08, line);
                } else
                    FUN_000481dc(&DAT_003b8f08, DAT_003785c4, i);
            }
            if (DAT_003e1e04->ready > -1) {
                if (FUN_000c0ea8(DAT_003e1e04, DAT_003e1e04->ready))
                    FUN_000481dc(&DAT_003b8f08, DAT_003785cc);
                else
                    FUN_000481dc(&DAT_003b8f08, DAT_003785e8);
            }
            break;
        }
        case NET_STATE_GAME_LIST: {
            PtrVec<GameInfo> *v = DAT_003e1e04->games;
            FUN_000481dc(&DAT_003b8f08, DAT_00378600);
            if (v && v->Size()) {
                for (Iter<GameInfo> it = v->begin(); it != v->end(); ++it) {
                    if ((*it)->players > 0) {
                        char line[LINE_SIZE];
                        new (line) char[LINE_SIZE]();
                        unsigned char *mac = (*it)->mac;
                        FUN_000143b0(line, DAT_00378570, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
                        FUN_000481dc(&DAT_003b8f08, line);
                        FUN_000481dc(&DAT_003b8f08, DAT_0037855c);
                    }
                }
            } else {
                FUN_000481dc(&DAT_003b8f08, DAT_0037860c);
                int dots = self->frame % 40 / 10 + 1;
                for (int i = 0; i < dots; i++)
                    FUN_000481dc(&DAT_003b8f08, DAT_00378558);
            }
            break;
        }
        case NET_STATE_REQUESTING: {
            FUN_000481dc(&DAT_003b8f08, DAT_00378618);
            int dots = self->frame % 40 / 10 + 1;
            for (int i = 0; i < dots; i++)
                FUN_000481dc(&DAT_003b8f08, DAT_00378558);
            break;
        }
        case NET_STATE_MEMBERS:
            FUN_000481dc(&DAT_003b8f08, DAT_00378594);
            for (int i = 0; i < MEMBER_SLOTS; i++) {
                Member *m = &DAT_003e1e04->members[i];
                char line[LINE_SIZE];
                new (line) char[LINE_SIZE]();
                if (FUN_0001100c(m, DAT_003e1e04->mac1, MAC_SIZE) == 0)
                    FUN_000481dc(&DAT_003b8f08, DAT_0037859c);
                if (FUN_0001100c(m, DAT_003e1e04->mac2, MAC_SIZE) == 0)
                    FUN_000481dc(&DAT_003b8f08, DAT_003785a0);
                if (FUN_000c0ea8(DAT_003e1e04, i))
                    FUN_000481dc(&DAT_003b8f08, DAT_003785a4);
                if (m->valid) {
                    FUN_000143b0(line, DAT_003785a8, i, m->mac[0], m->mac[1], m->mac[2], m->mac[3], m->mac[4], m->mac[5]);
                    FUN_000481dc(&DAT_003b8f08, line);
                } else
                    FUN_000481dc(&DAT_003b8f08, DAT_003785c4, i);
            }
            if (DAT_003e1e04->ready > -1) {
                if (FUN_000c0ea8(DAT_003e1e04, DAT_003e1e04->ready))
                    FUN_000481dc(&DAT_003b8f08, DAT_003785cc);
                else
                    FUN_000481dc(&DAT_003b8f08, DAT_003785e8);
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
