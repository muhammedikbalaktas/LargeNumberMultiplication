# LargeNumberMultiplication
 
In this article i will talk about the code that i write for multiplying large number without computer errors. As we know when someone try to multiply large number as two int value the computer crashes due to lack of bits. For that reason the purpose of project is providing the ability of multiplying lare numbers. 
I have four node in my program; big_one,small_one,result and final_result.
In the code i have eight functions including main functions and i used doubly linked list.

1-)void add_first(node** root,int number) ;
The first function adds a node at the beggining of linked list.

2-) void add(node** root,int number);
The second functions adds a node at the end of linked list.

3-)node* go_first_index(node** root);
The third functions returns the first index of a node which is taken as parameters.

4-)node* go_last_index(node** root);
The fourth functions works like third function. It returns the last node of linked list.

5-)void multiply_node_by_number(node** root,node **result,node** final_result,int multiplier);
The fifth functions makes the second part of multiplication. It takes three node pointer and one number for multiplying. It will be explained detaily below.

6-)void add_two_nodes(node ** node1,node** node2);
The sixth functions adds two nodes element by element. Each node number should be less then ten.

7-)void multiply_whole_node_numbers(node** big_one,node** small_one,node** result,node** final_result);
The seventh functions makes the first step of multiplication. It works with loop and multiplies all number of nodes. It will eplained detailly below.

8-)int main();
The main function does the file operations. The work flow of main function is like that; it creates two char array with size of 100. And take all char elements in file. The first char array takes the first number and second array takes the second number. Then all elements inside two array are getting parsed to two nodes.(big_one and small_one)

How it works
Before explaining how my code works i would like to explain the main idea of my algorithm.
When we multiply two integer bigger than 10 there is a formula that we can use in programming. For example lets consider 123*456. We can change the multiplication like (123*6)+(1230*5)+(12300*4). So my algorithm works same with this formula. 
At the first step of multiplication (in void multiply_whole_node_numbers function) it takes the first node as base node. Lets continue with 123*456 example. As it shown in figüre the functions works with a loop. It calls  (multiply_node_by_number) function each time and it adds one zero at the end of base node in order to apply formula. 
The (multiply node by number) function multiplies all node members with one element of second node with proper attributes. For example when result becomes bigger than 10 then it pass additional number to next element. (it called “elde” in Turkish). After multiplication it saves the multiplication to result node. And finally it adds the result node to final_result node each time using (add_two_nodes) function untill the second node finishes

![Screenshot from 2022-08-19 22-58-01](https://user-images.githubusercontent.com/93763631/185697912-a44a9289-5001-44b0-af32-a78a04e5febe.png)



