#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int v;
    struct TreeNode* left;
    struct TreeNOde* right;
} TreeNode;

void pre_order(TreeNode* root) {
    if(!root) {
        return;
    }

    printf("%d, ", root->v);

    if(root->left) {
        pre_order(root->left);
    }

    if(root->right) {
        pre_order(root->right);
    }
}

void in_order(TreeNode* root) {
    if(!root) {
        return;
    }

    if(root->left) {
        in_order(root->left);
    }

    printf("%d, ", root->v);

    if(root->right) {
        in_order(root->right);
    }
}

void post_order(TreeNode* root) {
    if(!root) {
        return;
    }
    if(root->left) {
        post_order(root->left);
    }
    if(root->right) {
        post_order(root->right);
    }

    printf("%d ,", root->v);
}
// Binary Search Tree
TreeNode* insert(TreeNode* root, TreeNode* node) {
   if (!root) {
     return node;
   } else {
      TreeNode* p = root;
      while(1) {
        if (p->v >= node->v) {
           if (p->left) {
               p = p->left;
           } else {
               p->left = node;
           }
        } else {
           if (p->right) {
               p = p->right;
           } else {
              p->right = node;
           }
        }

      }
   return root;
   }
}

TreeNode* delete_node(TreeNode* root, int v) {
     return NULL;
}

int is_balance(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 1;
    }

    int min_depth = 0x7FFFFFFF;
    int max_depth = 0;

    recursive_check(root, 1, &min_depth, &max_depth);

    if (max_depth - min_depth > 1) {
        return 0;
    } else {
        return 1;
    }
}

void recursive_check(TreeNode* node, int depth, int* min_ptr, int* max_ptr) {
    if (!node->left && !node->right) {
        if (depth < *min_ptr) {
            *min_ptr = depth;
        }

        if (depth > *max_ptr) {
            *max_ptr = depth;
        }

        if (*max_ptr - *min_ptr > 1) {
            return;
        }
    } else {
       if (node->left) {
           recursive_check(node->left, depth + 1, min_ptr, max_ptr);
       }

       if (node->right) {
           recursive_check(node->right, depth + 1, min_ptr, max_ptr);
       }
    }
}

struct TreeNode{
    int v;
    struct TreeNode* Node;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* convert(int* nums, int head, int tail) {
    if(head > tail){
        return NULL;
    } else{
        int mid = (head + tail)/2;
        struct TreeNode* Node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        Node->v = nums[mid];
        Node->left = convert(nums, head, mid-1);
        Node->right = convert(nums, mid+1, tail);
        return Node;
    }
};
struct TreeNode* sortedArrayToBST(int*nums, int numsSize){
    return convert(nums,0,numsSize-1);
};
// try to implement this algorithm with non-recursive methods.


int main()
{
    TreeNode n00 = {.v = 5, .left = NULL, .right = NULL};
    TreeNode n10 = {.v = 3, .left = NULL, .right = NULL};
    TreeNode n11 = {.v = 6, .left = NULL, .right = NULL};
    TreeNode n20 = {.v = 1, .left = NULL, .right = NULL};

    n00.left = &n10;
    n00.right = &n11;
    n10.left = &n20;

    printf("Pre Order: \n");
    pre_order(&n00);

    printf("In order: \n");
    in_order(&n00);

    printf("Post order: \n");
    post_order(&n00);

    printf("Hello world!\n");

    printf("is_balanced: %d", is_balance(&n00));
    return 0;
}
