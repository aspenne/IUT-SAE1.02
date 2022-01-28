# SAE1.02

## Contributors :
- Eliott GUILLOSSOU
  - https://github.com/eliottguls
- Axel MICHELO
  - https://github.com/aspenne

## Context : 
We have national data on the number of Covid cases by age group and
by department of Brittany. <br>In order to facilitate research or provide
synthetic results, it can be very useful to sort this dataset on
different way. <br>For this you will implement several solutions and you will
compare.

## General presentation of the project
The purpose of this SAE is to compare the performance of different sort algorithms
of tables.<br>
We need to program 3 sort algorithms. First one is insert sorting, second one the comb sort and last one, the quick sort. <br>
These programs will have to modifed depending of data's types we want to sort. Here integers but also with a text file.

## Steps explanation 
### Step 1 : 
For each algorithm we will need to code them in C. Our sorting algorithms will sort integers crescently and decrescently. <br>
In order to have a first approach with algorithm complexity, we will have to test them through an average table, <br>
a sorted table end a decrescent integer table. These tables are fullfilled of 10 integers.

### Step 2 :
This step makes us changing scale and will makes ud adapt our algorithms in order to use them to sort table os 500 000 integers.<br> 
We will have to to the same tests as in the first step(decrescent table, crescent table...)

### Step 3 :
Now we have worked with tables of integers we will transform them in order to sort strings tables.<br>
More specifically, tables of 150 000 strings. And as always, test our programs like previous steps.

### Step 4 :
Now we have done multiple algorithms, we will compare their efficiency.<br> 
In order to do this correctly we will count the time requested, number of comparisons and permutations for each algorithm.<br>
These tests will have to be done with integers tables. <br>
In order to make these test and have correct results, we will do the average of multiple tests in each configuration of our table that we will sort<br>
All our results we be presented in a table for each case. We will have to deal with the strings sorting alogorithms too to make the same tests.

### Step 5 :
Now it's time to use real datas. The main idea of this step is to copy some Covid datas in a tables which we will be able to sort depending diferent criterias.<br> That's why we will have to declare and use a table of structures entitled "covid".


## Dates to deliver our works depending on the previous steps :
|When|What|Where|
|:---:|:---:|:---:|
|8th Decmeber|Source code of our programs from step 1 <br> traces of our algorithms before and after sorting our table |On Moodle|
|15th December|Source code of our programs from step 2|On Moodle|
|22th December|Source code of our programs from step 3|On Moodle|
|9th January|Source code of our programs from step 4|On Moodle|
|16th January|Source code of our programs from step 5|On Moodle|
|17th January|Noted practical work| Iut Lannion |.
