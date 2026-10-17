/* HSTMATCH module=EBOOT.BIN start=0x000d5bf0 end=0x000d5ca8 symbol=FUN_000d5bf0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for string keys: find the insert position (0xd5d04 returns the parent and
   sets the last not-greater node j plus the left/leftmost flags), insert through 0xd7460 unless j's key
   equals k (string compare 0x430c), and return pair<iterator, bool>. The two bool values are read from
   writable byte globals (0x2d6835 true, 0x2d6836 false): declared `const`, MWCC hoists their loads above
   the node store. Locals declared in retail's frame order (flags at 47/46, j at 40). Names provisional. */
struct String_000d5bf0 { int rep_[3]; };
extern "C" int FUN_0000430c(const String_000d5bf0 *self, const String_000d5bf0 &x); /* compare */
struct Node_000d5bf0 {
    Node_000d5bf0 *left_;
    Node_000d5bf0 *right_;
    unsigned parent_;
    String_000d5bf0 key_;
};
struct Tree_000d5bf0;
struct Result_000d5bf0 { Node_000d5bf0 *node; bool inserted; };
extern "C" {
extern bool DAT_002d6835; /* true */
extern bool DAT_002d6836; /* false */
Node_000d5bf0 *FUN_000d5d04(Tree_000d5bf0 *t, const String_000d5bf0 &k, Node_000d5bf0 *&j, bool &left, bool &leftmost);
Node_000d5bf0 *FUN_000d7460(Tree_000d5bf0 *t, Node_000d5bf0 *parent, bool left, bool leftmost, const String_000d5bf0 &k);
}
extern "C" void FUN_000d5bf0(Result_000d5bf0 *r, Tree_000d5bf0 *t, const String_000d5bf0 &k)
{
    bool left;
    bool leftmost;
    Node_000d5bf0 *j;
    Node_000d5bf0 *y = FUN_000d5d04(t, k, j, left, leftmost);
    if (j == 0 || FUN_0000430c(&j->key_, k) < 0) {
        r->node = FUN_000d7460(t, y, left, leftmost, k);
        r->inserted = DAT_002d6835;
    } else {
        r->node = j;
        r->inserted = DAT_002d6836;
    }
}
