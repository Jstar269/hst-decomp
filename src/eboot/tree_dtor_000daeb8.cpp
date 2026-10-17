/* HSTMATCH module=EBOOT.BIN start=0x000daeb8 end=0x000daf14 symbol=__dt__13Tree_000daeb8Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_000daeb8;
struct Tree_000daeb8 {
    int header;
    Node_000daeb8 *root;
    ~Tree_000daeb8();
};
extern "C" void FUN_000daf14(Tree_000daeb8 *t, Node_000daeb8 *x);
Tree_000daeb8::~Tree_000daeb8()
{
    if (root)
        FUN_000daf14(this, root);
}
