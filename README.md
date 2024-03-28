# Greedy algorithm 2023/2024

## Group members:
- David García Guirado
- Jorge García Marín
- Antonio Tendero Beltrán

## Description of the problem:
The goal with this algorythm is to maximize the money received from GREEDY Co.
As all items, regardless of its weight, are paid the same amount (40 €), this will be done including the items whose weight is smaller first, that is, we will order this items with increasing weight.



## Description of the key elements:

Candidates: Carried objects.

Ordering: Increasing weight. 

Feasibility: If the total weight included in the lorry plus the weight of the candidate item is lower or equal than the capacity of the lorry, then we increment the total weight adding the weight of the included candidate, and update the total price of the lorry objects adding 40. If this condition isn´t fulfilled, then we have reached the ending condition of our algorithm.

Selection:* Selection is not required, since we won´t require an extra ordination.

Ending condition: If the total weight included in the lorry plus the weight of the candidate item is greater than the remaining capacity, then the algorithm finishes.

## Pseudocode:

Candidates: Object[]{price=40;weight}.

Ordering: Increasing weight (by means of merge sort); totalPrice=0; totalWeight=0;capacity=10;i=0;

Feasibility: if(totalWeight+weight(i)<=capacity){
                totalWeight+=weight(i); 
                i++;totalPrice+=40;
                } 
              else end;

Selection:* Selection is not required, since we won´t require an extra ordination;

Ending condition: else

## Computational cost:
As we know, the computational cost of a greedy algorithm is the one that comes from the sorting algorithm. In our case, we used merge sort, which means that in the average case the computational cost of our algorithm will be nlog(n).

