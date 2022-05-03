#include "../tree.hpp"

int main() {
    Tree* tree = new Tree();
    for (int i = 0; i < 26; i++) {
        tree->insert(i);
    }
    tree->bfs();
    cout << endl;
    tree->dfs();
    cout << endl;
    cout << "min := " << tree->min() << endl;
    cout << "max := " << tree->max() << endl;
    cout << "sum := " << tree->sum() << endl;
    return 0;
}