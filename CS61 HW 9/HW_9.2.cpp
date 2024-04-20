#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>

// I had a very basic idea on how to accomplish this task. The person I peer viewed
// helped guided me on how to do it fully. I wish I was as busy with studying for so many finals
// that I could have arrived to this point without guidence.

using namespace std;

class graph {
public:

    graph() {
        v = vector<list<size_t> >();
    }

    size_t vertices() const {
        return v.size();
    }

    size_t edges() const
    {
        size_t ans(0);
        for (auto i : v)
            ans += i.size();

        return ans / 2;
    }

    void add_vertex()
    {
        v.push_back(list<size_t>());
    }

    void add_edge(size_t a, size_t b) {
        assert(a < vertices() && b < vertices());
        if (!is_edge(a, b)) {
            v[a].push_front(b);
            v[b].push_front(a);
        }
    }

    void remove_vertex(size_t a);

    void remove_edge(size_t a, size_t b) {
        assert(a < vertices() && b < vertices());
        if (is_edge(a, b)) {
            v[a].remove(b);
            v[b].remove(a);
        }
    }

    bool is_edge(size_t a, size_t b) const {
        if (a >= vertices() || b >= vertices()) {
            return false;
        }

        for (auto i : v[a]) {
          if (i == b) {
              return true;
          }
        }
        return false;
    }

    list<size_t> neighbors(size_t source) const {
        assert(source < vertices());
        return v[source];
    }

    size_t nc() {
        vector<int> parent(vertices(), -1);
        size_t connections(0);
        size_t dia(0);
        size_t w;

        for (size_t i = 0; i < vertices(); ++i) {
            if (parent[i] == -1) {
                bfs1(i, parent);
                ++connections;
                if (diameter(i) > dia) {
                    w = i;
                    dia = diameter(i);
                }
            }
        }
        cout << "diameter = " << dia << " at " << w << endl;
        return connections;
    }

    bool is_connected() {
        return (nc() == 1);
    }

    bool is_complete() const {
        for (auto i : v)
            if (i.size() != vertices() - 1)
                return false;

        return true;
    }

    size_t diameter(size_t start) {
        queue<size_t> q;
        vector<int> d(vertices(), -1);
        q.push(start);
        d[start] = 0;
        size_t x;
        while (!q.empty()) {
            x = q.front();
            q.pop();
            for (auto i : v[x])
                if (d[i] == -1)
                {
                    d[i] = d[x] + 1;
                    q.push(i);

                }
        }
        cout << "diameter starting at " << x;
        size_t y = x;
        q.push(x);
        d = vector<int>(vertices(), -1);
        d[x] = 0;
        while (!q.empty())
        {
            x = q.front();
            q.pop();
            for (auto j : v[x])
                if (d[j] == -1)
                {
                    d[j] = d[x] + 1;
                    q.push(j);
                }
        }
        cout << "  ending at " << x << ": " << d[x] << endl;

        for (auto k : shortest_path(y, x)) {
          cout << k << " ";
        }
        cout << "  len = " << d[x] << endl;
        return d[x];
    }

    vector<int> shortest_path(size_t start, size_t dest) {
        vector<int> parent(vertices(), -1);
        bfs1(start, parent);
        if (parent[dest] == -1) {
          return vector<int>();
        }
        vector<int> ans;
        for (int v = dest; v != start; v = parent[v]) {
            ans.push_back(v);
        }
        ans.push_back(start);
        return ans;
    }


private:

    void bfs1(size_t start, vector<int>& parent) {
        queue<size_t> q;
        parent[start] = start;
        q.push(start);
        while (!q.empty())
        {
            size_t x = q.front();
            q.pop();
            for (auto i : v[x])
                if (parent[i] == -1)
                {
                    parent[i] = x;
                    q.push(i);
                }
        }
    }

    std::vector<std::list<std::size_t> > v;

};


ostream& operator <<(ostream& os, const graph& g) {
    os << g.vertices() << " " << g.edges() << endl;
    for (size_t i = 0; i < g.vertices(); ++i) {
        std::list<std::size_t> n = g.neighbors(i);
        for (auto j : n)
            if (j > i)
                os << i << " " << j << endl;
    }
    return os;
}

istream& operator >>(istream& is, graph& g) {
    size_t n;
    size_t m;
    size_t a;
    size_t b;
    is >> n >> m;
    g = graph();
    for (size_t i = 0; i < n; ++i) {
        g.add_vertex();
    }

    for (size_t j = 0; j < m; ++j) {
        is >> a >> b;
        g.add_edge(a, b);
    }
    return is;
}

class doublelet {
public:
    doublelet() {}
    void makeWords() {
        ifstream file;
        file.open("knuth.txt");
        string temp;
        while (file >> temp) {
            connections.add_vertex();
            words.push_back(temp);
        }
        file.close();
        string temp1;
        string temp2;
        for (int i = 0; i < words.size(); i++) {
            temp1 = words[i];
            for (int j = i; j < words.size(); j++) {
                temp2 = words[j];
                int match = 0;
                for (int ind = 0; ind < 5; ind++) {
                    if (temp1[ind] == temp2[ind])match++;
                }
               if (match == 4) {
                 connections.add_edge(i, j);
               }
            }
        }
    }

    void solve(const string& origin, const string& target) {
        size_t first;
        size_t last;
        vector<int> answer;
        for (first = 0; first < words.size(); first++) {
            if (words[first] == origin) break;
        }
        for (last = 0; last < words.size(); last++) {
            if (words[last] == target) break;
        }
        answer = connections.shortest_path(last, first);
        cout << origin << " -> " << target << endl;
        if (answer.size() == 0) { cout << "No Path" << endl; return; }
        for (int i = 0; i < answer.size(); ++i) {
            cout << words[answer[i]]<< " ";
        }
        cout << endl;
    }


private:
    graph connections;
    vector<string> words;
};

int main() {
    doublelet test;
    test.makeWords();
    test.solve("black", "white");
    test.solve("tears", "smile");
    test.solve("small", "giant");
    test.solve("stone", "money");
    test.solve("angel", "devil");
    test.solve("amino", "right");
    test.solve("amigo", "signs");
    return 0;
}
