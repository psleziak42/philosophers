# Philosophers

Official description:
"_In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex._"

### The task is to solve problem of dinning philosophers via threads. 

<br>  .Philosophers are sitting at a round table with bowls of spaghetti. 
<br>  .Forks are placed between them. To eat spaghetti each needs to use 2 forks at the same time. Fork is a shared resource so we use mutex to make sure it will not be accessed by more than thread at the same time.
<br>  .Philosopher can: _eat_ -> after he finishes eating he goes to _sleep_ -> after he wakes up he may _think_. If any philosopher will not start eating before give _time to die_, he dies and simulation stops. If such an event won't occur they should be running forever.
<br><br><br>  .On this project the biggest challenge for me was a strategy to tacke it. In the beginning I had created one "mother" structure that any philo could access via its proper structure that had pointer to "mother". As a @mikysett explained to me later, "this would work but easily one thread could compromise behaviour of all the program by changing time to eat/sleep/die in "mother" what would affect all other threads". The approach used had changed, every philo got his own structure and they do not have more access to other philos data. There is also main structurethat holds shared data like forks, mutexes. Those are arrays and when we say "left and right fork" we mean address of the position of philo nr and address of the positon of philo nr + 1 in the mother structure array. For instance: philo 2 can pick up fork 2 and 3 (or 1 if there is only 2 philos), then if fork is taken its status in mother structure changes from 1 to 0. Now when thread 3 (philo 3) will try to acces hisforks (fork 3 and 4) he will mutex fork 3 and 4 and he will see that fork 3 is currently occupied so he will unmutex and keep checking untill he dies (time to die) or will finally pickit up :)
