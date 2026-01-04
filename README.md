# Philosophers

The Philosophers project is a simulation of the classic Dining Philosophers problem using threads and mutexes. The goal is to manage shared resources in a way that prevents deadlocks and data races, while respecting the philosophers’ lifecycles.

## Goal

- Learn and apply multithreading in C.
- Implement correct synchronization for shared resources.
- Handle timing and starvation constraints for multiple threads.
- Demonstrate understanding of deadlock prevention and safe concurrent programming.

## Program Description
Each philosopher:
1. Takes two forks
2. Eats for time_to_eat
3. Sleeps for time_to_sleep
4. Thinks

The simulation ends when:
- A philosopher dies because fails to eat within time_to_die
- All philosophers have eaten the times_to_eat

## Implementation Details

- Written in C using POSIX threads (pthread)
- Each philosopher is a separate thread
- The number of forks is the number of philosophers
- Forks are represented by mutexes
- Timestamps are calculated using gettimeofday to track last meal and detect death
- Shared variables are protected with mutexes to prevent data races

## Usage

1. Prerequisites
- POSIX-compliant operating system (Linux or macOS)
- POSIX-compatible shell (bash or zsh)
- GCC or Clang compiler with pthread support
2. Clone the repository.
```bash
git clone git@github.com:CLMartello/philosophers.git
```
3. Command "make" to compile.
```bash
make
```
4. Run executable ./philo followed by arguments.
```bash
./philo NUMBER_PHILOSOPHERS TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP TIMES_TO_EAT(OPTIONAL)
```

## License

This project is licensed under the MIT License — see the LICENSE file.
