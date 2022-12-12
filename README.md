# BiliGraph
( ゜- ゜)つロ Cheers~

BiliGraph uses statistics on videos individually and jointly released by famous uploaders on Bilibili, then we analyze the effectiveness of jiontly-published videos.

### Leading Question 
We will collect statistics on videos individually and jointly released by famous uploaders on Bilibili(a video platform, Chinese version Youtube) through a third-party API, such as the number of views, uploading time, and number of coins, and output the dataset in the form of csv files. We will use the BFS algorithm to traverse the graph, then use Kruskal's Algorithm to find Minimum Spanning Tree, from which we will analyze the effectiveness of the videos jointly uploaded by Bilibili's Uploaders (specifically, we can see pairs of uploaders whose joint videos have the worst effect). We will also use Betweeness centrality to look for who is the most/least socially active author.

The rules of Bilibili: Each video on Bilibili has a coin function in addition to likes. Every user who has watched the video can choose to support the video with 0-2 coins. We will introduce a variable to analyze the attractiveness of the joint contribution video to the audience (we may use the ratio of the number of coins to the number of views).

## Build
Run the Docker, and clone our project. 

To build with Makefile, type
  ```
  make exec
  ```
  or
  ```
  make test
  ```
 Then type 
 ```
 cd bin
 ```
 ```
 .exec
 ``` 
 or
 ```
 .test
 ```
To put desired data into our project, modify `entry/main.cpp`, replace `../data/authorData.csv` with new authorData and `../data/test.csv` with new video data in 
```
buildGraph out("../data/authorData.csv", "../data/test.csv");
```


## Project Structure
1. `bin` folder contains executable files after the user runs ```make test   or   make exec``` 
2. `data` folder contains all the datasets we use for this project and Python scripts for data acquisition.
3. `entry` folder contains the `main.cpp` file
4. `lib` folder contains libraies we use for CMake
5. `src` folder contains main `.h` and `.cpp` files
6. `tests` folder contains all the test cases for our functions.


## References:
1.Mikolov, T. et al. (2013) Efficient estimation of word representations in vector space, arXiv.org. Available at: https://arxiv.org/abs/1301.3781 (Accessed: December 6, 2022). 

2.Devlin, J. et al. (2018) Bert: Pre-training of deep bidirectional Transformers for language understanding, ACL Anthology. Available at: https://aclanthology.org/N19-1423/ (Accessed: December 6, 2022). 

3.Shen, J. et al. (2019) Setexpan: Corpus-based set expansion via context feature selection and Rank Ensemble, SpringerLink. Springer International Publishing. Available at: https://link.springer.com/chapter/10.1007/978-3-319-71249-9_18 (Accessed: December 6, 2022). 
