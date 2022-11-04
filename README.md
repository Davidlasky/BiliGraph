# BiliGraph

( ゜- ゜)つロ Cheers~

## Project Proposal

### Leading Question 
We will collect statistics on videos individually and jointly released by famous uploaders  on Bilibili(a video platform, Chinese version Youtube) through a third-party API, such as the number of views, uploading time, and number of coins, and output the dataset in the form of csv files. We will use the BFS algorithm to traverse the graph, then use Kruskal's Algorithm to find Minimum Spanning Tree, from which we will analyze the effectiveness of the videos jointly uploaded by Bilibili's Uploaders (specifically, we can see pairs of uploaders whose joint videos have the worst effect). We will also use Graphic output of a graph to visualize our graph(not exactly what to use yet, but we may use Bresenham algorithm).


The rules of Bilibili: Each video on Bilibili has a coin function in addition to likes. Every user who has watched the video can choose to support the video with 0-2 coins. We will introduce a variable to analyze the attractiveness of the joint contribution video to the audience (we may use the ratio of the number of coins to the number of views).

### Dataset Acquisition

#### Data Format
We will utilize api from https://github.com/Nemo2011/bilibili-api to acquire data we need. We plan on acquire data from the top 100 BiliBili uploaders (which is a subset).

There will be two csv files, one stores data pertains to the author, the other stores data regarding the videos.The format will be as follows:

Author: 
1. UID
2. Number of followers 
3. List of videos 

Videos:
1. Author list
2. BVID
3. Number of play
4. Number of likes
5. Number of coins


#### Data Correction
We will limit and use weighted average to process data based on the time of release for each video.

The data will be briefly examined using Excel. Empty entry should only occur if the code is wrong, since every video has to have all the entries we need.

However, if there is such circumstances of missing entries and/or not physically possible values (e.g: no such uploader), we will correct our data using python, since we deal with the API on python.


#### Data Storage
We will convert the data from the CSV files into vectors of strings so they can be put into the graph structure with uploaders as vertices and their effectiveness(of jointly uploading videos) as edges. We will also have functions to calculate the effectiveness.

We will use adjacency list to store our graph. We will treat it as an undirected weighted graph.
Space complexity: O(V+E) where V is the information of uploaders and E is the effectiveness between uploaders. In the worst case, our adjacency list implementation will be O(V^2) when every node is connected to all other nodes.




### Graph Algorithm 

We decide to use BFS + Minimum Spanning Tree (Kruskal Algorithm) + Graphic output of a graph(not exactly sure what to use yet, but we may use Bresenham algorithm).

#### Function Inputs:

For the graph building algorithm, the input would be string data of uploaders and relationships (this can be acquired by reading from the csv files). We may also need maps to store UIDs to authors. 

As mentioned above, we would calculate the "effectiveness" based on number of plays, likes, and coins, as well as multiple videos from one author in other functions, so we won't include them as the input here. We will have helper functions that take in them as input, as well as maps between them.

For BFS, MST algorithm and graphic visualization algorithm, we will just input our graph we create in previous functions. But we may also need helper functions (such as union find) where we may need other parameters such as vectors and maps.



#### Function Outputs:
For BFS traversal, it will traverse through the whole graph and we need a graph iterator.

For the Kruskal Algorithm, it will return a minimum spanning tree, which has the "minimum effectiveness" (the minimum possible total edge weight) routes to every other node from a specific node. Kruskal Algorithm will be used to accomplish this result.  

For Graphic output of a graph, it will output an PNG represent the effect of join uploading. 

#### Function Efficiency:

For our graph, the time complexity of BFS is O(V + E) and space complexity is O(V). 

The time complexity of Kruskal's Algorithm is O(E*logE) and space complexity is O(V + E). 

The time complexity of Bresenham algorithm is O(x2 – x1) and space complexity is O(1), but the visualization algorithm we use may subject to change.



### Timeline
11/4-11/11 Preliminary Coding(creating files, read in csv, calculate required parameters for main functions), Data Aquisition finished in most cases, Data analysing started.

11/11-11/18 Data Aquisition finished, Graph building and BFS code drafted.

11/18-12/2 Graph building finished, BFS finished. MST and graphic output start.

12/2-12/9 MST analyzed, graph output finished. Final presentation.


## Team Contract

### Communication
1. **Team Meetings** 

    Once a week on Sunday evening. Each meeting last for 2 hours(And will check out everyone's progress in the middle of the week).
    
    We will meet in person. If there is a special case, we will meet on zoom.
    
    Sally Xue will take notes.
    
2. **Assistance** 

    We will contact through instant message app. We will respond in 5-10 minutes from 10am - 11:59pm every day.

3. **Respect** 

    Every group member will take turns to host the meeting. Also, we encourage group members to ask questions so their opinions and ideas can be heard.

### Collaboration

4. **Work Distribution** 

    Group Collaboration: 

        API & generating csv file: Xuanpu Zhang
    
        C++ algorithms and coding: Sally Xue, Tianyue Yin, Xicheng Jiang, Xuanpu Zhang
    
        Data processing and analysis(python, subject to change): Sally Xue, Xicheng Jiang
    
        Presentation: Tianyue Yin
    
    
    
    How will you address unexpected complications or unforeseen work? 

        We will contact our mentor, and add group meetings if necessary.
    
    

5. **Time Commitment** 

    10-15 hours/week.
    
    We will meet together and discuss (and meet with mentor). We will commit extra hours if necessary.

6. **Conflict Resolution** 

    How will the team resolve situations where there is a disagreement between members?

        We can vote on different opinions and ideas.
    
    Situations where one or more members have not accomplished their tasks?

        We will check everyone's progress at the middle of the week (every Tuesday).

    Situations where one or more members are habitually late? 

        The person who is late everytime will buy every other members a boba tea!! :p
    
    Other hypothetical situation: if someone catch COVID, we will instead meet on zoom


### Signatures

    Xuanpu Zhang
    
    Sally Xue
    
    Tianyue Yin
    
    Xicheng Jiang
