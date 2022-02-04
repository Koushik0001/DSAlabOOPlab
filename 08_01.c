/*
2. At the beginning of the file, use block comments to write details about name,
roll no, assignment details, input required and output generated. Also put the
compilation [should be WARNINGS/Errors free] and execution sequence under
the block comment. [Check the comment file]
/*
Name :
Roll : 
Team No.

Name :
Roll : 
Team No.

Name :
Roll : 
Team No.

Name :
Roll : 
Team No.
*/
/*
Input Required : ./08_01 <L/F> <cache_size> <memory_reference1> <memory_reference2> <memory_reference3> ...
Output Generated :
                
LRU algorithm : This algorithm ensures that the most recently used memry block is always present 
                at the end of the queue and the least recently used memory block always remains at the begining
                of the queue.

Step 1: The main() method receives the cache size and memory block references through command line
Step 2: In the main() method an array is created for holding the memory block references
Step 3: The array and the total number of memory references are passed to the LRU() function
Step 4: LRU() function then calls is_hit() function with the reference as an argument 
Step 5: The is_hit function returns the pointer to the node where the memory block is present or returns
        NULL if the memory block is not present in the queue.
Step 6: If the node pointer returned by is_hit() is not NULL(Cache HIT) then the node is deleted using 
        delete_node() function and enqueued again to ensure that the node gets placed at the end of the 
        Queue and in case of the node being the front node of the queue, the dequeue() function is called 
        instead of the delete_node() function because deleting the front node and dequeing the queue is same.
Step 7: If the node pointer returned by is_hit() is NULL then simple enqueue operation is performed untill
        the queue is full. If the queue is full and again NULL pointer is returned then dequeue and enqueue
        operations are performed respectably to delete the least recently used memory block that is present
        at the begining of the queue and to place most recently used memry block at the end of the queue.
Step 8: Step 4 through Step 7 are repeated for all the memory references.
*/
#include <stdio.h>   
#include<stdlib.h>
int *cache;
int total_number_of_block_requests;
int count_misses=0, count_hits=0;
int size_cache, size_mainMemory, number_of_elements_in_cache = 0;
void replace(int current_memory_block,int old_memory_block);//old_memory_block will be replaced with current memory block
void put_in_cache(int memory_blok);//This will put a memory block in the cache
void get_from_main_memory(int number_of_references,int *array,char replacement_policy);//This will call the replacement algoritms
void display_cache();

float hit_ratio();
float miss_ratio();
struct node   
{  
    int data;   
    struct node *next;  
};
struct node *front;  
struct node *rear;  
void enqueue();  
int dequeue();  
void delete_node(struct node* ptr);
void display();  
  
void FIFO(int block_reference);
void LRU(int block_reference);
struct node* is_hit(int reference);//returns the node pointer if it is a hit, and returns NULL if it is a miss  

int main (int argc, char* argv[])  
{  
    size_cache = atoi(argv[2]);
    total_number_of_block_requests = argc-3;
    char replacement_policy = argv[1][0];
    cache = (int *) malloc(sizeof(int) * size_cache);
    int *array = (int *) malloc(sizeof(int) * total_number_of_block_requests);
    for(int i=3;i<argc;i++)
    {
        array[i-3] = atoi(argv[i]);
    }
    get_from_main_memory(total_number_of_block_requests,array,replacement_policy); 
    printf("Miss Ratio = %f\n",miss_ratio());
    printf("Hit Ratio = %f\n",hit_ratio()); 
    return 0;
}  

void get_from_main_memory(int number_of_references,int *array,char replacement_policy)
{
    if(replacement_policy == 'F')
    {
        for(int i=0; i<number_of_references; i++)
        {
            FIFO(array[i]);
            display_cache();
            printf("\n\n");
        }
    }
    else if(replacement_policy == 'L')
    {
        for(int i=0; i<number_of_references; i++)
        {
            LRU(array[i]);
            display_cache();
            printf("\n\n");
        }
    }
}

void FIFO(int memory_block_reference)
{
    struct node* ptr = is_hit(memory_block_reference);
    if(ptr == NULL)
    {
        if(number_of_elements_in_cache < size_cache)
        {
            put_in_cache(memory_block_reference);
            enqueue(memory_block_reference);
        }
        else
        {
            int element_to_be_replaced = dequeue();
            enqueue(memory_block_reference);
            replace(memory_block_reference,element_to_be_replaced);
        }
    }
}

