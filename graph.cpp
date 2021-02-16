//----------------------------------------------------------------------
// Name: Sami Blevens
// File: graph.cpp
// Date: Spring 2021
// Desc: A directed graph consists of vertices and edges. Each vertex
// has a unique identifier (from 0 to n-1) and each edge has a
// (non-unique) integer label.
//----------------------------------------------------------------------

#include "graph.h"
#include <iostream>
#include <queue>

void Graph::bfs(bool dir, int src, Map& tree) const {
   //mark all vertices as unexplored
   bool *explored = new bool[vertex_count()];
   for(int i=0; i< vertex_count(); ++i){
      explored[i] = false;
   }
   //mark vertex src as explored
   explored[src] = true;
   //set root
   tree[src] = -1;
   //queue init with src
   std::queue<int> q;
   q.push(src);

   while(!q.empty()){
      int u = q.front();
      q.pop();

      std::list<int> adj_v;
      //if directed , call connected_to
      //if undirected , call adjacent
      if(dir)
         connected_to(u,adj_v);
      else
         adjacent(u,adj_v);
      for(int v: adj_v){
         if(explored[v]==false){
            explored[v] = true;
            tree[v] = u;
            q.push(v);
         }
      }
   }
   delete [] explored;
}


void Graph::shortest_path_length(bool dir, int src, int dst, std::list<int>& path) const {
   Map search_tree;
   bfs(dir,src,search_tree);
   int parent = -1;
   int child = dst;
   path.push_front(dst);
   while(parent!=src){
      //if path does not connect/exist
      if(search_tree.count(child)==0){
         path.clear();
         return;
      }
      parent = search_tree[child];
      path.push_front(parent);
      child = parent;
   }
}

void Graph::bfs_connected_components(Map& components) const {
   bool *explored = new bool[vertex_count()];
   for(int i=0; i< vertex_count(); ++i){
      explored[i] = false;
   }
   Map search_tree;
   int c = 0;
   for(int i=0; i<vertex_count(); ++i){
      if(explored[i]==false){
         search_tree.clear();
         bfs(false,i,search_tree);
         for(std::pair<int,int> p: search_tree){
            explored[p.first] = true;
            components[p.first] = c;
         }
         ++c;
      }
   }

   delete [] explored;
}

bool Graph::bipartite_graph(Map& coloring) const {
   //1 = blue, 0 = green, -1 = not colored
   bool *explored = new bool[vertex_count()];
   for(int i=0; i< vertex_count(); ++i){
      explored[i] = false;
   }

   //queue init with src
   std::queue<int> q;

   for(int i=0; i<vertex_count(); ++i){
      if(explored[i]==false){
         //mark first vertex blue
         coloring[i] = 1;
         explored[i] = true;
         q.push(i);

         while(!q.empty()){
            int u = q.front();
            q.pop();

            std::list<int> adj_v;
            adjacent(u,adj_v);

            for(int v: adj_v){
               if(explored[v]==false){
                  //explored[v] = true;

                  if(coloring.count(v) == 0){
                     coloring[v] = (coloring[u] == 1) ? 0 : 1;
                  } else if(coloring[v] == coloring[u]){
                     return false;
                  }
                  
                  q.push(v);
               }
            }
            explored[u] = true;
         }
      }
   }

   delete [] explored;
   return true;
}
