/*
2. At the beginning of the file, use block comments to write details about name,
roll no, assignment details, input required and output generated. Also put the
compilation [should be WARNINGS/Errors free] and execution sequence under
the block comment. [Check the comment file]

Name :  Koushik Mahanta
Roll :  002011001106
Team No.08

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

*/
/*
Input Required : ./08_01 <cache_size> <main_memory_size> <L/F> <memory_reference1> <memory_reference2> <memory_reference3> ...
Output Generated :  Output will display the contents of the cache after each memory reference and also whether its a hit or a miss,
                    after the end of all refereces it will display the corresponding hit ratio.
*/
#include <stdio.h>   
#include<stdlib.h>

int *cache;
int total_number_of_block_requests;
int count_hits=0;
int size_cache, size_mainMemory, number_of_elements_in_cache = 0;

void replace(int current_memory_block,int old_memory_block);//old_memory_block will be replaced with current memory block
void put_in_cache(int memory_blok);//This function will put a memory block in the cache
void get_from_main_memory(int number_of_references,int *array,char replacement_policy);//This function will call the replacement algoritms for each of the memory references
void display_cache();//This function will display the contents of the cache
float hit_ratio();//This function will count and return the corresponding hit ratio after successful execution of the replacement algorithms

struct node   
{  
    int data;//this contains the data field
    struct node *next;//this contains the pointer to the next node
};
struct node *front;//this points to the first element of the queue
struct node *rear; //this points to the last element of the queue
void enqueue();//this function will add an element at the end of the queue
int dequeue(); //this function will delete the element at the begining of the queue
void delete_node(struct node* ptr);//this fuction will receive a pointer to a perticular node(element of the queue) of the queue end delete that node(element of the queue)  
  
void FIFO(int block_reference);/*this function receives a memory block reference and checks if it is present in the cache or not and
                                takes necessary action just to fill the cache and/or decides which memory block (that is already present in cache) is to be deleted to make space for the current reference acccording to the FIFO policy*/
void LRU(int block_reference);/*this function receives a memory block reference and checks if it is present in the cache or not and
                                takes necessary action just to fill the cache and/or decides depending on the recency of there referencs, which memory block (that is already present in cache) is to be deleted to make space for the current reference according to the LRU policy*/
struct node* is_hit(int reference);//this function receives a memory block referece and searches the queue (that is used to keep record of the contents of the cache and recency of reference to those contents) for that reference and returns NULL if it it not present in there and returns the pointer to the node of the queue if it is present 

int main (int argc, char* argv[]) //
{  
    size_cache = atoi(argv[1]);
    size_mainMemory = atoi(argv[2]);
    if(size_cache > (size_mainMemory/4))
    {
        printf("\nSize of cache must not be more than one-forth of the main memory size...\n\n");
        exit(1);
    }
    total_number_of_block_requests = argc-4;//first four string arguments contain the ./<executable file name>,size of cache,size of main memory and replacement policy respectably
    char replacement_policy = argv[3][0];
    cache = (int *) malloc(sizeof(int) * size_cache);
    int *array_of_memory_block_references = (int *) malloc(sizeof(int) * total_number_of_block_requests);

    for(int i=4;i<argc;i++)
        array_of_memory_block_references[i-4] = atoi(argv[i]);
    
    get_from_main_memory(total_number_of_block_requests,array_of_memory_block_references,replacement_policy);

    printf("Hit Ratio = %f\n",hit_ratio()); 
    return 0;
}  

void get_from_main_memory(int number_of_references,int *array,char replacement_policy)
{
    switch (replacement_policy)
    {
    case 'F':
        for(int i=0; i<number_of_references; i++)
        {
            FIFO(array[i]);
            display_cache();
            printf("\n\n");
        }
        break;
    
    case 'L':
        for(int i=0; i<number_of_references; i++)
        {
            LRU(array[i]);
            display_cache();
            printf("\n\n");
        }
        break;
    }
}

