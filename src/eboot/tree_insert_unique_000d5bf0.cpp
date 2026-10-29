/* HSTMATCH module=EBOOT.BIN start=0x000d5bf0 end=0x000d5ca8 symbol=FUN_000d5bf0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for string keys: find the insert position (0xd5d04 returns the parent and
   sets the last not-greater node j plus the left/leftmost flags), insert through 0xd7460 unless j's key
   equals k (string compare 0x430c), and return pair<iterator, bool>. The two bool values are read from
   writable byte globals (0x2d6835 true, 0x2d6836 false): declared `const`, MWCC hoists their loads above
   the node store. Locals declared in retail's frame order (flags at 47/46, j at 40). Names provisional. */
/* String object (three words). */
struct String { int rep_[3]; };
extern "C" int FUN_0000430c(const String *self, const String &x); /* compare */
struct StrNode {
    StrNode *left_;
    StrNode *right_;
    unsigned parent_;
    String key_;
};
struct StrTree;
struct InsertResult { StrNode *node; bool inserted; };
extern "C" {
extern bool DAT_002d6835; /* true */
extern bool DAT_002d6836; /* false */
StrNode *FUN_000d5d04(StrTree *t, const String &k, StrNode *&j, bool &left, bool &leftmost);
StrNode *FUN_000d7460(StrTree *t, StrNode *parent, bool left, bool leftmost, const String &k);
}
/* Insert-unique: inserts k unless an equal key exists; r receives the node and whether it was inserted. */
extern "C" void FUN_000d5bf0(InsertResult *r, StrTree *t, const String &k)
{
    bool left;
    bool leftmost;
    StrNode *j;
    StrNode *parent = FUN_000d5d04(t, k, j, left, leftmost);
    if (j == 0 || FUN_0000430c(&j->key_, k) < 0) {
        r->node = FUN_000d7460(t, parent, left, leftmost, k);
        r->inserted = DAT_002d6835;
    } else {
        r->node = j;
        r->inserted = DAT_002d6836;
    }
}