void LRU(int memory_block_reference)
{
    struct node* ptr = is_hit(memory_block_reference);
    if(ptr != NULL)
    {
        if(ptr == front)
        {
            int dequed = dequeue();
            enqueue(memory_block_reference);
        }
        else
        {
            delete_node(ptr);
            enqueue(memory_block_reference);
        }
    }
    else
    {
        if(number_of_elements_in_cache < size_cache)
        {
            put_in_cache(memory_block_reference);
            enqueue(memory_block_reference);
        }
        else
        {
            int element_to_be_replaced = dequeue();
            enqueue(memory_block_reference);
            replace(memory_block_reference,element_to_be_replaced);
        }
    }
}

void put_in_cache(int current_memory_blok)
{
    cache[number_of_elements_in_cache] = current_memory_blok;
    number_of_elements_in_cache++;
}

void replace(int current_memory_block,int old_memory_block)
{
    for(int i=0; i<size_cache; i++)
    {
        if(cache[i] == old_memory_block)
        {
            cache[i] = current_memory_block;
            break;
        }
    }
}

struct node* is_hit(int reference)
{
    printf("\n-------------------------\n");
    printf("Reference = %d\n",reference);
    struct node* temp = front;
    while(temp != NULL && temp->data != reference)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Miss\n");
        count_misses++;
    }
    else if(temp->data == reference)
    {
        printf("Hit\n");
        count_hits++;
    }
    return temp;
}
float miss_ratio()
{
    return (count_misses/(float)total_number_of_block_requests);
}
float hit_ratio()
{
    return (count_hits/(float)total_number_of_block_requests);
}
void delete_node(struct node* ptr)
{
    struct node* temp = front;
    while(temp->next != ptr)
        temp = temp->next;

    temp->next = ptr->next;
    if(temp->next == NULL)
        rear = temp;
    free(ptr);
}

void enqueue(int value)  
{  
    struct node *ptr;    
      
    ptr = (struct node *) malloc (sizeof(struct node));  
     
    if(ptr != NULL)  
    {    
        ptr -> data = value;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        } 
    } 
} 

int dequeue ()  
{  
    struct node *ptr = front;
    int dequed_element = front->data;   
    front = front -> next;  
    free(ptr);  
    return dequed_element;
} 

void display_cache()
{
    printf("Printing cache contents .....\n");
    for(int i=0; i<number_of_elements_in_cache; i++)
        printf("\t%d\n",cache[i]);
    printf("-------------------------\n");
}
/*
 * Put the compilation command.
 * Put the execution sequence.
 */
//Input format : ./08_01 cache_size <memory_reference1> memory_reference2 memory_reference3 ...
/*
commandline input>> ./08_01 4 0 1 2 2 2 4 2 5 4 3 4 3 5

-------------------------
Reference = 0
Miss
Printing cache contents .....
Least Recently Used
	0
Most Recently Used
-------------------------



-------------------------
Reference = 1
Miss
Printing cache contents .....
Least Recently Used
	0
	1
Most Recently Used
-------------------------



-------------------------
Reference = 2
Miss
Printing cache contents .....
Least Recently Used
	0
	1
	2
Most Recently Used
-------------------------



-------------------------
Reference = 2
Hit
Printing cache contents .....
Least Recently Used
	0
	1
	2
Most Recently Used
-------------------------



-------------------------
Reference = 2
Hit
Printing cache contents .....
Least Recently Used
	0
	1
	2
Most Recently Used
-------------------------



-------------------------
Reference = 4
Miss
Printing cache contents .....
Least Recently Used
	0
	1
	2
	4
Most Recently Used
-------------------------



-------------------------
Reference = 2
Hit
Printing cache contents .....
Least Recently Used
	0
	1
	4
	2
Most Recently Used
-------------------------



-------------------------
Reference = 5
Miss
Printing cache contents .....
Least Recently Used
	1
	4
	2
	5
Most Recently Used
-------------------------



-------------------------
Reference = 4
Hit
Printing cache contents .....
Least Recently Used
	1
	2
	5
	4
Most Recently Used
-------------------------



-------------------------
Reference = 3
Miss
Printing cache contents .....
Least Recently Used
	2
	5
	4
	3
Most Recently Used
-------------------------



-------------------------
Reference = 4
Hit
Printing cache contents .....
Least Recently Used
	2
	5
	3
	4
Most Recently Used
-------------------------



-------------------------
Reference = 3
Hit
Printing cache contents .....
Least Recently Used
	2
	5
	4
	3
Most Recently Used
-------------------------



-------------------------
Reference = 5
Hit
Printing cache contents .....
Least Recently Used
	2
	4
	3
	5
Most Recently Used
-------------------------


 */