

#include "graph.h"
using namespace std;           //Use the code from the class files
namespace main_savitch_15 {

  template <class Item>
  void graph<Item>::add_vertex(const Item& label) {
    std::size_t new_vertex_number;
    std::size_t other_number;
    assert(size( ) < MAXIMUM);
    new_vertex_number = many_vertices;
    many_vertices++;
    for (other_number = 0; other_number < many_vertices; ++other_number) {
      edges[other_number][new_vertex_number] = false;
      edges[new_vertex_number][other_number] = false;
    }
    labels[new_vertex_number] = label;
  }

  template <class Item>
  void graph<Item>::add_edge(std::size_t source, std::size_t target) {
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = true;
  }

  template <class Item>
  void graph<Item>::remove_edge(std::size_t source, std::size_t target) {
    assert(source < size( ));
    assert(target < size( ));
    edges[source][target] = false;
  }

  template <class Item>
  Item& graph<Item>::operator [ ] (std::size_t vertex) {
    assert(vertex < size());
    return labels[vertex];
  }

  template <class Item>
  bool graph<Item>::is_edge(std::size_t source, std::size_t target) const {
    assert(source < size());
    assert(target < size());
    return edges[source][target];
  }

  template <class Item>
  std::set<std::size_t> graph<Item>::neighbors(std::size_t vertex) const {
    std::set<std::size_t> answer;
    assert(vertex < size( ));
    for(std::size_t i = 0; i < size( ); ++i) {
      if (edges[vertex][i]) {
        answer.insert(i);
      }
    }
    return answer;
  }

  template <class Item>
  Item graph<Item>::operator[ ] (std::size_t vertex) const {
    assert(vertex < size( ));
    return labels[vertex];
  }

  template <class Item>
  int graph<Item>::longestDis() {
    bool visit[many_vertices];
    int longest = -1;
    int d;
    for(std::size_t i = 0; i < many_vertices; i++){
      visit[i]=false;
    }
    for(std::size_t j = 0; j < many_vertices; j++){
        for(std::size_t k = 0; k < many_vertices; k++){
            d = dist(j,k,visit);
            if(d > longest) {
              longest = d;
            }
        }
    }
    return longest;
  }

  template <class Item>
  int graph<Item>::dist(std::size_t source, std::size_t target, bool visit[]) {
    std::set<std::size_t> hold = neighbors(source);
    int d;
    if(target == source){
      return 0;
    }
    for(auto i:hold){
        if(visit[i] == false){
            d = dist(i,target,visit);
            if(d != -1){
              return d+1;
            }
        }
    }
    for(auto j:hold){
        if(j == target) {
          return 1;
        }
        visit[j] = true;
    }
    return -1;
  }


}
