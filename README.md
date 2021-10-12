# Philosophers

Official description:
"_In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex._"

### The task is to solve problem of dinning philosophers via threads. 
<br>
<br>  .Philosophers are sitting at a round table with bowls of spaghetti. 
<br>  .Forks are placed between them. To eat spaghetti each needs to use 2 forks at the same time. Fork is a shared resource so we use mutex to make sure it will not be accessed by more than thread at the same time.
<br>  .Philosophers can: _eat_ -> after they finish eating they go to _sleep_ -> after they wake up they may _think_. If any philosopher will not start eating before give _time to die_, he dies and simulation stops. If such an event won't occur they should be running forever.
