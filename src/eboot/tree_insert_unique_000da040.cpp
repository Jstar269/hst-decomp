/* HSTMATCH module=EBOOT.BIN start=0x000da040 end=0x000da0f8 symbol=FUN_000da040 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_000d5bf0.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for string keys: find the insert position (0xd5d04 returns the parent and
   sets the last not-greater node j plus the left/leftmost flags), insert through 0xd7460 unless j's key
   equals k (string compare 0x430c), and return pair<iterator, bool>. The two bool values are read from
   writable byte globals (0x2d6acf true, 0x2d6ad0 false): declared `const`, MWCC hoists their loads above
   the node store. Locals declared in retail's frame order (flags at 47/46, j at 40). Names provisional. */
struct String_000da040 { int rep_[3]; };
extern "C" int FUN_0000430c(const String_000da040 *self, const String_000da040 &x); /* compare */
struct Node_000da040 {
    Node_000da040 *left_;
    Node_000da040 *right_;
    unsigned parent_;
    String_000da040 key_;
};
struct Tree_000da040;
struct Result_000da040 { Node_000da040 *node; bool inserted; };
extern "C" {
extern bool DAT_002d6acf; /* true */
extern bool DAT_002d6ad0; /* false */
Node_000da040 *FUN_000da19c(Tree_000da040 *t, const String_000da040 &k, Node_000da040 *&j, bool &left, bool &leftmost);
Node_000da040 *FUN_000da9dc(Tree_000da040 *t, Node_000da040 *parent, bool left, bool leftmost, const String_000da040 &k);
}
extern "C" void FUN_000da040(Result_000da040 *r, Tree_000da040 *t, const String_000da040 &k)
{
    bool left;
    bool leftmost;
    Node_000da040 *j;
    Node_000da040 *y = FUN_000da19c(t, k, j, left, leftmost);
    if (j == 0 || FUN_0000430c(&j->key_, k) < 0) {
        r->node = FUN_000da9dc(t, y, left, leftmost, k);
        r->inserted = DAT_002d6acf;
    } else {
        r->node = j;
        r->inserted = DAT_002d6ad0;
    }
}
