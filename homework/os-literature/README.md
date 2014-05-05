# All of Time and Space

Continue our journey through seminal operating systems literature by using library resources (digital or otherwise) to find at least three additional publications (also digital or otherwise) that are related to and/or build upon the work given out in class. For each found publication:

* State its connection to the other work in our small collection—the connection must be explicit (i.e., cited). Connections may be to the other work that you find, but at least one must point to something given out in class.
* State what it does new or differently from the prior cited works.
* Give a brief assessment of the quality of the work. Consider the authors, the publication venue, the level of detail, references cited, etc.

You are not expected to fully understand every thing in every piece that you find, but should have some kind of idea.
Commit and push this mini-annotated bibliography in any widely-readable format to `homework/os-literature`. Provide full citations for your found work. If you can supply full-text copies of these items, that would be great also.



##Article 1: 

###Limitations of Dijkstra's Semaphore Primitives and Petri nets states 
<br>ACM SIGOPS Operating Systems Review</br>
<br>Volume 7 Issue 4, October 1973 </br>
<br>S. Rao Kosaraju	</br>
<br>Pages 122 - 126</br>

*Connection to Previous Work*
***
This is related to our small collection because Kosaraju talks about Djikstra's concurrent programming control limitations. The author also goes over a possible approach that improves that provided by Djikstra.

*Difference from Previous Work*
***
The article explains how the semaphores with the primitives P and V are not sufficiently powerful to handle some synchronization cases. Kosaraju makes reference to Petri's synchronization problem named *Cigarette Smokers' Problem* to pinpoint the limitations of Dijkstra's Semaphore Primitives when using a small number of variables. Finally, Kosaraju provides a solution involving the use of an array of semaphores which is limited on the number of total semaphores that it can take. This approach allows for the resolution of a wider variety of synchronization cases, but it still has its limitations.  

*Quality*
***
Kosaraju has over 70 articles published up on ACM's Digital Library with an average download per article of 325, which depicts his dedication to the academic study of science. Judging from the articles I visited previous to arriving at this paper, I can say that Kosaraju's writing is concise and descriptive. He uses a good amount of examples to explain his points while still keeping it to an amount that is not excessive. 
