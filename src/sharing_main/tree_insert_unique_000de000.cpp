/* HSTMATCH module=hstp_trans_main.prx start=0x000de000 end=0x000de0b8 symbol=FUN_000de000 lang=c++ */
/* Clone of src/eboot/tree_insert_unique_000d5bf0.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style tree insert_unique for string keys: find the insert position (0xd5d04 returns the parent and
   sets the last not-greater node j plus the left/leftmost flags), insert through 0xd7460 unless j's key
   equals k (string compare 0x430c), and return pair<iterator, bool>. The two bool values are read from
   writable byte globals (0x37d704 true, 0x37d705 false): declared `const`, MWCC hoists their loads above
   the node store. Locals declared in retail's frame order (flags at 47/46, j at 40). Names provisional. */
struct String_000de000 { int rep_[3]; };
extern "C" int FUN_0000430c(const String_000de000 *self, const String_000de000 &x); /* compare */
struct Node_000de000 {
    Node_000de000 *left_;
    Node_000de000 *right_;
    unsigned parent_;
    String_000de000 key_;
};
struct Tree_000de000;
struct Result_000de000 { Node_000de000 *node; bool inserted; };
extern "C" {
extern bool DAT_0037d704; /* true */
extern bool DAT_0037d705; /* false */
Node_000de000 *FUN_000de15c(Tree_000de000 *t, const String_000de000 &k, Node_000de000 *&j, bool &left, bool &leftmost);
Node_000de000 *FUN_000de99c(Tree_000de000 *t, Node_000de000 *parent, bool left, bool leftmost, const String_000de000 &k);
}
extern "C" void FUN_000de000(Result_000de000 *r, Tree_000de000 *t, const String_000de000 &k)
{
    bool left;
    bool leftmost;
    Node_000de000 *j;
    Node_000de000 *y = FUN_000de15c(t, k, j, left, leftmost);
    if (j == 0 || FUN_0000430c(&j->key_, k) < 0) {
        r->node = FUN_000de99c(t, y, left, leftmost, k);
        r->inserted = DAT_0037d704;
    } else {
        r->node = j;
        r->inserted = DAT_0037d705;
    }
}
