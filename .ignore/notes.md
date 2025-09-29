### A REWARD-TODO-BASED APP IN C

### ARCHITECTURE

Aug 23
-

there is one `task_file` that is split in different col 
TASKID  COMPLETE(Y/N)

I have different options
- Create a new task (this task will be written in the `task_file`)
    I need to prompt the different task field
    A task can be represented by a struct with 2 different fields
        char []name
        int complete

- Task is created:
    check if there is the `task` file. : I can check this with the fd.
    add a new line with the task name to the file
    open the file. write the task (start writing from the last char)
                    > can use getnextline to go
    close the file.

Running the app, and we see our current task: 
I can: Complete a task by pressing its ID `0-9`
Add a new task by pressing `N`
`Your current tasks:
    t1
    t2
    ...`

I have one function that create a task.

Aug 24
-
or all the task are in a list with an id.

### CODE DESIGN

2 main different objects:
ACHIEVEMENT & DESIRE/YIELD
and 1 unit of measure: *$$* (TOKEN)

*TASK*
    - ID
    - NAME
    - COMPLETED
    - REWARD ($)
*TASK_LIST*
    TASK1 TASK2 ...

*ACHIEVEMENTS*
    -> completed TASK historic
*ACHIEVEMENTS_LIST*
    `DONE_TASK1 DONE_TASK2 ...`

*YIELD*
    - ID
    - NAME
    - COST
*DESIRE_LIST*
    DESIRE1 DESIRE2 DESIRE3 ...

*TOKEN*
    - INT VALUE

*Where does the task_list stand? where is it created? in add_task()?*
*Init in the main, pass it as argument in createTask*

### FUNCTIONALITIES
    -INIT LIST()
        return tasklist
 
    - CREATETASK(TASKLIST)
        create the task struct:
            TASK ID: count the number of tasks in the list and +1 for the one.
            NAME: scanf
            COMPLETED: false
            REWARD: scanf
        addTask()
        return task;
   
   -  CREATEDESIRE(DESIRELIST)
        ...

    - ADDTASK()
        *add task to the task list*
    - ADDDESIRE()
        *add a desire to the desire list*
   - REMOVETASK() 
        *delete task from the list*
    - PRINTTASKS(tasklist)
        *go through the task list,*
        *print each task with its associated reward*
    - COMPLETETASK()
        scanf the task ID
        `remove_task_from_list`
    - PRINTDESIRES()
        ...
    - PRINTACHIEVEMNT() (Completed tasks)
        ...

    - YIELDDESIRE()
    - UPDATETOKEN()
    - PRINTTOKEN() (Always visible)

### GLOBAL DESIGN
src/
  main.c
  cli.c            // parse argv -> call services
  fs.c             // paths, mkdir -p, write-append
  timeutil.c       // ISO8601 now(), parse/format
  ledger.c         // appendevent(), scanevents(), computebalance()
  rules.c          // load missions.tsv / rewards.tsv, cooldowns, streak/combos
  economy.c        // price calculation with multipliers
  print.c          // table printers
include/*.h*
data/
  quests.tsv
  rewards.tsv
ledger/
snapshots/

I can use readline()
there is an infinite loop running in the `background`
each time I prompt, 
- readline get the input
- my parser parse (transform the different elements in *token*)
- />.grind ***print events 30***

-			  cmd   arg1   arg2
	*output*
ls yield
ls quest
	has to print in a time order or a expensive order or a importance order

log balance

Let's say I want to print the events (by default it will prompt the user)
I need to go in ./ledger/
from here: I need to check what is the current month
I use `t_time time = time_now()`
I parse time and keep the month: 9 (sept). I need to change the month from 9 to 09 (strcat is segfaulting)
so if the `time.current_month` is 09, I compare it with each filename and open the one corresponding. 
I write a new line of the Event.
TIMESTAMP            TYPE    ID    TOKEN   DONE   NOTES       (<=if there is no file, write this line)
2025-09-06:T20:57    QUEST   YTSH  +50     YES    42 related  (raw data) 

So any function like ls quests
need to go in that ledger file and start parsing the data properly ?
no. it would be for specific command want to have specific info.
it is like 
ls
ls -l
ls -la
ls -h
the default infile is always the same but the output will be in 3
different forms with additional data.
In my case, when I create a quest, with `> add quest "EXAM RANK 3"` I
can retrieve the time: it will be modified-time of the quests file. since I will write into this file. 
Where do I get the ledger-field data ?
TIMESTAMP: quests.tsv or any_file.tsv being written.
TYPE: argument in the cmd line (words[1]) `quest`
ID: words[2] "EXAM RANK 3"
GOLD: words[3] or based on the words[2] value:
actually even the words[2] value will be based on the words[1] value.
and words[1] depends on words[0]

for example for words[0] being add, that means that the words[1] cannot
be `balance` for example. that eliminate some context values.
can be 
- event
- reward
thats it.
I am no suppose to add any thing else.
I just have an idea that seams good. lets say I type `add quest`
then I am being scanf in the readline to get the different values, like the quest ID.
`add quest`
    ID:


but for now my logic is different: I directly read from the quests file
and I even want to add the quests when I type add quest cmd.

I run the app.

            WALLET: -100₡ 

            QUESTS:
            * GRIND GRINDEV 500₡    []
            * QUEST QUESTID REWARD  []
            

25.09.25
push from home pc

### Commands
cmd context arg
ls quest // list quest in a importance order
ls event 10 // list the last 10 events saved
log balance // print current wallet balance
ls quest today `log the quest of the day (deadline today)`
ls quest all // list all the quest
ls both // list all the quest and the desire 
ls quest week // list the quest of the week (until deadline comming sunday)
deadline // list the quest in a deadline order
ls yield // list yields from first to last chronologically
ls quest urgent // list quest in order of importantecy
recap print last 5 events, 5 desires and log wallet balance
add quest ID deadline important-level gold
add desire ID cost
complete quest ID
yield desire ID
help display ascreen help with commin commsasm


### Tokens
program
cmd
context
arg

we use readline to get the user input.


We need to think about the element review...
I cannot check each combination.
I need think of a logic that works for the cmd + arg + ...

Sep 26, 20:00
I need to scan the string, from there determine the elements I have in. 
Since I am working only
We need a scanner that we tell us 
- how many `words` we have in our input.
- what are they `type`
- are the matching.
- build a logic for a list of type. like ls that only work with execve for example.

We need structure.
we literrally need structure.
I need a struct that holds/store command, context and arg.

we need to make the difference between cmd and command list.

struct input{
	cmd
	context
	arg
}

Sep 27, 22:33

commands
contexts
args

	they are hard coded list of string.

we need the number of arguments in the cli
for example
	ls quests 10
	3 arguments
we also need the arg value

need to handle the last argument (arg) 
can be a number.
can be a string.

Sep 28, 01:32
Restructuration:
    need to have a logic for each cmd
    and cmd with arguments
	
parser logic:
	define our words
	scan
	count words
	identify words (tokenization)
	find pair (token match)
	execute

the argument case be a cmd, a `cmd_ctx` (actually we could even call it argument1) and 2nd argument...

#### The problem with `get_arg`
The return value `arg` can have different type.
it can be an int or a `char *`
the actual way we can handle this is actually by passing void to the function.
`void get_arg`
check whether arg is multiple digit values 
in that case return an int; or return the `char *` if it is not.
