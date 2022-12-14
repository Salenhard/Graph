#include <iostream>
#include "Graph.h"
#include "VertexIterator.h"
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
void PrintList(SeqList<T> &list) {
    SeqListIterator<T> liter(list);
    for (liter.Reset(); !liter.EndOfList(); liter.Next()) {
        cout << liter.Data() << " ";
    }
}

template <class T>
void ConnectedComponent(Graph<T>& G) {
    VertexIterator<T> viter(G);
    SeqList<T> markedList, scList, L, R;
    for (viter.Reset(); !viter.EndOfList(); viter.Next()) {
        if (!markedList.Find(viter.Data())) {
            scList.ClearList();
            L = G.DepthFirstSerch(viter.Data());
            SeqListIterator<T> liter(L);
            for(liter.Reset(); !liter.EndOfList(); liter.Next())
                if (PathConnect(G, liter.Data(), viter.Data())) {
                    scList.Insert(liter.Data());
                    markedList.Insert(liter.Data());
                }
            PrintList(scList);
            cout << endl;
        }
    }
    
}

int main()
{
    setlocale(0, "ru");
    Graph<const char*> G;
    G.InsertVertex("Chita");
    G.InsertVertex("Moscow");
    G.InsertVertex("Ekb");
    G.InsertVertex("Sol");
    G.InsertEdge("Chita", "Moscow", 100);
    G.InsertEdge("Chita", "Ekb", 300);
    G.InsertEdge("Moscow", "Ekb", 50);
    G.InsertEdge("Moscow", "Sol", 10);
    G.InsertEdge("Ekb", "Sol", 30);
    cout << "Сильные компоненты:" << endl;
    ConnectedComponent(G);
}
