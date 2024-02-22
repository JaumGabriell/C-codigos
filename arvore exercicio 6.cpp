#include <iostream>
#include <string>
#include <map>

using namespace std;

// estrutura de um nó da árvore binária
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// função que constrói uma árvore binária a partir dos percursos prefixo e infixo
TreeNode* buildTree(string preorder, string inorder, int& index, int start, int end, map<char, int>& inorder_map) {
    if (start > end) {
        return NULL;
    }

    char current = preorder[index++];
    TreeNode* node = new TreeNode(current);

    if (start == end) {
        return node;
    }

    int i = inorder_map[current];

    node->left = buildTree(preorder, inorder, index, start, i - 1, inorder_map);
    node->right = buildTree(preorder, inorder, index, i + 1, end, inorder_map);

    return node;
}

// função que percorre a árvore em pós-ordem
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}

int main() {
    int c;
    cin >> c;

    while (c--) {
        int n;
        string preorder, inorder;
        cin >> n >> preorder >> inorder;

        map<char, int> inorder_map;

        // mapeia a posição de cada nó no percurso infixo
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }

        int index = 0;
        TreeNode* root = buildTree(preorder, inorder, index, 0, n - 1, inorder_map);

        postorderTraversal(root);
        cout << endl;

        // libera a memória alocada para a árvore
        delete root;
    }

    return 0;
}