void FIFO(int memory_block_reference)
{
    struct node* ptr = is_hit(memory_block_reference);
    if(ptr == NULL)//Cache Miss, changes are made both to the cache and queue
    {
        if(number_of_elements_in_cache < size_cache)//cache not full , current memory block reference is put directly in the cache and enqueued in the queue at the same time 
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
    if(ptr != NULL)//Cache HIT, No changes in the cache, changes are made to the queue
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
    else//Cache MISS, changes are made both to the cache and the queue
    {
        if(number_of_elements_in_cache < size_cache)//The cache is not full so current memory block reference is put directly in the cache and enqueued in the queue at the same time
        {
            put_in_cache(memory_block_reference);
            enqueue(memory_block_reference);
        }
        else//The cache is full the least recently used element present at the beginig of the queue is dequeued and current block reference is put at the end of the queue using enqueue()
            //The dequeued memory block present in the cache is also replaced by the current memory block in the cache using replace() function
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
    number_of_elements_in_cache++;//increnents the varible which keeps count of the elements present in the cache
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
        printf("Miss\n");
    else if(temp->data == reference)
    {
        printf("Hit\n");
        count_hits++;
    }
    return temp;
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
/*               
LRU algorithm : This algorithm ensures that the most recently used memory block is always present 
                at the end of the queue and the least recently used memory block always remains at the begining
                of the queue to keep trak of recency of their reference and performs replacements in the cache accordingly.

    Step 1: LRU() function calls is_hit() function with the current memory reference as the argument 
    
    Step 2: The is_hit function returns the pointer to the node where the memory block is present or returns
            NULL if the memory block is not present in the queue (and the cache as well because the queue keeps record of the contents of the cache). 
    
    Step 3: If the node pointer returned by is_hit() is not NULL(Cache HIT) then no changes are made to the cache.
            But to record that the block is the most recently referenced memory block changes are made to the queue and the node holding the block in the queue is deleted using 
            delete_node() function and enqueued again to ensure that the node gets placed at the end of the 
            Queue and in case of the node being the front node of the queue, the dequeue() function is called 
            instead of the delete_node() function because deleting the front node and dequeing the queue is same.

    Step 4: If the node pointer returned by is_hit() is NULL(Cache MISS) then changes are made both to the cache and the queue 
            If the cache is not full simple put_in_cache() and enqueue() operation is performed untill the cache is full placing the most recently used block at the end and least recently used block at the begining of the queue
            If the cache is full and again NULL pointer is returned then dequeue and enqueue operations are performed espectably to delete the least recently used memory block from the queue and place the most recently used memory block at the end of the queue
            then the replace() is called (with the new memory block and the dequeued memor block as arguments) which replaces the least recently used memory block in cache(which is the dequeued one) by the most recently used memory block.
*/

/*
FIFO algorithm : This algorithm  ensures that the oldest memory block in the cache always remains at the begining of the queue and the newest one remains at the end of the queue
                and performs replacements in the cache accordingly.
    
    Step 1: FIFO() function calls is_hit() function with the current memory reference as the argument

    Step 2: The is_hit function returns the pointer to the node where the memory block is present or returns
            NULL if the memory block is not present in the queue(and the cache as well because the queue keeps record of the contents of the cache).

    Step 3: If the node pointer returned by is_hit() is not NULL(Cache HIT) then no changes are made to the cache and queue. Because the oldest element in the cache is already presnt at the begining of the queue and the oldest at the end of the queue.

    Step 4: If the node pointer returned by is_hit() is NULL(Cache MISS) then changes are made both to the cache and the queue 
            If the cache is not full simple put_in_cache() and enqueue() operation is performed untill the cache is full because of which the oldest element in the cache remains at the begining of the queue and newest element remains at the end of the queue
            If the cache is full and again NULL pointer is returned then dequeue() is performed to delete the first block (which is the oldest block in cache) from the queue  and after that enqueue() is performed to place the new memory block at the end of the queue
            then the replace() is called (with the new memory block and the dequeued memor block as arguments) which replaces the oldest memory block in the cache(which is the dequeued one) by the new one.
*/
/*