Ayden Best

Data Structures & Algorithms at Chapman University

# Queue Implementation - Kiosk and Waiting Line Simulation

## Linked Queue
LinkedQueue is a linked-list based queue structure built from scratch

## Simulation
The implementation is a simulation of a registrar kiosk for students. Students arrive over time to wait in a line until a kiosk is available. Once at a kiosk, a student must spend some specified time recieving service at the kiosk.

##### Input Format
```
[number of windows]
[time of arrival for wave of students]
[number of students 'n']
[required service: student 1]
[required service: student 2]
[required service: student 3]
...
[required service: student n]
GOTO [time of arrival for wave of students]
```

##### Example input
Creates a simulation with:
- 5 kiosks
- at time 1, 2 students arrive with service times [5, 10]
- at time 3, 1 student arrives with service time [4]
```
5
1
2
5
10
3
1
4
```
