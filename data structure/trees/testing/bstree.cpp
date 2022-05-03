#include "../bstree.hpp"

int main() {
    BSTree* tree = new BSTree();
    for (int i = 0; i < 4; i++) {
        tree->insert(i);
    }
    for (int i = 0; i < 4; i++) {
        tree->insert(i);
    }
    tree->bfs();
    cout << endl;
    tree->remove(1);
    tree->remove(1);
    tree->bfs();
    cout << endl;
    tree->dfs();
    cout << endl;
    tree->remove(2);
    tree->sortedPrinting();
    cout << endl;
    cout << tree->min() << endl;
    cout << tree->max() << endl;
    cout << tree->sum() << endl;
    cout << tree->search(2)->_data << endl;
    return 0;
}