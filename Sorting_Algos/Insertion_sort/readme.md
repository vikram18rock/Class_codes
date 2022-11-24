# INSERTION SORT
consider sequence  ` 4, 1, 3, 2`<br>
 Assume that the first element is already a sorted sub array <br> ` 4 | 1, 3, 2`
 <br> Starting from the second element i.e 1, place the element into correct position in the *sorted subarray*
 <br>Take 1, compare it with 4, as it is less than 4 insert 1 before 4 <br> `1, 4 | 3, 2`
 <br>Now place 3 into it's position in the sorted sub array 
 - Compare 4, 3. _4 > 3_ so move left
 -  _1 < 3_ so the position for 3 is after 1
 -  move all the elements after 3 in sorted sub array by one place and add 3 after 1<br>`1, 3, 4 | 2`<br>
 
 Lastly place 2 in it's position in sorted subarray same as we did for 3
 <br>`1, 2, 3, 4`
 
You can see the psuedo code [here](/ins_sort_psuedo.txt)
