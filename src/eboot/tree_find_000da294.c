/* HSTMATCH module=EBOOT.BIN start=0x000da294 end=0x000da340 symbol=FUN_000da294 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: inline NodeLength helper for encoded-length selection. */

typedef struct EncodedString {
  unsigned int tag;
  unsigned int length;
  const unsigned char *data;
} EncodedString;

typedef struct TreeNode {
  struct TreeNode *left;
  struct TreeNode *right;
  unsigned int field_8;
  EncodedString key;
} TreeNode;

static inline unsigned int NodeLength(const EncodedString *value)
{
  if ((value->tag & 1) != 0) return value->length;
  return ((unsigned int)*(const unsigned char *)&value->tag << 24) >> 25;
}

extern int FUN_00003c74(const void *, int, unsigned int, const void *, unsigned int);

TreeNode * FUN_000da294(int unused, const unsigned char *key, TreeNode *current, TreeNode *result)
{
  TreeNode *best = result;
  if (current != 0) {
    do {
      const unsigned char *key_data;
      unsigned int key_length;
      unsigned int node_length;
      if ((*(const unsigned int *)key & 1) == 0) {
        key_data = key + 1;
        key_length = ((unsigned int)*key << 24) >> 25;
      } else {
        key_data = *(const unsigned char * const *)(key + 8);
        key_length = *(const unsigned int *)(key + 4);
      }
      node_length = NodeLength(&current->key);
      if (FUN_00003c74(&current->key, 0, node_length, key_data, key_length) >= 0) {
        best = current;
        current = current->left;
      } else {
        current = current->right;
      }
    } while (current != 0);
  }
  return best;
}
