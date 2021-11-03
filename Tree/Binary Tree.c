#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
};

void createNode(int x) {
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root->key = x;
    root->left = NULL;
    root->right = NULL;
}

struct node *insertNode(struct node *root, int x) {
    if (root == NULL) {
        createNode(x);
        return root;
    }
    else {
        if (x > root->key) {
            return insertNode(root->right, x);
        }
        else {
            return insertNode(root->left, x);
        }
    }
}

struct node *searchNode(struct node *root, int x) {
    if (root == NULL) {
        printf("\n****NOT FOUND****");
    }
    if (root->key == x) {
        printf("\n****FOUND****");
        return root;
    }
    else {
        if (root->key < x) {
            return searchNode(root->right, x);
        }
        else{
            return searchNode(root->left, x);
        }
    }
}

struct node *largestNode(struct node *root) {
    if ((root == NULL)||(root->right == NULL)) {
        return root;
    }
    else {
        return largestNode(root->right);
    }
}

struct node *smallestNode(struct node *root) {
    if ((root == NULL)||(root->left == NULL)) {
        return root;
    }
    else {
        return smallestNode(root->left);
    }
}

int totalNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return (totalNodes(root->left) + totalNodes(root->right) + 1);
    }
}

int Height(struct node *root) {
    int leftH, rightH;
    if (root == NULL) {
        return 0;
    }
    else {
        leftH = Height(root->left);
        rightH = Height(root->right);
        if (leftH < rightH) {
            return (rightH + 1);
        }
        else {
            return (leftH + 1);
        }
    }
}

int leafNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    else if ((root->left == NULL)&&(root->right == NULL)) {
            return 1;
    }
        else {
            return (leafNodes(root->left) + leafNodes(root->right));
        }
}

struct node *deleteNode(struct node *root, int x) {
    if (root == NULL) {
        return root;
    }
        if (x > root->key) {
            return deleteNode(root->right, x);
        }
        else if (x < root->key) {
            return deleteNode(root->left, x);
        }
            else {
                if (root-> left == NULL) {
                    struct node *temp = root->right;
                    free(root);
                    return temp;
                }
                else if (root->right == NULL) {
                    struct node *temp = root->left;
                    free(root);
                    return temp;
                }
                struct node *temp = largestNode(root->left);
                root->key = temp->key;
                root->left = deleteNode(root->left, temp->key);
            }
    return root;
}

struct node *mirrorImage(struct node *root) {
    struct node *ptr;
    if (root != NULL) {
        mirrorImage(root->left);
        mirrorImage(root->right);
        ptr = root->left;
        root->left = root->right;
        root->right = ptr;
        return ptr;
    }
 
}

void preorder(struct node *root) {
   if (root != NULL) {
        printf("%d -> ", root->key);
        preorder(root->left);
        preorder(root->right);  
   }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ", root->key);  
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->key);
        inorder(root->right);  
    }
}

struct node *deleteTree(struct node *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
        return root;
    }
}


int main() {
    struct node *root = NULL;
    int choice, data, choiceDelete;
    while (1) {
        printf("\n****1.INSERT\n2.DELETE\n3.SEARCH\n4.HEIGHT\n5.INORDER\n6.PREORDER\n7.POSTORDER\n8.NUMBER OF NODES\n9.NUMBER OF LEAF NODES\n10.FIND MIN/MAX\n11.MIRROR IMAGE\n12.DELETE ENTIRE TREE");
        printf("\n****ENTER YOUR CHOICE****");
        scanf("%d", &choice);
        switch(choice) {
        case 1:printf("\nEnter the data you want to add");
               scanf("%d", &data); 
               insertNode(root, data);
               break;
        case 2:printf("\nEnter the node you want to delete");
               scanf("%d", &data);
               deleteNode(root, data);
               break;
        case 3:printf("\nEnter the node you want to search");
               scanf("%d", &data);
               searchNode(root, data);
               break;
        case 4:printf("\nThe Height of BST is");
               Height(root);
               break;
        case 5:printf("\nInorder Traversal is");
               inorder(root);
               break;             
        case 6:printf("\nPreorder Traversal is");
               preorder(root);
               break;
        case 7:printf("\nPostorder Traversal is");
               postorder(root);
               break;
        case 8:printf("\nCounting the number of nodes");
               totalNodes(root);
               break;
        case 9:printf("\nNumber of Leaf nodes");
               leafNodes(root);
               break;
        case 10:printf("\nDisplaying min/max node");
                largestNode(root);
                printf("\n");
                smallestNode(root);
                break;
        case 11:printf("\nShowing mirror image");
                mirrorImage(root);
                break;
        case 12:printf("\nAre you sure??\nEnter 1 for yes");
                scanf("%d", &choiceDelete);
                if (choiceDelete == 1) {
                    deleteTree(root);
                }
                break;
        case 13:printf("\nExiting .....");
                exit(0);
        }
    }  
    return 0;
}