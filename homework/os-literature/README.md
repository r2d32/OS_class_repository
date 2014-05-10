# All of Time and Space

Continue our journey through seminal operating systems literature by using library resources (digital or otherwise) to find at least three additional publications (also digital or otherwise) that are related to and/or build upon the work given out in class. For each found publication:

* State its connection to the other work in our small collection—the connection must be explicit (i.e., cited). Connections may be to the other work that you find, but at least one must point to something given out in class.
* State what it does new or differently from the prior cited works.
* Give a brief assessment of the quality of the work. Consider the authors, the publication venue, the level of detail, references cited, etc.

You are not expected to fully understand every thing in every piece that you find, but should have some kind of idea.
Commit and push this mini-annotated bibliography in any widely-readable format to `homework/os-literature`. Provide full citations for your found work. If you can supply full-text copies of these items, that would be great also.



##Article 1: Limitations of Dijkstra's Semaphore Primitives and Petri nets states 
ACM SIGOPS Operating Systems Review</br>
<br>Volume 7 Issue 4, October 1973 </br>
<br>S. Rao Kosaraju	</br>
<br>Pages 122 - 126</br>

*Connection to Previous Work*
***
This is related to our collection because Kosaraju talks about Djikstra's concurrent programming control limitations. The author also goes over a possible approach that improves that provided by Djikstra.

*Difference from Previous Work*
***
The article explains how the semaphores with the primitives P and V are not sufficiently powerful to handle some synchronization cases. Kosaraju makes reference to Petri's synchronization problem named *Cigarette Smokers' Problem* to pinpoint the limitations of Dijkstra's Semaphore Primitives when using a small number of variables. Finally, Kosaraju provides a solution involving the use of an array of semaphores which is limited on the number of total semaphores that it can take. This approach allows for the resolution of a wider variety of synchronization cases, but it still has its limitations.  

*Quality*
***
Kosaraju has over 70 articles published up on ACM's Digital Library with an average download per article of 325, which depicts his dedication to the academic study of computer science. Judging from the articles I visited previous to arriving at this paper, I can say that Kosaraju's writing is concise and descriptive. He uses a good amount of examples to explain his points while still keeping it to an amount that is not excessive. 

##Article 2: A simple solution to Lamport's concurrent programming problem with linear wait 
ICS '88 Proceedings of the 2nd international conference on Supercomputing</br>
<br>ACM New York, NY, USA ©1988 </br>
<br>B. K. Szymanski	</br>
<br>Pages 621 - 626</br>

*Connection to Previous Work*
***
Szymanski article relates to our source by Lamport, since it makes mention of the three conditions that must be satisfied under Lamport theory. It also uses *A New Solution to Lamport's Concurrent Programming Problem Using Small Shared Variables* by Gary Peterson, as a starting point to find a solution to include solving the read errors issues occurring during writes. There are similarities between the solutions posted in this article and Peterson's since it solves the problems of process failures and restarts.

*Difference from Previous Work*
***
The solution covered in this article uses five values of shared memory for each process, preventing shared memory by the user. The values in each process are stored in three 1-bit boolean variables for each process or can be stored within one variable. The solution considers the possibility of process failures and the various pitfalls that can occur with vlsi chip-based multiprocessors. Peterson's solution uses one fewer value for each process and also has a lower fairness property than the solution in this article. 

*Quality*
***
Szymanski has over 120 articles published up on ACM's Digital Library with an average download per article of 1,190.89, which depicts a remarkable dedication to the academic study of computer science. As mentioned previously, judging from the articles I visited before to arriving at this paper, I can evaluate Szymanski's writing as as a very clear and solidly rooted work. Szymanski references many important papers through the article, and he also provides an easy to understand argument that guides the reader through the understanding of every detail on it.
