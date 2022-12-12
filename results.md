# Algorithm & Tests 

( ゜- ゜)つロ Cheers~

## BFS  
For BFS traversal, it will traverse through the whole graph. The function will generate a corresponding BFS traverse map for all starting nodes.
 

## MST(Kruskal) 
We use Kruskal to return a minimum spanning tree, which has the "minimum effectiveness" (the minimum possible total edge weight) routes to every other node from a specific node. We use disjoint sets to implement the algorithm. Our Kruskal helper function returns a vector that contains all edges to connect the MST.


## Betweenness Centrality 
We use it to look for who is the most/least socially active author.

## Test Cases 
For BFS, we manually split out smaller csv files. For uploaders in this sample, we know that all 47 uploaders are all connected, so they should be in the same graph. Therefore, we test whether the graph size is 47 after BFS traversal.

For MST, edges in our MST should have ascending weight (which is defined by the collaborated video that has best affect). Therefore, we check whether the weight of edges is increasing.

For Betweeness Centrality, we find out the uploader with the highest centrality. We do notice that he collaborate with people from other video sections (music, life, etc), which makes him the "hub".

# Conclusion 
Our project perfectly solves the leading qustion. We find out the most socially-active uploader and the worst video uploaders group. The dataset we use right now is a relatively small sample, which only includes the top 104 uploaders last yesar, and we also include features that can handle even more uploaders in a bigger scale.
