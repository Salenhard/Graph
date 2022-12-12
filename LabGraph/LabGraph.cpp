#include <iostream>
#include "Graph.h"
#include "VertexIterator.h"
#include "SeqListIterator.h"
template <class T>
int PathConnect(Graph<T>& G, T v, T w) {
    SeqList<T> L;

    L = G.DepthFirstSerch(v);
    if (L.Find(w))
        return 1;
    else
        return 0;
}

template <class T>
void PrintList(SeqList<T> list) {
    SeqListIterator<T> liter;
    for (liter.Reset(); !liter.EndOfList(); liter.Next()) {
        cout << liter.Data();
    }
}

template <class T>
void ConnectedComponent(Graph<T>& G) {
    VertexIterator  <T> viter(G);
    SeqList<T> markedLsit, scList, L, R;
    for (viter.Reset(); !viter.EndOfList(); viter.Next()) {
        if (!markedLsit.Find(viter.Data())) {
            scList.ClearList();
            L = G.DepthFirstSerch(viter.Data());
            SeqListIterator<T> liter(L);
            for(liter.Reset();!liter.EndOfList(); liter.Next())
                if (PathConnect(G, liter.Data(), viter.Data())) {
                    scList.Insert(liter.Data());
                    markedLsit.Insert(liter.Data());
                }
            PrintList(scList);
            cout << endl;
        }
    }
}

int main()
{
    Graph<char> G;
    G.ReadGraph("sctest.dat");
    cout << "Сильные компоненты:" << endl;
    ConnectedComponent(G);
}
