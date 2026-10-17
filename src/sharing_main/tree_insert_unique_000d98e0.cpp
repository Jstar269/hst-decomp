/* HSTMATCH module=hstp_trans_main.prx start=0x000d98e0 end=0x000d9998 symbol=FUN_000d98e0 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_000d5bf0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for string keys: find the insert position (0xd5d04 returns the parent and
   sets the last not-greater node j plus the left/leftmost flags), insert through 0xd7460 unless j's key
   equals k (string compare 0x430c), and return pair<iterator, bool>. The two bool values are read from
   writable byte globals (0x37d325 true, 0x37d326 false): declared `const`, MWCC hoists their loads above
   the node store. Locals declared in retail's frame order (flags at 47/46, j at 40). Names provisional. */
struct String_000d98e0 { int rep_[3]; };
extern "C" int FUN_0000430c(const String_000d98e0 *self, const String_000d98e0 &x); /* compare */
struct Node_000d98e0 {
    Node_000d98e0 *left_;
    Node_000d98e0 *right_;
    unsigned parent_;
    String_000d98e0 key_;
};
struct Tree_000d98e0;
struct Result_000d98e0 { Node_000d98e0 *node; bool inserted; };
extern "C" {
extern bool DAT_0037d325; /* true */
extern bool DAT_0037d326; /* false */
Node_000d98e0 *FUN_000d99f4(Tree_000d98e0 *t, const String_000d98e0 &k, Node_000d98e0 *&j, bool &left, bool &leftmost);
Node_000d98e0 *FUN_000db150(Tree_000d98e0 *t, Node_000d98e0 *parent, bool left, bool leftmost, const String_000d98e0 &k);
}
extern "C" void FUN_000d98e0(Result_000d98e0 *r, Tree_000d98e0 *t, const String_000d98e0 &k)
{
    bool left;
    bool leftmost;
    Node_000d98e0 *j;
    Node_000d98e0 *y = FUN_000d99f4(t, k, j, left, leftmost);
    if (j == 0 || FUN_0000430c(&j->key_, k) < 0) {
        r->node = FUN_000db150(t, y, left, leftmost, k);
        r->inserted = DAT_0037d325;
    } else {
        r->node = j;
        r->inserted = DAT_0037d326;
    }
}
