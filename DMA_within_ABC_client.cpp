#include "DMA_within_ABC.cpp"

const int ITEMS_COUNT = 3;

int main() {
    ABCGeneral *items[ITEMS_COUNT];
    char kind;
    string strtemp1, strtemp2;
    int sztemp, rtg;
    lacksDMA baloon("no color", "no label", 0);
    hasDMA map("no style", "no label", 0);
    for (int i = 0; i < ITEMS_COUNT; ++i) {
        cout << "Enter 1 for Shirt or 2 for Baloon or 3 for Map: "s;
        while (cin >> kind && (kind != '1' && kind != '2' && kind != '3')) {
            cout << "Enter either 1 or 2 or 3: "s << endl;
        }
        if (kind == '1') {
            cout << "Enter label for shirt:"s << endl;
            const char *lbltemp = readInput(strtemp1);
            cout << "Enter rating for shirt:"s << endl;
            cin >> rtg;
            cout << "Enter size for a shirt (1, 2, 3):"s << endl;
            cin >> sztemp;
            items[i] = new firstDerived(lbltemp, rtg, sztemp);
        } else if (kind == '2') {
            cout << "Enter label for baloon:"s << endl;
            const char *lbltemp = readInput(strtemp1);
            cout << "Enter rating for baloon:"s << endl;
            cin >> rtg;
            cout << "Enter baloon color: "s << endl;
            const char *coltemp = readInput(strtemp2);
            items[i] = new lacksDMA(coltemp, lbltemp, rtg);
        } else {
            cout << "Enter publisher for map:"s << endl;
            const char *lbltemp = readInput(strtemp1);
            cout << "Enter rating for map:"s << endl;
            cin >> rtg;
            cout << "Enter style for a map:"s << endl;
            const char *stltemp = readInput(strtemp2);
            items[i] = new hasDMA(stltemp, lbltemp, rtg);
        }

        while (cin.get() != '\n') {continue; }
    }

    for (int i = 0; i < ITEMS_COUNT; ++i) {
        items[i]->View();
    }

    lacksDMA baloon2(baloon);
    cout << "\nCopy constructor for 'no' lacksDMA:"s << endl;
    baloon2.View();
    hasDMA map2;
    map2 = map;
    cout << "\nResult of hasDMA assignment to 'no':\n";
    map2.View();

    for (int i = 0; i < ITEMS_COUNT; ++i) {
        delete items[i]; // free memory
    }
    cout << "Done.\n";
    return 0;
}
