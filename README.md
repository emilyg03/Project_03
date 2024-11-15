CSCI 3333 Project Three
Finding  Shortest Word Ladders

Basic Part (100 points)
The Word Ladder Problem: 
In this homework assignment, I would like you to use some combination of graph, hash, list, stack, and queue data structures to solve the word ladder problem.
Given a start word and an end word, find a shortest sequence of words (shortest word ladder) from the start to the end so that 
Each word is a legal word from a given dictionary
The next word is obtained from the previous word by substituting exactly one letter. 
If there is no such sequence, then say so. 

Note: Assume all words are in lowercase. If they are not in  lower case, then convert to lower for processing. 

Efficiency requirements: 
The dictionary will be provided later for this problem. This dictionary has over a quarter of million words. Given this large size, the design and implementation of your program must consider the run time efficiency, that is, the practical running time complexity of your program. 
Under the usual computing environment, e.g., a typical laptop or a desktop, your program shall be able to complete the work in no more than 1 minute of running time. 
One additional consideration is the space complexity. If you are not careful in your design of algorithms and data structures, you might try to use an adjacency matrix to represent the “word transition” graph, which might be too big to fit into the main memory of your laptop or desktop.  
Hints: 
You may consider designing a list of hash maps, one for each set of words with the same length. 
You may consider which of the graph algorithms is best suited for your needs
Shortest path finding, such as Dijkstra’s algorithm
Breadth-first traversal
Depth-first traversal
You may also need to design data structures to record the paths for finding a word ladder. The question is:
Once a ladder is found, can you print it out easily?

Example: 
Given a start word zero and an end word five, here is the ladder: 
zero => hero => here => hire => fire => five 
We assume that all the words are legal.

The Dictionary: 
The dictionary is given here: The Dictionary for Word Ladders
(https://faculty.utrgv.edu/zhixiang.chen/cs3333/3333/dic/wordLadder_dictionary.txt)

The Shortest-Path Problem: 
Consider each word in the dictionary as a node. If one word is obtained from another word by substituting exactly one letter, then there is an edge connecting these two words. In this setting, the word ladder problem is equivalent to find a shortest path from one word (node) to another word (node). If there is no such a path, then say so. 
If you can build a graph as mentioned above for the words in the dictionary, then you can directly apply a shortest-path finding algorithm to solve the word ladder problem.
The Challenge: 
When the dictionary is large, like the one you are given, it is not easy to build a graph. It may take too long or too much space so that it becomes unrealistic to build a graph.
How to Overcome the Challenge for unweighted letters: 
Use the graph at conceptually level. During the solution process, there is no need to build the complete graph. Use some sort of breadth-first or depth-first search strategy to find the word ladder. Note: For any node representing a word, without accessing to a fully-built graph for the dictionary, you can find its adjacent nodes (or words you can obtained from it through substituting exactly one letter). Think about how to do so, how to do so as fast as you can. 
Cautions: 
The above suggestion works only for unweighted words.
Caution: DO NOT PRINT OUT THE DATA FILES!

Specific Execution Time Requirement: 

The loading time of your program shall not be more than three minutes and the execution time for each pair of two words shall not be more than two minutes (consider a typical laptop or a desktop). Otherwise, no credit will be given to your program.
Your program shall repeatedly ask the user to enter two words and then find the ladder for these two words or tell that no ladder exists. Each program will be tested by a fixed set of word pairs composed of 
fishery ---- compute     	(length = 23)
scroll ---- cloudy 		(length = 12)
scroll ---- sundae 		 (no ladder)
computers ---- beautiful 	(no ladder)
gimlets ---- theeing 		(length = 21)

Optional Part for possible extra credits: The Weighted Word Ladder Problem

Now we consider a weighted version of the Word Ladder Problem. A weight table is given below: 

Note that this table is symmetric with respect to diagonal line. The plain text file of the above cost matrix is available at the Blackboard.  

For example, the graph below shows edge weights as determined by the table 


Figure 1. A weighted graph of letters
 
Your need to re-do Basic Part with the weight word graphs as determined by the weight table. For a pair of the start word and the end word, this time you have to find the shorted weighted ladder from the start to the end. Specific execution time requirements from the unweighted word ladder problem apply to the weighted word ladder problem, and the same test word pairs will be used. 

Efficiency requirements: 
Under the usual computing environment, e.g., a typical laptop or a desktop, your program shall be able to complete the work in no more than 1 minute of running time. 

