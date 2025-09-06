### A TODO APP IN C

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
ACHIEVEMENT & DESIRE
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
    DONE_TASK1 DONE_TASK2 ...

*DESIRE*
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
        remove_task_from_list
    - PRINTDESIRES()
        ...
    - PRINTACHIEVEMNT() (Completed tasks)
        ...

    - YIELDDESIRE()
    - UPDATETOKEN()
    - PRINTTOKEN() (Always visible)

###GLOBAL DESIGN
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
