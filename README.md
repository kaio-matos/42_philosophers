# Philosophers

This project aims to introduce 42 students into threads and your pitfalls with data races and deadlocks.
The concept around this project is to imagine a table with multiple philosophers (at least > 1 for at least 2 forks) that will `eat`, `sleep`, `think`.

The action `eat` requires the philosopher to take your own fork (each philosopher start with one fork attached to it) and borrow the fork from the next philosopher. This can cause multiple issues with data races.

The action `sleep` just makes the philosopher sleep (do nothing).

The action `think` is the majority of time just the time that the philosopher waits for take your own fork before eating (because he has to wait the other philosophers finish eating).

## Execution

With Make installed just run `make` in the terminal to compile the program:
```bash
cd philo
make
```

Arguments:
`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep times_to_eat (OPTIONAL)`

Then execute the program using the following rules:
`./philo 5 800 200 200`, the program should start printing each philosopher action until some philosopher dies.

### Examples

This should go on forever and ever
```bash
./philo 5 800 200 200
```


Every philosopher should eat at least 7 times
```bash
./philo 5 800 200 200 7
```


One philosopher should die
```bash
./philo 1 800 200 200
```


This should go on forever and ever
```bash
./philo 4 410 200 200
```

Some philosopher should die
```bash
./philo 3 410 200 200
```
