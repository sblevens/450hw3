//----------------------------------------------------------------------
// NAME: Sami Blevens
// FILE: adjacency_list.cpp
// DATE: Spring 2021
// DESC: Adjacency list implementation of the graph interface
//----------------------------------------------------------------------

#ifndef ADJACENCY_LIST_CPP
#define ADJACENCY_LIST_CPP

#include "adjacency_list.h"
#include <iostream>

AdjacencyList::AdjacencyList(int vertex_count){
   number_of_vertices = vertex_count;
   number_of_edges = 0;
   adj_list_out = new Node*[number_of_vertices];
   adj_list_in = new Node*[number_of_vertices];

   for(int i=0; i<number_of_vertices; ++i){
      adj_list_out[i] = nullptr;
      adj_list_in[i] = nullptr;
   }
}

AdjacencyList::AdjacencyList(const AdjacencyList& rhs){
   number_of_vertices = 0;
   number_of_edges = 0;
   adj_list_in = nullptr;
   adj_list_out = nullptr;

   *this = rhs;
}

AdjacencyList::~AdjacencyList(){
   make_empty();
}

void AdjacencyList::make_empty() {
   //hashtable make empty
   Node* cur; 
   Node* prev;
   for(int i=0; i<number_of_vertices; ++i){
      //adj in
      if(adj_list_in[i]){
         //delete entire linked list at this array index
         prev = adj_list_in[i];
         while(prev->next){
            cur = prev->next;
            delete prev;
            prev = cur;
         }
         delete prev;
      }
      if(adj_list_out[i]){
         prev = adj_list_out[i];
         while(prev->next){
            cur = prev->next;
            delete prev;
            prev = cur;
         }
         delete prev;
      }
   }

   delete[] adj_list_out;
   delete[] adj_list_in;

   adj_list_out = nullptr;
   adj_list_in = nullptr;

   number_of_vertices = 0;
   number_of_edges = 0;
}

AdjacencyList& AdjacencyList::operator=(const AdjacencyList& rhs){
   if(this == &rhs){
      return *this;
   }

   make_empty();

   number_of_vertices = rhs.number_of_vertices;
   number_of_edges = rhs.number_of_edges;

   adj_list_in = new Node*[number_of_vertices];
   adj_list_out = new Node*[number_of_vertices];

   for(int i=0; i<number_of_vertices; ++i){
      adj_list_out[i] = nullptr;
      adj_list_in[i] = nullptr;
   }

   for(int i=0; i<number_of_vertices; ++i){
      Node* rhs_temp = rhs.adj_list_in[i];
      Node* lhs_temp = adj_list_in[i];
      if(rhs_temp){
         Node* temp = new Node;
         temp->edge = rhs_temp->edge;
         temp->vertex = rhs_temp->vertex;
         temp->next = nullptr;
         adj_list_in[i] = temp;
         lhs_temp = temp;
         rhs_temp = rhs_temp->next;
      }
      while(rhs_temp){
         Node* temp = new Node;
         temp->edge = rhs_temp->edge;
         temp->vertex = rhs_temp->vertex;
         temp->next = nullptr;
         lhs_temp->next = temp;
         lhs_temp = lhs_temp->next;
         rhs_temp = rhs_temp->next;
      }

      Node* rhs_temp_out = rhs.adj_list_out[i];
      Node* lhs_temp_out = adj_list_out[i];
      if(rhs_temp_out){
         Node* temp = new Node;
         temp->edge = rhs_temp_out->edge;
         temp->vertex = rhs_temp_out->vertex;
         temp->next = nullptr;
         adj_list_out[i] = temp;
         lhs_temp_out = temp;
         rhs_temp_out = rhs_temp_out->next;
      }
      while(rhs_temp_out){
         Node* temp = new Node;
         temp->edge = rhs_temp_out->edge;
         temp->vertex = rhs_temp_out->vertex;
         temp->next = nullptr;
         lhs_temp_out->next = temp;
         lhs_temp_out = lhs_temp_out->next;
         rhs_temp_out = rhs_temp_out->next;
      }
   }

   return *this;
}

void AdjacencyList::set_edge(int v1, int edge_label, int v2){
   //out edge v1 -> v2
   Node* temp = adj_list_out[v1];
   //if linked list exists / has edges out from v1
   bool found = false;
   while(temp && !found){
      //if edge exists
      if(temp->vertex == v2){
         //update label
         temp->edge = edge_label;
         found = true;
      } else {
         //if current edge is not correct
         temp = temp->next;
      }
   }
   if(!found){
      //edge did not exist -> create edge, add to beginning
   Node* out = new Node;
   out->edge = edge_label;
   out->vertex = v2;
   out->next = adj_list_out[v1];
   adj_list_out[v1] = out;
   }
   
   found = false;
   //in edge v2 <- v1
   temp = adj_list_in[v2];
   //if linked list exists / has edges in from  v1
   while(temp && !found){
      //if edge exists
      if(temp->vertex == v1){
         //update label
         temp->edge = edge_label;
         found = true;
      } else {
         //current edge is not v1->v2
         temp = temp->next;
      }
   }
   if(!found){
      //edge did not exist -> create edge, add to beginning
      Node* in = new Node;
      in->edge = edge_label;
      in->vertex = v1;
      in->next = adj_list_in[v2];
      adj_list_in[v2] = in;
   }

   if(!found){
      ++number_of_edges;
   }


}

bool AdjacencyList::has_edge(int v1, int v2) const{
   Node* temp = adj_list_out[v1];
   while(temp){
      if(temp->vertex == v2){
         return true;
      } else {
         temp = temp->next;
      }
   }
   return false;
}

bool AdjacencyList::get_edge(int v1, int v2, int& edge) const {
   Node* temp = adj_list_out[v1];
   while(temp){
      if(temp->vertex == v2){
         edge = temp->edge;
         return true;
      } else {
         temp = temp->next;
      }
   }
   return false;
}

void AdjacencyList::connected_to(int v1, std::list<int>& vertices) const {
   Node* temp = adj_list_out[v1];
   while(temp){
      vertices.push_back(temp->vertex);
      temp = temp->next;
   }
}

void AdjacencyList::connected_from(int v2, std::list<int>& vertices) const {
   Node* temp = adj_list_in[v2];
   while(temp){
      vertices.push_back(temp->vertex);
      temp = temp->next;
   }
}

//two liner
void AdjacencyList::adjacent(int v, std::list<int>& vertices) const {
   connected_from(v,vertices);
   connected_to(v, vertices);
}

int AdjacencyList::vertex_count() const {
  return number_of_vertices;
}

int AdjacencyList::edge_count() const {
  return number_of_edges;
}

#endif