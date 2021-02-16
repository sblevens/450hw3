//----------------------------------------------------------------------
// Name: 
// File: hw3_tests.cpp
// Date: Spring 2021
// Desc: Unit tests for HW-3 BFS-related algorithms
//----------------------------------------------------------------------


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "graph.h"
#include "adjacency_list.h"
#include "adjacency_matrix.h"


using namespace std;


//----------------------------------------------------------------------
// Helper functions for testing
//----------------------------------------------------------------------

void print_search_tree(Map search_tree)
{
  for (pair<int,int> p : search_tree)
    cout << "parent: " << p.second << ", child: " << p.first << endl;
}

void print_path(list<int> path)
{
  for (int v : path)
    cout << v << " ";
  cout << endl;
}


//----------------------------------------------------------------------
// Adjacency List Tests
//----------------------------------------------------------------------


// Basic BFS test over a directed graph
TEST(AdjacencyListTest, BasicDirectedBFS) {
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 2);
  g.set_edge(2, -1, 3);
  g.set_edge(1, -1, 0);
  Map search_tree;
  // bfs from 0
  g.bfs(true, 0, search_tree);
  ASSERT_EQ(4, search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  ASSERT_EQ(0, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
  // bfs from 1
  search_tree.clear();
  g.bfs(true, 1, search_tree);
  ASSERT_EQ(4, search_tree.size());
  ASSERT_EQ(-1, search_tree[1]);
  ASSERT_EQ(1, search_tree[0]);
  ASSERT_EQ(0, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
}

// TODO: at least two additional directed graph BFS tests
TEST(AdjacencyListTest, DirectedBFSNoAdjacent){
  AdjacencyList g(5);
  g.set_edge(0, -1, 1);
  g.set_edge(3, -1, 4);
  Map search_tree;
  //bfs from 0
  g.bfs(true,0,search_tree);
  ASSERT_EQ(2,search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  search_tree.clear();
  //bfs from 2
  g.bfs(true,2,search_tree);
  ASSERT_EQ(1,search_tree.size());
  ASSERT_EQ(-1,search_tree[2]);
}

TEST(AdjacencyListTest, DirectedBFSLargeGraph){
  AdjacencyList g(30);
  for(int i = 0; i< 28; ++i){
    g.set_edge(i,-1,i+1);
    g.set_edge(i,-1,i+2);
  }
  Map search_tree;
  g.bfs(true,0,search_tree);
  ASSERT_EQ(30,search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  ASSERT_EQ(0, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
  ASSERT_EQ(2, search_tree[4]);
  ASSERT_EQ(4, search_tree[5]);
  ASSERT_EQ(4, search_tree[6]);
  ASSERT_EQ(6, search_tree[7]);
  ASSERT_EQ(6, search_tree[8]);
  ASSERT_EQ(8, search_tree[9]);
  ASSERT_EQ(8, search_tree[10]);
  ASSERT_EQ(10, search_tree[11]);
  ASSERT_EQ(10, search_tree[12]);
  ASSERT_EQ(12, search_tree[13]);
  ASSERT_EQ(12, search_tree[14]);
  ASSERT_EQ(14, search_tree[15]);
  ASSERT_EQ(14, search_tree[16]);
  ASSERT_EQ(16, search_tree[17]);
  ASSERT_EQ(16, search_tree[18]);
  ASSERT_EQ(18, search_tree[19]);
  ASSERT_EQ(18, search_tree[20]);
  ASSERT_EQ(20, search_tree[21]);
  ASSERT_EQ(20, search_tree[22]);
  ASSERT_EQ(22, search_tree[23]);
  ASSERT_EQ(22, search_tree[24]);
  ASSERT_EQ(24, search_tree[25]);
  ASSERT_EQ(24, search_tree[26]);
  ASSERT_EQ(26, search_tree[27]);
  ASSERT_EQ(26, search_tree[28]);
  ASSERT_EQ(27, search_tree[29]);
}


// TODO: undirected graph BFS test
TEST(AdjacencyListTest, BasicUndirectedBFS) {
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 2);
  g.set_edge(2, -1, 3);
  g.set_edge(1, -1, 2);
  Map search_tree;
  // bfs from 0
  g.bfs(false, 0, search_tree);
  ASSERT_EQ(4, search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  ASSERT_EQ(0, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
  // bfs from 1
  search_tree.clear();
  g.bfs(false, 1, search_tree);
  ASSERT_EQ(4, search_tree.size());
  ASSERT_EQ(-1, search_tree[1]);
  ASSERT_EQ(1, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
  ASSERT_EQ(1, search_tree[0]);
}

// TODO: at least two additional undirected graph BFS tests
TEST(AdjacencyListTest, UndirectedBFSNoAdjacent){
  AdjacencyList g(5);
  g.set_edge(0, -1, 1);
  g.set_edge(3, -1, 4);
  Map search_tree;
  //bfs from 0
  g.bfs(false,0,search_tree);
  ASSERT_EQ(2,search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  search_tree.clear();
  //bfs from 2
  g.bfs(false,2,search_tree);
  ASSERT_EQ(1,search_tree.size());
  ASSERT_EQ(-1,search_tree[2]);
}

TEST(AdjacencyListTest, UndirectedBFSLargeGraph){
  AdjacencyList g(30);
  for(int i = 0; i< 28; ++i){
    g.set_edge(i,-1,i+1);
    g.set_edge(i,-1,i+2);
  }
  Map search_tree;
  g.bfs(false,0,search_tree);
  ASSERT_EQ(30,search_tree.size());
  ASSERT_EQ(-1, search_tree[0]);
  ASSERT_EQ(0, search_tree[1]);
  ASSERT_EQ(0, search_tree[2]);
  ASSERT_EQ(2, search_tree[3]);
  ASSERT_EQ(2, search_tree[4]);
  ASSERT_EQ(4, search_tree[5]);
  ASSERT_EQ(4, search_tree[6]);
  ASSERT_EQ(6, search_tree[7]);
  ASSERT_EQ(6, search_tree[8]);
  ASSERT_EQ(8, search_tree[9]);
  ASSERT_EQ(8, search_tree[10]);
  ASSERT_EQ(10, search_tree[11]);
  ASSERT_EQ(10, search_tree[12]);
  ASSERT_EQ(12, search_tree[13]);
  ASSERT_EQ(12, search_tree[14]);
  ASSERT_EQ(14, search_tree[15]);
  ASSERT_EQ(14, search_tree[16]);
  ASSERT_EQ(16, search_tree[17]);
  ASSERT_EQ(16, search_tree[18]);
  ASSERT_EQ(18, search_tree[19]);
  ASSERT_EQ(18, search_tree[20]);
  ASSERT_EQ(20, search_tree[21]);
  ASSERT_EQ(20, search_tree[22]);
  ASSERT_EQ(22, search_tree[23]);
  ASSERT_EQ(22, search_tree[24]);
  ASSERT_EQ(24, search_tree[25]);
  ASSERT_EQ(24, search_tree[26]);
  ASSERT_EQ(26, search_tree[27]);
  ASSERT_EQ(26, search_tree[28]);
  ASSERT_EQ(27, search_tree[29]);
}


// Basic shortest-path test over a directed graph
TEST(AdjacencyListTest, BasicDirectedShortestPath) {
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 2);
  g.set_edge(2, -1, 3);
  g.set_edge(1, -1, 0);
  list<int> path;
  // check 0 -> 1
  g.shortest_path_length(true, 0, 1, path);
  ASSERT_EQ(2, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(1, path.front());
  path.clear();
  // check 0 -> 2
  g.shortest_path_length(true, 0, 2, path);
  ASSERT_EQ(2, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.clear();
  // check 0 -> 3
  g.shortest_path_length(true, 0, 3, path);
  ASSERT_EQ(3, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(3, path.front());
  path.clear();
  // check 1 -> 3
  g.shortest_path_length(true, 1, 3, path);
  ASSERT_EQ(4, path.size());
  ASSERT_EQ(1, path.front());
  path.pop_front();
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(3, path.front());
  path.clear();
}

// TODO: at least two additional shortest-path tests over a directed
// graph
TEST(AdjacencyListTest, DirectedShortestPathNoPath){
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 3);
  g.set_edge(1, -1, 3);
  list<int> path;
  g.shortest_path_length(true,0,2,path);
  ASSERT_EQ(0,path.size());
}

TEST(AdjacencyListTest, DirectedShortestPathLargeGraph){
  AdjacencyList g(30);
  for(int i = 0; i< 28; ++i){
    g.set_edge(i,-1,i+1);
    g.set_edge(i,-1,i+2);
  }
  list<int> path;
  //check 1 to 29
  g.shortest_path_length(true,2,29,path);
  ASSERT_EQ(15,path.size());
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(4, path.front());
  path.pop_front();
  ASSERT_EQ(6, path.front());
  path.pop_front();
  ASSERT_EQ(8, path.front());
  path.pop_front();
  ASSERT_EQ(10, path.front());
  path.pop_front();
  ASSERT_EQ(12, path.front());
  path.pop_front();
  ASSERT_EQ(14, path.front());
  path.pop_front();
  ASSERT_EQ(16, path.front());
  path.pop_front();
  ASSERT_EQ(18, path.front());
  path.pop_front();
  ASSERT_EQ(20, path.front());
  path.pop_front();
  ASSERT_EQ(22, path.front());
  path.pop_front();
  ASSERT_EQ(24, path.front());
  path.pop_front();
  ASSERT_EQ(26, path.front());
  path.pop_front();
  ASSERT_EQ(27, path.front());
  path.pop_front();
  ASSERT_EQ(29, path.front());
  path.pop_front();
}


// TODO: shortest path test over an undirected graph
TEST(AdjacencyListTest, BasicUndirectedShortestPath) {
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 2);
  g.set_edge(2, -1, 3);
  g.set_edge(1, -1, 2);
  list<int> path;
  // check 0 -> 1
  g.shortest_path_length(false, 0, 1, path);
  ASSERT_EQ(2, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(1, path.front());
  path.clear();
  // check 0 -> 2
  g.shortest_path_length(false, 0, 2, path);
  ASSERT_EQ(2, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.clear();
  // check 0 -> 3
  g.shortest_path_length(false, 0, 3, path);
  ASSERT_EQ(3, path.size());
  ASSERT_EQ(0, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(3, path.front());
  path.clear();
  // check 1 -> 3
  g.shortest_path_length(false, 1, 3, path);
  ASSERT_EQ(3, path.size());
  ASSERT_EQ(1, path.front());
  path.pop_front();
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(3, path.front());
  path.clear();
}

// TODO: at least two additional shortest-path tests over undirected
// graphs
TEST(AdjacencyListTest, UndirectedShortestPathNoPath){
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(0, -1, 3);
  g.set_edge(1, -1, 3);
  list<int> path;
  g.shortest_path_length(false,0,2,path);
  ASSERT_EQ(0,path.size());
}

TEST(AdjacencyListTest, UndirectedShortestPathLargeGraph){
  AdjacencyList g(30);
  for(int i = 0; i< 28; ++i){
    g.set_edge(i,-1,i+1);
    g.set_edge(i,-1,i+2);
  }
  list<int> path;
  //check 1 to 29
  g.shortest_path_length(false,2,29,path);
  ASSERT_EQ(15,path.size());
  ASSERT_EQ(2, path.front());
  path.pop_front();
  ASSERT_EQ(4, path.front());
  path.pop_front();
  ASSERT_EQ(6, path.front());
  path.pop_front();
  ASSERT_EQ(8, path.front());
  path.pop_front();
  ASSERT_EQ(10, path.front());
  path.pop_front();
  ASSERT_EQ(12, path.front());
  path.pop_front();
  ASSERT_EQ(14, path.front());
  path.pop_front();
  ASSERT_EQ(16, path.front());
  path.pop_front();
  ASSERT_EQ(18, path.front());
  path.pop_front();
  ASSERT_EQ(20, path.front());
  path.pop_front();
  ASSERT_EQ(22, path.front());
  path.pop_front();
  ASSERT_EQ(24, path.front());
  path.pop_front();
  ASSERT_EQ(26, path.front());
  path.pop_front();
  ASSERT_EQ(27, path.front());
  path.pop_front();
  ASSERT_EQ(29, path.front());
  path.pop_front();
}


// Basic BFS-based connected components test 
TEST(AdjacencyListTest, BasicBFSConnectedComponents) {
  AdjacencyList g(6);
  g.set_edge(0, -1, 1);
  g.set_edge(1, -1, 2);
  g.set_edge(2, -1, 0);
  g.set_edge(3, -1, 4);
  g.set_edge(4, -1, 3);
  g.set_edge(5, -1, 3);
  Map components;
  g.bfs_connected_components(components);
  ASSERT_EQ(6, components.size());
  int c1 = components[0];
  ASSERT_EQ(c1, components[1]);
  ASSERT_EQ(c1, components[2]);
  int c2 = components[3];
  ASSERT_EQ(c2, components[4]);
  ASSERT_EQ(c2, components[5]);
  ASSERT_NE(c1, c2);
}

// TODO: at least two additional BFS-based connected components tests
TEST(AdjacencyListTest, VComponentsBFSConnectedComponents){
  AdjacencyList g(4);
  Map components;
  g.bfs_connected_components(components);
  ASSERT_EQ(4,components.size());
  int c1 = components[0];
  int c2 = components[1];
  ASSERT_NE(c1,c2);
  int c3 = components[2];
  int c4 = components[3];
  ASSERT_NE(c3,c4);
  ASSERT_NE(c1,c4);
}

TEST(AdjacencyListTest, OneComponentBFSConnectedComponents){
  AdjacencyList g(4);
  g.set_edge(0, -1, 1);
  g.set_edge(1, -1, 2);
  g.set_edge(2, -1, 3);
  g.set_edge(3, -1, 0);
  Map components;
  g.bfs_connected_components(components);
  ASSERT_EQ(4, components.size());
  int c1 = components[0];
  ASSERT_EQ(c1,components[1]);
  ASSERT_EQ(c1,components[2]);
  ASSERT_EQ(c1, components[3]);
}


// Basic Bipartite graph tests
TEST(AdjacencyListTest, BasicBipartiteGraph) {
  // two node graph
  AdjacencyList g1(2);
  g1.set_edge(0, -1, 1);
  g1.set_edge(1, -1, 0);
  Map coloring;
  ASSERT_EQ(true, g1.bipartite_graph(coloring));
  ASSERT_EQ(2, coloring.size());
  ASSERT_NE(coloring[0], coloring[1]);
  coloring.clear();
  // 3-node graph w/ 2-coloring
  AdjacencyList g2(3);
  g2.set_edge(0, -1, 1);
  g2.set_edge(0, -1, 2);
  ASSERT_EQ(true, g2.bipartite_graph(coloring));
  ASSERT_EQ(3, coloring.size());
  ASSERT_NE(coloring[0], coloring[1]);
  ASSERT_NE(coloring[0], coloring[2]);
  coloring.clear();
  // 3-node graph w/ 2-coloring
  AdjacencyList g3(3);
  g3.set_edge(0, -1, 1);
  g3.set_edge(1, -1, 2);
  ASSERT_EQ(true, g3.bipartite_graph(coloring));
  ASSERT_EQ(3, coloring.size());
  ASSERT_NE(coloring[0], coloring[1]);
  ASSERT_NE(coloring[1], coloring[2]);
  coloring.clear();
  // 3-node graph w/out 2-coloring
  AdjacencyList g4(3);
  g4.set_edge(0, -1, 1);
  g4.set_edge(0, -1, 2);
  g4.set_edge(1, -1, 2);
  ASSERT_EQ(false, g4.bipartite_graph(coloring));
  coloring.clear();
  // 4-node graph w/ 2-coloring
  AdjacencyList g5(4);
  g5.set_edge(0, -1, 1);
  g5.set_edge(1, -1, 3);
  g5.set_edge(3, -1, 2);
  g5.set_edge(2, -1, 0);
  ASSERT_EQ(true, g5.bipartite_graph(coloring));
  ASSERT_NE(coloring[0], coloring[1]);
  ASSERT_NE(coloring[0], coloring[2]);
  ASSERT_EQ(coloring[0], coloring[3]);
}


// bipartite graph test for disconnected graph
TEST(AdjacencyListTest, DisconnectedBipartiteGraph) {
  // two node graph
  AdjacencyList g(7);
  g.set_edge(0, -1, 1);
  g.set_edge(1, -1, 3);
  g.set_edge(3, -1, 2);
  g.set_edge(2, -1, 0);
  g.set_edge(4, -1, 5);
  g.set_edge(4, -1, 6);
  Map coloring;
  ASSERT_EQ(true, g.bipartite_graph(coloring));
  ASSERT_EQ(7, coloring.size());
  ASSERT_NE(coloring[0], coloring[1]);
  ASSERT_NE(coloring[1], coloring[3]);  
  ASSERT_NE(coloring[3], coloring[2]);  
  ASSERT_NE(coloring[2], coloring[0]);  
  ASSERT_NE(coloring[4], coloring[5]);  
  ASSERT_NE(coloring[4], coloring[6]);  
}

// TODO: at least one additional bipartite graph tests
TEST(AdjacencyListTest, DisconnectedFalseBipartiteGraph) {
  // two node graph
  AdjacencyList g(7);
  g.set_edge(0, -1, 1);
  g.set_edge(1, -1, 3);
  g.set_edge(3, -1, 2);
  g.set_edge(2, -1, 0);

  g.set_edge(4, -1, 5);
  g.set_edge(4, -1, 6);
  g.set_edge(5, -1, 6);

  Map coloring;
  ASSERT_EQ(false, g.bipartite_graph(coloring));
}


int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

