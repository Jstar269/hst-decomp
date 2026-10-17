/* HSTMATCH module=EBOOT.BIN start=0x00229a54 end=0x00229ab0 symbol=__dt__13Tree_00229a54Fv lang=c++ */
/* Clone of src/eboot/tree_dtor_000d5ca8.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Map/tree container destructor (MWCC deleting-destructor form: this + short flag; delete when flag > 0):
   tear down the node tree from the root at +4 through the out-of-line recursive destroy 0xd71a8. Names provisional. */
struct Node_00229a54;
struct Tree_00229a54 {
    int header;
    Node_00229a54 *root;
    ~Tree_00229a54();
};
extern "C" void FUN_00229d98(Tree_00229a54 *t, Node_00229a54 *x);
Tree_00229a54::~Tree_00229a54()
{
    if (root)
        FUN_00229d98(this, root);
}
