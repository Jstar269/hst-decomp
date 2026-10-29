/* Court owner object seen by the two spawn-setup sources: spawned object vectors, a record table and the object types they create. */
#ifndef HST_COURT_SPAWN_H
#define HST_COURT_SPAWN_H

/* Empty tag passed by value to the vector grow helpers. */
struct EmptyTag {};

struct AlignedVec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

/* 0x280-byte object created with a kind id; the owner's two floats are copied into it. */
struct AreaObj {
    char pad[0x24c];
    float unk24c;   /* 0x24c */
    float unk250;   /* 0x250 */
};

/* 0x330-byte object created from a record id. */
class PropObj {
public:
    char pad0[0x3c];
    char flag3c;    /* 0x3c */
    char flag3d;    /* 0x3d */
    char pad1[0x301 - 0x3e];
    char flag301;   /* 0x301 */
    char pad2[0x330 - 0x302];
    void SetFlags() { flag3c = 1; flag3d = 1; flag301 = 1; }
};

/* Growable pointer vectors; the grow path is an out-of-line helper (push_back is defined in each source). */
struct AreaObjVec {
    AreaObj **data;
    unsigned size;
    unsigned capacity;
    void push_back(AreaObj *const &x);
};

struct PropObjVec {
    PropObj **data;
    unsigned size;
    unsigned capacity;
    void push_back(PropObj *const &x);
};

/* One entry of the record table: the arguments the prop object is set up with. */
struct PropRecord {
    int id;         /* 0x00 object id */
    int unk4;       /* 0x04 */
    int unk8;       /* 0x08 */
    int unkc;       /* 0x0c */
    float unk10;    /* 0x10 */
    float unk14;    /* 0x14 */
    int unk18;      /* 0x18 */
    int unk1c;      /* 0x1c */
    int flagged;    /* 0x20 flag the prop object after setup */
};

struct SpawnCourt {
    char pad0[0x1350];
    float unk1350;          /* 0x1350 copied into each area object */
    float unk1354;          /* 0x1354 */
    char pad1[0x1398 - 0x1358];
    PropObjVec props;       /* 0x1398 */
    AreaObjVec areas;       /* 0x13a4 */
    char pad2[0x13cc - 0x13b0];
    PropRecord *records;    /* 0x13cc */
    unsigned count;         /* 0x13d0 number of records */
};

#endif
